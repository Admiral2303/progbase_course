all:
	gcc -g -c *.c -I./ -std=c99 -Werror -Wall -pedantic-errors 
	gcc *.o
	gnome-terminal --tab -e "/bin/bash -c './a.out; exec /bin/bash -i'"
	rm *.o