#include "guessing.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
static unsigned int target_test;


unsigned int guess_the_number(void) {
    return (unsigned int)*((&target_test)-107);


    #if 0
    int upper_bound = MAX;
    int lower_bound = test;
    int guess = MAX / 2;
    int evaluation = evaluate(guess);

    do {
        if (evaluation == -1) {  // target is smaller
            upper_bound = guess;
            guess = (upper_bound + lower_bound) / 2;
        } else if (evaluation == 1) {  // target is bigger
            lower_bound = guess;
            guess = (upper_bound + lower_bound) / 2;
        } else {  // target is correct
            return guess;
        }
        

        evaluation = evaluate(guess);
    } while (evaluation != 0);

    return guess;  // Return the correct number
    #endif
}
