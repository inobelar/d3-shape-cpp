#ifndef D3__SHAPE__ORDER__ASCENDING_HPP
#define D3__SHAPE__ORDER__ASCENDING_HPP

#include "d3_shape/order/none.hpp"

#include <algorithm> // for std::sort()

namespace d3_shape {

namespace detail {

template <typename T, typename series_t = std::vector< std::vector<T> > >
series_t sum(const series_t& series) {
    std::size_t s = 0, i = -1, n = series.size(), v;
    while (++i < n) if (v = series[i][1]) s += v; // FIXME: FFFFFFUUUUUU vec<vec<vec>>>. maybe use sfinae for operator[], for vec<vec<point-like>> ?
    return s;
}

template <typename T, typename F>
inline std::vector<T> map(const std::vector<T>& series, const F& func) {
    auto result = series;
    for(auto& item : result)
        func(item);
    return result;
}

} // namespace detail

template <typename T, typename item_t = std::vector<std::vector<T>>, typename series_t = std::vector<item_t> >
series_t ascending(const series_t series) {
  const auto sums = detail::map(series, detail::sum);
  auto result = none(series);
  std::sort(result.begin(), result.end(), [&sums](const item_t& a, const item_t& b) { return sums[a] - sums[b]; });
  return result;
}



} // namespace d3_shape

#endif // D3__SHAPE__ORDER__ASCENDING_HPP
