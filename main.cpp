#include "example.hpp"
#include "test.hpp"
#include <iostream>
#include <quantlib.hpp>
#include <vector>

int main() {
    using namespace std;
    using namespace QuantLib;

    //TestCubicSplineFitting();
    //TestParametricTermStructure();
    //TestNelsonSiegelClassTermStructure();
    //CampareCubicAndQuadratic();
    //TestActual365_25();
    //ShiborIRScurve();
    //ChinaFixingRepoSwapCurve();
    //TestChinaFixingRepoCoupon();
    TestChinaFixingRepoSwap();

    return EXIT_SUCCESS;
}