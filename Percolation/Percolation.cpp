#include "Percolation.hpp"

//Initialise the percolation type
Percolation::Percolation(){}

//Initialises the parametrisation of the percolation class
void Percolation::percolation(int m){
    n = m;
    x.WQF(n*n+2);      // the total dimension is n*n+2 = top + bottom + n*n
    top = 0;                    // we call the top node as the zero
    bottom = n*n+1;             // we call the bottom node as the n*n+1
    open.assign(n*n,0);         // a vector which associated 0 to n*n boxes in the grid, we will
}                                   // set it to 1 when the box is open.

//Open the box at grid entry (i,j)
void Percolation::Open(int i,int j){
    if(i < 1 || i > n || j < 1 || j > n) {
        throw std::out_of_range ("out of range");
    }
    open.at(n*(i-1)+j-1) = 1;                       //Sets entry to 1
    
    if (i == 1){                                    //The following is a set of conditions upon which
        x.merge(j,top);                             //we open the boxes in the grid. We must make
    }                                               //sure to connect boxes which we open on the top
    if (i == n){                                    //or bottom rows with the 'top' or 'bottom' node.
        x.merge(n*(n-1)+j, bottom);
    }
    if (i > 1 && open.at(n*(i-2)+j-1) == 1){
        x.merge(n*(i-2)+j, n*(i-1)+j);
    }
    if(j > 1 && open.at(n*(i-1)+j-2) == 1){
        x.merge(n*(i-1)+j, n*(i-1)+j-1);
    }
    if(i < n && open.at(n*i+j-1) == 1){
        x.merge(n*i+j, n*(i-1)+j);
    }
    if(j < n && open.at(n*(i-1)+j) == 1){
        x.merge(n*(i-1)+j+1, n*(i-1)+j);
    }
}

//A boolean to return true if a box is open
bool Percolation::isOpen(int i, int j){
    return (open.at(n*(i-1)+j-1) == 1);
}

//A boolean to return true if the top and bottom node are connected, i.e. the system percolates.
bool Percolation::percolates(){
    return(x.connected(top,bottom));
}
    




