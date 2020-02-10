#include "d3_shape/curve/natural.hpp"

#include <limits>

#include <array>

// See https://www.particleincell.com/2012/bezier-splines/ for derivation.
template <typename T>
std::array<std::vector<T>, 2> controlPoints(const std::vector<T>& x) {
  std::size_t i;
  const std::size_t n = x.size() - 1;
  double m;
  auto a = std::vector<T>(n);
  auto b = std::vector<T>(n);
  auto r = std::vector<T>(n);

  a[0] = 0, b[0] = 2, r[0] = x[0] + 2 * x[1];
  for (i = 1; i < n - 1; ++i) a[i] = 1, b[i] = 4, r[i] = 4 * x[i] + 2 * x[i + 1];
  a[n - 1] = 2, b[n - 1] = 7, r[n - 1] = 8 * x[n - 1] + x[n];
  for (i = 1; i < n; ++i) m = a[i] / b[i - 1], b[i] -= m, r[i] -= m * r[i - 1];
  a[n - 1] = r[n - 1] / b[n - 1];
  for (i = n - 2; i >= 0; --i) a[i] = (r[i] - a[i + 1]) / b[i];
  b[n - 1] = (x[n] + a[n - 1]) / 2;
  for (i = 0; i < n - 1; ++i) b[i] = 2 * x[i + 1] - a[i + 1];
  return {a, b};
}

constexpr auto NULL_NUM = std::numeric_limits<d3_shape::Natural::number_t>::quiet_NaN();

d3_shape::Natural::Natural(d3_path::PathInterface *context)
    : _context(context)

    , _line(NULL_NUM)
{

}

void d3_shape::Natural::areaStart() {
    this->_line = 0;
}

void d3_shape::Natural::areaEnd() {
    this->_line = NULL_NUM;
}

void d3_shape::Natural::lineStart() {
    this->_x.clear();
    this->_y.clear();
}

void d3_shape::Natural::lineEnd() {
    const auto& x = this->_x;
    const auto& y = this->_y;
    const auto  n = x.size();

    if (n) {
        this->_line ? this->_context->lineTo(x[0], y[0]) : this->_context->moveTo(x[0], y[0]);
        if (n == 2) {
            this->_context->lineTo(x[1], y[1]);
        } else {
            const auto
                    px = controlPoints(x),
                    py = controlPoints(y);
            for (std::size_t i0 = 0, i1 = 1; i1 < n; ++i0, ++i1) {
                this->_context->bezierCurveTo(px[0][i0], py[0][i0], px[1][i0], py[1][i0], x[i1], y[i1]);
            }
        }
    }

    if (this->_line || (this->_line != 0 && n == 1)) this->_context->closePath();
    this->_line = 1 - this->_line;
    this->_x.clear();  this->_y.clear();
}

void d3_shape::Natural::point(CurveInterface::number_t x, CurveInterface::number_t y) {
    this->_x.push_back(x);
    this->_y.push_back(y);
}

// -----------------------------------------------------------------------------

d3_shape::Natural d3_shape::natural(d3_path::PathInterface *context) {
    return Natural(context);
}
