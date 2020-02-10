#include "d3_shape/curve/basisOpen.hpp"

#include <limits>

constexpr auto NULL_NUM = std::numeric_limits<d3_shape::Basis::number_t>::quiet_NaN();

void d3_shape::BasisOpen::areaStart()
{
    this->_line = 0;
}

void d3_shape::BasisOpen::areaEnd()
{
    this->_line = NULL_NUM;
}

void d3_shape::BasisOpen::lineStart()
{
    this->_x0 = this->_x1 =
    this->_y0 = this->_y1 = NULL_NUM;
    this->_point = 0;
}

void d3_shape::BasisOpen::lineEnd()
{
    if (this->_line || (this->_line != 0 && this->_point == 3)) this->_context->closePath();
    this->_line = 1 - this->_line;
}

void d3_shape::BasisOpen::point(CurveInterface::number_t x, CurveInterface::number_t y)
{
    switch (this->_point) {
        case 0: this->_point = 1; break;
        case 1: this->_point = 2; break;
        case 2: { this->_point = 3; const auto x0 = (this->_x0 + 4 * this->_x1 + x) / 6, y0 = (this->_y0 + 4 * this->_y1 + y) / 6; this->_line ? this->_context->lineTo(x0, y0) : this->_context->moveTo(x0, y0); } break;
        case 3: this->_point = 4; // proceed
        default: point_(this, x, y); break;
    }
    this->_x0 = this->_x1; this->_x1 = x;
    this->_y0 = this->_y1; this->_y1 = y;
}

// -----------------------------------------------------------------------------

d3_shape::BasisOpen d3_shape::basisOpen(d3_path::PathInterface *context) {
    return BasisOpen(context);
}
