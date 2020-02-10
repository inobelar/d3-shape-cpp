#ifndef D3__SHAPE__CURVE__CARDINAL_HPP
#define D3__SHAPE__CURVE__CARDINAL_HPP

#include "d3_shape/curve/CurveInterface.hpp"

#include "d3_path/PathInterface.hpp"

namespace d3_shape {

class Cardinal : public CurveInterface
{
    d3_path::PathInterface* _context;
    double _k;

    int _point;
    number_t _line; // TODO: must be int
    number_t _x0, _x1, _x2, _y0, _y1, _y2;

    // NOTE: in js code, this function is 'exported'. why?
    // maybe this used somehow outside of this scope ?
    // or propably do an merge request tom make it local
    // or make it public here
    static void point_(Cardinal* that, number_t x, number_t y);

public:
    Cardinal(d3_path::PathInterface* context, double tension);

    void areaStart() override;
    void areaEnd() override;
    void lineStart() override;
    void lineEnd() override;
    void point(number_t x, number_t y) override;
};

// TODO: cardinal func

} // namespace d3_shape

#endif // D3__SHAPE__CURVE__CARDINAL_HPP
