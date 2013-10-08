
// cf Rcpp Gallery post

#include <Rcpp.h>

// [[Rcpp::depends(BH)]]

#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/random/normal_distribution.hpp>

using namespace std;
using namespace Rcpp;

typedef boost::mt19937 RNGType; 	// select a generator, MT good default

class boostNormal {
public:
    boostNormal(unsigned int seed=123456) : 
	rng(seed), 
	n01(0.0, 1.0), 
	rngNormal(rng, n01) { }
    double norm() {
	return rngNormal(); 
    }
private:
    RNGType rng;
    boost::normal_distribution<> n01;
    boost::variate_generator< RNGType, boost::normal_distribution<> > rngNormal;
};

boostNormal bn;

// [[Rcpp::export]]
NumericVector boostNormals(int n) {
    NumericVector V(n);
    for ( int i = 0; i < n; i++ ) {
        V[i] = bn.norm();
    };     
    return V;
}

// [[Rcpp::export]]
NumericVector boostNormalsOld(int n) {
    
    typedef boost::mt19937 RNGType; 	// select a generator, MT good default
    RNGType rng(123456);			// instantiate and seed

    boost::normal_distribution<> n01(0.0, 1.0);
    boost::variate_generator< RNGType, boost::normal_distribution<> > rngNormal(rng, n01);

    NumericVector V(n);
    for ( int i = 0; i < n; i++ ) {
        V[i] = rngNormal();
    };
  
    return V;
}

// [[Rcpp::plugins(cpp11)]]
#include <random>

using namespace Rcpp;

class c11Normals {
public:
    c11Normals(int seed=42) : engine(seed), normal(0.0, 1.0) {}
    double norm() { return normal(engine); }
private:
    std::mt19937 engine;
    std::normal_distribution<> normal;
};


c11Normals c11N;

// [[Rcpp::export]]
NumericVector cxx11Normals(int n) {
    NumericVector V(n);
    for ( int i = 0; i < n; i++ ) {
        V[i] = c11N.norm();
    };
    return V;
}

// [[Rcpp::export]]
NumericVector sugarNormals(int n) {
    return rnorm(n);
}
