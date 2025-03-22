
library(RcppZiggurat)

zsetseed(123456890)
print(zrnorm(10), digits=5)

zsetseed(123456890)
print(zrnorm(10), digits=5)

zsetseed(123456890)
print(summary(zrnorm(1e6)), digits=5)
