all:
	gcc -g -c *.c -I./ -std=c99 -Werror -Wall -pedantic-errors 
	gcc *.o -ljansson
	gnome-terminal --tab -e "/bin/bash -c 'valgrind --leak-check=yes ./a.out; exec /bin/bash -i'"
	rm *.o