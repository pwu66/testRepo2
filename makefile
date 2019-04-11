manager : main.o menu.o user.o
	gcc -o new main.o menu.o user.o
main.o : main.c
	gcc -c -o main.o main.c
menu.o : menu.c
	 gcc -c -o menu.o menu.c
user.o : user.c
	gcc -c -o user.o user.c

clean :
	rm *.o manager
