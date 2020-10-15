\name{RcppZiggurat-package}
\alias{RcppZiggurat-package}
\alias{RcppZiggurat}
\docType{package}
\title{
  Collection and comparison of different Ziggurat RNGs
}
\description{
  Marsaglia and Tsang (JSS, 2000) introduced a very fast random number
  generator for drawing from a standard normal distribution.  Leong,
  Zhang, Lee, Luk and Villasenor (JSS, 2005) suggested a simple
  improvement to provide better distributional properties.

  This package implements both approaches, both in simple forms faithful
  to original papers, as well as in extended and modified versions of
  the C/C++ code provided by John Burkardt.

  It also includes a variant which calls the fairly widely used Ziggurat
  implementation by Jochen Voss that is part of the GNU GSL. It uses the
  Mersenne-Twister as its uniform generator and does not suffer from the
  problem identified by Leong et al.
}
\author{
  Dirk Eddelbuettel
}
\references{
  George Marsaglia and Wai Wan Tsang. The Ziggurat Method for Generating Random Variables.
  Journal of Statistical Software, Vol 5, Iss 8, Oct 2000
  \url{https://www.jstatsoft.org/v05/i08}
   
  Philip H W Leong, Ganglie Zhang, Dong-U Lee, Wayne Luk, and John Villasenor.
  A Comment on the Implementation of the Ziggurat method,
  Journal of Statistical Software, Vol 12, Iss 7, Feb 2005
  \url{https://www.jstatsoft.org/v12/i07}

  Website of John Burkardt. \url{https://people.sc.fsu.edu/~jburkardt/}

  Website of Jochen Voss. \url{https://www.seehuhn.de/pages/ziggurat}
}
\keyword{package}
\examples{
  set.seed(42)
  system.time(replicate(500, rnorm(10000)))

  zsetseed(42)
  system.time(replicate(500, zrnorm(10000)))
}
