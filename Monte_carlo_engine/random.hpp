#ifndef random_hpp
#define random_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/math/distributions/normal.hpp>
#include <numeric>
#include <stdexcept>
#include "vectors.hpp"
#include "MC_base.hpp"
typedef double(*function)(double);
typedef Rvec<double> vec;
vec function_pass(vec vect,function func);
matrix function_pass(matrix mat, function func);

//Statistics
double mean(vec N);
double covariance(vec vec1, vec vec2, double mean1, double mean2, bool meanknown);
double variance(vec vec1, double mean, bool meanknown);
double correlation(vec vec1, vec vec2, double mean1, double mean2,bool meanknown1,bool meanknown2);


#endif /* random_hpp */
