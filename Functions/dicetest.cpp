/*
 * File: dicetest.cpp
 * ----------------
 * This program simulates rolling a die.
 */

#include <iostream>
#include "random.h"
using namespace std;

/*
 * Constants
 * ---------
 * NTrials -- Number of trials
 */

#define NTrials 10

/* Function prototypes */

int RollDie(void);

/* Main program */

int main()
{
    int i;

    for (i = 0; i < NTrials; i++) {
        cout << RollDie() << endl;
    }
}

/*
 * Function: RollDie
 * Usage: die = RollDie();
 * -----------------------
 * This function generates and returns a random integer in the
 * range 1 to 6, representing the roll of a six-sided die.
 */

int RollDie(void)
{
    return (RandomInteger(1, 6));
}
