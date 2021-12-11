#include <qlex/quantlibex.hpp>
#include <test/utility.hpp>

QuantLib::Real CubicSplineSpotRate(const std::vector<QuantLib::Real>& knots,
                                   const QuantLib::Array& weights,
                                   const QuantLib::Time& t) {
    using namespace std;
    using namespace QuantLib;

    CubicSpline spline(knots);
    Size s = weights.size();
    Real d = 1.0, r;

    for (Size i = 0; i < s; ++i) {
        d += weights[i] * spline(i + 1, t);
    }

    r = -std::log(d) / t;

    return r;
}
