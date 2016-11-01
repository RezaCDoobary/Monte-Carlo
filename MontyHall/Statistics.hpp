#ifndef Statistics_hpp
#define Statistics_hpp
#include <iostream>
#include <vector>
#include <random>

//This is a statistics header file where we declare various useful function that we will need later.

class Statistics{
private:
    std::vector<double> t;   //A vector where we will store data
    
public:
    double mean(std::vector<double> t);                     //Finds the mean of the data in t
    double standardDeviation(std::vector<double> t);     //Finds the standard deviation of the data in t
    double ConfidenceLevelHi(std::vector<double> t);    //upper confidence level
    double ConfidenceLevelLo(std::vector<double> t);    //lower confidence level
    int random(int from, int to); //random number general from a numbr to a number(inclusive from both)
    int randomexclude(int from, int to, int ex); // random (as previous) but we exclude ex
    int randomexclude2(int from, int to, int ex, int ex2);// random (as previous) but we exclude ex and
                                                          // ex2
};

#endif /* Statistics_hpp */
