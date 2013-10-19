
## This chisq test is used in the Leong et al paper

library(RcppZiggurat)

N <- 200                                # 200 bins equally spaced from -7 to 7
gr <- seq(-7, 7, length=N+1)            # 201 'borders' defining the grids
d  <- (7 - -7)/N                        # difference between grids

pv <- diff(pnorm(gr))                   # expectect probability in each cell using
                                        # difference in probability distr. at point

draws <- 5e9                            # set to 1e9 or higher for more rigourous tests
#draws <- 1e7
#draws <- 400

op <- options("warn"=-1)
generators <- c("Ziggurat", "MT", "LZLLV", "GSL", "V1", "V1b")
res <- lapply(generators, FUN=function(g) {
    cat("Running ", g, "\n")
    M <- ziggbin(N, draws, g)
    vals <- apply(M, 1, FUN=function(row, pv) {
        z <- chisq.test(row, p=pv)$statistic
    }, pv)
    vals
})
names(res) <- generators
res <- as.data.frame(res)
cat("Actual chisq(", N, ") values\nCritical one-sided 95% value is ", qchisq(0.95, N-1), "\n")
#print(res)

