#ifndef BJORKCHRISTENSENFITTING_HPP
#define BJORKCHRISTENSENFITTING_HPP

namespace QuantLib {

class BjorkChristensenFitting : public FittedBondDiscountCurve::FittingMethod {
  public:
    BjorkChristensenFitting(const Array& weights = Array(),
                            ext::shared_ptr<OptimizationMethod> optimizationMethod = ext::shared_ptr<OptimizationMethod>(),
                            const Array& l2 = Array());
    BjorkChristensenFitting(const Array& weights, const Array& l2);
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

#endif    // BJORKCHRISTENSENFITTING_HPP
