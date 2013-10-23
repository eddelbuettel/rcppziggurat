
## This chisq test is used in the Leong et al paper

library(RcppZiggurat)

bins <- 200
chires <- RcppZiggurat:::chisqTest(draws=1e8,          # individual draws
                                   bins=bins,          # repeats pre draw
                                   edge=7,             # cutoff for binning at +/- edge
                                   seed=123456789,
                                   res=50,             # resolution (number of rows until draws)
                                   generators=c("Ziggurat", "MT", "LZLLV", "GSL", "V1", "V1b"))

cval <- qchisq(0.95, bins-1)
cat("Critical one-sided 95% value is ", cval, "\n")
cat("Actual chisq(", bins, ") values\n")
print(tail(chires,1))

op <- par(mfrow=c(2,3), mar=c(3,3,3,1))
for (i in seq_len(ncol(res))) {
    plot(chires[,i], type='l', ylim=c(0,max(chires)), main=colnames(chires)[i])
    abline(h=cval, col="darkgrey", lty="dotted")
}
par(op)
