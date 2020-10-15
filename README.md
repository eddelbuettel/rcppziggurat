
## RcppZiggurat: Rcpp Bindings for Ziggurat RNGs

[![Build Status](https://travis-ci.org/eddelbuettel/rcppziggurat.svg)](https://travis-ci.org/eddelbuettel/rcppziggurat) 
[![License](http://img.shields.io/badge/license-GPL%20%28%3E=%202%29-brightgreen.svg?style=flat)](http://www.gnu.org/licenses/gpl-2.0.html) 
[![CRAN](http://www.r-pkg.org/badges/version/RcppZiggurat)](https://cran.r-project.org/package=RcppZiggurat) 
[![Downloads](http://cranlogs.r-pkg.org/badges/RcppZiggurat?color=brightgreen)](https://www.r-pkg.org:443/pkg/RcppZiggurat)
[![Last Commit](https://img.shields.io/github/last-commit/eddelbuettel/rcppziggurat)](https://github.com/eddelbuettel/rcppziggurat)

### Overview

The RcppZiggurat package regroups a number of implementations of the
'Ziggurat' random number generator by Marsaglia and Tsang (JSS, 2000), both
in the original version and via the update by Leong, Zhang, Lee, Luk and
Villasenor (JSS, 2005).

The purpose of the package is to both study and time these implementations in
order to provide a fast N(0,1) generator for use by R.  The generators
included in R are excellent and very diligently implemented, but not
generally the fastest.  This package aims to close the performance gap.

You should know what you are doing when deploying this package. If in doubt,
stick with the default generators.

### Vignette
 
The package contains a [detailed vignette](http://dirk.eddelbuettel.com/papers/RcppZiggurat.pdf)  summarizing the methods, the
implementation as well as the statistical properties (examined via three
different tests) and the generator speed. 

### Status

The package currently contains six different implementations. Two are
standard from the literature: the original Marsaglia and Tsang approach (which should *not* be 
used as the resulting generator has be improved as suggested by Leong et
al.), the improved Leong et al variant, a version from the GNU GSL, a version
from the GNU Gretl econometric program as well as a version from QuantLib.

### Demo

The package contains several demo scripts. Try

    R> demo(package="RcppZiggurat")

### TODO

More testing never hurts, ...

More generators as e.g. the modified Ziggurat implementation suggested by 
Doornik (though his code is not under an open source licence)

### Author

Dirk Eddelbuettel

### License

GPL (>= 2)

