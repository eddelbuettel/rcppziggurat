# RcppZiggurat

[![Build Status](https://travis-ci.org/eddelbuettel/rcppziggurat.png)](https://travis-ci.org/eddelbuettel/rcppziggurat)

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

## Status

The package currently contains five different implementations. Two of these 
are based on the original Marsaglia and Tsang approach and should *not* be 
used as the resulting generator has be improved as suggested by Leong et al.
In other words, do not deploy `zrnormMT()` or `zrnormV1()` (even though the 
latter is still the fastest).

The recommended approach is to deploy `zrnorm()` and its associated seed 
setter and getter.

## TODO

Testing, testing, testing, ...

More generators as e.g. the modified Ziggurat implementation suggested by 
Doornik, the Ziggurat generators contained in GNU Gretl and in QuantLib. 

## Demo

The package contains a demo script benchmarking the implementation. Run

    R> library(RcppZiggurat)
    R> demo("benchmark", package="RcppZiggurat")

which should result in something like the following:

    R> print(res[,1:4])
                test replications elapsed relative
    4 zrnormVecV1(v)         1000   0.918    1.000
    3    zrnormV1(N)         1000   1.274    1.388
    7   zrnormVec(v)         1000   2.189    2.385
    1    zrnormMT(N)         1000   2.296    2.501
    2 zrnormLZLLV(N)         1000   2.410    2.625
    6      zrnorm(N)         1000   2.516    2.741
    8   zrnormgsl(N)         1000   3.159    3.441
    5       rnorm(N)         1000  14.102   15.362
    R> 

