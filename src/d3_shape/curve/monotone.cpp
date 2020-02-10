#include "d3_shape/curve/monotone.hpp"

// =============================================================================

#include <limits>

using number_t = d3_shape::MonotoneX::number_t; // Shortcut

constexpr auto NULL_NUM = std::numeric_limits<number_t>::quiet_NaN();

// =============================================================================

#include <algorithm> // for std::min({})

template <typename T>
inline T sign(T x) {
    return x < 0 ? -1 : 1;
}

// Calculate the slopes of the tangents (Hermite-type interpolation) based on
// the following paper: Steffen, M. 1990. A Simple Method for Monotonic
// Interpolation in One Dimension. Astronomy and Astrophysics, Vol. 239, NO.
// NOV(II), P. 443, 1990.
number_t d3_shape::MonotoneX::slope3(d3_shape::MonotoneX* that, number_t x2, number_t y2) {
    const auto
            h0 = that->_x1 - that->_x0,
            h1 = x2 - that->_x1,
            s0 = (that->_y1 - that->_y0) / (h0 || h1 < 0 && -0),
            s1 = (y2 - that->_y1) / (h1 || h0 < 0 && -0),
            p = (s0 * h1 + s1 * h0) / (h0 + h1);
    return (sign(s0) + sign(s1)) * std::min({std::abs(s0), std::abs(s1), 0.5 * std::abs(p)}) || 0;
}

// Calculate a one-sided slope.
number_t d3_shape::MonotoneX::slope2(d3_shape::MonotoneX* that, number_t t) {
    auto h = that->_x1 - that->_x0;
    return h ? (3 * (that->_y1 - that->_y0) / h - t) / 2 : t;
}

// According to https://en.wikipedia.org/wiki/Cubic_Hermite_spline#Representations
// "you can express cubic Hermite interpolation in terms of cubic Bézier curves
// with respect to the four values p0, p0 + m0 / 3, p1 - m1 / 3, p1".
void d3_shape::MonotoneX::point(d3_shape::MonotoneX* that, number_t t0, number_t t1) {
    const auto
            x0 = that->_x0,
            y0 = that->_y0,
            x1 = that->_x1,
            y1 = that->_y1,
            dx = (x1 - x0) / 3;
    that->_context->bezierCurveTo(x0 + dx, y0 + dx * t0, x1 - dx, y1 - dx * t1, x1, y1);
}

// =============================================================================

d3_shape::MonotoneX::MonotoneX(d3_path::PathInterface *context)
    : _context(context)

    , _point(0)
    , _line(NULL_NUM)
    , _x0(NULL_NUM)
    , _x1(NULL_NUM)
    , _y0(NULL_NUM)
    , _y1(NULL_NUM)
    , _t0(NULL_NUM)
{}

void d3_shape::MonotoneX::areaStart() {
    this->_line = 0;
}

void d3_shape::MonotoneX::areaEnd() {
    this->_line = NULL_NUM;
}

void d3_shape::MonotoneX::lineStart() {
    this->_x0 = this->_x1 =
    this->_y0 = this->_y1 =
    this->_t0 = NULL_NUM;
    this->_point = 0;
}

void d3_shape::MonotoneX::lineEnd() {
    switch (this->_point) {
    case 2: this->_context->lineTo(this->_x1, this->_y1); break;
    case 3: point(this, this->_t0, slope2(this, this->_t0)); break;
    }
    if (this->_line || (this->_line != 0 && this->_point == 1)) this->_context->closePath();
    this->_line = 1 - this->_line;
}

void d3_shape::MonotoneX::point(CurveInterface::number_t x, CurveInterface::number_t y) {
    number_t t1 = NULL_NUM;

    if (x == this->_x1 && y == this->_y1) return; // Ignore coincident points.
    switch (this->_point) {
    case 0: this->_point = 1; this->_line ? this->_context->lineTo(x, y) : this->_context->moveTo(x, y); break;
    case 1: this->_point = 2; break;
    case 2: this->_point = 3; point(this, slope2(this, t1 = slope3(this, x, y)), t1); break;
    default: point(this, this->_t0, t1 = slope3(this, x, y)); break;
    }

    this->_x0 = this->_x1; this->_x1 = x;
    this->_y0 = this->_y1; this->_y1 = y;
    this->_t0 = t1;
}

// =============================================================================
