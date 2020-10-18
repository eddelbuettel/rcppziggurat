\name{NEWS}
\title{News for Package \pkg{RcppZiggurat}}
\newcommand{\ghpr}{\href{https://github.com/eddelbuettel/rcppziggurat/pull/#1}{##1}}
\newcommand{\ghit}{\href{https://github.com/eddelbuettel/rcppziggurat/issues/#1}{##1}}

\section{Changes in version 0.1.6 (2020-10-18)}{
  \itemize{
    \item Several typos were corrected in the vignette (Blagoje Ivanovic
    in \ghpr{9}).
    \item New getters and setters for internal state were added to
    resume simulations (Dirk in \ghpr{11} fixing \ghit{10}).
    \item Minor updates to \code{cleanup} script and Travis CI setup (Dirk).
  }
}

\section{Changes in version 0.1.5 (2018-06-10)}{
  \itemize{
    \item Description rewritten using doi for references.
    \item Re-setting the Ziggurat generator seed now correctly re-sets
    state (Ralf Stubner in \ghpr{7} fixing \ghit{3})
    \item Dynamic registration reverts to manual mode so that
    user_norm_rand() is visible as well (\ghit{7}).
    \item The vignette was updated to accomodate pandoc 2* [CRAN request].
  }
}

\section{Changes in version 0.1.4 (2017-09-27)}{
  \itemize{
    \item The vignette now uses the pinp package in two-column mode.
    \item Dynamic symbol registration is now enabled.
  }
}

\section{Changes in version 0.1.3 (2015-07-25)}{
  \itemize{
    \item Use the \code{SHR3} generator for the default implementation
    just like Leong et al do, making our default implementation
    identical to theirs (but 32- and 64-bit compatible)
    \item Switched generators from \code{float} to \code{double}
    ensuring that results are identical on 32- and 64-bit platforms
    \item Simplified builds with respect to GSL use via the
    \CRANpkg{RcppGSL} package; added a seed setter for the GSL variant
    \item Corrected use of \code{fabs()} to \code{abs()} on integer
    variables, with a grateful nod to Brian Ripley for the hint (based
    on CRAN checks on the beloved Slowlaris machines)
    \item Accelerated Travis CI tests by relying exclusively on
    \code{r-cran-*} packages from the PPAs by Michael Rutter and myself
    \item Updated \code{DESCRIPTION} and \code{NAMESPACE} according to
    current best practices, and \code{R-devel CMD check --as-cran} checks
  }
}

\section{Changes in version 0.1.2 (2013-12-28)}{
  \itemize{
    \item Add a new generator deploying R's unif_rand which faciliates use
    of Ziggurat as the user-supplied generator for N(0,1) 
    \item Update a 'local' demo comparing normal distribution RNGs from
    Boost, C++11 and Armadillo none of which are particularly speedy
    \item Add declaration to import a symbol from \CRANpkg{Rcpp} to
    \code{NAMESPACE} to ensure proper instantiation with the upcoming
    \CRANpkg{Rcpp} version 
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
