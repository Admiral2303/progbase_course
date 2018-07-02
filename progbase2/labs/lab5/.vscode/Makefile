all:
	gcc -c -g *.c  -std=c99 -Werror -Wall -pedantic-errors -I /usr/include/libxml2 
	gcc *.o -o a.out -lprogbase -lcheck -lxml2 -ljansson
	gnome-terminal --tab -e "/bin/bash -c 'valgrind --leak-check=yes ./a.out; exec /bin/bash -i'"
	rm *.o