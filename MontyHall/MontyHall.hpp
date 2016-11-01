#ifndef MontyHall_hpp
#define MontyHall_hpp
#include <stdio.h>
#include "Statistics.hpp"

//We now turn to the actual Monty Hall Problem, the monte carlo will be implemented as follows: we randomly select the winning door, and have the host show us one of the losing doors. We then have two options, to stay or to swap. We do the experiement trials-many times, then divide the number of successes by the number trials, we should then see that it is statistically favourable to swap.

class MontyHall{
private:
    int count;          //couting for staying
    int count2;         //counting for switching
    int Winner;         //The randomly selected winning door
    int firstChoice;    //Our initial choice
    int showLosingDoor; //the host shows us the losing door
    int swapChoice;     //The swap (which is random - since it is not the randomly selected initial door)
    Statistics y;
public:
  
    MontyHall();
    double prob_if_stay(int trials); //The probablity of staying if we swap
    double prob_if_swap(int trials); //The probablity of winning if we swap
};



#endif /* MontyHall_hpp */
