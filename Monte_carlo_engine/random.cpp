#include "random.hpp"

vec function_pass(vec vect,function func)
{
    for(unsigned long i = 0; i < vect.size(); i++)
    {
        vect.at(i) = func(vect.at(i));
    }
    return vect;
}

matrix function_pass(matrix mat, function func)
{
    for(unsigned long i = 0; i < mat.size(); i++)
    {
        mat.at(i) = function_pass(mat.at(i),func);
    }
    return mat;
}

//Statistics
double mean(vec N)
{
    double sum = std::accumulate(N.begin(),N.end(),0.0);
    return (double)sum/N.size();
}


double covariance(vec vec1, vec vec2, double mean1, double mean2, bool meanknown)
{
    double res;
    if(vec1.size()!=vec2.size())
    {
        throw std::invalid_argument( "dimension of vectors must be the same" );
    }
    if(meanknown == false)
    {
        double sum = 0;
        for(unsigned long i = 0; i < vec1.size(); i++)
        {
            sum+=(vec1[i]-mean1)*(vec2[i]-mean2)/(vec1.size()-1);
        }
        res = sum;
    }
    else
    {
        if(vec1.size()!=vec2.size())
        {
            throw std::invalid_argument( "dimension of vectors must be the same" );
        }
        double sum = 0;
        for(unsigned long i = 0; i < vec1.size(); i++)
        {
            sum+=(vec1[i]-mean1)*(vec2[i]-mean2)/(vec1.size());
        }
        res = sum;
    }
    return res;
}

double variance(vec vec1, double mean, bool meanknown)
{
    return covariance(vec1,vec1,mean,mean,meanknown);
}

double correlation(vec vec1, vec vec2, double mean1, double mean2, bool meanknown1,bool meanknown2)
{
    double result = 0;
    if(meanknown1 == meanknown2 == true)
    {
        double cov = covariance(vec1,vec2,mean1,mean2,true);
        result = (double)cov/(sqrt(variance(vec1,mean1,true)*variance(vec2,mean2,true)));
    }
    if(meanknown1 == meanknown2 == false)
    {
        double cov = covariance(vec1,vec2,mean1,mean2,false);
        result = (double)cov/(sqrt(variance(vec1,mean1,false)*variance(vec2,mean2,false)));
    }
    if(meanknown1 == true && meanknown2 == false)
    {
        double cov = covariance(vec1,vec2,mean1,mean2,true);
        result = (double)cov/(sqrt(variance(vec1,mean1,true)*variance(vec2,mean2,false)));
    }
    if(meanknown2 == true && meanknown1 == false)
    {
        double cov = covariance(vec1,vec2,mean1,mean2,true);
        result = (double)cov/(sqrt(variance(vec1,mean1,false)*variance(vec2,mean2,true)));
    }
    return result;
}



//arthmetic
std::vector<double> add(std::vector<double>& vec1, std::vector<double>& vec2)
{
    if(vec1.size()!=vec2.size())
    {
        throw std::invalid_argument( "dimension of vectors must be the same" );
    }
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), vec1.begin(), std::plus<double>());
    return vec1;
}

std::vector<double> takeaway(std::vector<double>& vec1, std::vector<double>& vec2)
{
    if(vec1.size()!=vec2.size())
    {
        throw std::invalid_argument( "dimension of vectors must be the same" );
    }
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), vec1.begin(), std::minus<double>());
    return vec1;
}

std::vector<double> scalar_mul(std::vector<double>& vec1, double scalar)
{
    std::transform(vec1.begin(), vec1.end(), vec1.begin(),std::bind1st(std::multiplies<double>(),(double) scalar));
    return vec1;
}


