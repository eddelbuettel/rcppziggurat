// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppGSL.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// zrnormMT
Rcpp::NumericVector zrnormMT(int n);
RcppExport SEXP _RcppZiggurat_zrnormMT(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormMT(n));
    return rcpp_result_gen;
END_RCPP
}
// zsetseedMT
void zsetseedMT(int s);
RcppExport SEXP _RcppZiggurat_zsetseedMT(SEXP sSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type s(sSEXP);
    zsetseedMT(s);
    return R_NilValue;
END_RCPP
}
// zrnormLZLLV
Rcpp::NumericVector zrnormLZLLV(int n);
RcppExport SEXP _RcppZiggurat_zrnormLZLLV(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormLZLLV(n));
    return rcpp_result_gen;
END_RCPP
}
// zsetseedLZLLV
void zsetseedLZLLV(int s);
RcppExport SEXP _RcppZiggurat_zsetseedLZLLV(SEXP sSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type s(sSEXP);
    zsetseedLZLLV(s);
    return R_NilValue;
END_RCPP
}
// zrnormV1
Rcpp::NumericVector zrnormV1(int n);
RcppExport SEXP _RcppZiggurat_zrnormV1(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormV1(n));
    return rcpp_result_gen;
END_RCPP
}
// zrnormVecV1
Rcpp::NumericVector zrnormVecV1(Rcpp::NumericVector x);
RcppExport SEXP _RcppZiggurat_zrnormVecV1(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormVecV1(x));
    return rcpp_result_gen;
END_RCPP
}
// zrnormStlV1
std::vector<double> zrnormStlV1(int n);
RcppExport SEXP _RcppZiggurat_zrnormStlV1(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormStlV1(n));
    return rcpp_result_gen;
END_RCPP
}
// zsetseedV1
void zsetseedV1(unsigned long int s);
RcppExport SEXP _RcppZiggurat_zsetseedV1(SEXP sSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned long int >::type s(sSEXP);
    zsetseedV1(s);
    return R_NilValue;
END_RCPP
}
// zgetseedV1
unsigned long int zgetseedV1();
RcppExport SEXP _RcppZiggurat_zgetseedV1() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(zgetseedV1());
    return rcpp_result_gen;
END_RCPP
}
// zrnorm
Rcpp::NumericVector zrnorm(int n);
RcppExport SEXP _RcppZiggurat_zrnorm(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnorm(n));
    return rcpp_result_gen;
END_RCPP
}
// zrexp
Rcpp::NumericVector zrexp(int n);
RcppExport SEXP _RcppZiggurat_zrexp(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrexp(n));
    return rcpp_result_gen;
END_RCPP
}
// zruni
Rcpp::NumericVector zruni(int n);
RcppExport SEXP _RcppZiggurat_zruni(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zruni(n));
    return rcpp_result_gen;
END_RCPP
}
// zrnormVec
Rcpp::NumericVector zrnormVec(Rcpp::NumericVector x);
RcppExport SEXP _RcppZiggurat_zrnormVec(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormVec(x));
    return rcpp_result_gen;
END_RCPP
}
// zrnormStl
std::vector<double> zrnormStl(int n);
RcppExport SEXP _RcppZiggurat_zrnormStl(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormStl(n));
    return rcpp_result_gen;
END_RCPP
}
// zsetseed
void zsetseed(unsigned long int s);
RcppExport SEXP _RcppZiggurat_zsetseed(SEXP sSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned long int >::type s(sSEXP);
    zsetseed(s);
    return R_NilValue;
END_RCPP
}
// zgetseed
unsigned long int zgetseed();
RcppExport SEXP _RcppZiggurat_zgetseed() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(zgetseed());
    return rcpp_result_gen;
END_RCPP
}
// zgetpars
Rcpp::NumericVector zgetpars();
RcppExport SEXP _RcppZiggurat_zgetpars() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(zgetpars());
    return rcpp_result_gen;
