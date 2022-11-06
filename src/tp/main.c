#include <stdlib.h>
#include <stdio.h>


int num_of_piles = 1;
int* piles;
int cur_move;


void generate_game()
{
int max_num_of_matches = 15;
int min_num_of_matches = 1;
printf("Условия игры.\n ");

num_of_piles = 3;
printf("Количество куч:");
printf("%d", num_of_piles);
printf("\n");
piles = (int *)calloc(num_of_piles, sizeof( int ) );
for (int i = 0; i < num_of_piles; i++)
{
piles[i] = rand() % (max_num_of_matches + 1);
if (piles[i] < min_num_of_matches)
{
piles[i] = min_num_of_matches;
}
printf("количество камней в куче#");
printf("%d", i+1);
printf(":");
printf("%d", piles[i]);
printf("\n");
}

}

int nim_sum()
{
int nim = 0;
for (int i = 0; i < num_of_piles; i++)
{
nim = nim ^ piles[i];
}
return nim;
}

void choose_first_move()
{
system("cls");
printf("Выберите кто будет ходить первым\n");
printf("Нажмите 'n' и первым пойдем компьютер, любая другая клавиша и первым ходит игрок\n");
if (getchar() == 'n')
{
if (nim_sum() == 0)
{
printf("Подтвердите выбор нажатием клавиши 'n'.\n");
if (getchar() == 'n')
{
printf("Начинает компьютер.\n");
cur_move = 0;
}
else
{
printf("Начинает игрок.\n");
cur_move = 1;
}
}
else
{
printf("Начинает компьютер.\n");
cur_move = 0;
}
}
else
{
printf("Начинает игрок.");
cur_move = 1;
}
printf("Начнем играть!\nДля продолжения нажмите любую клавишу.\n");
getchar();
}

void show_piles()
{
system("cls");
printf("Условия:\n");
for (int i = 0; i < num_of_piles; i++)
{
printf("[");
printf("%d", piles[i]);
printf("]");
printf("камней в куче#");
printf("%d", i+1);
printf("\n");
}
printf("Текущая ним-сумма:");
printf("%d ", nim_sum());
printf("\n");
}

void ai_move()
{
int nim = nim_sum();
int i = 0;
if (nim == 0)
{
while (piles[i] == 0)
{
i++;
}
printf("Так...\n");
printf("Компьютер забирает 1 камень из кучи номер #");
printf("%d", i+1);
printf("\n");
piles[i]--;
}
else
{
while(((piles[i] ^ nim) >= piles[i]) && (i < num_of_piles))
{
i++;
}
printf("Так...\n");
printf("Я забираю ");
printf("%d", piles[i] - (piles[i] ^ nim));
printf("камней из кучи# ");
printf("%d", i+1);
printf("\n");
piles[i] = (piles[i] ^ nim);
}
}

void player_move()
{
int pile = 0;
printf("Введите номер кучи из которой хотите забрать камни.\n");
while ((pile - 1 < 0) || (pile > num_of_piles) || (piles[pile-1] == 0))
{
scanf("%d", &pile);
}
printf("Введите количество камней, которые хотите взять.\n");
int matches = 1000;
while ((matches < 0) || (piles[pile-1] < matches))
{
scanf("%d", &matches);
}
piles[pile-1] = piles[pile-1] - matches;
}

void new_move()
{
show_piles();
if (cur_move == 1)
{
player_move();
}
else
{
ai_move();
}
cur_move = (cur_move+1) % 2;

printf("Надо подумать...\nдля продолжения нажмите любую клавишу.\n");
getchar();
}

int game_ended()
{
for (int i = 0; i < num_of_piles; i++)
{
if (piles[i] > 0)
{
return 0;
}
}

return 1;
}

void win()
{
show_piles();
if (cur_move == 0)
{
printf("\nВы победили!\n");
}
else
{
printf("\n? Поражение...\n");
}

printf("\nДля выхода нажмите любую клавишу.\n");
}

int main()
{
printf("Я игра НИМ.\nДля начала игры нажмите'n'.\nДля закрытия нажмите любую другую клавишу.\n");
char choice = getchar();
if (choice != 'n')
{
return 1;
}
while (choice == 'n')
{
free(piles);
system("cls");
generate_game();
printf("Если вы хотите изменить условия нажмите 'n'./n");
choice = getchar();
}
choose_first_move();

while(!game_ended())
{
new_move();
}

win();

free(piles);
getchar();
return 0;
}
