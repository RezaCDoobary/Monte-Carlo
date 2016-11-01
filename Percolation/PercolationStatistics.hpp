#ifndef PercolationStatistics_hpp
#define PercolationStatistics_hpp
#include "Statistics.hpp"
#include "Percolation.hpp"

//We invent another class which will actually peform the monte-carlo simulation upon the percolation class.

class percolationstats{
private:
    int n;                          //n by n grid
    Statistics y;                   //We require the statistics data type
    double threshold(int n);        //Function which computes the threshold.
    int T;                          //number of trials
    std::vector<double> t;          //vector storing the threshold of each experiment, will be T-dim

public:
    percolationstats(int N, int trials);    //N by N grid and trials many trials
    double mean();                          //mean of all the trials
    double sD();                            //standard deviation of the trials
    double Hi();                            //upper confidence of trials
    double Lo();                            //lower confidence or trials
    
};

#endif /* PercolationStatistics_hpp */
