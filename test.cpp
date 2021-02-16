#include "Actual365_25.hpp"
#include "AdjustedSvenssonFitting.hpp"
#include "BjorkChristensenFitting.hpp"
#include "BlissFitting.hpp"
#include "ChinaFixingRepo.hpp"
#include "ChinaFixingRepoCoupon.hpp"
#include "ChinaFixingRepoSwap.hpp"
#include "CubicSpline.hpp"
#include "CubicSplinesFitting.hpp"
#include "DieboldLiFitting.hpp"
#include "QuadraticSpline.hpp"
#include "QuadraticSplinesFitting.hpp"
#include "test.hpp"
#include <cmath>
#include <iostream>
#include <ql/quantlib.hpp>
#include <vector>

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

void TestCubicSplineFitting() {

    using namespace std;
    using namespace QuantLib;

    Size bondNum = 50;

    vector<Real> cleanPrice = {
        100.002, 99.92, 99.805, 99.75, 100.305, 99.76, 99.75, 99.975, 100.0416, 100.0574,
        99.5049, 101.0971, 101.137, 100.7199, 99.8883, 100.908, 103.3553, 99.5034, 103.913, 97.4229,
        104.5636, 99.7527, 104.3708, 99.6051, 104.8603, 101.3415, 105.29, 102.4969, 103.7602, 100.2803,
        102.6046, 102.5291, 99.4748, 95.9702, 97.1815, 114.2849, 100.2847, 112.23, 98.397, 102.0235,
        99.8483, 121.2711, 125.9157, 114.5791, 103.2202, 123.4668, 113.4694, 103.1873, 91.5603, 95.4441};

    vector<Handle<Quote>> priceHandle(bondNum);

    for (Size i = 0; i < bondNum; ++i) {
        ext::shared_ptr<Quote> q(
            new SimpleQuote(cleanPrice[i]));
        Handle<Quote> hq(q);
        priceHandle[i] = hq;
    }

    vector<Year> issueYear = {
        2002, 2006, 2003, 2006, 1998, 2006, 2003, 2006, 1999, 2007,
        2004, 2007, 1999, 2007, 2004, 2007, 1999, 2005, 2000, 2005,
        2000, 2006, 2001, 2006, 2001, 2007, 2002, 2007, 2002, 2003,
        2003, 2004, 2004, 2005, 2005, 1986, 2006, 1986, 2006, 2007,
        2007, 1993, 1997, 1998, 1998, 2000, 2000, 2003, 2004, 2006};

    vector<Month> issueMonth = {
        Aug, Mar, Apr, May, Jul, Aug, Sep, Nov, Jan, Feb,
        Feb, May, Jul, Aug, Aug, Sep, Oct, Feb, May, Aug,
        Sep, Feb, May, Aug, Dec, Feb, Jun, Aug, Dec, Jun,
        Oct, Apr, Oct, Apr, Oct, Jun, Apr, Sep, Oct, Apr,
        Sep, Dec, Jul, Jan, Oct, Jan, Oct, Jan, Dec, Dec};

    vector<Day> issueDay = {
        14, 8, 11, 30, 4, 30, 25, 30, 4, 28, 2, 30, 4, 24, 25, 21, 22,
        24, 5, 26, 29, 26, 23, 30, 28, 28, 26, 24, 31, 24, 21, 25, 27, 28,
        30, 20, 26, 20, 31, 27, 21, 29, 3, 4, 7, 4, 27, 22, 24, 28};

    vector<Year> maturityYear = {
        2008, 2008, 2008, 2008, 2008, 2008, 2008, 2008, 2009, 2009,
        2009, 2009, 2009, 2009, 2009, 2009, 2010, 2010, 2010, 2010,
        2011, 2011, 2011, 2011, 2012, 2012, 2012, 2012, 2013, 2013,
        2014, 2014, 2015, 2015, 2016, 2016, 2016, 2016, 2017, 2017,
        2018, 2024, 2027, 2028, 2028, 2030, 2031, 2034, 2037, 2039};

    vector<Month> maturityMonth = {
        Feb, Mar, Apr, Jun, Jul, Sep, Oct, Dec, Jan, Mar,
        Apr, Jun, Jul, Sep, Oct, Dec, Jan, Apr, Jul, Oct,
        Jan, Apr, Jul, Oct, Jan, Apr, Jul, Oct, Jan, Jul,
        Jan, Jul, Jan, Jul, Jan, Jun, Jul, Sep, Jan, Jul,
        Jan, Jan, Jul, Jan, Jul, Jan, Jan, Jul, Jan, Jul};

    vector<Day> maturityDay = {
        15, 14, 11, 13, 4, 12, 10, 12, 4, 13, 17, 12, 4, 11, 9, 11,
        4, 9, 4, 8, 4, 8, 4, 14, 4, 13, 4, 12, 4, 4, 4, 4, 4, 4, 4,
        20, 4, 20, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

    vector<Date> issueDate(bondNum), maturityDate(bondNum);

    for (Size i = 0; i < bondNum; ++i) {
        Date idate(issueDay[i], issueMonth[i], issueYear[i]);
        Date mdate(maturityDay[i], maturityMonth[i], maturityYear[i]);
        issueDate[i] = idate;
        maturityDate[i] = mdate;
    }

    vector<Real> couponRate = {
        0.0425, 0.03, 0.03, 0.0325, 0.0475, 0.035, 0.035, 0.0375, 0.0375, 0.0375,
        0.0325, 0.045, 0.045, 0.04, 0.035, 0.04, 0.05375, 0.0325, 0.0525, 0.025,
        0.0525, 0.035, 0.05, 0.035, 0.05, 0.04, 0.05, 0.0425, 0.045, 0.0375, 0.0425,
        0.0425, 0.0375, 0.0325, 0.035, 0.06, 0.04, 0.05625, 0.0375, 0.0425, 0.04,
        0.0625, 0.065, 0.05625, 0.0475, 0.0625, 0.055, 0.0475, 0.04, 0.0425};

    Frequency frequency = Annual;
    Actual365Fixed dayCounter(Actual365Fixed::Standard);
    BusinessDayConvention paymentConv = Unadjusted;
    BusinessDayConvention terminationDateConv = Unadjusted;
    BusinessDayConvention convention = Unadjusted;
    Real redemption = 100.0;
    Real faceAmount = 100.0;
    Germany calendar(Germany::Eurex);

    Date today = calendar.adjust(Date(30, Jan, 2008));
    Settings::instance().evaluationDate() = today;

    Natural bondSettlementDays = 0;
    Date bondSettlementDate = calendar.advance(
        today,
        Period(bondSettlementDays, Days));

    vector<ext::shared_ptr<BondHelper>> instruments(bondNum);
    vector<Time> maturity(bondNum);

    for (Size i = 0; i < bondNum; ++i) {

        vector<Real> bondCoupon = {couponRate[i]};

        Schedule schedule(
            issueDate[i],
            maturityDate[i],
            Period(frequency),
            calendar,
            convention,
            terminationDateConv,
            DateGeneration::Backward,
            false);

        ext::shared_ptr<FixedRateBondHelper> helper(
            new FixedRateBondHelper(
                priceHandle[i],
                bondSettlementDays,
                faceAmount,
                schedule,
                bondCoupon,
                dayCounter,
                paymentConv,
                redemption));

        maturity[i] = dayCounter.yearFraction(
            bondSettlementDate, helper->maturityDate());

        instruments[i] = helper;
    }

    Real tolerance = 1.0e-6;
    Natural max = 5000;

    ext::shared_ptr<OptimizationMethod> optMethod(
        new LevenbergMarquardt());

    vector<Real> knots = CubicSplinesFitting::autoKnots(maturity);
    vector<Real> termstrcKnotes = {
        0.000000, 1.006027, 2.380274, 5.033425, 9.234521, 31.446575};

    cout << "QuantLib knots:\t";
    for (auto v : knots) {
        cout << setprecision(6) << fixed << v << ", ";
    }
    cout << endl;

    cout << "termstrc knots:\t";
    for (auto v : termstrcKnotes) {
        cout << setprecision(6) << fixed << v << ", ";
    }
    cout << endl;

    cout << endl;

    CubicSplinesFitting csf(
        knots, Array(), optMethod);

    FittedBondDiscountCurve tsCubicSplines(
        bondSettlementDate,
        instruments, dayCounter,
        csf, tolerance, max);

    Array weights = tsCubicSplines.fitResults().solution();
    Array termstrcWeights(7);
    termstrcWeights[0] = 1.9320e-02, termstrcWeights[1] = -8.4936e-05,
    termstrcWeights[2] = -3.2009e-04, termstrcWeights[3] = -3.7101e-04,
    termstrcWeights[4] = 7.2921e-04, termstrcWeights[5] = 2.0159e-03,
    termstrcWeights[6] = -4.1632e-02;

    cout << "QuantLib weights: \t" << weights << endl;
    cout << "termstrc weights: \t" << termstrcWeights << endl;

    cout << endl;

    cout << "QuantLib final cost value:\t"
         << tsCubicSplines.fitResults().minimumCostValue() << endl;

    cout << endl;

    Real spotRate, termstrcSpot;

    for (Size i = 0; i < bondNum; ++i) {

        Time t = dayCounter.yearFraction(
            bondSettlementDate, maturityDate[i]);

        spotRate =
            tsCubicSplines.zeroRate(t, Compounding::Continuous, frequency).rate() * 100.0;
        termstrcSpot =
            CubicSplineSpotRate(termstrcKnotes, termstrcWeights, t) * 100.0;

        cout << setprecision(3) << fixed
             << t << ",\t"
             << spotRate << ",\t"
             << termstrcSpot << ",\t"
             << spotRate - termstrcSpot << endl;
    }
}

void TestNelsonSiegelClassTermStructure() {

    using namespace std;
    using namespace QuantLib;

    Size bondNum = 16;

    vector<Real> cleanPrice = {
        100.4941, 103.5572, 104.4135, 105.0056, 99.8335, 101.25, 102.3832, 97.0053,
        99.5164, 101.2435, 104.0539, 101.15, 96.1395, 91.1123, 122.0027, 92.4369};

    vector<Handle<Quote>> priceHandle(bondNum);

    for (Size i = 0; i < bondNum; ++i) {
        ext::shared_ptr<Quote> q(
            new SimpleQuote(cleanPrice[i]));
        Handle<Quote> hq(q);
        priceHandle[i] = hq;
    }

    vector<Year> issueYear = {
        1999, 1999, 2001, 2002, 2003, 1999, 2004, 2005,
        2006, 2007, 2003, 2008, 2005, 2006, 1997, 2007};

    vector<Month> issueMonth = {
        Feb, Oct, Jan, Jan, May, Jan, Jan, Apr,
        Apr, Sep, Jan, Jan, Jan, Jan, Jul, Jan};

    vector<Day> issueDay = {
        22, 22, 4, 9, 20, 15, 15, 26, 21, 17, 15, 8, 14, 11, 10, 12};

    vector<Year> maturityYear = {
        2009, 2010, 2011, 2012, 2013, 2014, 2014, 2015,
        2016, 2017, 2018, 2019, 2020, 2021, 2027, 2037};

    vector<Month> maturityMonth = {
        Jul, Jan, Jan, Jul, Oct, Jan, Jul, Jul,
        Sep, Sep, Jan, Mar, Jul, Sep, Jul, Mar};

    vector<Day> maturityDay = {
        15, 15, 4, 15, 20, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15};

    vector<Date> issueDate(bondNum), maturityDate(bondNum);

    for (Size i = 0; i < bondNum; ++i) {
        Date idate(issueDay[i], issueMonth[i], issueYear[i]);
        Date mdate(maturityDay[i], maturityMonth[i], maturityYear[i]);
        issueDate[i] = idate;
        maturityDate[i] = mdate;
    }

    vector<Real> couponRate = {
        0.04, 0.055, 0.0525, 0.05, 0.038, 0.04125, 0.043, 0.035,
        0.04, 0.043, 0.0465, 0.0435, 0.039, 0.035, 0.0625, 0.0415};

    Frequency frequency = Annual;
    Actual365Fixed dayCounter(Actual365Fixed::Standard);
    BusinessDayConvention paymentConv = Unadjusted;
    BusinessDayConvention terminationDateConv = Unadjusted;
    BusinessDayConvention convention = Unadjusted;
    Real redemption = 100.0;
    Real faceAmount = 100.0;
    Australia calendar;

    Date today = calendar.adjust(Date(30, Jan, 2008));
    Settings::instance().evaluationDate() = today;

    Natural bondSettlementDays = 0;
    Date bondSettlementDate = calendar.advance(
        today,
        Period(bondSettlementDays, Days));

    vector<ext::shared_ptr<BondHelper>> instruments(bondNum);
    vector<Time> maturity(bondNum);

    for (Size i = 0; i < bondNum; ++i) {

        vector<Real> bondCoupon = {couponRate[i]};

        Schedule schedule(
            issueDate[i],
            maturityDate[i],
            Period(frequency),
            calendar,
            convention,
            terminationDateConv,
            DateGeneration::Backward,
            false);

        ext::shared_ptr<FixedRateBondHelper> helper(
            new FixedRateBondHelper(
                priceHandle[i],
                bondSettlementDays,
                faceAmount,
                schedule,
                bondCoupon,
                dayCounter,
                paymentConv,
                redemption));

        maturity[i] = dayCounter.yearFraction(
            bondSettlementDate, helper->maturityDate());

        instruments[i] = helper;
    }

    Real accuracy = 1.0e-6;
    Natural maxEvaluations = 5000;
    Array weights;

    Array l2Ns(4, 0.5);
    Array guessNs(4);
    guessNs[0] = 4 / 100.0, guessNs[1] = 0.0, guessNs[2] = 0.0, guessNs[3] = 0.5;

    Array l2Sv(6, 0.5);
    Array guessSv(6);
    guessSv[0] = 4 / 100.0, guessSv[1] = 0.0, guessSv[2] = 0.0, guessSv[3] = 0.0, guessSv[4] = 0.2, guessSv[5] = 0.15;

    Array l2Asv(6, 0.5);
    Array guessAsv(6);
    guessAsv[0] = 4 / 100.0, guessAsv[1] = 0.0, guessAsv[2] = 0.0, guessAsv[3] = 0.0, guessAsv[4] = 0.2, guessAsv[5] = 0.3;

    Array l2Bc(5, 0.5);
    Array guessBc(5);
    guessBc[0] = 4 / 100.0, guessBc[1] = 0.0, guessBc[2] = 0.0, guessBc[3] = 0.0, guessBc[4] = 0.2;

    Array l2Bl(5, 0.5);
    Array guessBl(5);
    guessBl[0] = 4 / 100.0, guessBl[1] = 0.0, guessBl[2] = 0.0, guessBl[3] = 0.5, guessBl[4] = 0.5;

    ext::shared_ptr<OptimizationMethod> optMethod(
        new LevenbergMarquardt());

    NelsonSiegelFitting nsf(
        weights, optMethod, l2Ns);

    SvenssonFitting svf(
        weights, optMethod, l2Sv);

    AdjustedSvenssonFitting asvf(
        weights, optMethod, l2Asv);

    DieboldLiFitting dlf(
        0.5, weights, optMethod);

    BjorkChristensenFitting bcf(
        weights, optMethod, l2Bc);

    BlissFitting blf(
        weights, optMethod, l2Bl);

    FittedBondDiscountCurve tsNelsonSiegel(
        bondSettlementDate,
        instruments,
        dayCounter,
        nsf,
        accuracy,
        maxEvaluations,
        guessNs);

    FittedBondDiscountCurve tsSvensson(
        bondSettlementDate,
        instruments,
        dayCounter,
        svf,
        accuracy,
        maxEvaluations,
        guessSv);

    FittedBondDiscountCurve tsAdjustedSvensson(
        bondSettlementDate,
        instruments,
        dayCounter,
        asvf,
        accuracy,
        maxEvaluations,
        guessAsv);

    FittedBondDiscountCurve tsDieboldLi(
        bondSettlementDate,
        instruments,
        dayCounter,
        dlf,
        accuracy,
        maxEvaluations);

    FittedBondDiscountCurve tsBjorkChristensen(
        bondSettlementDate,
        instruments,
        dayCounter,
        bcf,
        accuracy,
        maxEvaluations,
        guessBc);

    FittedBondDiscountCurve tsBliss(
        bondSettlementDate,
        instruments,
        dayCounter,
        blf,
        accuracy,
        maxEvaluations,
        guessBl);

    cout << "NelsonSiegel Results: \t\t" << tsNelsonSiegel.fitResults().solution() << endl;
    cout << "Svensson Results: \t\t" << tsSvensson.fitResults().solution() << endl;
    cout << "AdjustedSvensson Results: \t" << tsAdjustedSvensson.fitResults().solution() << endl;
    cout << "DieboldLi Results: \t\t" << tsDieboldLi.fitResults().solution() << endl;
    cout << "BjorkChristensen Results: \t" << tsBjorkChristensen.fitResults().solution() << endl;
    cout << "Bliss Results: \t\t\t" << tsBliss.fitResults().solution() << endl;

    cout << endl;
    /*
    cout << "QuantLib final cost value:\t" << tsNelsonSiegel.fitResults().minimumCostValue() << endl;
    cout << "QuantLib final cost value:\t" << tsSvensson.fitResults().minimumCostValue() << endl;
    cout << "QuantLib final cost value:\t" << tsAdjustedSvensson.fitResults().minimumCostValue() << endl;
    cout << "QuantLib final cost value:\t" << tsDieboldLi.fitResults().minimumCostValue() << endl;
    cout << "QuantLib final cost value:\t" << tsBjorkChristensen.fitResults().minimumCostValue() << endl;
    cout << "QuantLib final cost value:\t" << tsBliss.fitResults().minimumCostValue() << endl;

    cout << endl;
    */
    Real NSrate, SVrate, ASVrate, DLrate, BCrate, Brate;

    for (Size i = 0; i < bondNum; ++i) {

        Time t = dayCounter.yearFraction(
            bondSettlementDate, maturityDate[i]);

        NSrate = tsNelsonSiegel.zeroRate(t, Compounding::Continuous, frequency).rate() * 100.0;
        SVrate = tsSvensson.zeroRate(t, Compounding::Continuous, frequency).rate() * 100.0;
        ASVrate = tsAdjustedSvensson.zeroRate(t, Compounding::Continuous, frequency).rate() * 100.0;
        DLrate = tsDieboldLi.zeroRate(t, Compounding::Continuous, frequency).rate() * 100.0;
        BCrate = tsBjorkChristensen.zeroRate(t, Compounding::Continuous, frequency).rate() * 100.0;
        Brate = tsBliss.zeroRate(t, Compounding::Continuous, frequency).rate() * 100.0;

        cout << setprecision(3) << fixed
             << t << ",\t"
             << NSrate << ",\t"
             << SVrate << ",\t"
             << ASVrate << ",\t"
             << DLrate << ",\t"
             << BCrate << ",\t"
             << Brate << endl;
    }
}

void CompareCubicAndQuadratic() {

    using namespace std;
    using namespace QuantLib;

    Size bondNum = 50;

    vector<Real> cleanPrice = {
        100.002, 99.92, 99.805, 99.75, 100.305, 99.76, 99.75, 99.975, 100.0416, 100.0574,
        99.5049, 101.0971, 101.137, 100.7199, 99.8883, 100.908, 103.3553, 99.5034, 103.913, 97.4229,
        104.5636, 99.7527, 104.3708, 99.6051, 104.8603, 101.3415, 105.29, 102.4969, 103.7602, 100.2803,
        102.6046, 102.5291, 99.4748, 95.9702, 97.1815, 114.2849, 100.2847, 112.23, 98.397, 102.0235,
        99.8483, 121.2711, 125.9157, 114.5791, 103.2202, 123.4668, 113.4694, 103.1873, 91.5603, 95.4441};

    vector<Handle<Quote>> priceHandle(bondNum);

    for (Size i = 0; i < bondNum; ++i) {
        ext::shared_ptr<Quote> q(
            new SimpleQuote(cleanPrice[i]));
        Handle<Quote> hq(q);
        priceHandle[i] = hq;
    }

    vector<Year> issueYear = {
        2002, 2006, 2003, 2006, 1998, 2006, 2003, 2006, 1999, 2007,
        2004, 2007, 1999, 2007, 2004, 2007, 1999, 2005, 2000, 2005,
        2000, 2006, 2001, 2006, 2001, 2007, 2002, 2007, 2002, 2003,
        2003, 2004, 2004, 2005, 2005, 1986, 2006, 1986, 2006, 2007,
        2007, 1993, 1997, 1998, 1998, 2000, 2000, 2003, 2004, 2006};

    vector<Month> issueMonth = {
        Aug, Mar, Apr, May, Jul, Aug, Sep, Nov, Jan, Feb,
        Feb, May, Jul, Aug, Aug, Sep, Oct, Feb, May, Aug,
        Sep, Feb, May, Aug, Dec, Feb, Jun, Aug, Dec, Jun,
        Oct, Apr, Oct, Apr, Oct, Jun, Apr, Sep, Oct, Apr,
        Sep, Dec, Jul, Jan, Oct, Jan, Oct, Jan, Dec, Dec};

    vector<Day> issueDay = {
        14, 8, 11, 30, 4, 30, 25, 30, 4, 28, 2, 30, 4, 24, 25, 21, 22,
        24, 5, 26, 29, 26, 23, 30, 28, 28, 26, 24, 31, 24, 21, 25, 27, 28,
        30, 20, 26, 20, 31, 27, 21, 29, 3, 4, 7, 4, 27, 22, 24, 28};

    vector<Year> maturityYear = {
        2008, 2008, 2008, 2008, 2008, 2008, 2008, 2008, 2009, 2009,
        2009, 2009, 2009, 2009, 2009, 2009, 2010, 2010, 2010, 2010,
        2011, 2011, 2011, 2011, 2012, 2012, 2012, 2012, 2013, 2013,
        2014, 2014, 2015, 2015, 2016, 2016, 2016, 2016, 2017, 2017,
        2018, 2024, 2027, 2028, 2028, 2030, 2031, 2034, 2037, 2039};

    vector<Month> maturityMonth = {
        Feb, Mar, Apr, Jun, Jul, Sep, Oct, Dec, Jan, Mar,
        Apr, Jun, Jul, Sep, Oct, Dec, Jan, Apr, Jul, Oct,
        Jan, Apr, Jul, Oct, Jan, Apr, Jul, Oct, Jan, Jul,
        Jan, Jul, Jan, Jul, Jan, Jun, Jul, Sep, Jan, Jul,
        Jan, Jan, Jul, Jan, Jul, Jan, Jan, Jul, Jan, Jul};

    vector<Day> maturityDay = {
        15, 14, 11, 13, 4, 12, 10, 12, 4, 13, 17, 12, 4, 11, 9, 11,
        4, 9, 4, 8, 4, 8, 4, 14, 4, 13, 4, 12, 4, 4, 4, 4, 4, 4, 4,
        20, 4, 20, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

    vector<Date> issueDate(bondNum), maturityDate(bondNum);

    for (Size i = 0; i < bondNum; ++i) {
        Date idate(issueDay[i], issueMonth[i], issueYear[i]);
        Date mdate(maturityDay[i], maturityMonth[i], maturityYear[i]);
        issueDate[i] = idate;
        maturityDate[i] = mdate;
    }

    vector<Real> couponRate = {
        0.0425, 0.03, 0.03, 0.0325, 0.0475, 0.035, 0.035, 0.0375, 0.0375, 0.0375,
        0.0325, 0.045, 0.045, 0.04, 0.035, 0.04, 0.05375, 0.0325, 0.0525, 0.025,
        0.0525, 0.035, 0.05, 0.035, 0.05, 0.04, 0.05, 0.0425, 0.045, 0.0375, 0.0425,
        0.0425, 0.0375, 0.0325, 0.035, 0.06, 0.04, 0.05625, 0.0375, 0.0425, 0.04,
        0.0625, 0.065, 0.05625, 0.0475, 0.0625, 0.055, 0.0475, 0.04, 0.0425};

    Frequency frequency = Annual;
    Actual365Fixed dayCounter(Actual365Fixed::Standard);
    BusinessDayConvention paymentConv = Unadjusted;
    BusinessDayConvention terminationDateConv = Unadjusted;
    BusinessDayConvention convention = Unadjusted;
    Real redemption = 100.0;
    Real faceAmount = 100.0;
    Germany calendar(Germany::Eurex);

    Date today = calendar.adjust(Date(30, Jan, 2008));
    Settings::instance().evaluationDate() = today;

    Natural bondSettlementDays = 0;
    Date bondSettlementDate = calendar.advance(
        today,
        Period(bondSettlementDays, Days));

    vector<ext::shared_ptr<BondHelper>> instruments(bondNum);
    vector<Time> maturity(bondNum);

    for (Size i = 0; i < bondNum; ++i) {

        vector<Real> bondCoupon = {couponRate[i]};

        Schedule schedule(
            issueDate[i],
            maturityDate[i],
            Period(frequency),
            calendar,
            convention,
            terminationDateConv,
            DateGeneration::Backward,
            false);

        ext::shared_ptr<FixedRateBondHelper> helper(
            new FixedRateBondHelper(
                priceHandle[i],
                bondSettlementDays,
                faceAmount,
                schedule,
                bondCoupon,
                dayCounter,
                paymentConv,
                redemption));

        maturity[i] = dayCounter.yearFraction(
            bondSettlementDate, helper->maturityDate());

        instruments[i] = helper;
    }

    Real tolerance = 1.0e-6;
    Natural max = 5000;

    ext::shared_ptr<OptimizationMethod> optMethod(
        new LevenbergMarquardt());

    vector<Real> knotCubic = CubicSplinesFitting::autoKnots(maturity);
    vector<Real> knotQuadratic = QuadraticSplinesFitting::autoKnots(maturity);
    vector<Real> termstrcKnotes = {
        0.000000, 1.006027, 2.380274, 5.033425, 9.234521, 31.446575};

    cout << "knotCubic:\t";
    for (auto v : knotCubic) {
        cout << setprecision(6) << fixed << v << ", ";
    }
    cout << endl;

    cout << "termstrc knots:\t";
    for (auto v : termstrcKnotes) {
        cout << setprecision(6) << fixed << v << ", ";
    }
    cout << endl;

    cout << "knotQuadratic:\t";
    for (auto v : knotQuadratic) {
        cout << setprecision(6) << fixed << v << ", ";
    }
    cout << endl;

    cout << endl;

    CubicSplinesFitting csf(
        knotCubic, Array(), optMethod);
    QuadraticSplinesFitting qsf(
        knotQuadratic, Array(), optMethod);

    FittedBondDiscountCurve tsCubicSplines(
        bondSettlementDate,
        instruments, dayCounter,
        csf, tolerance, max);
    FittedBondDiscountCurve tsQuadraticSplines(
        bondSettlementDate,
        instruments, dayCounter,
        qsf, tolerance, max);

    Array weightsCubic = tsCubicSplines.fitResults().solution();
    Array weightsQuadratic = tsQuadraticSplines.fitResults().solution();
    Array termstrcWeights(7);
    termstrcWeights[0] = 1.9320e-02, termstrcWeights[1] = -8.4936e-05,
    termstrcWeights[2] = -3.2009e-04, termstrcWeights[3] = -3.7101e-04,
    termstrcWeights[4] = 7.2921e-04, termstrcWeights[5] = 2.0159e-03,
    termstrcWeights[6] = -4.1632e-02;

    cout << "Cubic weights: \t" << weightsCubic << endl;
    cout << "Quadratic weights: \t" << weightsQuadratic << endl;
    cout << "termstrc weights: \t" << termstrcWeights << endl;

    cout << endl;

    cout << "Cubic final cost value:\t"
         << tsCubicSplines.fitResults().minimumCostValue() << endl;
    cout << "Quadratic final cost value:\t"
         << tsQuadraticSplines.fitResults().minimumCostValue() << endl;

    cout << endl;

    Real spotRateCubic, spotRateQuadratic, termstrcSpot;

    for (Size i = 0; i < bondNum; ++i) {

        Time t = dayCounter.yearFraction(
            bondSettlementDate, maturityDate[i]);

        spotRateCubic =
            tsCubicSplines.zeroRate(t, Compounding::Continuous, frequency).rate() * 100.0;
        spotRateQuadratic =
            tsQuadraticSplines.zeroRate(t, Compounding::Continuous, frequency).rate() * 100.0;
        termstrcSpot =
            CubicSplineSpotRate(termstrcKnotes, termstrcWeights, t) * 100.0;

        cout << setprecision(3) << fixed
             << t << ",\t"
             << spotRateCubic << ",\t"
             << spotRateQuadratic << ",\t"
             << termstrcSpot << ",\t"
             << spotRateCubic - termstrcSpot << ",\t"
             << spotRateQuadratic - termstrcSpot << endl;
    }
}

void TestActual365_25() {
    using namespace std;
    using namespace QuantLib;

    Actual365_25 act365_25;
    Actual365Fixed act365;

    Date d1(28, December, 2007),
        d2(28, February, 2008),
        d3(29, February, 2008),
        d4(31, October, 2007),
        d5(30, November, 2008),
        d6(2, January, 2008),
        d7(1, May, 2009);

    cout << act365.yearFraction(d1, d2) << ", "
         << act365_25.yearFraction(d1, d2) << ", "
         << act365_25.yearFraction(d1, d2) * 365.25 / 365.0 << endl;

    cout << act365.yearFraction(d1, d3) << ", "
         << act365_25.yearFraction(d1, d3) << ", "
         << act365_25.yearFraction(d1, d3) * 365.25 / 365.0 << endl;

    cout << act365.yearFraction(d4, d5) << ", "
         << act365_25.yearFraction(d4, d5) << ", "
         << act365_25.yearFraction(d4, d5) * 365.25 / 365.0 << endl;

    cout << act365.yearFraction(d6, d7) << ", "
         << act365_25.yearFraction(d6, d7) << ", "
         << act365_25.yearFraction(d6, d7) * 365.25 / 365.0 << endl;
}

void TestChinaFixingRepoCoupon() {
    using namespace std;
    using namespace QuantLib;

    Calendar calendar = China(China::IB);
    Date today(21, January, 2020);
    Settings::instance().evaluationDate() = today;

    Natural fixingDays = 1;

    DayCounter dayCounter = Actual365Fixed(Actual365Fixed::Standard);

    ext::shared_ptr<ChinaFixingRepo> fr(
        new ChinaFixingRepo(
            Period(7, Days),
            fixingDays));

    vector<Date> dates = {
        Date(27, July, 2018),
        Date(3, August, 2018),
        Date(10, August, 2018),
        Date(17, August, 2018),
        Date(24, August, 2018),
        Date(31, August, 2018),
        Date(7, September, 2018),
        Date(14, September, 2018),
        Date(21, September, 2018),
        Date(30, September, 2018),
        Date(12, October, 2018),
        Date(19, October, 2018),
        Date(26, October, 2018)};

    vector<Rate> fwds = {
        2.8 / 100.0,
        2.4 / 100.0,
        2.29 / 100.0,
        2.65 / 100.0,
        2.5 / 100.0,
        2.66 / 100.0,
        2.69 / 100.0,
        2.6 / 100.0,
        2.65 / 100.0,
        2.76 / 100.0,
        2.6 / 100.0,
        2.61 / 100.0,
        2.65 / 100.0};

    TimeSeries<Real> ts(dates.begin(), dates.end(), fwds.begin());

    IndexManager::instance().setHistory(fr->name(), ts);

    Date startDate(30, July, 2018);
    Date endDate(30, October, 2018);

    ChinaFixingRepoCoupon coupon(
        endDate,
        10000.0,
        startDate,
        endDate,
        fr,
        1.0,
        0.0,
        startDate,
        endDate,
        dayCounter);

    cout << coupon.rate() << endl;

    size_t n = coupon.fixingDates().size();

    for (size_t i = 0; i < n; ++i) {
        cout << setw(15) << coupon.fixingDates()[i]
             << setw(15) << coupon.valueDates()[i] << endl;
    }
}

void TestChinaFixingRepoSwap() {
    using namespace std;
    using namespace QuantLib;

    Calendar calendar = China(China::IB);
    Date today(21, January, 2020);
    Settings::instance().evaluationDate() = today;

    Natural fixingDays = 1;

    DayCounter dayCounter = Actual365Fixed(Actual365Fixed::Standard);

    ext::shared_ptr<YieldTermStructure> flat(
        new FlatForward(today, 0.03, dayCounter));
    Handle<YieldTermStructure> flatHandle(flat);

    ext::shared_ptr<ChinaFixingRepo> fr(
        new ChinaFixingRepo(
            Period(7, Days),
            fixingDays));

    Date effectiveDate(22, January, 2020), terminationDate(22, January, 2030);

    Schedule sch(
        effectiveDate,
        terminationDate,
        Period(3, Months),
        calendar,
        ModifiedFollowing,
        Unadjusted,
        DateGeneration::Forward,
        false);

    vector<Date> zrDates = {
        Date(22, January, 2020),
        Date(22, January, 2020) + Period(8, Days),
        Date(22, January, 2020) + Period(36, Days),
        Date(22, January, 2020) + Period(92, Days),
        Date(22, January, 2020) + Period(183, Days),
        Date(22, January, 2020) + Period(281, Days),
        Date(22, January, 2020) + Period(373, Days),
        Date(22, January, 2020) + Period(738, Days),
        Date(22, January, 2020) + Period(1105, Days),
        Date(22, January, 2020) + Period(1462, Days),
        Date(22, January, 2020) + Period(1834, Days),
        Date(22, January, 2020) + Period(2564, Days),
        Date(22, January, 2020) + Period(3660, Days)};

    vector<Real> zrs = {
        0.00000,
        2.59113 / 100.0,
        2.58362 / 100.0,
        2.56513 / 100.0,
        2.57243 / 100.0,
        2.58659 / 100.0,
        2.59732 / 100.0,
        2.66064 / 100.0,
        2.73611 / 100.0,
        2.82605 / 100.0,
        2.91498 / 100.0,
        3.05578 / 100.0,
        3.19530 / 100.0};

    ext::shared_ptr<YieldTermStructure> zc(
        new InterpolatedZeroCurve<Linear>(
            zrDates, zrs, dayCounter, calendar,
            Linear(), Continuous));

    Handle<YieldTermStructure> zcHandle(zc);

    ext::shared_ptr<PricingEngine> engine(
        new DiscountingSwapEngine(zcHandle));

    ext::shared_ptr<ChinaFixingRepo> idx(
        new ChinaFixingRepo(
            Period(7, Days),
            fixingDays,
            zcHandle));

    ChinaFixingRepoSwap swap(
        ChinaFixingRepoSwap::Type::Payer,
        10000000.0,
        sch,
        3.1763 / 100.0,
        dayCounter,
        idx);

    swap.setPricingEngine(engine);

    cout << swap.NPV() / 10000000.0 * 100.0 << '%' << endl;
    cout << swap.fixedLegNPV() / 10000000.0 * 100.0 << '%' << endl;
    cout << swap.floatingLegNPV() / 10000000.0 * 100.0 << '%' << endl;
}
