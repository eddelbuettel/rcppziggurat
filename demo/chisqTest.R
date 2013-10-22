
## This chisq test is used in the Leong et al paper

library(RcppZiggurat)

bins <- 200
res <- chisqTest(draws=1e8,    		# individual draws
                 bins=bins,  		# repeats pre draw
                 edge=7, 		# cutoff for binning at +/- edge
                 seed=123456789,
                 res=50,       	# resolution (number of rows until draws)
                 generators=c("Ziggurat", "MT", "LZLLV", "GSL", "V1", "V1b"))

cval <- qchisq(0.95, bins-1)
cat("Actual chisq(", bins, ") values\n")
cat("Critical one-sided 95% value is ", cval, "\n")
print(tail(res,1))

matplot(res, type='l')
abline(h=cval, col="darkgrey", lty="dotted")
