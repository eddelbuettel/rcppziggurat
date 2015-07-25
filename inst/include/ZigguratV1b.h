// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// ZigguratV1b.h:  Marsaglia and Tsang Ziggurat generator first implementation 
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
// but not the Leong, Zhang et al modifications.
//
// The code by Burkardt was modified by
// a) reorganising it as a C++ class,
// b) switching from use of (unsigned) long variable (which implied 32 bit
//    at the time) to use of (u)int32_t from the stdint.h header file
// c) removing the exponential generator
// d) switching kn[] back to uint32_t
//
// Per the article of Leong, Zhang et al (see file ZigguratLZLLV.h
// here), this generator based on the original Marsaglia and Tsang
// article should NOT be used as originally published.
//
// This implementation serves primarily for comparison.  

// MarsagliaTsang
// Derived from an older version by John Burkardt
// Does not contain Leong et al correction
// Does contain (u)int32_t use

#ifndef RcppZiggurat__ZigguratV1b_h
#define RcppZiggurat__ZigguratV1b_h

#include <Zigg.h>

namespace Ziggurat {
namespace V1 {

    class ZigguratV1b : public Zigg {
    public:
        ZigguratV1b(uint32_t seed=12345678) {
            setSeed(seed);
            init();
        }
        ~ZigguratV1b() {};
        void setSeed(const uint32_t s) { jsr=s; }
        uint32_t getSeed() { return jsr; }
        double norm(void) {
            int hz, iz;
            const double r = 3.442620;
            double value, x, y;
        
            hz = shr3();
            iz = (hz & 127);
        
            if (abs(hz) < kn[iz]) {
                value = (double) (hz) * wn[iz];
            } else {
                for (;;) {
                    if (iz == 0) {
                        for (;;) {
                            x = - 0.2904764 * log(r4_uni());
                            y = - log(r4_uni());
                            if (x * x <= y + y) {
                                break;
                            }
                        }
                    
                        if (hz <= 0) {
                            value = - r - x;
                        } else {
                            value = + r + x;
                        }
                        break;
                    }
                    x = (double) ( hz ) * wn[iz];
                    if (fn[iz] + r4_uni() * (fn[iz-1] - fn[iz]) < exp (- 0.5 * x * x )) {
                        value = x;
                        break;
                    }
                
                    hz = shr3();
                    iz = (hz & 127);
                
                    if (abs(hz) < kn[iz]) {
                        value = (double) (hz) * wn[iz];
                        break;
                    }
                }
            }
            return value;
        }

    private:
        uint32_t kn[128];
        double fn[128], wn[128];
        uint32_t jsr;

        uint32_t shr3() {
            uint32_t value;

            value = jsr;

            jsr = ( jsr ^ ( jsr <<   13 ) );
            jsr = ( jsr ^ ( jsr >>   17 ) );
            jsr = ( jsr ^ ( jsr <<    5 ) );

            value = value + jsr;

            return value;
        }

        double r4_uni() {

            uint32_t jsr_input;
            double value;

            jsr_input = jsr;

            jsr = ( jsr ^ ( jsr <<   13 ) );
            jsr = ( jsr ^ ( jsr >>   17 ) );
            jsr = ( jsr ^ ( jsr <<    5 ) );

            value = fmod ( 0.5 + ( double ) ( jsr_input + jsr ) / 65536.0 / 65536.0, 1.0 );

            return value;
        }

        void init() {               // called from ctor, could be in ctor
            double dn = 3.442619855899;
            int i;
            const double m1 = 2147483648.0;
            double q;
            double tn = 3.442619855899;
            const double vn = 9.91256303526217E-03;

            q = vn / exp (- 0.5 * dn * dn);
        
            kn[0] = (uint32_t) ((dn / q) * m1);
            kn[1] = 0;

            wn[0] = (double) (q / m1);
            wn[127] = (double) (dn / m1);

            fn[0] = 1.0;
            fn[127] = (double) (exp (- 0.5 * dn * dn));
        
            for (i = 126; 1 <= i; i--) {
                dn = sqrt(- 2.0 * log (vn / dn + exp(- 0.5 * dn * dn)));
                kn[i+1] = (uint32_t) ((dn / tn) * m1);
                tn = dn;
                fn[i] = (double) (exp (- 0.5 * dn * dn));
                wn[i] = (double) (dn / m1);
            }
            return;
        }
    };

}
}

#endif
