
#ifndef MC_antithetic_hpp
#define MC_antithetic_hpp

#include <stdio.h>
#include "vectors.hpp"
#include "MC_base.hpp"
#include "random.hpp"



class MC_antithetic : public MC
{
private:
    function antithetic_pair;
    vec antithetic_vector;
public:
    MC_antithetic(){};
    MC_antithetic(dist_ptr p_, unsigned long size_,function antithetic_pair_);
    function getanti();
    void setanti(function func);
    vec getantivec();
    void setantivec(vec fvec);
    vec result(vec func,vec gunc);
    vec operator()(function func);
};





#endif /* MC_antithetic_hpp */
