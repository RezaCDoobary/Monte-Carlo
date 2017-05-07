#include "MC_importance.hpp"

MC_importance::MC_importance(dist_ptr p_, dist_ptr p_num_, unsigned long size_)
{
    vec RV_ = p_->gen_ran_vec(size_);
    RV = RV_;
    p = p_;
    p_num = p_num_;
    size = size_;
}

double MC_importance::Z(double x, dist_ptr p_num, dist_ptr p)
{
    return (*p_num)(x)/(*p)(x);
}

vec MC_importance::result(vec func)
{
    vec Zfunc;
    vec result;
    for(unsigned long i = 0; i < size; i++)
    {
        Zfunc.push_back(Z(RV[i],p_num,p));
    }
    func*Zfunc;
    result.push_back(mean(func));
    result.push_back(variance(func,mean(func),false));
    return result;

}

vec MC_importance::operator()(function func)
{
    vec ffunc = function_pass(RV,func);
    return result(ffunc);
}

