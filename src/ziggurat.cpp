// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// ziggurat.cpp: R wrapper for various Ziggurat implementations in RcppZiggurat
//
// Copyright (C) 2013  Dirk Eddelbuettel
//
// This file is part of RcppZiggurat.
//
// RcppZiggurat is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// RcppZiggurat is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RcppZiggurat.  If not, see <http://www.gnu.org/licenses/>.

// trying a simple Ziggurat class based (initially) on John Burkardt's code
// Burkhardt implements the original paper  http://www.jstatsoft.org/v05/i08/paper
// but (initially) NOT the comment paper    http://www.jstatsoft.org/v12/i07/paper
// following email with Burkhard has modified
#include <Rcpp.h>

#include <ZigguratMT.h>     
#include <ZigguratLZLLV.h>     
#include <ZigguratV1.h>     
#include <ZigguratV1b.h>     
#include <Ziggurat.h>  
#include <ZigguratGSL.h>
#include <ZigguratQL.h>
#include <ZigguratGretl.h>
#include <ZigguratR.h>


// Version 1 -- Derived from Marsaglia and Tsang, JSS, 2000
static Ziggurat::MT::ZigguratMT ziggmt;

// Marsaglia and Tsang (JSS,2000)
// [[Rcpp::export]]
Rcpp::NumericVector zrnormMT(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = ziggmt.norm();
    }
    return x;
}
// [[Rcpp::export]]
void zsetseedMT(int s) {
    ziggmt.setSeed(s);
}



// Version 2 -- Derived from Leong et al, JSS, 2005
static Ziggurat::LZLLV::ZigguratLZLLV zigglzllv;

// Marsaglia and Tsang (JSS,2000)
// [[Rcpp::export]]
Rcpp::NumericVector zrnormLZLLV(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = zigglzllv.norm();
    }
    return x;
}
// [[Rcpp::export]]
void zsetseedLZLLV(int s) {
    zigglzllv.setSeed(s);
}



// Version 3 -- Derived from John Burkardt's older implementation
static Ziggurat::V1::ZigguratV1 ziggv1;

// [[Rcpp::export]]
Rcpp::NumericVector zrnormV1(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = ziggv1.norm();
    }
    return x;
}

// [[Rcpp::export]]
Rcpp::NumericVector zrnormVecV1(Rcpp::NumericVector x) {
    int n = x.size();
    for (int i=0; i<n; i++) {
        x[i] = ziggv1.norm();
    }
    return x;
}

// [[Rcpp::export]]
std::vector<double> zrnormStlV1(int n) {
    std::vector<double> x(n);
    for (int i=0; i<n; i++) {
        x[i] = ziggv1.norm();
    }
    return x;
}

// [[Rcpp::export]]
void zsetseedV1(unsigned long int s) {
    ziggv1.setSeed(s);
    return;
}

// [[Rcpp::export]]
unsigned long int zgetseedV1() {
    return ziggv1.getSeed();
}




// Version 4 -- Derived from John Burkardt's new implementation of our mods
static Ziggurat::Ziggurat::Ziggurat zigg;

// [[Rcpp::export]]
Rcpp::NumericVector zrnorm(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = zigg.norm();
    }
    return x;
}

// [[Rcpp::export]]
Rcpp::NumericVector zrnormVec(Rcpp::NumericVector x) {
    int n = x.size();
    for (int i=0; i<n; i++) {
        x[i] = zigg.norm();
    }
    return x;
}

// [[Rcpp::export]]
std::vector<double> zrnormStl(int n) {
    std::vector<double> x(n);
    for (int i=0; i<n; i++) {
        x[i] = zigg.norm();
    }
    return x;
}

// [[Rcpp::export]]
void zsetseed(unsigned long int s) {
    zigg.setSeed(s);
    return;
}

// [[Rcpp::export]]
unsigned long int zgetseed() {
    return zigg.getSeed();
}

// [[Rcpp::export]]
Rcpp::NumericVector zgetpars() {
    return Rcpp::wrap(zigg.getPars());
}

// [[Rcpp::export]]
void zsetpars(Rcpp::NumericVector p) {
    std::vector<uint32_t> pars;
    for (int i = 0; i < 4; i++) {
        uint32_t par_i = static_cast<uint32_t>(p[i]);
        pars.push_back(par_i);
    }
    zigg.setPars(pars);
    return;
}

// Version 5 -- Wrapping the GSL version
static Ziggurat::GSL::ZigguratGSL gsl;

// [[Rcpp::export]]
void zsetseedGSL(const uint32_t s) {
    gsl.setSeed(s);
    return;
}

// [[Rcpp::export]]
Rcpp::NumericVector zrnormGSL(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = gsl.norm();
    }
    return x;
}


// Version 6 -- Modified V1
static Ziggurat::V1::ZigguratV1b ziggv1b;

// [[Rcpp::export]]
Rcpp::NumericVector zrnormV1b(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = ziggv1b.norm();
    }
    return x;
}

