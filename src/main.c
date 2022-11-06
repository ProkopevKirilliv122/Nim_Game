#include "game.h"
extern piles;
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
