#include "diamond.hpp"

#include <cmath>

static const double tan30 = std::sqrt(1.0 / 3);
static const double tan30_2 = tan30 * 2;

void d3_shape::diamond::draw(d3_path::PathInterface &context, double size) {
    const auto
            y = std::sqrt(size / tan30_2),
            x = y * tan30;
    context.moveTo(0, -y);
    context.lineTo(x, 0);
    context.lineTo(0, y);
    context.lineTo(-x, 0);
    context.closePath();
}
