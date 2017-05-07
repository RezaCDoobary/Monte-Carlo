#include "MC_controlvariate.hpp"


MC_controlvariate::MC_controlvariate(dist_ptr p_, unsigned long size_,function control_, double control_expectation_)
{
    vec RV_ = p_->gen_ran_vec(size_);
    RV = RV_;
    p = p_;
    size = size_;
    control = control_;
    control_expectation = control_expectation_;
}


vec MC_controlvariate::fstar(vec func)
{
    vec gunc = function_pass(RV,control);
    double cov = covariance(func,gunc,mean(func),control_expectation,true);
    double varg = variance(gunc,control_expectation,true);
    
    double optimal_lambda = cov/varg;
    
    vec v;
    for(unsigned long i = 0; i < gunc.size(); i++)
    {
        v.push_back(control_expectation);
    }
    vec temp1 = gunc-v;
    vec temp2 = temp1*optimal_lambda;
    vec res = func-temp2;
    return res;
}


function MC_controlvariate::getfunc()
{
    return control;
}
void MC_controlvariate::setfunc(function func)
{
    control = func;
}

double MC_controlvariate::getcontrol_exp()
{
    return control_expectation;
}
void MC_controlvariate::setcontrol_exp(double exp)
{
    control_expectation = exp;
}

vec MC_controlvariate::result(vec func)
{
    vec result;
    vec res = fstar(func);
    result.push_back(mean(res));
    result.push_back(variance(res,result[0],false));
    return result;
}



vec MC_controlvariate::operator()(function func_)
{
    vec func = function_pass(RV,func_);
    return result(func);
}



