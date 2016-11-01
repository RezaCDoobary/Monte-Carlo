#include "MontyHall.hpp"

//We perform the experiment here (averaging over 100000 experiments):

int main(){
    MontyHall x;
    std::cout << x.prob_if_stay(100000) << std::endl;   //Example result : 0.33411
    std::cout << x.prob_if_swap(100000) << std::endl;   //Example result : 0.67001
    }

