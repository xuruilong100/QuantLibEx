#ifndef TEST
#define TEST

#include <ql/math/array.hpp>
#include <ql/types.hpp>

#include <vector>

void TestCubicSplineFitting();
void TestNelsonSiegelClassTermStructure();
void CompareCubicAndQuadratic();
void TestActual365_25();

QuantLib::Real CubicSplineSpotRate(const std::vector<QuantLib::Real>& knots,
                                   const QuantLib::Array& weights,
                                   const QuantLib::Time& t);

void TestChinaFixingRepoCoupon();
void TestChinaFixingRepoSwap();

#endif
