#ifndef D3__SHAPE__ORDER__REVERSE_HPP
#define D3__SHAPE__ORDER__REVERSE_HPP

#include "d3_shape/order/none.hpp"

#include <algorithm> // for std::reverse<T>()

namespace d3_shape {

template <typename T>
inline std::vector<T> reverse(const std::vector<T>& series)
{
    auto result = none(series);
    std::reverse(result.begin(), result.end());
    return result;
}

} // namespace d3_shape

#endif // D3__SHAPE__ORDER__REVERSE_HPP
