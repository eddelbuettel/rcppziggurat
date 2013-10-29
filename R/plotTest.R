
plotAll <- function(data) {
    op <- par(mfrow=c(2,3), mar=c(3,3,3,1))
    for (i in seq_len(ncol(data))) {
        plotTest(data[,i], colnames(data)[i])
    }
    par(op)
    invisible(NULL)
}

plotTest <- function(v, g) {
    pks <- ks.test(v, "punif", 0, 1, exact=TRUE)$p.value
    pw <- wilcox.test(v, mu=0.5)$p.value

    plot(ecdf(v), verticals=TRUE, do.p=FALSE,
         main=paste0(g, " pKS: ", round(pks, digits=4), " pWil.: ", round(pw, digits=4)))
    segments(0,0,1,1, col='darkgray', lty="dotted")
    invisible(NULL)
}

plotChiSq <- function(res, bins) {
    cval <- qchisq(0.95, bins-1)
    cat("Critical one-sided 95% value is ", cval, "\n")
    cat("Actual chisq(", bins, ") values\n")
    print(tail(res,1))

    op <- par(mfrow=c(2,3), mar=c(3,3,3,1))
    for (i in seq_len(ncol(res))) {
        plot(res[,i], type='l', ylim=c(0,max(res)), main=colnames(res)[i])
        abline(h=cval, col="darkgrey", lty="dotted")
    }
    par(op)
}
