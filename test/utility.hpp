#ifndef Utility_HPP
#define Utility_HPP

#include <ql/math/array.hpp>
#include <ql/types.hpp>
#include <vector>

QuantLib::Real CubicSplineSpotRate(const std::vector<QuantLib::Real>& knots,
                                   const QuantLib::Array& weights,
                                   const QuantLib::Time& t);

#endif
