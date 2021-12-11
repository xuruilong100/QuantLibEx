#include <iostream>
#include <ql/quantlib.hpp>
#include <qlex/quantlibex.hpp>
#include <test/example.hpp>
#include <test/utility.hpp>
#include <vector>

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

void ShiborIRScurve() {

    using namespace QuantLib;
    using namespace std;

    Calendar calendar = China(China::IB);
    Date today(15, January, 2020);
    Settings::instance().evaluationDate() = today;

    Natural delayDays = 1;

    Date settlementDate = calendar.advance(
        today, delayDays, Days);
    // must be a business day
    settlementDate = calendar.adjust(settlementDate);

    cout << "Today: " << today << endl;
    cout << "Settlement date: " << settlementDate << endl;

    cout << endl;

    DayCounter termStrcDayCounter = Actual365_25();

    Period mn1(1, Months), mn3(3, Months), mn6(6, Months), mn9(9, Months),
        yr1(1, Years), yr2(2, Years), yr3(3, Years), yr4(4, Years),
        yr5(5, Years), yr7(7, Years), yr10(10, Years);

    ext::shared_ptr<Quote>
        m1Rate(new SimpleQuote(2.7990 / 100.0)),
        m3Rate(new SimpleQuote(2.8650 / 100.0)),
        s6mRate(new SimpleQuote(2.8975 / 100.0)),
        s9mRate(new SimpleQuote(2.9125 / 100.0)),
        s1yRate(new SimpleQuote(2.9338 / 100.0)),
        s2yRate(new SimpleQuote(3.0438 / 100.0)),
        s3yRate(new SimpleQuote(3.1639 / 100.0)),
        s4yRate(new SimpleQuote(3.2805 / 100.0)),
        s5yRate(new SimpleQuote(3.3876 / 100.0)),
        s7yRate(new SimpleQuote(3.5575 / 100.0)),
        s10yRate(new SimpleQuote(3.7188 / 100.0));

    Handle<Quote>
        m1RateHandle(m1Rate),
        m3RateHandle(m3Rate),
        s6mRateHandle(s6mRate),
        s9mRateHandle(s9mRate),
        s1yRateHandle(s1yRate),
        s2yRateHandle(s2yRate),
        s3yRateHandle(s3yRate),
        s4yRateHandle(s4yRate),
        s5yRateHandle(s5yRate),
        s7yRateHandle(s7yRate),
        s10yRateHandle(s10yRate);

    DayCounter depositDayCounter = Actual360();

    ext::shared_ptr<RateHelper>
        m1(new DepositRateHelper(
            m1RateHandle, mn1, delayDays, calendar,
            ModifiedFollowing, false, depositDayCounter)),
        m3(new DepositRateHelper(
            m3RateHandle, mn3, delayDays, calendar,
            ModifiedFollowing, false, depositDayCounter));

    Frequency fixedLegFreq = Quarterly;
    BusinessDayConvention fixedLegConv = ModifiedFollowing;
    DayCounter fixedLegDayCounter = Actual365Fixed();

    ext::shared_ptr<IborIndex> shiborIndex(
        new IborIndex(
            "Shibor", mn3, delayDays, CNYCurrency(),
            calendar, Unadjusted, false, Actual360()));

    ext::shared_ptr<RateHelper>
        s6m(new SwapRateHelper(
            s6mRateHandle, mn6, calendar, fixedLegFreq, fixedLegConv,
            fixedLegDayCounter, shiborIndex)),
        s9m(new SwapRateHelper(
            s9mRateHandle, mn9, calendar, fixedLegFreq, fixedLegConv,
            fixedLegDayCounter, shiborIndex)),
        s1y(new SwapRateHelper(
            s1yRateHandle, yr1, calendar, fixedLegFreq, fixedLegConv,
            fixedLegDayCounter, shiborIndex)),
        s2y(new SwapRateHelper(
            s2yRateHandle, yr2, calendar, fixedLegFreq, fixedLegConv,
            fixedLegDayCounter, shiborIndex)),
        s3y(new SwapRateHelper(
            s3yRateHandle, yr3, calendar, fixedLegFreq, fixedLegConv,
            fixedLegDayCounter, shiborIndex)),
        s4y(new SwapRateHelper(
            s4yRateHandle, yr4, calendar, fixedLegFreq, fixedLegConv,
            fixedLegDayCounter, shiborIndex)),
        s5y(new SwapRateHelper(
            s5yRateHandle, yr5, calendar, fixedLegFreq, fixedLegConv,
            fixedLegDayCounter, shiborIndex)),
        s7y(new SwapRateHelper(
            s7yRateHandle, yr7, calendar, fixedLegFreq, fixedLegConv,
            fixedLegDayCounter, shiborIndex)),
        s10y(new SwapRateHelper(
            s10yRateHandle, yr10, calendar, fixedLegFreq, fixedLegConv,
            fixedLegDayCounter, shiborIndex));

    vector<ext::shared_ptr<RateHelper>> instruments;

    instruments.push_back(m1);
    instruments.push_back(m3);
    instruments.push_back(s6m);
    instruments.push_back(s9m);
    instruments.push_back(s1y);
    instruments.push_back(s2y);
    instruments.push_back(s3y);
    instruments.push_back(s4y);
    instruments.push_back(s5y);
    instruments.push_back(s7y);
    instruments.push_back(s10y);

    ext::shared_ptr<YieldTermStructure> termStrc(
        new PiecewiseYieldCurve<ForwardRate, BackwardFlat>(
            today,
            instruments,
            termStrcDayCounter));

    Date curveNodeDate = calendar.adjust(settlementDate + mn1);

    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + mn3);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + mn6);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + mn9);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr1);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr2);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr3);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr4);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr5);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr7);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr10);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
}

