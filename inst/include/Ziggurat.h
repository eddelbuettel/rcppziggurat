// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Ziggurat.h:  Marsaglia + Tsang / Leong, Zhang et al Ziggurat generator
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

// This file is derived from the files provided by John Burkardt at
//    http://people.sc.fsu.edu/~jburkardt/
// In particular, it represent an implementation of the article
//
//    George Marsaglia and Wai Wan Tsang 
//    The Ziggurat Method for Generating Random Variables,
//    Journal of Statistical Software, Vol 5, Iss 8, Oct 2000
//    http://www.jstatsoft.org/v05/i08 
//
// but also the Leong, Zhang et al modifications from the article
//
//    Philip H W Leong, Ganglie Zhang, Dong-U Lee, Wayne Luk, and John Villasenor,
//    A Comment on the Implementation of the Ziggurat method,
//    Journal of Statistical Software, Vol 12, Iss 7, Feb 2005
//    http://www.jstatsoft.org/v12/i07
//
// following emails with John Burckardt and sending him an initial 
// 'Marsaglia and Tsang modified by Leong, Zhang et al' implementation
//
// The code by Burkardt was modified by
// a) reorganising it as a C++ class,
// b) removing the exponential generator
//
// This file represent the Leong, Zhang et al improvement over the
// original Marsaglia and Tsang article and can be recommended for use.

// MarsagliaTsang
// Derived from newer version by John Burkardt
// Does contain Leong et al correction, uses (u)int32_t

#ifndef RcppZiggurat__Ziggurat_h
#define RcppZiggurat__Ziggurat_h

#include <Zigg.h>

namespace Ziggurat {
namespace Ziggurat {

#define znew (z = 36969 * (z & 65535) + ( z >> 16 ))
#define wnew (w = 18000 * (w & 65535) + ( w >> 16 ))
#define MWC  (( znew << 16) + wnew)
#define SHR3 (jz = jsr, jsr ^= (jsr << 13), jsr ^= (jsr >> 17), jsr ^= (jsr << 5), jz + jsr)
#define CONG (jcong = 69069 * jcong + 1234567)
#define KISS ((MWC ^ CONG ) + SHR3)
    
#define UNI  (0.5 + (int32_t) KISS * 0.2328306e-09)
#define IUNI KISS
#define RNOR (hz = KISS, iz = hz & 127, ( abs ( hz ) < kn[iz] ) ? hz * wn[iz] : nfix())

    class Ziggurat : public Zigg {
    public:
        Ziggurat(uint32_t seed=123456789) : jcong(380116160), jsr(123456789), 
                                            w(521288629), z(362436069) {
            init();
            setSeed(seed);
        }
        ~Ziggurat() {};
        void setSeed(const uint32_t s) {
            jsr = 123456789;
            if (jsr != s) {         // avoid setting jsr to 0
                jsr ^= s; 
            }
            z     = 362436069;
            w     = 521288629;
            jcong = 380116160;
        }
        uint32_t getSeed() { 
            return jsr; 
        }
        inline double norm() {
            return RNOR;
        }
        std::vector<uint32_t> getPars() {
            //C++11: std::vector<uint32_t> pars{ jsr, z, w, jcong };
            std::vector<uint32_t> pars;
            pars.push_back(jsr);
            pars.push_back(z);
            pars.push_back(w);
            pars.push_back(jcong);
            return pars; 
        }
        void setPars(std::vector<uint32_t> pars) {
            jsr = pars[0];
            z = pars[1];
            w = pars[2];
            jcong = pars[3];
        }
        
    private:
        double fn[128];
        int32_t hz;
        uint32_t iz;
        uint32_t jcong;
        uint32_t jsr;
        uint32_t jz;
        uint32_t kn[128];
        uint32_t w;
        double wn[128];
        uint32_t z;

        void init() {               // called from ctor, could be in ctor
            double dn = 3.442619855899;
            int i;
            const double m1 = 2147483648.0;
            double q;
            double tn = 3.442619855899;
            const double vn = 9.91256303526217E-03;

            //  Set up the tables for the normal random number generator.
            q = vn / exp (- 0.5 * dn * dn);
            kn[0] = (uint32_t) ((dn / q) * m1);
            kn[1] = 0;

            wn[0]   = (double) (q / m1);
            wn[127] = (double) (dn / m1);
            
            fn[0] = 1.0;
            fn[127] = (double) (exp(- 0.5 * dn * dn));
        
            for (i = 126; 1 <= i; i--) {
                dn = sqrt(- 2.0 * log (vn / dn + exp (- 0.5 * dn * dn)));
                kn[i+1] = (uint32_t ) ((dn / tn ) * m1);
                tn = dn;
                fn[i] = (double) (exp( - 0.5 * dn * dn));
                wn[i] = (double) (dn / m1);
            }
            return;
        }

        //inline float nfix(void) { return wn[34]; }
        inline double nfix(void) {
            const double r = 3.442620;
            double x, y;
            
            for (;;) {
                //  IZ = 0 handles the base strip.
                x = (double) (hz * wn[iz]);
                if ( iz == 0 ) { 
                    do {
                        x = - log (UNI) * 0.2904764; 
                        y = - log (UNI);
                    }
                    while (y + y < x * x);
                    
                    return (0 < hz) ? r + x : - r - x;
                }
                //  0 < IZ, handle the wedges of other strips.
                if ( fn[iz] + UNI * ( fn[iz-1] - fn[iz] ) < exp (- 0.5 * x * x ) ) {
                    return x;
                }
                //  Initiate, try to exit the loop.
                hz = SHR3;      // note we still use SHR3; using KISS leads to degradation
                iz = (hz & 127);
                if (abs(hz) < kn[iz]) {
                    return ((double) (hz * wn[iz]));
                }
            }
        }
    };

#undef znew
#undef wnew
#undef MWC
#undef SHR3
#undef CONG
#undef KISS

#undef UNI
#undef IUNI
#undef RNOR

}
}

#endif
