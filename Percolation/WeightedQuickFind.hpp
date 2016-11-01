#ifndef WeightedQuickFind_hpp
#define WeightedQuickFind_hpp
#include <iostream>
#include <vector>

//This is the header file to the Weighted quick union algorithm (see section 1.3 of "Algorithms in C++, parts 1-4" by Robert Sedgewick for the theory).

class WeightedQuickFind{
private:
    std::vector<int> id;    //id stores the information about how trees are connected
    std::vector<int> sz;    //sz will be the size of a given tree
    
    
public:
    WeightedQuickFind();            //constructor
    void WQF(int N);                //parametrises the number of nodes; N 
    bool connected(int p,int q);    //Are two nodes connected by an edge?
    int root(int i);                //What is the root of a given node?
    void merge(int p, int q);       //Merges two nodes
};

#endif /* WeightedQuickFind_hpp */
