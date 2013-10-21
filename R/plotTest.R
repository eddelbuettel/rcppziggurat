
plotTest <- function(v, g) {
    pks <- ks.test(v, "punif", 0, 1, exact=TRUE)$p.value
    pw <- wilcox.test(v, mu=0.5)$p.value

    plot(ecdf(v), verticals=TRUE, do.p=FALSE,
         main=paste0(g, " pKS: ", round(pks, digits=4), " pWil.: ", round(pw, digits=4)))
    segments(0,0,1,1, col='darkgray', lty="dotted")
}
