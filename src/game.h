#ifndef GAME_H
#define GAME_H
#include <stdlib.h>
#include <stdio.h>

void generate_game();
int nim_sum();
void choose_first_move();
void show_piles();
void ai_move();
void player_move();
void new_move();
int game_ended();
void win();
int main();
#endif