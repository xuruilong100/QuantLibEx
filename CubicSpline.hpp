#ifndef CUBICSPLINE_HPP
#define CUBICSPLINE_HPP

#include <ql/types.hpp>
#include <vector>

namespace QuantLib {

class CubicSpline {
  public:
    CubicSpline(const std::vector<Real>& knots);
    ~CubicSpline();
    Real operator()(Natural i, Real x) const;

  private:
    Size n_;
    std::vector<Real> knots_ex_;
};

}    // namespace QuantLib

#endif    // CUBICSPLINE_HPP
