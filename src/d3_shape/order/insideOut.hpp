#ifndef D3__SHAPE__ORDER__INSIDEOUT_HPP
#define D3__SHAPE__ORDER__INSIDEOUT_HPP

#include "d3_shape/order/appearance.hpp"
#include "d3_shape/order/ascending.hpp" // for detail::sum()

namespace d3_shape {

namespace detail {


template <typename T>
inline std::vector<T> concat(std::vector<T>& dest, const std::vector<T>& src)
{
    // via: https://stackoverflow.com/a/21972296
    // Move elements from src to dest.
    // src is left in undefined but safe-to-destruct state.
    dest.insert(
        dest.end(),
        std::make_move_iterator(src.begin()),
        std::make_move_iterator(src.end())
      );
}

} // namespace detail

template <typename T>
void insideOut(const std::vector<T>& series) {
    const std::size_t n = series.size();
    std::size_t i,
                j;
    auto sums = detail::map(series, detail::sum);
    auto order = appearance(series);
    T top = 0;
    T bottom = 0;
    std::vector<T> tops = {};
    std::vector<T> bottoms = {};

    for (i = 0; i < n; ++i) {
        j = order[i];
        if (top < bottom) {
            top += sums[j];
            tops.push_back(j);
        } else {
            bottom += sums[j];
            bottoms.push_back(j);
        }
    }

    std::reverse(bottoms.begin(), bottoms.end());
    detail::concat(bottoms, tops);
    return bottoms;
}

} // namespace d3_shape

#endif // D3__SHAPE__ORDER__INSIDEOUT_HPP
