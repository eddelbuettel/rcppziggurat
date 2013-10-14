
## This modifies the approach in (R)DieHarder which does
##   take N draws from a U(0,1)
##   repeat M times a
##   and for large enough N, then the sum of all N draws goes to
##       mean   --> N/2
##       stddev --> sqrt(N/12)
##   which is known as the Irwin-Hall distribution
##   the for each of the M values we can use the inverse of the normal to a p-value
##   that p value should be uniformly distributed across these M draws
##   so use Kuiper's K/S test variant
##
## Here we don;t need Irwin-Hall: the sum of N vars drawn as N(0,1) will be N(0,sqrt(N))
## So we compute a p value from that and assemple M such p values

N <- 1e7                                # individual draws
M <- 1e2                                # repeats

res <- vector(mode="numeric", length=M)

generators <- c("Ziggurat", "MT", "LZLLV", "GSL", "V1", "V1b")
res <- sapply(generators, FUN=function(g) {
    cat("Running ", g, "\n")
    for (i in 1:M) {
        res[i] <- sum(zrnorm(N))
    }
    v <- pnorm(res, sd=sqrt(N))

    pks <- ks.test(v, "punif", 0, 1, exact=TRUE)$p.value

    plot(ecdf(v), verticals=TRUE, do.p=FALSE, main=paste(g, ":", round(pks, digits=4)))
    segments(0,0,1,1, col='darkgray', lty="dotted")

    pks
})
names(res) <- generators

