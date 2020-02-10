#include "d3_shape/symbol/triangle.hpp"

#include <cmath>

static const auto sqrt3 = std::sqrt(3);

void d3_shape::triangle::draw(d3_path::PathInterface &context, double size) {
    const auto y = -std::sqrt(size / (sqrt3 * 3));
    context.moveTo(0, y * 2);
    context.lineTo(-sqrt3 * y, -y);
    context.lineTo(sqrt3 * y, -y);
    context.closePath();
}
