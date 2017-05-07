#include "distributions.hpp"

distribution::distribution(double mean_,double variance_)
{
    mean = mean_;
    variance = variance_;
}

distribution::~distribution()
{
//    std::cout << "distribution is dead" << std::endl;
}

matrix uniform_distribution::gen_ran_stratified_mat(const unsigned long totalsamplesize, const unsigned long numberofstrats)
{
    matrix u;
    const unsigned long sampleinstratum = totalsamplesize/numberofstrats;
    vec r;
    double s1 = (double)1/numberofstrats;
    for(unsigned long i = 0 ; i < numberofstrats; i++)
    {
        r = gen_ran_vec(sampleinstratum);
        r = r+i;
        r = r*s1;
        u.push_back(r);
    }
    return u;
}

vec uniform_distribution::gen_ran_vec(const unsigned long size)
{

    static boost::mt19937 e;
    static boost::uniform_real<double> d(0,1);
    static boost::variate_generator<boost::mt19937,boost::uniform_real<double> > g(e,d);
    
    vec s;
    for(int i = 0; i < size; i++)
    {
        s.push_back(g());
    }
    return s;
}

double uniform_distribution::operator()(double x)
{
    return 1;
}

uniform_distribution::~uniform_distribution()
{
//    std::cout << "uniform distribution is dead" << std::endl;
}

normal_distribution::normal_distribution(double mean_,double variance_)
{
    mean = mean_;
    variance = variance_;
}

vec normal_distribution::gen_ran_vec(const unsigned long size)
{
    static boost::mt19937 e;
    boost::normal_distribution<>  nd(mean, variance);
    static boost::variate_generator<boost::mt19937,boost::normal_distribution<> > g(e,nd);
    
    vec s;
    for(int i = 0; i < size; i++)
    {
        s.push_back(g());
    }
    return s;
}

double normal_distribution::operator()(double x)
{
    auto d = boost::math::normal_distribution<>{mean,variance};
    return pdf(d,x);
}

matrix normal_distribution::gen_ran_stratified_mat(const unsigned long totalsamplesize, const unsigned long numberofstrats)
{
    uniform_distribution u;
    matrix strat = u.gen_ran_stratified_mat(totalsamplesize,numberofstrats);
    matrix result;
    boost::math::normal dist(mean,variance);
    for(unsigned long i = 0; i < strat.size(); i++)
    {
        for(unsigned long j = 0; j < strat[0].size();j++)
        {
            strat[i][j] = boost::math::quantile(dist,strat[i][j]);
        }
    }
    return strat;
}

normal_distribution::~normal_distribution()
{
//    std::cout << "normal distribution is dead" << std::endl;
}