END_RCPP
}
// zsetpars
void zsetpars(Rcpp::NumericVector p);
RcppExport SEXP _RcppZiggurat_zsetpars(SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type p(pSEXP);
    zsetpars(p);
    return R_NilValue;
END_RCPP
}
// zsetseedGSL
void zsetseedGSL(const uint32_t s);
RcppExport SEXP _RcppZiggurat_zsetseedGSL(SEXP sSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const uint32_t >::type s(sSEXP);
    zsetseedGSL(s);
    return R_NilValue;
END_RCPP
}
// zrnormGSL
Rcpp::NumericVector zrnormGSL(int n);
RcppExport SEXP _RcppZiggurat_zrnormGSL(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormGSL(n));
    return rcpp_result_gen;
END_RCPP
}
// zrnormV1b
Rcpp::NumericVector zrnormV1b(int n);
RcppExport SEXP _RcppZiggurat_zrnormV1b(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormV1b(n));
    return rcpp_result_gen;
END_RCPP
}
// zrnormQL
Rcpp::NumericVector zrnormQL(int n);
RcppExport SEXP _RcppZiggurat_zrnormQL(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormQL(n));
    return rcpp_result_gen;
END_RCPP
}
// zsetseedQL
void zsetseedQL(unsigned long int s);
RcppExport SEXP _RcppZiggurat_zsetseedQL(SEXP sSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned long int >::type s(sSEXP);
    zsetseedQL(s);
    return R_NilValue;
END_RCPP
}
// zrnormGl
Rcpp::NumericVector zrnormGl(int n);
RcppExport SEXP _RcppZiggurat_zrnormGl(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormGl(n));
    return rcpp_result_gen;
