\name{NEWS}
\title{News for Package \pkg{RcppZiggurat}}
\newcommand{\cpkg}{\href{http://CRAN.R-project.org/package=#1}{\pkg{#1}}}

\section{Changes in version 0.1.2 (2013-12-28)}{
  \itemize{
    \item Add a new generator deploying R's unif_rand which faciliates use
    of Ziggurat as the user-supplied generator for N(0,1) 
    \item Update a 'local' demo comparing normal distribution RNGs from
    Boost, C++11 and Armadillo none of which are particularly speedy
    \item Add declaration to import a symbol from \cpkg{Rcpp} to
    \code{NAMESPACE} to ensure proper instantiation with the upcoming
    \cpkg{Rcpp} version 
  }
}

\section{Changes in version 0.1.1 (2013-12-22)}{
  \itemize{
    \item Set dependency on R (>= 3.0.0) needed by vignette builder
    \item Remove pdf files in vignette on cleanup to ensure rebuilds
  }
}

\section{Changes in version 0.1.0 (2013-12-21)}{
  \itemize{
    \item Testing framework added with a standard RNG test, a new and
    similar test particular for Normal distributions, and the Chi^2 test
    from the Leong et al paper (JSS, 2005)
    \item New \code{demo()} functionality showing the three added tests.
    \item Code has been reorganized into separate headers implementing
    the generators, using a common (virtual) base class; and accessors
    and tests in the \code{src/} directory.
    \item Two new ziggurat generators implementations have been adapted
    from, respectively, GNU Gretl and QuantLib
    \item Added a \code{vignette}
  } 
}

\section{Changes in version 0.0.1 (2013-10-06)}{
  \itemize{
    \item Initial basic package version, wrapping five different
    implementations 
  } 
}
