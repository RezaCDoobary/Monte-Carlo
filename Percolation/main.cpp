#include "PercolationStatistics.hpp"

//An example of the computation is as follows:
int main(){
    percolationstats x(10,100);
    std::cout<< x.mean() << std::endl;   //Example result : 0.5948
    std::cout<< x.sD() << std::endl;     //Example result : 0.0715694
    std::cout<< x.Hi() << std::endl;     //Example result : 0.608828
    std::cout<< x.Lo() << std::endl;     //Example result : 0.580772
    return 0;
    
    
}
