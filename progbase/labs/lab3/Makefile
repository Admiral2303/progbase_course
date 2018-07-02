

lab3: main.o function.o menu.o cat.o assert.o
	gcc -o lab3 main.o function.o menu.o cat.o assert.o -lprogbase
main.o: main.c
	gcc -c main.c
menu.o: menu.c
	gcc -c menu.c
function.o: function.c
	gcc -c function.c
cat.o: cat.c
	gcc -c cat.c
assert.o: assert.c
	gcc -c assert.c

clean:
	rm -f *.o lab3
