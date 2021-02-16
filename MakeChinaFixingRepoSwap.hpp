#ifndef MAKECHINAFIXINGREPOSWAP_HPP
#define MAKECHINAFIXINGREPOSWAP_HPP

#include "ChinaFixingRepoSwap.hpp"

#include <ql/termstructures/yieldtermstructure.hpp>
#include <ql/time/dategenerationrule.hpp>

namespace QuantLib {

class ChinaFixingRepo;

class MakeChinaFixingRepoSwap {
  public:
    MakeChinaFixingRepoSwap(const Period& swapTenor,
                            const ext::shared_ptr<ChinaFixingRepo>& chinaFixingRepo,
                            Rate fixedRate = Null<Rate>(),
                            const Period& fwdStart = 0 * Days);

    operator ChinaFixingRepoSwap() const;
    operator ext::shared_ptr<ChinaFixingRepoSwap>() const;

    MakeChinaFixingRepoSwap& receiveFixed(bool flag = true);
    MakeChinaFixingRepoSwap& withType(ChinaFixingRepoSwap::Type type);
    MakeChinaFixingRepoSwap& withNominal(Real n);
    MakeChinaFixingRepoSwap& withSettlementDays(Natural settlementDays);
    MakeChinaFixingRepoSwap& withEffectiveDate(const Date&);
    MakeChinaFixingRepoSwap& withTerminationDate(const Date&);
    MakeChinaFixingRepoSwap& withRule(DateGeneration::Rule r);
    MakeChinaFixingRepoSwap& withPaymentFrequency(Frequency f);
    MakeChinaFixingRepoSwap& withPaymentAdjustment(BusinessDayConvention convention);
    MakeChinaFixingRepoSwap& withPaymentLag(Natural lag);
    MakeChinaFixingRepoSwap& withPaymentCalendar(const Calendar& cal);
    MakeChinaFixingRepoSwap& withEndOfMonth(bool flag = true);
    MakeChinaFixingRepoSwap& withFixedLegDayCount(const DayCounter& dc);
    MakeChinaFixingRepoSwap& withFloatingLegGearing(Real gearing);
    MakeChinaFixingRepoSwap& withFloatingLegSpread(Spread sp);
    MakeChinaFixingRepoSwap& withDiscountingTermStructure(
        const Handle<YieldTermStructure>& discountingTermStructure);
    MakeChinaFixingRepoSwap& withPricingEngine(
        const ext::shared_ptr<PricingEngine>& engine);

  private:
    Period swapTenor_;
    ext::shared_ptr<ChinaFixingRepo> chinaFixingRepo_;
    Rate fixedRate_;
    Period forwardStart_;
    Natural settlementDays_;
    Date effectiveDate_, terminationDate_;
    Calendar calendar_;
    Frequency paymentFrequency_;
    Calendar paymentCalendar_;
    BusinessDayConvention paymentConvention_;
    Natural paymentLag_;
    DateGeneration::Rule rule_;
    bool endOfMonth_, isDefaultEOM_;
    ChinaFixingRepoSwap::Type type_;
    Real nominal_;
    Real gearing_;
    Spread spread_;
    DayCounter fixedDayCount_;
    ext::shared_ptr<PricingEngine> engine_;
};

}    // namespace QuantLib

#endif    // MAKECHINAFIXINGREPOSWAP_HPP
