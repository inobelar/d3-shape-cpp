#include "d3_shape/curve/basisClosed.hpp"

#include <limits>

constexpr auto NULL_NUM = std::numeric_limits<d3_shape::BasisClosed::number_t>::quiet_NaN();


d3_shape::BasisClosed d3_shape::basisClosed(d3_path::PathInterface *context)
{
    return BasisClosed(context);
}

d3_shape::BasisClosed::BasisClosed(d3_path::PathInterface *context)
    : Basis(context)

    , _x2(NULL_NUM)
    , _y2(NULL_NUM)
    , _x3(NULL_NUM)
    , _y3(NULL_NUM)
    , _x4(NULL_NUM)
    , _y4(NULL_NUM)
{ }

void d3_shape::BasisClosed::areaStart()
{
    // Noop
}

void d3_shape::BasisClosed::areaEnd()
{
    // Noop
}

void d3_shape::BasisClosed::lineStart() {
    this->_x0 = this->_x1 = this->_x2 = this->_x3 = this->_x4 =
    this->_y0 = this->_y1 = this->_y2 = this->_y3 = this->_y4 = NULL_NUM;
    this->_point = 0;
}

void d3_shape::BasisClosed::lineEnd() {
    switch (this->_point) {
    case 1: {
        this->_context->moveTo(this->_x2, this->_y2);
        this->_context->closePath();
        break;
    }
    case 2: {
        this->_context->moveTo((this->_x2 + 2 * this->_x3) / 3, (this->_y2 + 2 * this->_y3) / 3);
        this->_context->lineTo((this->_x3 + 2 * this->_x2) / 3, (this->_y3 + 2 * this->_y2) / 3);
        this->_context->closePath();
        break;
    }
    case 3: {
        this->point(this->_x2, this->_y2);
        this->point(this->_x3, this->_y3);
        this->point(this->_x4, this->_y4);
        break;
    }
    }
}

void d3_shape::BasisClosed::point(CurveInterface::number_t x, CurveInterface::number_t y) {
    switch (this->_point) {
    case 0: { this->_point = 1; this->_x2 = x, this->_y2 = y; } break;
    case 1: { this->_point = 2; this->_x3 = x, this->_y3 = y; } break;
    case 2: { this->_point = 3; this->_x4 = x, this->_y4 = y; this->_context->moveTo((this->_x0 + 4 * this->_x1 + x) / 6, (this->_y0 + 4 * this->_y1 + y) / 6); } break;
    default: point_(this, x, y); break;
    }
    this->_x0 = this->_x1; this->_x1 = x;
    this->_y0 = this->_y1; this->_y1 = y;
}
