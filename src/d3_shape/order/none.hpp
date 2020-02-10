#ifndef D3__SHAPE__ORDER__NONE_HPP
#define D3__SHAPE__ORDER__NONE_HPP

#include <vector>

namespace d3_shape {

template <typename T>
inline std::vector<T> none(const std::vector<T>& series)
{
    const auto n = series.size(); auto o = new std::vector<T>(n);
    while (--n >= 0) o[n] = n;
    return o;
}

} // namespace d3_shape

#endif // D3__SHAPE__ORDER__NONE_HPP