// Version 7 -- QuantLib
static Ziggurat::QL::ZigguratQL ziggql;

// [[Rcpp::export]]
Rcpp::NumericVector zrnormQL(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = ziggql.norm();
    }
    return x;
}

// [[Rcpp::export]]
void zsetseedQL(unsigned long int s) {
    ziggql.setSeed(s);
    return;
}

// Version 8 -- Gretl
static Ziggurat::Gretl::ZigguratGretl zigggl;

// [[Rcpp::export]]
Rcpp::NumericVector zrnormGl(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = zigggl.norm();
    }
    return x;
}

// [[Rcpp::export]]
void zsetseedGl(unsigned long int s) {
    zigggl.setSeed(s);
    return;
}


// Version 9 -- Ziggurat with R's unif. generator
static Ziggurat::R::ZigguratR ziggr;

// [[Rcpp::export]]
Rcpp::NumericVector zrnormR(int n) {
    Rcpp::NumericVector x(n);
    for (int i=0; i<n; i++) {
        x[i] = ziggr.norm();
    }
    return x;
}

// no zsetseedR() as we use set.seed() to seed R's uniform

// see help(RNGind) and help(Random.user) in R
static double x_;
extern "C" double *user_norm_rand() {
    x_ = ziggr.norm();
    return &x_;
}




Ziggurat::Zigg* getZiggurat(const std::string generator, const int seed) {
    if (generator=="MT") {
        return new Ziggurat::MT::ZigguratMT(seed); 
    } else if (generator=="LZLLV") {
        return new Ziggurat::LZLLV::ZigguratLZLLV(seed); 
    } else if (generator=="V1") {
        return new Ziggurat::V1::ZigguratV1(seed); 
    } else if (generator=="Ziggurat") {
        return new Ziggurat::Ziggurat::Ziggurat(seed); 
    } else if (generator=="GSL") {
        return new Ziggurat::GSL::ZigguratGSL(seed); 
    } else if (generator=="V1b") {
        return new Ziggurat::V1::ZigguratV1b(seed); 
    } else if (generator=="QL") {
        return new Ziggurat::QL::ZigguratQL(seed); 
    } else if (generator=="Gretl") {
        return new Ziggurat::Gretl::ZigguratGretl(seed); 
    } 

    Rcpp::Rcout << "Unrecognised generator: " << generator << "\n";
    return NULL;
}

// [[Rcpp::export]]
Rcpp::NumericMatrix ziggbin(int nbins, double ndraws, 
                            const std::string generator = "Ziggurat", 
                            const int seed=42, int edge = 7, int res = 40) {
    Rcpp::NumericMatrix v(res, nbins);
    const double grmin = -edge;
    const double grmax = edge;
    const double d = (grmax - grmin)/static_cast<double>(nbins);

    Ziggurat::Zigg *zigg = getZiggurat(generator, seed);

    double seglen = static_cast<double>(ndraws)/static_cast<double>(res);

    // Yes, it crazy to write the inner loop with doubles. But the CRAN maintainers
    // still say that we cannot use C99 or C++0x -- so no long long int for us.
    // And an unsigned long makes it only to 4.2e9 which is not enough for our use.
    for (int row=0; row<res; row++) {
        double i = 0.0;
        while (i < seglen) {
            double val = zigg->norm();              // N(0,1) draw 
            
            int can = floor((val - grmin)/d);       // find the 'can' to bin it in
            can = (can < 0) ? 0 : can;              // protect can from being below 0
            can = (can > nbins-1) ? nbins-1 : can;  // or past the last can
            v(row,can) = v(row,can) + 1.0;          // increment counter
            i = i + 1.0;
        }
        if (row < res-1) {
            v(row+1,Rcpp::_) = v(row,Rcpp::_);
        }
    }

    delete zigg;

    return v;
}



// [[Rcpp::export]]
Rcpp::NumericVector ziggsum(int nbins, double ndraws, 
                            const std::string generator = "Ziggurat", 
                            const int seed=42) {
    Rcpp::NumericVector vec(nbins);
    
    Ziggurat::Zigg *zigg = getZiggurat(generator, seed);

    for (int i=0; i<nbins; i++) {
        double sum = 0.0;
        double j = 0.0;
        while (j < ndraws) {
            sum = sum + zigg->norm();
            j = j + 1.0;
        }
        vec[i] = sum;
    }

    delete zigg;

    return vec;
}

// [[Rcpp::export]]
Rcpp::NumericVector ziggtest(int nbins, double ndraws, 
                             const std::string generator = "Ziggurat", 
                             const int seed=42) {
    Rcpp::NumericVector vec(nbins);
    
    Ziggurat::Zigg *zigg = getZiggurat(generator, seed);

    for (int i=0; i<nbins; i++) {
        double sum = 0.0;
        double j = 0.0;
        while (j < ndraws) {
            sum = sum + R::pnorm(zigg->norm(),0.0,1.0,0,0);
            j = j + 1.0;
        }
        vec[i] = sum;
    }

    delete zigg;

    return vec;
}

