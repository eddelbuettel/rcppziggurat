library(RcppZiggurat)
## this RData file contains the pre-run results
##
##   [1] "chires"   "norres"   "rspeed"   "stdres"   "zigspeed"
##
## from the two speed comparions (ie rspeed and zigspeed) as well the three
## simulation results (ie norres, stdres, and chires)
##
## code for the two speed tests is shown below, the simulations results were run as
##
##   #!/bin/bash
##   Rscript -e 'library(RcppZiggurat); options("mc.cores"=6L); resS <- RcppZiggurat:::standardTest(5e9); saveRDS(resS, "standardTest.rds")' &
##   Rscript -e 'library(RcppZiggurat); options("mc.cores"=6L); resC <- RcppZiggurat:::chisqTest(1e10); saveRDS(resC, "chisqTest.rds")' &
##   Rscript -e 'library(RcppZiggurat); options("mc.cores"=6L); resN <- RcppZiggurat:::normalTest(5e9); saveRDS(resN, "normalTest.rds")' &
##
load("../RcppZiggurat.RData")



library(lattice)
rdf <- as.data.frame(rspeed)
rdf[,1] <- ordered(rdf[,1], levels=c("AH","KR","Inv","BM"), labels=c("AH","KR","Inv","BM"))
pdf("timingR.pdf", 8, 8)
print(bwplot(time/1e6 ~ expr, rdf, ylab="Time in msec", main="Time for 100 times 1e6 normal draws",
             panel=function(...,box.ratio) {
                panel.violin(..., col="lightgray", varwidth=FALSE, box.ratio=box.ratio)
             }))
dev.off()


library(lattice)
#res <- readRDS("~/git/rcppziggurat/vignettes/Zigspeed.rds")
zdf <- as.data.frame(zigspeed)
zdf[,1] <- ordered(zdf[,1],
                   levels=c("Zigg", "ZiggGSL", "ZiggQL", "ZiggGretl", "RInv"),
                   labels=c("Zigg", "ZiggGSL", "ZiggQL", "ZiggGretl", "RInv"))
pdf("timingZiggurat.pdf", 8, 8)
print(bwplot(time/1e6 ~ expr, zdf, ylab="Time in msec",
             main="Time for 100 times 1e6 normal draws",
             panel=function(...,box.ratio) {
                 panel.violin(..., col="lightgray", varwidth=FALSE, box.ratio=box.ratio)
             }))
dev.off()


pdf("standardResults.pdf")
RcppZiggurat:::plotAll(stdres)
dev.off()


pdf("normalResults.pdf")
RcppZiggurat:::plotAll(norres)
dev.off()

pdf("chisquareResults.pdf")
RcppZiggurat:::plotChiSq(chires)
dev.off()
