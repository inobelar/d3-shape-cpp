#ifndef D3__SHAPE__POINT_HPP
#define D3__SHAPE__POINT_HPP

namespace d3_shape {

template <typename PointT, typename T>
inline T& x(PointT& p) {
    return p[0];
}

template <typename PointT, typename T>
inline T& y(PointT& p) {
    return p[1];
}

} // namespace d3_shape

#endif // D3__SHAPE__POINT_HPP
