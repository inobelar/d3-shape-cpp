#include "d3_shape/curve/basis.hpp"

#include <limits>

constexpr auto NULL_NUM = std::numeric_limits<d3_shape::Basis::number_t>::quiet_NaN();


void d3_shape::Basis::point_(d3_shape::Basis *that, CurveInterface::number_t x, CurveInterface::number_t y)
{
    that->_context->bezierCurveTo(
      (2 * that->_x0 + that->_x1) / 3,
      (2 * that->_y0 + that->_y1) / 3,
      (that->_x0 + 2 * that->_x1) / 3,
      (that->_y0 + 2 * that->_y1) / 3,
      (that->_x0 + 4 * that->_x1 + x) / 6,
      (that->_y0 + 4 * that->_y1 + y) / 6
    );
}

d3_shape::Basis::Basis(d3_path::PathInterface *context)
    : _context(context)

    , _line(NULL_NUM)
    , _point(0)

    , _x0(NULL_NUM)
    , _y0(NULL_NUM)
    , _x1(NULL_NUM)
    , _y1(NULL_NUM)
{}

void d3_shape::Basis::areaStart() {
    this->_line = 0;
}

void d3_shape::Basis::areaEnd() {
    this->_line = NULL_NUM;
}

void d3_shape::Basis::lineStart() {
    this->_x0 = this->_x1 =
    this->_y0 = this->_y1 = NULL_NUM;
    this->_point = 0;
}

void d3_shape::Basis::lineEnd() {
    switch (this->_point) {
    case 3: point_(this, this->_x1, this->_y1); // proceed
    case 2: this->_context->lineTo(this->_x1, this->_y1); break;
    }
    if (this->_line || (this->_line != 0 && this->_point == 1)) this->_context->closePath();
    this->_line = 1 - this->_line;
}

void d3_shape::Basis::point(CurveInterface::number_t x, CurveInterface::number_t y) {
    switch (this->_point) {
    case 0: { this->_point = 1; this->_line ? this->_context->lineTo(x, y) : this->_context->moveTo(x, y); } break;
    case 1: { this->_point = 2; } break;
    case 2: { this->_point = 3; this->_context->lineTo((5 * this->_x0 + this->_x1) / 6, (5 * this->_y0 + this->_y1) / 6); } // proceed
    default: point_(this, x, y); break;
    }
    this->_x0 = this->_x1; this->_x1 = x;
    this->_y0 = this->_y1; this->_y1 = y;
}

// -----------------------------------------------------------------------------

d3_shape::Basis d3_shape::basis(d3_path::PathInterface *context) {
    return Basis(context);
}
