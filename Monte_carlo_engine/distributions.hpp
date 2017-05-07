#ifndef distributions_hpp
#define distributions_hpp

#include <stdio.h>
#include "vectors.hpp"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/math/distributions/normal.hpp>

typedef Rvec<double> vec;
typedef Rvec<Rvec<double> > matrix;

class distribution
{
protected:
    double mean;
    double variance;
public:
    distribution(){};
    distribution(double mean_,double variance_);
    virtual vec gen_ran_vec(const unsigned long size) = 0;
    virtual double operator()(double x) = 0;
    virtual matrix gen_ran_stratified_mat(const unsigned long totalsamplesize, const unsigned long numberofstrats) = 0;
    virtual ~distribution();
};

class uniform_distribution : public distribution
{
public:
    uniform_distribution(){};
    virtual vec gen_ran_vec(const unsigned long size);
    virtual double operator()(double x);
    virtual matrix gen_ran_stratified_mat(const unsigned long totalsamplesize, const unsigned long numberofstrats);
    virtual ~uniform_distribution();
};

class normal_distribution : public distribution
{
public:
    normal_distribution(){};
    normal_distribution(double mean_,double variance_);
    virtual vec gen_ran_vec(const unsigned long size);
    virtual double operator()(double x);
    virtual matrix gen_ran_stratified_mat(const unsigned long totalsamplesize, const unsigned long numberofstrats);
    virtual ~normal_distribution();

};

#endif /* distributions_hpp */