END_RCPP
}
// zsetseedGl
void zsetseedGl(unsigned long int s);
RcppExport SEXP _RcppZiggurat_zsetseedGl(SEXP sSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned long int >::type s(sSEXP);
    zsetseedGl(s);
    return R_NilValue;
END_RCPP
}
// zrnormR
Rcpp::NumericVector zrnormR(int n);
RcppExport SEXP _RcppZiggurat_zrnormR(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(zrnormR(n));
    return rcpp_result_gen;
END_RCPP
}
// ziggbin
Rcpp::NumericMatrix ziggbin(int nbins, double ndraws, const std::string generator, const int seed, int edge, int res);
RcppExport SEXP _RcppZiggurat_ziggbin(SEXP nbinsSEXP, SEXP ndrawsSEXP, SEXP generatorSEXP, SEXP seedSEXP, SEXP edgeSEXP, SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type nbins(nbinsSEXP);
    Rcpp::traits::input_parameter< double >::type ndraws(ndrawsSEXP);
    Rcpp::traits::input_parameter< const std::string >::type generator(generatorSEXP);
    Rcpp::traits::input_parameter< const int >::type seed(seedSEXP);
    Rcpp::traits::input_parameter< int >::type edge(edgeSEXP);
    Rcpp::traits::input_parameter< int >::type res(resSEXP);
    rcpp_result_gen = Rcpp::wrap(ziggbin(nbins, ndraws, generator, seed, edge, res));
    return rcpp_result_gen;
END_RCPP
}
// ziggsum
Rcpp::NumericVector ziggsum(int nbins, double ndraws, const std::string generator, const int seed);
RcppExport SEXP _RcppZiggurat_ziggsum(SEXP nbinsSEXP, SEXP ndrawsSEXP, SEXP generatorSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type nbins(nbinsSEXP);
    Rcpp::traits::input_parameter< double >::type ndraws(ndrawsSEXP);
    Rcpp::traits::input_parameter< const std::string >::type generator(generatorSEXP);
    Rcpp::traits::input_parameter< const int >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(ziggsum(nbins, ndraws, generator, seed));
    return rcpp_result_gen;
END_RCPP
}
// ziggtest
Rcpp::NumericVector ziggtest(int nbins, double ndraws, const std::string generator, const int seed);
RcppExport SEXP _RcppZiggurat_ziggtest(SEXP nbinsSEXP, SEXP ndrawsSEXP, SEXP generatorSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type nbins(nbinsSEXP);
    Rcpp::traits::input_parameter< double >::type ndraws(ndrawsSEXP);
    Rcpp::traits::input_parameter< const std::string >::type generator(generatorSEXP);
    Rcpp::traits::input_parameter< const int >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(ziggtest(nbins, ndraws, generator, seed));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_RcppZiggurat_zrnormMT", (DL_FUNC) &_RcppZiggurat_zrnormMT, 1},
    {"_RcppZiggurat_zsetseedMT", (DL_FUNC) &_RcppZiggurat_zsetseedMT, 1},
    {"_RcppZiggurat_zrnormLZLLV", (DL_FUNC) &_RcppZiggurat_zrnormLZLLV, 1},
    {"_RcppZiggurat_zsetseedLZLLV", (DL_FUNC) &_RcppZiggurat_zsetseedLZLLV, 1},
    {"_RcppZiggurat_zrnormV1", (DL_FUNC) &_RcppZiggurat_zrnormV1, 1},
    {"_RcppZiggurat_zrnormVecV1", (DL_FUNC) &_RcppZiggurat_zrnormVecV1, 1},
    {"_RcppZiggurat_zrnormStlV1", (DL_FUNC) &_RcppZiggurat_zrnormStlV1, 1},
    {"_RcppZiggurat_zsetseedV1", (DL_FUNC) &_RcppZiggurat_zsetseedV1, 1},
    {"_RcppZiggurat_zgetseedV1", (DL_FUNC) &_RcppZiggurat_zgetseedV1, 0},
    {"_RcppZiggurat_zrnorm", (DL_FUNC) &_RcppZiggurat_zrnorm, 1},
    {"_RcppZiggurat_zrexp", (DL_FUNC) &_RcppZiggurat_zrexp, 1},
    {"_RcppZiggurat_zruni", (DL_FUNC) &_RcppZiggurat_zruni, 1},
    {"_RcppZiggurat_zrnormVec", (DL_FUNC) &_RcppZiggurat_zrnormVec, 1},
    {"_RcppZiggurat_zrnormStl", (DL_FUNC) &_RcppZiggurat_zrnormStl, 1},
    {"_RcppZiggurat_zsetseed", (DL_FUNC) &_RcppZiggurat_zsetseed, 1},
    {"_RcppZiggurat_zgetseed", (DL_FUNC) &_RcppZiggurat_zgetseed, 0},
    {"_RcppZiggurat_zgetpars", (DL_FUNC) &_RcppZiggurat_zgetpars, 0},
    {"_RcppZiggurat_zsetpars", (DL_FUNC) &_RcppZiggurat_zsetpars, 1},
    {"_RcppZiggurat_zsetseedGSL", (DL_FUNC) &_RcppZiggurat_zsetseedGSL, 1},
    {"_RcppZiggurat_zrnormGSL", (DL_FUNC) &_RcppZiggurat_zrnormGSL, 1},
    {"_RcppZiggurat_zrnormV1b", (DL_FUNC) &_RcppZiggurat_zrnormV1b, 1},
    {"_RcppZiggurat_zrnormQL", (DL_FUNC) &_RcppZiggurat_zrnormQL, 1},
    {"_RcppZiggurat_zsetseedQL", (DL_FUNC) &_RcppZiggurat_zsetseedQL, 1},
    {"_RcppZiggurat_zrnormGl", (DL_FUNC) &_RcppZiggurat_zrnormGl, 1},
    {"_RcppZiggurat_zsetseedGl", (DL_FUNC) &_RcppZiggurat_zsetseedGl, 1},
    {"_RcppZiggurat_zrnormR", (DL_FUNC) &_RcppZiggurat_zrnormR, 1},
    {"_RcppZiggurat_ziggbin", (DL_FUNC) &_RcppZiggurat_ziggbin, 6},
    {"_RcppZiggurat_ziggsum", (DL_FUNC) &_RcppZiggurat_ziggsum, 4},
    {"_RcppZiggurat_ziggtest", (DL_FUNC) &_RcppZiggurat_ziggtest, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_RcppZiggurat(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
