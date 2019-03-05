/**************************************************************************/
/* Libreria per la gestione di insiemi di numeri reali - implementazione  */
/**************************************************************************/

/******************************************************************************/
/* 	            Autore: Grasso Luca                         		          */
/******************************************************************************/


/******************************************************************************/
/* 			Inclusione delle librerie                      				      */
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/******************************************************************************/
/* 			Definizione dei tipi                                			  */
/******************************************************************************/
/* definizione di una struttura dati di tipo lista concatenata dato ricorsivo)*/
/* attraverso il costruttore di tipo struttura ed il costruttore di tipo      */
/* puntatore (nodo della lista)                                               */
/******************************************************************************/

typedef struct lista_reali
{
   float   numero;	        	/* variabile per memorizzare un numero reale */
   struct  lista_reali* succ_p; /* puntatore alla successiva componente della lista */	
}l_reali;


/******************************************************************************/
/* 			dichiarazioni delle funzioni                          			  */
/******************************************************************************/

/* dichiarazione della funzione insieme_reali */
l_reali *insieme_reali (void);

/* dichiarazione della funzione stampa_insieme */
void stampa_insieme(l_reali* n);

/* dichiarazione della funzione inclusione_elemento */
int inclusione_elemento(float r, 
			l_reali* n);

/* dichiarazione della funzione inclusione_insieme */
int inclusione_insieme(l_reali* n1, 
		       l_reali* n2);

/* dichiarazione della funzione unione_insieme */
l_reali* unione_insiemi(l_reali* n1, 
			l_reali* n2);

/******************************************************************************/
/* 		Definizioni delle funzioni                       		              */
/******************************************************************************/

/******************************************************************************/
/* 		Funzione: insieme_reali                  		                      */
/******************************************************************************/
/* la funzione restituisce un insieme di numeri reali acquisiti da tastiera   */ 
/* attraverso una variabile puntatore alla prima componente di una lista      */ 
/* concatenata in cui sono memorizzati tutti gli elementi dell' insieme       */
/******************************************************************************/

l_reali *insieme_reali (void)
{

  /* dichiarazione delle variabili locali alla funzione */
  int i, 	      /* variabile di servizio */
      k = 0,	  /* variabile di servizio */	
      ne,	      /* numero degli elementi dell'insieme */
      esito_lettura;  /* variabile di validazione dei dati di input */
	
  l_reali* p = NULL;  /* puntatore: prima componente della lista */
  l_reali* n = NULL;  /* puntatore: componente generica della lista */
																
  /* acquisizione da tastiera del numero di elementi dell'insieme */		
  do
  {
    printf("************************************************\n"); 
    printf("Inserire numero di elementi dell'insieme (n>=0):\n");
    printf("************************************************\n"); 
    esito_lettura = scanf("%d",   	
		          &ne);
    /*validazione stretta dei dati acquisiti */	
    if (esito_lettura != 1 || ne < 0 )
		printf("Dato di ingresso non corretto !!\n");
    while (getchar() != '\n');
	printf ("*****************************"\n);
  }
  while (esito_lettura != 1 || ne < 0 );
  
  /* acquisizione da tastiera degli elementi di un insieme non vuoto */
  if (ne != 0)
  {	  
    /* ciclo di istruzioni di ripetizione per la creazione di una lista
    concatenata (a partire dall'ultima componente fino alla prima) 
    attraverso allocazione dinamica della memoria. Ciascuna componente
    della lista (nodo) contiene un elemento dell'insieme ed il puntatore
    alla componente successiva */
    printf("************************************************\n"); 
    printf("Inserire elementi dell' insieme: \n");
    printf("************************************************\n");	
    for(i = ne;
        i > 0; 
        i--)	
    {
      /* allocazione dinamica di una componente della lista */ 
      n = (l_reali*)malloc(sizeof(l_reali));      	
      /* acquisizione degli elementi dell'insieme */  
      printf("[%d]: ",
             ++k);		
      do
      {	 																		
        esito_lettura = scanf("%f",         
		 	      &n->numero);     
        /* validazione dei dati acquisiti */ 
        if (esito_lettura != 1)            		   
        {
		  /* Comunico l'errore e richiedo l'inserimento */ 
          printf("Dato di ingresso non corretto !! \n");
		  printf("************************************************\n"); 		       
		  printf("Nuovo inserimento: \n[%d]: ", k); 			   
        }
        while (getchar() != '\n');
      }
      while (esito_lettura != 1);
      n->succ_p = p;	/* puntatore al nodo successivo della lista */
      p = n;		    /* puntatore alla prima componente della lista */
    }
  }
   /* se si acquisisce un insieme vuoto la lista concatenata non possiede
   nessuna componente) */
  else
  {	
    p = NULL;  
    printf("Acquisito un insieme vuoto !! \n");
  } 

  /* la funzione restituisce il puntatore alla prima componente della lista
  in cui è memorizzato l'insieme dei numeri reali acquisito da tastiera*/		

  return (p); 
}

/******************************************************************************/
/* 		     Funzione: stampa_insieme                                 */
/******************************************************************************/
/* funzione che ha come parametro formale un insieme di numeri reali          */
/* rappresentato da una struttura dati di tipo lista concatenata ove in ogni  */
/* componente è contenuto un elemento dell'insieme ed un puntatore alla       */
/* componente successiva.                                                     */
/* Dopo l'invocazione la funzione stampa a video tutti i numeri reali         */ 
/* dell'insieme                                                               */
/******************************************************************************/

