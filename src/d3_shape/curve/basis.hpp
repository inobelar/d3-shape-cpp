#ifndef D3__SHAPE__CURVE__BASIS_HPP
#define D3__SHAPE__CURVE__BASIS_HPP

#include "d3_shape/curve/CurveInterface.hpp"

#include "d3_path/PathInterface.hpp"

namespace d3_shape {

class Basis : public CurveInterface
{
protected:
    d3_path::PathInterface* _context;

    number_t _line; // TODO: must be int
    int _point;
    number_t _x0, _y0, _x1, _y1;

    void point_(Basis* that, number_t x, number_t y);

public:
    Basis(d3_path::PathInterface* context);

    void areaStart() override;
    void areaEnd() override;
    void lineStart() override;
    void lineEnd() override;
    void point(number_t x, number_t y) override;
};

Basis basis(d3_path::PathInterface* context);

} // namespace d3_shape

#endif // D3__SHAPE__CURVE__BASIS_HPP
