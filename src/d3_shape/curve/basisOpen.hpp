#ifndef D3__SHAPE__CURVE__BASIS_OPEN_HPP
#define D3__SHAPE__CURVE__BASIS_OPEN_HPP

#include "d3_shape/curve/basis.hpp"

namespace d3_shape {

class BasisOpen : public Basis
{
public:
    using Basis::Basis;

    void areaStart() override;
    void areaEnd() override;
    void lineStart() override;
    void lineEnd() override;
    void point(number_t x, number_t y) override;
};

BasisOpen basisOpen(d3_path::PathInterface* context);

} // namespace d3_shape

#endif // D3__SHAPE__CURVE__BASIS_OPEN_HPP
