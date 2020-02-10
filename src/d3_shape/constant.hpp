#ifndef D3__SHAPE__CONSTANT_HPP
#define D3__SHAPE__CONSTANT_HPP

#include <functional> // for std::function<>

namespace d3_shape {

template <typename T>
inline std::function<T()> constant(T x) {
    return [x] () {
        return x;
    };
}

} // namespace d3_shape

#endif // D3__SHAPE__CONSTANT_HPP
