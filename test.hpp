#ifndef TEST
#define TEST

#include <ql/math/array.hpp>
#include <ql/types.hpp>

#include <vector>

void TestCubicSplineFitting();

QuantLib::Real CubicSplineSpotRate(const std::vector<QuantLib::Real>& knots,
                                   const QuantLib::Array& weights,
                                   const QuantLib::Time& t);

#endif