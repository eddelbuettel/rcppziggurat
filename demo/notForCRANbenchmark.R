
library(rbenchmark)

N <- 1e5
v <- vector(mode="numeric", length=N)

sourceCpp("notForCRANbenchmark.cpp")

res <- benchmark(zrnormMT(N),       # Marsgalia and Tsang, JSS, 2000
                 zrnormLZLLV(N),    # Leong, Zhang et al, JSS, 2005
                 zrnormV1(N),       # based on initial Burkardt implementation
                 zrnormVecV1(v),    # fill a pre-supplied vector
                 #zrnormStlV1(N),   # fill STL vector
                 rnorm(N),          # R as a baseline
                 zrnorm(N),         # based on updated Burkardt implementation
                 zrnormVec(v),      # fill a pre-supplied vector
                 #zrnormStl(N),     # fill STL vector
                 zrnormgsl(N),      # GSL's ziggurat by Voss
                 boostNormals(N),   # Boost -- very slow on 32 bit, still slow on 54
                 cxx11Normals(N),   # C++11 is ok
                 sugarNormals(N),   # Rcpp for comparison
                 replications=1000, order="relative")
print(res[,1:4])
