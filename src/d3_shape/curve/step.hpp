#ifndef D3__SHAPE__CURVE__STEP_HPP
#define D3__SHAPE__CURVE__STEP_HPP

#include "d3_shape/curve/CurveInterface.hpp"

#include "d3_path/PathInterface.hpp"

namespace d3_shape {

class Step : public CurveInterface
{
    d3_path::PathInterface* _context;
    number_t  _t;

    int _point;
    number_t  _x;
    number_t  _y;
    number_t  _line; // TODO: possibly int
public:

    Step(d3_path::PathInterface* context, number_t t);

    void areaStart() override;
    void areaEnd()   override;

    void lineStart() override;
    void lineEnd()   override;

    void point(number_t x, number_t y) override;
};

Step step(d3_path::PathInterface* context);

Step stepBefore(d3_path::PathInterface* context);

Step stepAfter(d3_path::PathInterface* context);

} // namespace d3_shape

#endif // D3__SHAPE__CURVE__STEP_HPP
