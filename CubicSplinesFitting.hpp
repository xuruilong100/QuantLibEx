#ifndef CubicSplinesFitting_HPP
#define CubicSplinesFitting_HPP

#include "CubicSpline.hpp"
#include <ql/auto_ptr.hpp>
#include <ql/termstructures/yield/fittedbonddiscountcurve.hpp>

namespace QuantLib {

class CubicSplinesFitting
    : public FittedBondDiscountCurve::FittingMethod {
  public:
    CubicSplinesFitting(const std::vector<Time>& knotVector,
                        const Array& weights = Array(),
                        ext::shared_ptr<OptimizationMethod>
                            optimizationMethod = ext::shared_ptr<OptimizationMethod>(),
                        const Array& l2 = Array());
    CubicSplinesFitting(const std::vector<Time>& knotVector,
                        const Array& weights,
                        const Array& l2);
    //! cubic spline basis functions
    Real basisFunction(Integer i, Time t) const;
    static std::vector<Time> autoKnots(const std::vector<Time>& maturities);
#if defined(QL_USE_STD_UNIQUE_PTR)
    std::unique_ptr<FittedBondDiscountCurve::FittingMethod> clone() const;
#else
    std::auto_ptr<FittedBondDiscountCurve::FittingMethod> clone() const;
#endif
  private:
    Size size() const;
    DiscountFactor discountFunction(const Array& x, Time t) const;
    CubicSpline splines_;
    Size size_;
    //! N_th basis function coefficient to solve for when d(0)=1
    Natural N_;
};

}    // namespace QuantLib

#endif    // CubicSplinesFitting_HPP
