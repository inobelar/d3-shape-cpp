#ifndef D3__SHAPE__IDENTITY_HPP
#define D3__SHAPE__IDENTITY_HPP

namespace d3_shape {

template <typename T>
inline T& identity(T& d) {
    return d;
}

} // namespace d3_shape

#endif // D3__SHAPE__IDENTITY_HPP
