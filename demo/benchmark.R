
library(rbenchmark)

N <- 1e5
v <- vector(mode="numeric", length=N)

res <- benchmark(zrnormMT(N),       # Marsgalia and Tsang, JSS, 2000
                 zrnormLZLLV(N),    # Leong, Zhang et al, JSS, 2005
                 zrnormV1(N),
                 zrnormVecV1(v),    # fill a pre-supplied vector
                 #zrnormStlV1(N),   # fill STL vector
                 rnorm(N),
                 zrnorm(N),
                 zrnormVec(v),      # fill a pre-supplied vector
                 #zrnormStl(N),     # fill STL vector
                 zrnormgsl(N),
                 replications=1000, order="relative")
print(res[,1:4])