void stampa_insieme(l_reali* n) /* puntatore alla prima componente di una lista */   
{
  /* dichiarazione delle variabili locali alla funzione */		
  int k = 0;		       /* variabile di servizio */

  /* istruzione di stampa a video nel caso di un insieme vuoto */ 
  if (n == NULL)
    printf("Insieme vuoto\n");

  /* istruzioni di ripetizione che stampa a video il numero reale memorizzato in
  ciascuna componente della lista nel caso di un insieme non vuoto */
  while(n != NULL)		
  {				
    printf("[%d]: %f\n",    /* stampa a video del numero reale memorizzato nella*/ 
	   ++k, 	    /* componente della lista */
	   n->numero);	    				
    n = n->succ_p;	    /* passaggio alla componente successiva */											
  }	
}


/******************************************************************************/
/* 		    Funzione: inclusione_elemento                             */
/******************************************************************************/
/* funzione che ha come parametri formali un numero reale ed un insieme       */ 
/* di numeri reali (rappresentato da una struttura dati di tipo lista         */  
/* concatenata dove in ogni componente sono memorizzati un elemento           */
/* dell'insieme ed un puntatore alla componente successiva).                  */
/* La funzione stabilisce ricorsivamente se il numero è incluso nell'insieme  */
/* restituendo una variabile di tipo intero                                   */
/******************************************************************************/

int inclusione_elemento(float r,     /* numero reale */
			l_reali* n)  /* puntatore alla prima componente 
					di una lista */       
{
  /* dichiarazione delle variabili locali alla funzione*/
  int i /* variabile di ritorno della funzione */
                    
  /* primo caso base della ricorsione */	
  if (n == NULL)	        					
    i = 0;
  else
  { 
    /* secondo caso base della ricorsione */	
	i = (n->numero == r)?      	
        1:
        0;
	/* passo ricorsivo */
    i += inclusione_elemento(r,
			     n->succ_p);		
  }

  return (i); /* se i == 0 il numero non è incluso nell'insieme */
	          /* se i != 0 il numero è incluso nell'insieme */
}


/******************************************************************************/
/* 		    Funzione: inclusione_insieme                             		  */
/******************************************************************************/
/* funzione che ha come parametri formali due insiemi di numeri reali         */
/* (rappresentati da strutture dati di tipo lista concatenata dove in ogni    */
/* componente sono memorizzati un elemento dell'insieme ed un puntatore alla  */
/* componente successiva).                                                    */
/* La funzione stabilisce ricorsivamente se il primo insieme è incluso nel    */
/* secondo restituendo una variabile di tipo intero                           */ 
/******************************************************************************/

int inclusione_insieme(l_reali* n1,   /* puntatori alla prima componente */
		       l_reali* n2)   /* delle liste in cui sono memorizzati 
					 gli insiemi dei numeri reali */
{
  /* dichiarazione delle variabili locali alla funzione*/	
  int i = 0;		           /* variabile di ritorno della funzione */
  
  /* primo caso base della ricorsione */   		      
  if (n1 == NULL)                     	
    i = 1;
  /* secondo caso base della ricorsione */
  else if (!inclusione_elemento(n1->numero, n2)) 	
    i = 0;
  /* passo ricorsivo */
  else
    i = inclusione_insieme(n1->succ_p, 	    
			   n2);
  return (i);  /* se i == 0 il primo insieme (n1) non è incluso nel secondo (n2) */
  	           /* se i == 1 il primo insieme (n1) è incluso nel secondo (n2) */
}

/******************************************************************************/
/* 		     Funzione: unione_insiemi                                         */
/******************************************************************************/
/* funzione che ha come parametri formali due insiemi di numeri reali         */ 
/* (rappresentati da strutture dati di tipo liste concatenate dove in ogni    */
/* componente sono memorizzati un elemento dell'insieme ed un puntatore alla  */
/* componente successiva).                                                    */
/* La funzione determina ricorsivamente l'unione degli insiemi restituendo    */
/* il puntatore ad una nuova lista ottenuta inserendo alla prima elementi     */ 
/* della seconda non inclusi nella prima                                      */
/******************************************************************************/

l_reali* unione_insiemi(l_reali* n1, /* puntatori alla prima componente */
						l_reali* n2) /* delle liste in cui sono memorizzati 
										gli insiemi dei numeri reali */
{
  /* dichiarazione delle variabili locali alla funzione */
  l_reali* p1 = n1;		/* variabile di ritorno della funzione */

  /* caso base della ricorsione */
  if (n2 == NULL)                   	
    p1 = n1;
  /* passo ricorsivo */
  else if (inclusione_elemento(n2->numero,n1)) p1 = n2;
  
  /* per ogni elemento del secondo insieme non incluso nel primo insieme
  viene allocata dinamicamente una nuova componente della lista ed unita
  (inserimento in testa) a quelle del primo insieme */	
  else	  
  {	  
    n1 = (l_reali*) malloc(sizeof(l_reali)); 	
    n1->numero = n2->numero; 					
    n1->succ_p = p1; 	/* inserimento della nuova componente */					
    p1 = n1;
   /* passo ricorsivo */
   p1 = unione_insiemi(n1,                         		
		       n2->succ_p); 
  }   
  return (p1);
}






