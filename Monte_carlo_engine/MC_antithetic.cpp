#include "MC_antithetic.hpp"

MC_antithetic::MC_antithetic(dist_ptr p_, unsigned long size_,function antithetic_pair_)
{
    vec RV_ = p_->gen_ran_vec(size_);
    RV = RV_;
    p = p_;
    size = size_;
    antithetic_pair = antithetic_pair_;
    antithetic_vector = function_pass(RV,antithetic_pair);
}
function MC_antithetic::getanti()
{
    return antithetic_pair;
}

void MC_antithetic::setanti(function func)
{
    antithetic_pair = func;
}

vec MC_antithetic::getantivec()
{
    return antithetic_vector;
}

void MC_antithetic::setantivec(vec fvec)
{
    antithetic_vector = fvec;
}

vec MC_antithetic::result(vec func,vec gunc)
{
    vec result;
    func+gunc;
    func*(0.5);
    result.push_back(mean(func));
    result.push_back(variance(func,mean(func),false));
    return result;
}

vec MC_antithetic::operator()(function func)
{
    vec fun = function_pass(RV,func);
    vec gunc = function_pass(antithetic_vector,func);
    return result(fun,gunc);
}

