
#include "MC_base.hpp"



MC::MC(dist_ptr p_, unsigned long size_)
{
    vec RV_ = p_->gen_ran_vec(size_);
    RV = RV_;
    p = p_;
    size = size_;
}

vec MC::getRV()
{
    return RV;
}

void MC::setRV(vec V)
{
    RV = V;
}

dist_ptr MC::getdist_ptr()
{
    return p;
}

void MC::setdist_ptr(dist_ptr q)
{
    p=q;
}

unsigned long MC::getsize()
{
    return size;
}

