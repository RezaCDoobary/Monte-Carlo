#ifndef Percolation_hpp
#define Percolation_hpp
#include "WeightedQuickFind.hpp"

//The main exercise is to compute the critical ratio for a system to begin percolating by using monte-carlo simulation.

//The problem is stated as followed: Consider an n by b grid, with either open or blocked boxes. A system is said to percolate if there is a set of open boxes connected from the top of the grid to the bottom, conversely a system is said to not percolate if it does not. It is known that if the ratio of open boxes with respect to n is very large, the system is likely to percolate. The opposite creates a system which is very unlikely to percolate. The problem is thus to find the critical point at which system percolates by performing a monte carlo simulation. This is done by randomly distributing open boxes in the grid until the system percolates.

//The problem is done by taking each box in the grid to be a node in the WeightedQuickUnion algorithm. We include two extra nodes, a 'top' and 'bottom' node, and we deem the system as one that percolates if the top and bottom node are connected.

//In the following we refer to (i,j) as the grid itself - (1,1) being the top letf box, whilst (n,n) being the bottom right.

class Percolation {
private:
    int n;                      //n is the number of boxes in the grid
    int top;                    //The top node
    int bottom;                 //The botton node
    std::vector<int> open;      //A vector defined to tell us if a box in the grid is open or not
    WeightedQuickFind x;
public:
    Percolation();
    void percolation(int m);                //persolation data typ with m dofs
    void Open(int i,int j);                 //Open a box in grid position (i,j)
    bool isOpen(int i, int j);              //Is the grid position (i,j) open
    bool percolates();                      //Does the system percolate?
};

#endif /* Percolation_hpp */
