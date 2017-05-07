#include "MC_classical.hpp"


MC_class::MC_class(dist_ptr p_, unsigned long size_)
{
    vec RV_ = p_->gen_ran_vec(size_);
    RV = RV_;
    p = p_;
    size = size_;
}

vec MC_class::result(vec Vfunc)
{
    vec result;
    result.push_back(mean(Vfunc));
    result.push_back(variance(Vfunc,mean(Vfunc),false));
    return result;
    
}

vec MC_class::operator()(function func)
{
    vec ffunc = function_pass(RV,func);
    return result(ffunc);
}