void ChinaFixingRepoSwapCurve() {

    using namespace std;
    using namespace QuantLib;

    Calendar calendar = China(China::IB);
    Date today(21, January, 2020);
    Settings::instance().evaluationDate() = today;

    Natural delayDays = 1;

    Date settlementDate = calendar.advance(
        today, delayDays, Days);
    // must be a business day
    settlementDate = calendar.adjust(settlementDate);

    cout << "Today: " << today << endl;
    cout << "Settlement date: " << settlementDate << endl;

    cout << endl;

    DayCounter termStrcDayCounter = Actual365Fixed();

    Period dy7(7, Days), mn1(1, Months), mn3(3, Months), mn6(6, Months), mn9(9, Months),
        yr1(1, Years), yr2(2, Years), yr3(3, Years), yr4(4, Years),
        yr5(5, Years), yr7(7, Years), yr10(10, Years);

    ext::shared_ptr<Quote>
        d7Rate(new SimpleQuote(2.5900 / 100.0)),
        s1mRate(new SimpleQuote(2.5848 / 100.0)),
        s3mRate(new SimpleQuote(2.5713 / 100.0)),
        s6mRate(new SimpleQuote(2.5788 / 100.0)),
        s9mRate(new SimpleQuote(2.5925 / 100.0)),
        s1yRate(new SimpleQuote(2.6033 / 100.0)),
        s2yRate(new SimpleQuote(2.6665 / 100.0)),
        s3yRate(new SimpleQuote(2.7415 / 100.0)),
        s4yRate(new SimpleQuote(2.8288 / 100.0)),
        s5yRate(new SimpleQuote(2.9130 / 100.0)),
        s7yRate(new SimpleQuote(3.0466 / 100.0)),
        s10yRate(new SimpleQuote(3.1763 / 100.0));

    Handle<Quote>
        d7RateHandle(d7Rate),
        s1mRateHandle(s1mRate),
        s3mRateHandle(s3mRate),
        s6mRateHandle(s6mRate),
        s9mRateHandle(s9mRate),
        s1yRateHandle(s1yRate),
        s2yRateHandle(s2yRate),
        s3yRateHandle(s3yRate),
        s4yRateHandle(s4yRate),
        s5yRateHandle(s5yRate),
        s7yRateHandle(s7yRate),
        s10yRateHandle(s10yRate);

    DayCounter depositDayCounter = Actual365Fixed();

    ext::shared_ptr<RateHelper> d7(
        new DepositRateHelper(
            d7RateHandle, dy7, 0, calendar,
            Unadjusted, false, depositDayCounter));

    Frequency fixedLegFreq = Quarterly;
    BusinessDayConvention fixedLegConv = ModifiedFollowing;
    DayCounter fixedLegDayCounter = Actual365Fixed();

    ext::shared_ptr<ChinaFixingRepo> chinaFixingRepo(
        new ChinaFixingRepo(dy7, delayDays));

    ext::shared_ptr<RateHelper>
        s1m(new ChinaFixingRepoSwapRateHelper(
            delayDays, mn1,
            s1mRateHandle, chinaFixingRepo, Handle<YieldTermStructure>(), 0,
            fixedLegConv, fixedLegFreq, calendar)),
        s3m(new ChinaFixingRepoSwapRateHelper(
            delayDays, mn3,
            s3mRateHandle, chinaFixingRepo, Handle<YieldTermStructure>(), 0,
            fixedLegConv, fixedLegFreq, calendar)),
        s6m(new ChinaFixingRepoSwapRateHelper(
            delayDays, mn6,
            s6mRateHandle, chinaFixingRepo, Handle<YieldTermStructure>(), 0,
            fixedLegConv, fixedLegFreq, calendar)),
        s9m(new ChinaFixingRepoSwapRateHelper(
            delayDays, mn9,
            s9mRateHandle, chinaFixingRepo, Handle<YieldTermStructure>(), 0,
            fixedLegConv, fixedLegFreq, calendar)),
        s1y(new ChinaFixingRepoSwapRateHelper(
            delayDays, yr1,
            s1yRateHandle, chinaFixingRepo, Handle<YieldTermStructure>(), 0,
            fixedLegConv, fixedLegFreq, calendar)),
        s2y(new ChinaFixingRepoSwapRateHelper(
            delayDays, yr2,
            s2yRateHandle, chinaFixingRepo, Handle<YieldTermStructure>(), 0,
            fixedLegConv, fixedLegFreq, calendar)),
        s3y(new ChinaFixingRepoSwapRateHelper(
            delayDays, yr3,
            s3yRateHandle, chinaFixingRepo, Handle<YieldTermStructure>(), 0,
            fixedLegConv, fixedLegFreq, calendar)),
        s4y(new ChinaFixingRepoSwapRateHelper(
            delayDays, yr4,
            s4yRateHandle, chinaFixingRepo, Handle<YieldTermStructure>(), 0,
            fixedLegConv, fixedLegFreq, calendar)),
        s5y(new ChinaFixingRepoSwapRateHelper(
            delayDays, yr5,
            s5yRateHandle, chinaFixingRepo, Handle<YieldTermStructure>(), 0,
            fixedLegConv, fixedLegFreq, calendar)),
        s7y(new ChinaFixingRepoSwapRateHelper(
            delayDays, yr7,
            s7yRateHandle, chinaFixingRepo, Handle<YieldTermStructure>(), 0,
            fixedLegConv, fixedLegFreq, calendar)),
        s10y(new ChinaFixingRepoSwapRateHelper(
            delayDays, yr10,
            s10yRateHandle, chinaFixingRepo, Handle<YieldTermStructure>(), 0,
            fixedLegConv, fixedLegFreq, calendar));

    vector<ext::shared_ptr<RateHelper>> instruments;

    instruments.push_back(d7);
    instruments.push_back(s1m);
    instruments.push_back(s3m);
    instruments.push_back(s6m);
    instruments.push_back(s9m);
    instruments.push_back(s1y);
    instruments.push_back(s2y);
    instruments.push_back(s3y);
    instruments.push_back(s4y);
    instruments.push_back(s5y);
    instruments.push_back(s7y);
    instruments.push_back(s10y);

    ext::shared_ptr<YieldTermStructure> termStrc(
        new PiecewiseYieldCurve<ForwardRate, BackwardFlat>(
            today,
            instruments,
            termStrcDayCounter));

    Date curveNodeDate = calendar.adjust(settlementDate + dy7);

    cout << setw(4) << curveNodeDate - today << ", "
         << setprecision(8) << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + mn1);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + mn3);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + mn6);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + mn9);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr1);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr2);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr3);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr4);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr5);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr7);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
    curveNodeDate = calendar.adjust(settlementDate + yr10);
    cout << setw(4) << curveNodeDate - today << ", "
         << termStrc->discount(curveNodeDate) << ", "
         << termStrc->zeroRate(curveNodeDate, termStrcDayCounter, Continuous).rate() * 100.0
         << endl;
}
