all:
	gcc -c src/main.c -o obj/main.o 
	gcc -c src/game.c -o obj/game.o
	gcc -o main obj/*.o
rm:
	rm obj/*.o
	rm game

run:
	./main