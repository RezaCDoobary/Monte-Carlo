#ifndef MC_base_hpp
#define MC_base_hpp

#include <stdio.h>
#include <vector>
#include "vectors.hpp"
#include "distributions.hpp"
#include "random.hpp"

typedef double(*function)(double);
typedef Rvec<double> vec;
typedef Rvec<Rvec<double> > matrix;
typedef std::auto_ptr<distribution> dist_ptr;

class MC
{
protected:
    vec RV;
    dist_ptr p;
    unsigned long size;
public:
    MC(){};
    MC(dist_ptr p_, unsigned long size_);
    vec getRV();
    void setRV(vec V);
    dist_ptr getdist_ptr();
    void setdist_ptr(dist_ptr q);
    unsigned long getsize();
    virtual vec operator()(function f) = 0;
};

#endif /* MC_base_hpp */
