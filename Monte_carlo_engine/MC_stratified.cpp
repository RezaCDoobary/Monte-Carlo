#include "MC_stratified.hpp"
#include "random.hpp"
#include "MC_base.hpp"

MC_strat::MC_strat(dist_ptr p_, unsigned long size_, unsigned long number_of_strats_)
{
    matrix RVmat_ = p_->gen_ran_stratified_mat(size_, number_of_strats_);
    RVmat = RVmat_;
    p = p_;
    size = size_;
}


matrix MC_strat::getRVmat()
{
    return RVmat;
}

void MC_strat::setRVmat(matrix M)
{
    RVmat = M;
}

vec MC_strat::result(matrix Matfunc)
{
    vec result;
    vec local_mean;
    vec local_var;
    for(unsigned long i = 0; i < Matfunc.size(); i++)
    {
        local_mean.push_back(mean(Matfunc[i]));
        local_var.push_back(variance(Matfunc[i],mean(Matfunc[i]),false));
    }
    result.push_back(mean(local_mean));
    result.push_back(mean(local_var)/(Matfunc.size()*Matfunc[0].size()));
    return result;
}

vec MC_strat::operator()(function func)
{
    matrix ffunc = function_pass(RVmat,func);
    return result(ffunc);
}
