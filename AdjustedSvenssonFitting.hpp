#ifndef ADJUSTEDSVENSSONFITTING_HPP
#define ADJUSTEDSVENSSONFITTING_HPP

#include <ql/shared_ptr.hpp>
#include <ql/termstructures/yield/fittedbonddiscountcurve.hpp>

namespace QuantLib {

class AdjustedSvenssonFitting : public FittedBondDiscountCurve::FittingMethod {
  public:
    AdjustedSvenssonFitting(const Array& weights = Array(),
                            ext::shared_ptr<OptimizationMethod> optimizationMethod = ext::shared_ptr<OptimizationMethod>(),
                            const Array& l2 = Array());
    AdjustedSvenssonFitting(const Array& weights, const Array& l2);
#if defined(QL_USE_STD_UNIQUE_PTR)
    std::unique_ptr<FittedBondDiscountCurve::FittingMethod> clone() const;
#else
    std::auto_ptr<FittedBondDiscountCurve::FittingMethod> clone() const;
#endif
  private:
    Size size() const;
    DiscountFactor discountFunction(const Array& x, Time t) const;
};

}    // namespace QuantLib

#endif    // ADJUSTEDSVENSSONFITTING_HPP
