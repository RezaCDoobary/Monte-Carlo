#include "MontyHall.hpp"

//In both cases of the experiment, we do them trials - many times.

MontyHall::MontyHall(){};

double MontyHall::prob_if_stay(int trials){     //The probablity of winning if we stay, in principle this
    double count = 0;                           //is simply the same as never been given the told about
    for(int i = 0; i < trials; i++){            //the losing door.
        int Winner = y.random(1,3);
        int firstChoice = y.random(1,3);
        if(Winner==firstChoice){
            count++;
        }
    }
    return(count/trials);
}

double MontyHall::prob_if_swap(int trials){ //The probablity of winning is we swap, here we randomly
    double count2 = 0;                      //elect the losing door that the host shows us, but we must
    for(int i = 0; i < trials; i++){        //make sure that it does either the randomly selected winning
        int Winner = y.random(1,3);         //door or our first choice.
        int firstChoice = y.random(1,3);
        int showLosingDoor = y.randomexclude2(1,3,Winner,firstChoice);
        int swapChoice = y.randomexclude2(1, 3,firstChoice,showLosingDoor);
        if(Winner==swapChoice){
                count2++;
        }
    }
    return(count2/trials);
}
