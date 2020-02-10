#include "d3_shape/symbol/square.hpp"

#include <cmath> // for std::sqrt

void d3_shape::square::draw(d3_path::PathInterface &context, double size) {
    const auto
            w = std::sqrt(size),
            x = -w / 2;
    context.rect(x, x, w, w);
}
