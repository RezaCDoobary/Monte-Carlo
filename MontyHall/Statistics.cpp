#include "Statistics.hpp"

//mean
double Statistics::mean(std::vector<double> t){
    double sum = 0;
    for(int i = 0; i < t.size(); i++){
        sum += t.at(i);
    }
    return(sum/t.size());
}

//standard devation
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

//random number
int Statistics::random(int from, int to){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(from,to);
    return(dis(gen));
}

//random number, whilst excluding two numbers.
int Statistics::randomexclude2(int from, int to, int ex,int ex2){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(from,to);
    int c;
    
    do {
        c = dis(gen);
    } while (c == ex || c == ex2);
    
    return c;
}





