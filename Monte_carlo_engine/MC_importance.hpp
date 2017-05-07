#ifndef MC_importance_hpp
#define MC_importance_hpp

#include <stdio.h>
#include "vectors.hpp"
#include "MC_base.hpp"
#include "random.hpp"
#include "distributions.hpp"


class MC_importance : public MC
{
private:
    dist_ptr p_num;
public:
    MC_importance(dist_ptr p_, dist_ptr p_num_, unsigned long size_);
    double Z(double x,dist_ptr p_num, dist_ptr p);
    vec result(vec func);
    vec operator()(function func);
};

#endif /* MC_importance_hpp */
