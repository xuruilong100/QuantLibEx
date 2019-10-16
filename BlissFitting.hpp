#ifndef BLISSFITTING_HPP
#define BLISSFITTING_HPP

namespace QuantLib {

class BlissFitting : public FittedBondDiscountCurve::FittingMethod {
  public:
    BlissFitting(const Array& weights = Array(),
                 ext::shared_ptr<OptimizationMethod> optimizationMethod = ext::shared_ptr<OptimizationMethod>(),
                 const Array& l2 = Array());
    BlissFitting(const Array& weights, const Array& l2);
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

#endif    // BLISSFITTING_HPP
