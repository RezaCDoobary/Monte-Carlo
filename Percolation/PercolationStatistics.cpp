#include "PercolationStatistics.hpp"

//Computes the threshold by randomly selecting the box (p,q) and opening it whilst the system still does not eprcolate. We must make sure to check that we do not open a box already opened as this ruins our counting.
double percolationstats::threshold(int n){
    Percolation x;
    x.percolation(n);
    double count = 0;
    while(x.percolates() == 0) {
        int p = y.random(1,n);
        int q = y.random(1,n);
        if (x.isOpen(p,q) == 0) {
                count++;
                x.Open (p,q);
        }
    }
    return (count/(n*n));
}

//Creats a vector t which stores the trials-many threshold values for n by n grids.
percolationstats::percolationstats(int N, int trials){
        n = N;
        T = trials;
        t.assign(T,0);
        for(int i = 0; i < T; i++){
            t.at(i)=(threshold(n));
            
        }
}

//Computes means
double percolationstats::mean(){
    return(y.mean(t));
}

//Computes standard deviation
double percolationstats::sD(){
    return(y.standardDeviation(t));
}

//Computes upper confidence
double percolationstats::Hi(){
    return(y.ConfidenceLevelHi(t));
}

//Computes lower confidence
double percolationstats::Lo(){
    return(y.ConfidenceLevelLo(t));
}
    





