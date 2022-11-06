#include "game.h"
#include "ctest.h"
#include <stdio.h>
#include <stdlib.h>

int num_of_piles = 3;
int* piles;
int cur_move;

CTEST(nim, nim_sum)
{
    int num_of_piles = 3;
    piles[0]=7;
    piles[1]=6;
    piles[2]=9;
    ASSERT_EQUAL(8, nim_sum());
}
CTEST(end, game_ended)
{
   piles[0]=2;
    ASSERT_EQUAL(0, game_ended());
}
int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

