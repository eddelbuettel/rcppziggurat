
## This follows the approach in (R)DieHarder which does
##   take N draws from the N(0,1) we test here
##   convert into U(0,1) by using the inverse of the normal
##   repeat M times
##   and for large enough N, then the sum of all N draws goes to
##       mean   --> N/2
##       stddev --> sqrt(N/12)
##   which is known as the Irwin-Hall distribution
##   then for each of these M values use the inverse of normal to obtain a p-value
##   that p value should be uniformly distributed across these M draws
##   so use Kuiper's K/S test variant to test for uniform U(0,1)

library(RcppZiggurat)

N <- 1e6                                # individual draws
M <- 1e2                                # repeats
seed <- 42

res <- vector(mode="numeric", length=M)

generators <- c("Ziggurat", "MT", "LZLLV", "GSL", "V1", "V1b")
res <- lapply(generators, FUN=function(g, seed) {
    cat("Running ", g, "\n")
    res <- ziggtest(M, N, g, seed)

    v <- pnorm(res, mean=N/2, sd=sqrt(N/12))

    pks <- ks.test(v, "punif", 0, 1, exact=TRUE)$p.value
    pw <- wilcox.test(v, mu=0.5)$p.value

    plot(ecdf(v), verticals=TRUE, do.p=FALSE,
         main=paste0(g, " pKS: ", round(pks, digits=4), " pWil.: ", round(pw, digits=4)))

    segments(0,0,1,1, col='darkgray', lty="dotted")

    v
}, seed)
names(res) <- generators
res <- as.data.frame(res)


