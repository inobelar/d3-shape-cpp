#include "d3_shape/curve/cardinal.hpp"

#include <limits>

constexpr auto NULL_NUM = std::numeric_limits<d3_shape::Cardinal::number_t>::quiet_NaN();


void d3_shape::Cardinal::point_(d3_shape::Cardinal *that, CurveInterface::number_t x, CurveInterface::number_t y)
{
    that->_context->bezierCurveTo(
        that->_x1 + that->_k * (that->_x2 - that->_x0),
        that->_y1 + that->_k * (that->_y2 - that->_y0),
        that->_x2 + that->_k * (that->_x1 - x),
        that->_y2 + that->_k * (that->_y1 - y),
        that->_x2,
        that->_y2
    );
}

d3_shape::Cardinal::Cardinal(d3_path::PathInterface *context, double tension)
    : _context(context)
    , _k( (1 - tension) / 6 )

    , _point(0)
    , _line(NULL_NUM)
    , _x0(NULL_NUM)
    , _x1(NULL_NUM)
    , _x2(NULL_NUM)
    , _y0(NULL_NUM)
    , _y1(NULL_NUM)
    , _y2(NULL_NUM)
{}

void d3_shape::Cardinal::areaStart() {
    this->_line = 0;
}

void d3_shape::Cardinal::areaEnd() {
    this->_line = NULL_NUM;
}

void d3_shape::Cardinal::lineStart() {
    this->_x0 = this->_x1 = this->_x2 =
    this->_y0 = this->_y1 = this->_y2 = NULL_NUM;
    this->_point = 0;
}

void d3_shape::Cardinal::lineEnd() {
    switch (this->_point) {
    case 2: { this->_context->lineTo(this->_x2, this->_y2); } break;
    case 3: { point_(this, this->_x1, this->_y1); } break;
    }
    if (this->_line || (this->_line != 0 && this->_point == 1)) this->_context->closePath();
    this->_line = 1 - this->_line;
}

void d3_shape::Cardinal::point(CurveInterface::number_t x, CurveInterface::number_t y) {
    switch (this->_point) {
    case 0: { this->_point = 1; this->_line ? this->_context->lineTo(x, y) : this->_context->moveTo(x, y); } break;
    case 1: { this->_point = 2; this->_x1 = x, this->_y1 = y; } break;
    case 2: this->_point = 3; // proceed
    default: point_(this, x, y); break;
    }
    this->_x0 = this->_x1; this->_x1 = this->_x2; this->_x2 = x;
    this->_y0 = this->_y1; this->_y1 = this->_y2; this->_y2 = y;
}
