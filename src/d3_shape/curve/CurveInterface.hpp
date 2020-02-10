#ifndef D3__SHAPE__CURVE__CURVE_INTERFACE_HPP
#define D3__SHAPE__CURVE__CURVE_INTERFACE_HPP

class CurveInterface {
public:

    using number_t = double;

    virtual void areaStart() = 0;

    virtual void areaEnd() = 0;

    virtual void lineStart() = 0;

    virtual void lineEnd() = 0;

    virtual void point(number_t x, number_t y) = 0;

};

#endif // D3__SHAPE__CURVE__CURVE_INTERFACE_HPP
