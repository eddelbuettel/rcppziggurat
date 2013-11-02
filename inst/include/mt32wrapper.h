// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// mt32wrapper.h:  Simple wrapper providing Mersenne Twister via GSL's default 
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

// Simple class to provide the MT interface used here.
// We implement this as passthrough to the GSL default generator.
// We could use the MT from R -- but we cannot set the seed as 
// the API for doing so is blocked.  We could also use Boost (but it
// creates another dependency) or C++11 (but that cannot go onto CRAN)

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

#ifndef RcppZiggurat__MT32wrapper_h
#define RcppZiggurat__MT32wrapper_h

namespace Ziggurat {

    class mt32 {                  
    public:                         
	mt32(uint32_t seed=12345678) {
	    gsl_rng_env_setup() ;
	    r = gsl_rng_alloc (gsl_rng_default);
	    gsl_rng_set(r, seed);
	}
	~mt32() {
	    gsl_rng_free(r);
	}
	void setSeed(const uint32_t seed) {
	    gsl_rng_set(r, seed);
	}
	inline uint32_t int32() const {    // return a random int in [0,0xffffffff]-interval
	    return static_cast<uint32_t>(gsl_ran_flat(r,0.0,4294967296.0));
	}
	inline double int01() const {      // return a random number in the (0.0, 1.0)-interval
	    return gsl_ran_flat(r,0.0,1.0);
	}
    private:
	gsl_rng *r;
    };

}

#endif
