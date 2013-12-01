
library(RcppZiggurat)

zsetseed(123456890)
zrnorm(10)

zsetseed(123456890)
summary(zrnorm(1e6))
