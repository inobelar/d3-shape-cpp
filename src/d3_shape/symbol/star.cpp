#include "d3_shape/symbol/star.hpp"

#include "d3_shape/math.hpp"

namespace d3_shape {

constexpr    double ka = 0.89081309152928522810;
static const double kr = std::sin(pi / 10) / std::sin(7 * pi / 10),
                    kx = std::sin(tau / 10) * kr,
                    ky = -std::cos(tau / 10) * kr;

} // namespace d3_shape

void d3_shape::star::draw(d3_path::PathInterface &context, double size) {
    const auto
            r = std::sqrt(size * ka),
            x = kx * r,
            y = ky * r;
    context.moveTo(0, -r);
    context.lineTo(x, y);
    for (int i = 1; i < 5; ++i) {
        const auto
                a = tau * i / 5,
                c = std::cos(a),
                s = std::sin(a);
        context.lineTo(s * r, -c * r);
        context.lineTo(c * x - s * y, s * x + c * y);
    }
    context.closePath();
}
