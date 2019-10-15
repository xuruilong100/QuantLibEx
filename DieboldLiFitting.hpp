#ifndef DIEBOLDLIFITTING_HPP
#define DIEBOLDLIFITTING_HPP

#include <ql/shared_ptr.hpp>
#include <ql/termstructures/yield/fittedbonddiscountcurve.hpp>

namespace QuantLib {

class DieboldLiFitting : public FittedBondDiscountCurve::FittingMethod {
  public:
    DieboldLiFitting(Real kappa,
                     const Array& weights = Array(),
                     ext::shared_ptr<OptimizationMethod> optimizationMethod = ext::shared_ptr<OptimizationMethod>(),
                     const Array& l2 = Array());
    DieboldLiFitting(Real kappa,
                     const Array& weights,
                     const Array& l2);
#if defined(QL_USE_STD_UNIQUE_PTR)
    std::unique_ptr<FittedBondDiscountCurve::FittingMethod> clone() const;
#else
    std::auto_ptr<FittedBondDiscountCurve::FittingMethod> clone() const;
#endif

    Real kappa() const { return kappa; }

  private:
    Size size() const;
    DiscountFactor discountFunction(const Array& x, Time t) const;
    Real kappa_;
};

}    // namespace QuantLib

#endif    // DIEBOLDLIFITTING_HPP
