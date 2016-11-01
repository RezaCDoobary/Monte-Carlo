#include "WeightedQuickFind.hpp"


WeightedQuickFind::WeightedQuickFind(){};

//The parametrised constructor sets up N many nodes with id[i] = i, but the size of each node is only one since no merging has occured at initialisation.
void WeightedQuickFind::WQF(int N){
    for(int i = 0; i < N; i++){
        id.push_back(i);
    }
    for(int i = 0; i < N; i++){
        sz.push_back(1);
    }
}

//This asks if two nodes are connected, under the Quick Union Find algorithm, this is simply asking if two nodes are connected.
bool WeightedQuickFind::connected(int p,int q){
    return(root(p)==root(q));
}

//This finds the root of a node.
int WeightedQuickFind::root (int i){
    while(i!=id.at(i)){
        i = id.at(i);
    }
    return (i);
}

//The key feature of the quick union find algorithm, the merging occurs by taking the smaller tree and merging it to the larger true (with the goal to minimise larger tree lengths).
void WeightedQuickFind::merge (int p, int q){
    int i = root(p);
    int j = root(q);
    if(i==j){
        return;
    }
    if(sz.at(i) < sz.at(j)){
        id.at(i) = j;
        sz.at(j) += sz.at(i);
    }
    else{
        id.at(j) = i;
        sz.at(i) += sz.at(j);
    }
}
