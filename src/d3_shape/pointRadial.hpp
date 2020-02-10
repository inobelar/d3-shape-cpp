#ifndef D3__SHAPE__POINT_RADIAL_HPP
#define D3__SHAPE__POINT_RADIAL_HPP

#include <array>
#include <cmath>

namespace d3_shape {

template<typename T>
inline std::array<T, 2> pointRadial(T x, T y) {
    return {y * std::cos(x -= M_PI / 2), y * std::sin(x)};
}

} // namespace d3_shape

#endif // D3__SHAPE__POINT_RADIAL_HPP
