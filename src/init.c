#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .Call calls */
extern SEXP _RcppZiggurat_zrnormMT(SEXP);
extern SEXP _RcppZiggurat_zsetseedMT(SEXP);
extern SEXP _RcppZiggurat_zrnormLZLLV(SEXP);
extern SEXP _RcppZiggurat_zsetseedLZLLV(SEXP);
extern SEXP _RcppZiggurat_zrnormV1(SEXP);
extern SEXP _RcppZiggurat_zrnormVecV1(SEXP);
extern SEXP _RcppZiggurat_zrnormStlV1(SEXP);
extern SEXP _RcppZiggurat_zsetseedV1(SEXP);
extern SEXP _RcppZiggurat_zgetseedV1(SEXP);
extern SEXP _RcppZiggurat_zrnorm(SEXP);
extern SEXP _RcppZiggurat_zrnormVec(SEXP);
extern SEXP _RcppZiggurat_zrnormStl(SEXP);
extern SEXP _RcppZiggurat_zsetseed(SEXP);
extern SEXP _RcppZiggurat_zgetseed(SEXP);
extern SEXP _RcppZiggurat_zrnormGSL(SEXP);
extern SEXP _RcppZiggurat_zsetseedGSL(SEXP);
extern SEXP _RcppZiggurat_zrnormV1b(SEXP);
extern SEXP _RcppZiggurat_zrnormQL(SEXP);
extern SEXP _RcppZiggurat_zsetseedQL(SEXP);
extern SEXP _RcppZiggurat_zrnormGl(SEXP);
extern SEXP _RcppZiggurat_zsetseedGl(SEXP);
extern SEXP _RcppZiggurat_zrnormR(SEXP);
extern SEXP _RcppZiggurat_ziggbin(SEXP);
extern SEXP _RcppZiggurat_ziggsum(SEXP);
extern SEXP _RcppZiggurat_ziggtest(SEXP);

static const R_CMethodDef CEntries[] = {
    {"user_norm_rand", (DL_FUNC) &user_norm_rand, 0, NULL},
    {NULL, NULL, 0, NULL}
};

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
    {"_RcppZiggurat_zrnormVec", (DL_FUNC) &_RcppZiggurat_zrnormVec, 1},
    {"_RcppZiggurat_zrnormStl", (DL_FUNC) &_RcppZiggurat_zrnormStl, 1},
    {"_RcppZiggurat_zsetseed", (DL_FUNC) &_RcppZiggurat_zsetseed, 1},
    {"_RcppZiggurat_zgetseed", (DL_FUNC) &_RcppZiggurat_zgetseed, 0},
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

void R_init_RcppZiggurat(DllInfo *dll) {
    R_registerRoutines(dll, CEntries, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
