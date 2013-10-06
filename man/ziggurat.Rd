\name{zrnorm}
\alias{zrnorm}
\alias{zrnormLZLLV}
\alias{zrnormMT}
\alias{zrnormV1}
\alias{zrnormStl}
\alias{zrnormStlV1}
\alias{zrnormVec}
\alias{zrnormVecV1}
\alias{zrnormgsl}
\alias{zsetseed}
\alias{zsetseedV1}
\alias{zsetseedLZLLV}
\alias{zsetseedMT} 
\alias{zgetseed}
\alias{zgetseedV1}
\title{Collection of Ziggurat Normal RNGs}
\description{
  This package regroups and provides a nummber of implementations of the
  Ziggurat generator for drawing (standard) normally distributed random
  numbers. Ziggurat was introduced by Marsaglia and Tsang (JSS, 2000)
  and improved by Leong, Zhang, et al (JSS, 2005).
}
\usage{
  zrnorm(n)
  zrnormLZLLV(n)
  zrnormMT(n)
  zrnormV1(n)
  zrnormVec(x)
  zrnormVecV1(x)
  zrnormgsl(n)
  zsetseed(s)
  zsetseedV1(s)
  zsetseedLZLLV(s)
  zsetseedMT(s)
  zgetseed()
  zgetseedV1()
}
\arguments{
  \item{n}{An integer determining the length of the returned N(0,1) vector.}
  \item{x}{A numeric vector, already allocated, that is to filled with N(0,1) draws.}
  \item{s}{An integer number used to seed the Ziggurat algorithm.}
}
\value{
  The \code{zrnorm*} functions all return a vector of the requested
  size.

  The \code{zsetseed*} functions do not return a value, but set the seed
  of the generator.

  The \code{zgetseed*} functions return the (integer) seed.
}
\details{
  The \sQuote{MT} variants provide the original Marsaglia and Tsang
  implementation, updated to work in 32 and 64 bit environments. Their
  use is \strong{not} recommended.

  The \sQuote{LZLLV} variants provide the updated Marsaglia and Tsang
  implementation, based on the comment by Leong, Zhang, Luk, Lee and
  Villasenor. These versions should be suitable.  The code has also 
  been updated to work in 32 and 64 bit environments.

  The \sQuote{V1} variants are based on an earlier implementation by
  John Burkardt. While fastest, they also correspond to just the
  Marsaglia and Zhang approach and should \strong{not} be used.

  The function \code{zrnorm()} (and corresponding seed setter
  \code{zsetseed()} and getter \code{zgetseed()}) is the recommended
  implementation based on merging John Burkardt earlier code with the
  Leong et al improvements.  

  The \sQuote{GSL} are using the GNU GSL implementation by Jochen Voss.
  They too can be recommended for use.
}
\references{
  George Marsaglia and Wai Wan Tsang. The Ziggurat Method for Generating Random Variables.
  Journal of Statistical Software, Vol 5, Iss 8, Oct 2000
  \url{http://www.jstatsoft.org/v05/i08}
   
  Philip H W Leong, Ganglie Zhang, Dong-U Lee, Wayne Luk, and John Villasenor.
  A Comment on the Implementation of the Ziggurat method,
  Journal of Statistical Software, Vol 12, Iss 7, Feb 2005
  \url{http://www.jstatsoft.org/v12/i07}

  Website of John Burkardt. \url{http://people.sc.fsu.edu/~jburkardt/}

  Website of Jochen Voss. \url{http://www.seehuhn.de/pages/ziggurat}
}
\seealso{\link{RcppZiggurat-package}}
\author{Dirk Eddelbuettel}
\keyword{package}
\examples{
  set.seed(42)
  system.time(replicate(500, rnorm(10000)))

  zsetseed(42)
  system.time(replicate(500, zrnorm(10000)))
}
