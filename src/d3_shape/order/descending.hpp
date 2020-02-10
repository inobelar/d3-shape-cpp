#ifndef D3__SHAPE__ORDER__DESCENDING_HPP
#define D3__SHAPE__ORDER__DESCENDING_HPP

#include "d3_shape/order/ascending.hpp"

namespace d3_shape {

template <typename T>
std::vector<T> descending(const std::vector<std::vector<std::vector<T>>>& series) {
    auto result = ascending(series);
    std::reverse(result.begin(), result.end());
    return result;
}

} // namespace d3_shape

#endif // D3__SHAPE__ORDER__DESCENDING_HPP
