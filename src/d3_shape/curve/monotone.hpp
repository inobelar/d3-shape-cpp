#ifndef D3__SHAPE__MONOTONE_HPP
#define D3__SHAPE__MONOTONE_HPP

#include "d3_shape/curve/CurveInterface.hpp"

#include "d3_path/PathInterface.hpp"

namespace d3_shape {

class MonotoneX : public CurveInterface
{
    d3_path::PathInterface* _context;

    int _point;
    number_t _line; // TODO: Posibly int

    number_t _x0, _x1, _y0, _y1, _t0;

    static number_t slope3(d3_shape::MonotoneX* that, number_t x2, number_t y2);
    static number_t slope2(d3_shape::MonotoneX* that, number_t t);
    static void point(d3_shape::MonotoneX* that, number_t t0, number_t t1);

public:

    MonotoneX(d3_path::PathInterface* context);

    void areaStart() override;
    void areaEnd() override;
    void lineStart() override;
    void lineEnd() override;

    void point(number_t x, number_t y) override;
};

// TODO: ... rest

} // namespace d3_shape

#endif // D3__SHAPE__MONOTONE_HPP
