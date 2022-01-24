eseguibile: main.o insiemi_numeri_reali.o Makefile
	gcc -ansi -Wall -O main.o insiemi_numeri_reali.o -o eseguibile
main.o: main.c insiemi_numeri_reali.h Makefile
	gcc -ansi -Wall -O -c main.c
insiemi_numeri_reali.o: insiemi_numeri_reali.c insiemi_numeri_reali.h Makefile
	gcc -ansi -Wall -O -c insiemi_numeri_reali.c
pulisci:
	rm -f *.o
pulisci_tutto:
	rm -f eseguibile *.o
