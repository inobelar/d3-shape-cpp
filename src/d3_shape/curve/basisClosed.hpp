#ifndef D3__SHAPE__CURVE__BASIS_CLOSED_HPP
#define D3__SHAPE__CURVE__BASIS_CLOSED_HPP

#include "d3_shape/curve/basis.hpp"

namespace d3_shape {

class BasisClosed : public Basis
{
    number_t _x2, _y2, _x3, _y3, _x4, _y4;
public:
    BasisClosed(d3_path::PathInterface* context);

    void areaStart() override;
    void areaEnd() override;
    void lineStart() override;
    void lineEnd() override;
    void point(number_t x, number_t y) override;
};

BasisClosed basisClosed(d3_path::PathInterface* context);

} // namespace d3_shape


#endif // D3__SHAPE__CURVE__BASIS_CLOSED_HPP
