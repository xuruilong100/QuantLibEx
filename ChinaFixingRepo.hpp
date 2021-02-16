#ifndef CHINAFIXINGREPO_HPP
#define CHINAFIXINGREPO_HPP

#include <ql/indexes/iborindex.hpp>

namespace QuantLib {

class ChinaFixingRepo : public IborIndex {
  public:
    ChinaFixingRepo(const Period& tenor,
                    Natural fixingDays,
                    const Handle<YieldTermStructure>& h = Handle<YieldTermStructure>());

    ext::shared_ptr<IborIndex> clone(const Handle<YieldTermStructure>& forwarding) const override;
};

}    // namespace QuantLib

#endif    // CHINAFIXINGREPO_HPP
