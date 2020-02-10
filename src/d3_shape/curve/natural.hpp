#ifndef D3__SHAPE__CURVE__NATURAL_HPP
#define D3__SHAPE__CURVE__NATURAL_HPP

#include "d3_shape/curve/CurveInterface.hpp"

#include "d3_path/PathInterface.hpp"

#include <vector>

namespace d3_shape {

class Natural : public CurveInterface
{
    d3_path::PathInterface* _context;

    number_t _line; // TODO: possibly int
    std::vector<number_t> _x;
    std::vector<number_t> _y;
public:
    Natural(d3_path::PathInterface* context);

    void areaStart() override;
    void areaEnd() override;
    void lineStart() override;
    void lineEnd() override;
    void point(number_t x, number_t y) override;
};

Natural natural(d3_path::PathInterface* context);

} // namespace d3_shape

#endif // D3__SHAPE__CURVE__NATURAL_HPP
