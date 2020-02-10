#ifndef D3__SHAPE__MATH_HPP
#define D3__SHAPE__MATH_HPP

#include <cmath>

namespace d3_shape {

constexpr double epsilon = 1e-12;
constexpr double pi = M_PI;
constexpr double halfPi = pi / 2;
constexpr double tau = 2 * pi;

template <typename T>
inline T acos(T x) {
    return x > 1 ? 0 : x < -1 ? pi : std::acos(x);
}

template <typename T>
inline T asin(T x) {
    return x >= 1 ? halfPi : x <= -1 ? -halfPi : std::asin(x);
}

} // namespace d3_shape


#endif // D3__SHAPE__MATH_HPP
