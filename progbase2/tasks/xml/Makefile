all:
	gcc xml.c -g -c *.c -I./ -std=c99 -Werror -Wall -pedantic-errors -I /usr/include/libxml2 
	gcc *.o -lxml2
	gnome-terminal --tab -e "/bin/bash -c 'valgrind --leak-check=yes ./a.out; exec /bin/bash -i'"
	rm *.o