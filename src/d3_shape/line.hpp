#ifndef D3__SHAPE__LINE_HPP
#define D3__SHAPE__LINE_HPP

#include "d3_path/path.hpp"

#include "d3_shape/constant.hpp"
#include "d3_shape/curve/linear.hpp"
#include "d3_shape/point.hpp"

/*

  TODO: must be implemented

namespace d3_shape {

template <typename Datum>
class Line
{
public:
    using item_t = typename Datum::value_type;

    using component_func_t = std::function< double (item_t& d, std::size_t index, Datum& datum) >;

    using defined_func_t = std::function< bool (item_t& d, std::size_t index, Datum& datum) >;

    using curve_func_t = std::function< d3_shape::CurveInterface* ( d3_path::PathInterface* ) >;

private:
    component_func_t _x = d3_shape::x; // NOTE: in js code it's `pointX` alias
    component_func_t _y = d3_shape::y; // NOTE: in js code it's `pointY` alias
    defined_func_t _defined = constant(true);
    d3_path::PathInterface* _context = nullptr;
    auto _curve = d3_shape::linear;
    CurveInterface* _output = nullptr;

public:

    Line()
    {

    }

    std::string operator () (const Datum& data) { // TODO: result type must be optional<std::string>
        std::size_t       i;
        const std::size_t n = data.size();
        item_t            d;
        bool              defined0 = false;
        std::string       buffer;

        if (_context == nullptr) _output = _curve(buffer = d3_path::path());

            for (i = 0; i <= n; ++i) {
              if (!(i < n && _defined(d = data[i], i, data)) == defined0) {
                if (defined0 = !defined0) _output->lineStart();
                else _output->lineEnd();
              }
              if (defined0) _output->point( _x(d, i, data), _y(d, i, data));
            }

            if (buffer) return _output = null, buffer + "" || null;
    }

    component_func_t x() const {
        return _x;
    }
    Line& x(double x_) {
        _x = constant(x_);
        return *this;
    }
    Line& x(const component_func_t& func) {
        _x = func;
        return *this;
    }


    component_func_t y() const {
        return _y;
    }
    Line& y(double y_) {
        _y = constant(y_);
        return *this;
    }
    Line& y(const component_func_t& func) {
        _y = func;
        return *this;
    }


    defined_func_t defined() const {
        return _defined;
    }
    Line& defined(bool defined_) {
        _defined = constant(defined_);
        return *this;
    }
    Line& defined(const defined_func_t& func) {
        _defined = func;
        return *this;
    }



//      line.curve = function(_) {
//        return arguments.length ? (curve = _, context != null && (output = curve(context)), line) : curve;
//      };

    d3_path::PathInterface* context() const {
        return _context;
    }
    Line& context(d3_path::PathInterface* context_)
    {
        if(context_ == nullptr) {
            _context = _output = nullptr;
        } else {
            _output = _curve(_context = context_);
        }

        return *this;
    }
};

} // namespace d3_shape

*/

#endif // D3__SHAPE__LINE_HPP
