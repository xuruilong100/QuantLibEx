# QuantLibEx

[toc]

Some experimental codes that intend to extend QuantLib.

## About Term Structure

Classes `CubicSpline` and `CubicSplinesFitting` intend to fit term structure using **cubic splines**, the codes base on paper (Ferstl and Hayden, 2010) and (McCulloch, 1975).

Classes `QuadraticSpline` and `QuadraticSplinesFitting` intend to fit term structure using **quadratic splines**, the codes base on paper (McCulloch, 1971).

Class `AdjustedSvenssonFitting` intends to fit term structure using **adjusted Svensson model**, the codes base on paper (Ferstl and Hayden, 2010) and (Pooter, 2007).

Class `DieboldLiFitting` intends to fit term structure using **Diebold-Li model**, a special Nelson-Siegel model, the codes base on paper (Ferstl and Hayden, 2010).

Class `BlissFitting` intends to fit term structure using **Bliss three-factor model**, the codes base on paper and (Pooter, 2007).

Class `BjorkChristensenFitting` intends to fit term structure using **Björk-Christensen four-factor model**, the codes base on paper and (Pooter, 2007).

## About Day Counter

Class `Actual365_25` is Actual/365.25 day count convention. Just a copy of `Actual365Fixed`, but divied by 356.25.

## Reference

* Ferstl.R, Hayden.J (2010). "Zero-Coupon Yield Curve Estimation with the Package `termstrc`." *Journal of Statistical Software*, Volume 36, Issue 1.
* De Pooter M (2007). "Examining the Nelson-Siegel Class of Term Structure Models: In-Sample Fit versus Out-of-Sample Forecasting Performance." *SSRN eLibrary*. <http://ssrn.com/paper=992748>.
* McCulloch JH (1971). Measuring the Term Structure of Interest Rates. *The Journal of Business*, 44(1), 19-31.
* McCulloch JH (1975). The Tax-Adjusted Yield Curve. *The Journal of Finance*, 30(3), 811–830.



