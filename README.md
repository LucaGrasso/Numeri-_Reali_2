## Numeri Reali ##
Progetto di libreria in C per linux - Progetto presentato per il corso di laurea L31 a Urbino
Sessione Invernale Gennaio 2019

1. SPECIFICA DEL PROBLEMA 
Scrivere una libreria ANSI C che gestisce insiemi di numeri reali esportando le seguenti cinque funzioni.
- La prima funzione restituisce un insieme acquisito da tastiera.
- La seconda funzione ha come parametro di ingresso un insieme e lo stampa a video.
- La terza funzione ha come parametri di ingresso un numero reale e un insieme e stabilisce ricorsivamente se quel numero appartiene a quell’insieme.
- La quarta funzione ha come parametri di ingresso due insiemi e stabilisce ricorsivamente se il primo è contenuto nel secondo.
- La quinta funzione ha come parametri di ingresso due insiemi e restituisce la loro unione calcolata ricorsivamente.


Tutto il programma ruota sulla gesione della liste utilizzate come un insieme, e della locazione dinamica della memoria.

* definizione dei tipi                                                        
* definizione di una struttura dati di tipo lista concatenata dato ricorsivo)
* attraverso il costruttore di tipo struttura ed il costruttore di tipo       
* puntatore (nodo della lista) 
 
 ```C
typedef struct lista_reali {   float   numero;      
// variabile per memorizzare un numero reale
struct  lista_reali* succ_p;
// puntatore successiva componente della lista
}l_reali;
// allocazione dinamica di una componente della lista
n = (l_reali*)malloc(sizeof(l_reali));
```
e' presente un file Makefile con le seguenti istruzioni per compilare l'eseguibile su linux
 ```
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
 ```
 
Spero il programma possa aiutare studenti per la compressione e gestione delle liste.
Sono disponibile per domande o chiarimenti, contattatemi pure in email o su linkedin.

Luca

