
#ifndef MC_clasical_hpp
#define MC_clasical_hpp

#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include "random.hpp"
#include <numeric>
#include "MC_base.hpp"
#include "vectors.hpp"
#include "distributions.hpp"

class MC_class : public MC
{
public:
    MC_class(dist_ptr p_, unsigned long size_);
    vec result(vec Vfunc);
    vec operator()(function func);
};

#endif /* MC_clasical_hpp */
