#ifndef Statistics_hpp
#define Statistics_hpp
#include <iostream>
#include <vector>
#include <random>

//For the monte-carlo simulator, we will need some statistical methods.

class Statistics{
private:
    std::vector<double> t;      //we assume there exists the set of data in a vector
    
public:
    double mean(std::vector<double> t);                 //mean
    double standardDeviation(std::vector<double> t);    //standard deviation
    double ConfidenceLevelHi(std::vector<double> t);    //upper confidence level
    double ConfidenceLevelLo(std::vector<double> t);    //lower confidence level
    int random(int from, int to);                       //random number generator
    
};

#endif /* Statistics_h */
