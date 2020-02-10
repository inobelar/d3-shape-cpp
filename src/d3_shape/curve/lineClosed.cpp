#include "d3_shape/curve/lineClosed.hpp"

d3_shape::LineClosed::LineClosed(d3_path::PathInterface *context)
    : _context(context)

    , _point(0)
{}

void d3_shape::LineClosed::areaStart() {
    // noop
}

void d3_shape::LineClosed::areaEnd()
{
    // noop
}

void d3_shape::LineClosed::lineStart()
{
    this->_point = 0;
}

void d3_shape::LineClosed::lineEnd()
{
    if (this->_point) this->_context->closePath();
}

void d3_shape::LineClosed::point(CurveInterface::number_t x, CurveInterface::number_t y)
{
    if (this->_point) this->_context->lineTo(x, y);
    else { this->_point = 1; this->_context->moveTo(x, y); }
}

// -----------------------------------------------------------------------------

d3_shape::LineClosed d3_shape::lineClosed(d3_path::PathInterface *context) {
    return LineClosed(context);
}
