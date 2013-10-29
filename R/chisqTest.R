
chisqTest <- function(draws=1e5,	# number of (total) draws
                      bins=200,     	# number of equally-spaced bins
                      edge=7, 		# cutoff for binning at +/- edge
                      seed=123456789,
                      res=50,       	# resolution (number of rows until draws)
                      generators=c("Ziggurat", "MT", "LZLLV", "GSL", "V1", "V1b"),
                      showplot=interactive()) {

    gr <- seq(-edge,edge,length=bins+1) # bins+1 'borders' defining the grids
    ##d  <- 2*binedge/bins              # difference between grids (not used)
    pv <- diff(pnorm(gr))               # expectect probability in each cell using
                                        # difference in probability distr. at point
    pv <- pv/sum(pv)			# normalise

    op <- options("warn"=-1)            # suppress warning of chisq ties
    res <- lapply(generators, FUN=function(g) {
        #cat("Running ", g, "\n")
        mat <- ziggbin(bins, draws, g, seed, edge, res)
        vals <- apply(mat, 1, FUN=function(row, pv) {
            z <- chisq.test(row, p=pv)$statistic
        }, pv)
        vals
    })
    options(op)
    names(res) <- generators
    res <- as.data.frame(res)

    if (showplot) {
        plotChiSq(res, bins)
    }

    invisible(res)
}
