#ifndef D3__SHAPE__ORDER__APPEARANCE_HPP
#define D3__SHAPE__ORDER__APPEARANCE_HPP

#include "d3_shape/order/none.hpp"

#include <limits> // for std::numeric_limits<T>::infinity()

#include <algorithm> // for std::sort()

namespace d3_shape {

namespace detail {

template <typename T>
inline std::vector<T> peak(const std::vector<T>& series) {
    constexpr auto Infinity = std::numeric_limits<T>::infinity();

    std::size_t i = -1, j = 0, n = series.length, vi, vj = -Infinity;
    while (++i < n) if ((vi = series[i][1]) > vj) { vj = vi; j = i; } // TODO: series[i] and [1]!!!
    return j;
}

template <typename T, typename F>
inline std::vector<T> map(const std::vector<T>& series, const F& func) {
    auto result = series;
    for(auto& item : result)
        func(item);
    return result;
}

} // namespace detail

template <typename T, typename series_t = std::vector<T> >
inline series_t appearance(const series_t& series)
{
    const auto peaks = map(series, detail::peak);
    const auto result = none(series);
    std::sort(result.begin(), result.end(), [&peaks](const T& a, const T& b) { return peaks[a] - peaks[b]; });
    return result;
}

} // namespace d3_shape

#endif // D3__SHAPE__ORDER__APPEARANCE_HPP
