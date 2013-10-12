
## This chisq test is used in the Leong et al paper

N <- 200                                # 200 bins equally spaced from -7 to 7
gr <- seq(-7, 7, length=N+1)            # 201 'borders' defining the grids
d  <- (7 - -7)/N                        # difference between grids

pv <- diff(pnorm(gr))                   # expectect probability in each cell using
                                        # difference in probability distr. at point

draws <- 1e7                            # set to 1e9 or higher for more rigourous tests

op <- options("warn"=-1)
generators <- c("Ziggurat", "MT", "LZLLV", "GSL", "V1", "V1b")
res <- sapply(generators, FUN=function(g) {
    cat("Running ", g, "\n")
    v <- ziggbin(N, draws, g)
    tt <- chisq.test(v, p=pv)
    #print(tt)
    tt$statistic
})
names(res) <- generators
cat("Actual chisq(199) values\nCritical one-sided 95% value is ", qchisq(0.95, N-1), "\n")
print(res)

