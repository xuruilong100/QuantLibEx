#include "Actual365_25.hpp"
#include "example.hpp"
#include <iostream>
#include <quantlib.hpp>
#include <vector>

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