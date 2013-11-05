\name{NEWS}
\title{News for Package \pkg{RcppZiggurat}}
\newcommand{\cpkg}{\href{http://CRAN.R-project.org/package=#1}{\pkg{#1}}}

\section{Changes in version 0.0.2 (2013-11-04)}{
  \itemize{
    \item Two new generators imported from GNU Gretl and QuantLib
    implementations
    \item Testing framework added with a standard RNG test, a new and
    similar test particular for Normal distributions, and the Chi^2 test
    from the Leong et al paper (JSS, 2005)
    \item New \code{demo()} functionality showing the three added tests.
    \item Code has been reorganized into separate headers implementing
    the generators, using a common base class; and accessors and tests
    in the \code{src/} directory.
  } 
}

\section{Changes in version 0.0.1 (2013-10-06)}{
  \itemize{
    \item Initial basic package version, wrapping five different
    implementations 
  } 
}
