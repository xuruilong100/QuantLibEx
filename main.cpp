#include <ql/quantlib.hpp>
#include <qlex/quantlibex.hpp>
#include <test/example.hpp>
#include <test/test.hpp>

int main() {
    using namespace std;
    using namespace QuantLib;

    // TEST

    //TestCubicSplineFitting();
    //TestNelsonSiegelClassTermStructure();
    //TestActual365_25();
    //TestChinaFixingRepoCoupon();
    //TestChinaFixingRepoSwap();

    // EXAMPLE

    //CompareCubicAndQuadratic();
    //ShiborIRScurve();
    ChinaFixingRepoSwapCurve();

    return EXIT_SUCCESS;
}