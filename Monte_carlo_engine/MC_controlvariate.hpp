#ifndef MC_controlvariate_hpp
#define MC_controlvariate_hpp

#include <stdio.h>
#include "MC_base.hpp"
#include "random.hpp"



class MC_controlvariate : public MC
{
private:
    function control;
    double control_expectation;
    
public:
    MC_controlvariate(){};
    
    MC_controlvariate(dist_ptr p_, unsigned long size_,function control_, double control_expectation_);
    vec fstar(vec func);
    
    function getfunc();
    void setfunc(function func);
    
    double getcontrol_exp();
    void setcontrol_exp(double exp);
    
    
    vec result(vec func);
    vec operator()(function func);
};


#endif /* MC_controlvariate_hpp */
