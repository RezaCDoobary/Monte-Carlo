
#include "Statistics.hpp"


//standard definition of the mean, we build the vector t as we wish and then divide through by its size.
double Statistics::mean(std::vector<double> t){
    double sum = 0;
    for(int i = 0; i < t.size(); i++){
        sum += t.at(i);
    }
    return(sum/t.size());
}

//standard deviation
double Statistics::standardDeviation(std::vector<double> t){
    double sum = 0;
    for(int i = 0; i < t.size(); i++){
        sum += (t.at(i) - mean(t))*(t.at(i) - mean(t));
    }
    return(sqrt(sum/(t.size()-1)));
}

//upper confidence level
double Statistics::ConfidenceLevelHi(std::vector<double> t){
    double a = mean(t)+(1.96)*standardDeviation(t)/sqrt(t.size());
    return(a);
}

//lower confidence level
double Statistics::ConfidenceLevelLo(std::vector<double> t){
    double a = mean(t)-(1.96)*standardDeviation(t)/sqrt(t.size());
    return(a);
}

//random number generator
int Statistics::random(int from, int to){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(from,to);
    return(dis(gen));
}
    
    
    


