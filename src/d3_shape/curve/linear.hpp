#ifndef D3__SHAPE__CURVE__LINEAR_HPP
#define D3__SHAPE__CURVE__LINEAR_HPP

#include "d3_shape/curve/CurveInterface.hpp"

#include "d3_path/PathInterface.hpp"

namespace d3_shape {

class Linear : public CurveInterface
{
    d3_path::PathInterface* _context;

    int _point;
    number_t _line; // TODO: posibly int
public:

    Linear(d3_path::PathInterface* context);

    void areaStart() override;
    void areaEnd() override;
    void lineStart() override;
    void lineEnd() override;
    void point(number_t x, number_t y) override;
};

Linear linear(d3_path::PathInterface* context);

} // namespace d3_shape

#endif // D3__SHAPE__CURVE__LINEAR_HPP
