test_libreria_reali: numeri_reali.o test_libreria_reali.o Makefile 
	gcc -ansi -Wall -O numeri_reali.o test_libreria_reali.o -o test_libreria_reali 
numeri_reali.o: numeri_reali.c numeri_reali.h Makefile
	gcc -ansi -Wall -O -c numeri_reali.c
test_libreria_reali.o: test_libreria_reali.c numeri_reali.h Makefile
	gcc -ansi -Wall -O -c test_libreria_reali.c
pulisci: 
	rm -f *.o
pulisci_tutto:
	rm -f test_libreria_reali *.o	
