#include "d3_shape/curve/linear.hpp"

#include <limits>

constexpr auto NULL_NUM = std::numeric_limits<d3_shape::Linear::number_t>::quiet_NaN();

d3_shape::Linear::Linear(d3_path::PathInterface *context)
    : _context(context)

    , _point(0)
    , _line(NULL_NUM)
{}

void d3_shape::Linear::areaStart() {
    this->_line = 0;
}

void d3_shape::Linear::areaEnd() {
    this->_line = NULL_NUM;
}

void d3_shape::Linear::lineStart() {
    this->_point = 0;
}

void d3_shape::Linear::lineEnd() {
    if (this->_line || (this->_line != 0 && this->_point == 1)) this->_context->closePath();
    this->_line = 1 - this->_line;
}

void d3_shape::Linear::point(CurveInterface::number_t x, CurveInterface::number_t y) {
    switch (this->_point) {
    case 0: this->_point = 1; this->_line ? this->_context->lineTo(x, y) : this->_context->moveTo(x, y); break;
    case 1: this->_point = 2; // proceed
    default: this->_context->lineTo(x, y); break;
    }
}

// ------------------------------------------------------------------------------

d3_shape::Linear d3_shape::linear(d3_path::PathInterface *context) {
    return Linear(context);
}
