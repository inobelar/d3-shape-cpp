#include "d3_shape/curve/step.hpp"

#include <limits>

constexpr auto NULL_NUM = std::numeric_limits<d3_shape::Step::number_t>::quiet_NaN();

d3_shape::Step::Step(d3_path::PathInterface *context, number_t t)
    : _context(context)
    , _t(t)

    , _x(NULL_NUM)
    , _y(NULL_NUM)
    , _line(NULL_NUM)
{}

void d3_shape::Step::areaStart() {
    this->_line = 0;
}

void d3_shape::Step::areaEnd() {
    this->_line = NULL_NUM;
}

void d3_shape::Step::lineStart() {
    this->_x = this->_y = NULL_NUM;
    this->_point = 0;
}

void d3_shape::Step::lineEnd() {
    if (0 < this->_t && this->_t < 1 && this->_point == 2) this->_context->lineTo(this->_x, this->_y);
    if (this->_line || (this->_line != 0 && this->_point == 1)) this->_context->closePath();
    if (this->_line >= 0) this->_t = 1 - this->_t, this->_line = 1 - this->_line;
}

void d3_shape::Step::point(number_t x, number_t y) {
    switch (this->_point) {
    case 0: this->_point = 1; this->_line ? this->_context->lineTo(x, y) : this->_context->moveTo(x, y); break;
    case 1: this->_point = 2; // proceed
    default: {
        if (this->_t <= 0) {
            this->_context->lineTo(this->_x, y);
            this->_context->lineTo(x, y);
        } else {
            const auto x1 = this->_x * (1 - this->_t) + x * this->_t;
            this->_context->lineTo(x1, this->_y);
            this->_context->lineTo(x1, y);
        }
        break;
    }
    }
    this->_x = x; this->_y = y;
}

// -----------------------------------------------------------------------------

d3_shape::Step d3_shape::step(d3_path::PathInterface *context) {
    return Step(context, 0.5);
}

d3_shape::Step d3_shape::stepBefore(d3_path::PathInterface *context) {
    return Step(context, 0);
}

d3_shape::Step d3_shape::stepAfter(d3_path::PathInterface *context) {
    return Step(context, 1);
}
