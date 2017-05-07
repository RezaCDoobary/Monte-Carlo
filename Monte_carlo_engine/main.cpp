#include <iostream>
#include <cmath>
#include <numeric>
#include "random.hpp"
#include <math.h>
#include "to_csv.hpp"
#include <numeric>
#include "MC_stratified.hpp"
#include "MC_base.hpp"
#include "MC_classical.hpp"
#include "MC_controlvariate.hpp"
#include "MC_antithetic.hpp"
#include "vectors.hpp"
#include <boost/math/distributions/normal.hpp>
#include "distributions.hpp"
#include "MC_importance.hpp"
#include <memory>


//Integrate[Exp[x], {x, 0, 1}] // N = 1.71828;

using namespace std;


double f(double x)
{
    return exp(x);
}

double g(double x)
{
    return 1+x;
}

double anti(double x)
{
    return 1-x;
}

void mc_classical()
{
    dist_ptr p(new uniform_distribution);
    MC_class m(p,1000000);
    vec result = m(f);
    for(auto x:result)
    {
        cout << x << endl;
    }
}

void mc_antithetic()
{
    dist_ptr p(new uniform_distribution);
    MC_antithetic m(p,1000000,anti);
    vec result = m(f);
    for(auto x:result)
    {
        cout << x << endl;
    }
}


void mc_stratified()
{
    dist_ptr p(new uniform_distribution);
    MC_strat m(p,1000000,1000);
    vec result = m(f);
    for(auto x:result)
    {
        cout << x << endl;
    }
}


void mix()
{
    dist_ptr p(new uniform_distribution);
    
    matrix M = p->gen_ran_stratified_mat(1000000,1000);
    
    MC_controlvariate m;
    m.setfunc(g);
    m.setcontrol_exp(1.5);
    vec mu,sigsq,result;
    for(unsigned long i = 0; i < M.size(); i++)
    {
        m.setRV(M[i]);
        vec p = m(f);
        mu.push_back(p[0]);
        sigsq.push_back(p[1]);
    }
    
    result.push_back(mean(mu));
    result.push_back(mean(sigsq)/(M.size()*M[0].size()));
    
    for(auto x:result)
    {
        cout << x << endl;
    }
    

}


void mc_controlvariate()
{
    dist_ptr p(new uniform_distribution);
    MC_controlvariate m(p,1000000,g,1.5);
    vec result = m(f);
    for(auto x:result)
    {
        cout << x << endl;
    }
}


void mc_importance()
{
    dist_ptr p_num(new normal_distribution(0,1));
    dist_ptr p_den(new normal_distribution(1,1));
    MC_importance m(p_den,p_num,1000000);
    vec result = m(f);
    for(auto x:result)
    {
        cout << x << endl;
    }

}

int main()
{
    mc_classical();
    mc_antithetic();
    mc_controlvariate();
    mc_stratified();
    
}




