#include "d3_shape/symbol/circle.hpp"

#include "d3_shape/math.hpp"

void d3_shape::circle::draw(d3_path::PathInterface &context, double size) {
    const auto r = std::sqrt(size / pi);
    context.moveTo(r, 0);
    context.arc(0, 0, r, 0, tau);
}
