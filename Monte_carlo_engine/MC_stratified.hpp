
#ifndef stratified_sampling_hpp
#define stratified_sampling_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include "random.hpp"
#include <numeric>
#include "MC_base.hpp"

class MC_strat : public MC
{
private:
    unsigned long number_of_strats;
    matrix RVmat;
public:
    MC_strat(){};
    MC_strat(dist_ptr p_, unsigned long size_, unsigned long number_of_strats_);
    vec operator()(function func);
    matrix getRVmat();
    void setRVmat(matrix M);
    vec result(matrix Matfunc);
};

#endif /* stratified_sampling_hpp */










