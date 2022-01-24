/*
 * inclusione delle librerie
 */

#include <stdio.h>
#include <stdlib.h>

#include "insiemi_numeri_reali.h"

/*
 * dichiarazione delle funzioni
 */

eleinsieme_t *acquisisci_insieme();

void visualizza_insieme(const eleinsieme_t*);

int num_appartiene_insieme(double,
                           const eleinsieme_t*);

int insieme_incluso_insieme(const eleinsieme_t*,
                            const eleinsieme_t*);

eleinsieme_t *insieme_unione_insieme(const eleinsieme_t*,
                                     const eleinsieme_t*);

int input_valido();

/*
 * definizione delle funzioni
 */

/* definizione della funzione acquisisci_insieme */

eleinsieme_t *acquisisci_insieme()
{
  /* definizione variabili locali della funzione */
  int dim,                    /* input: numero elementi insieme */
      input_ok,               /* lavoro: validazione del valore */     
      i,                      /* lavoro: inserimento e confronto valori */
      appartiene;             /* lavoro: risultato appartenenza */
  double num_reale;           /* input: numero reale acquisito */
  eleinsieme_t *insieme=NULL, /* output: insieme inserito e validato */
               *primo=NULL;   /* lavoro: confronto elemento se presente */

  /* inserimento e validazione del numero di elementi dell'insieme */
  do
  {    
    printf("Inserire quanti elementi deve contenere l'insieme (>=0): ");
    scanf("%d",
          &dim);
    input_ok = input_valido(); /* valida il numero appena inserito */
    if (!input_ok || dim < 0) printf("Valore inserito non valido.\n");
  }
  while ((!input_ok || dim < 0)); /* validazione fallita o numero negativo */

  /* inserimento e validazione del valore degli elementi dell’insieme */
  for(i=1; 
      i<=dim;
      i++)
  {
    do
    {
      /* acquisire ogni elemento dell'insieme */
      printf("Inserire il valore del %d^ elemento: ",
             i);
      scanf(" %lf",
            &num_reale);
      input_ok = input_valido();
      if (!input_ok) printf("Valore inserito non valido.\n");
      appartiene = (num_appartiene_insieme(num_reale, primo));
      if (appartiene) printf("Valore gia' presente nell'insieme.\n");
    }
    /* rimane nel ciclo se il numero è già presente */
    while ((!input_ok) || (appartiene));
    if (i == 1)
    {
      /* allocazione della memoria dello heap per il primo elemento */
      insieme = (eleinsieme_t *) malloc (sizeof(eleinsieme_t));
      /* salva il primo elemento per controllare
         i numeri già presenti nell'insieme */
      primo = insieme;
    }
    else
    {
      /* allocazione della memoria dello heap per il successivo elemento */
      insieme->prox = (eleinsieme_t *) malloc (sizeof(eleinsieme_t));
      /* avanza al successivo elemento */
      insieme = insieme->prox;
    }
    /* associa il numero inserito ed inizalizza il link */
    insieme->numero = num_reale;
    insieme->prox = NULL;
  }
  if (insieme != NULL) insieme = primo; /* si posiziona sul primo elemento 
                                           dell'insieme */
  
  /* restituzione del risultato dell'insieme */
  return(insieme);
}

/* definizione della funzione visualizza_insieme */

void visualizza_insieme(const eleinsieme_t *insieme)
{
  if (insieme != NULL) /* se l'elemento esiste */
  {
    /* stampare a video l'elemento dell'insieme in ingresso */
    printf("%f\n",
           insieme->numero);
    
    /* in caso di almeno un elemento, la funzione invoca se stessa */
    visualizza_insieme(insieme->prox);
  }
  return;
}

/* definizione della funzione num_appartiene_insieme */

int num_appartiene_insieme(double numero_r,
                           const eleinsieme_t *insieme)
{
  /* definizione variabili locali della funzione */
  int appartiene; /* output: risultato appartenenza */
  
  /* se insieme vuoto restituisce non appartenenza */
  if (insieme == NULL) appartiene = 0;
  
  /* confronto tra numero reale ed elemento dell'insieme */
  else if (insieme->numero == numero_r) appartiene = 1; /* il numero coincide 
                                                           con l'elemento */
       /* chiamata ricorsiva con l'elemento successivo */  
       else
         appartiene = num_appartiene_insieme(numero_r, insieme->prox);
  
  return(appartiene);
}

/* definizione della funzione insieme_incluso_insieme */

int insieme_incluso_insieme (const eleinsieme_t *sottoinsieme,
                             const eleinsieme_t *insieme)
{
  /* definizione variabili locali della funzione */
  int appartiene; /* output: risultato appartenenza */

  if (sottoinsieme == NULL) appartiene = 1; /* il sottoinsieme è vuoto */
  else if (insieme == NULL) appartiene = 0; /* l'insieme è vuoto */
  else if (!num_appartiene_insieme(sottoinsieme->numero, insieme))
         appartiene = 0; /* elemento non trovato nell'insieme */
       else
         /* elemento trovato, passa al successivo */
         appartiene = insieme_incluso_insieme(sottoinsieme->prox, insieme);
  
  return(appartiene);
}

/* definizione della funzione insieme_unione_insieme */

eleinsieme_t *insieme_unione_insieme(const eleinsieme_t *insieme_1,
                                     const eleinsieme_t *insieme_2)
{
  /* definizione variabili locali della funzione */
  eleinsieme_t *unione_insiemi = NULL, /* output: insieme unione */
               *primo = NULL;          /* lavoro: confronto se presente */

  if (insieme_1 != NULL) /* insieme_1 non vuoto */
  {
    /* duplicazione insieme_1 e creazione del primo nodo */
    unione_insiemi = (eleinsieme_t *) malloc(sizeof(eleinsieme_t));
    primo=unione_insiemi; /* salva il primo elemento */
    /* copia insieme_1 in unione_insiemi */
    do
    {
      unione_insiemi->numero = insieme_1->numero; /* copia il valore */
      if (insieme_1->prox) /* nodo successivo non vuoto */
      {
        /* crea un nuovo nodo di coda */
        unione_insiemi->prox = (eleinsieme_t *) malloc(sizeof(eleinsieme_t));
        unione_insiemi = unione_insiemi->prox; /* va sul nuovo nodo di coda */
      }
      else /* nodo successivo vuoto */
      {
        unione_insiemi->prox = NULL; /* azzera riferimento al nodo successivo */
      }
      insieme_1=insieme_1->prox; /* va al nuovo successivo di insieme_1 */
    }
    while (insieme_1); /* insieme_1 non vuoto */
    unione_insiemi=primo;

    if (insieme_2!=NULL) /* insieme_2 non vuoto */
    {
      /* scorre l'insieme fino all'ultimo elemento */
      while (unione_insiemi->prox != NULL)
        { unione_insiemi = unione_insiemi->prox; }

      if (num_appartiene_insieme(insieme_2->numero, primo) == 0)
      /* l'elemento non apppartiene all'insieme */
      {
        /* inserisce l'elemento in coda */
        unione_insiemi->prox = (eleinsieme_t *) malloc(sizeof(eleinsieme_t));
        unione_insiemi = unione_insiemi->prox;
        unione_insiemi->numero = insieme_2->numero;
        unione_insiemi->prox = NULL;
      }
      /* chiamata ricorsiva per valutare l'elemento successivo di insieme_2 */
      unione_insiemi = insieme_unione_insieme(primo, 
                              insieme_2->prox);
    }
  }
  else if (insieme_2 != NULL) /* insieme_2 non vuoto */
  {
    /* duplicazione insieme_2 e creazione del primo nodo */
    unione_insiemi = (eleinsieme_t *) malloc(sizeof(eleinsieme_t));
    primo=unione_insiemi; /* salva il primo elemento */
    /* copia insieme_2 in unione_insiemi */
    do
    {
      unione_insiemi->numero = insieme_2->numero; /* copia il valore */
      if (insieme_2->prox) /* nodo successivo non vuoto */
      {
        /* crea un nuovo nodo di coda */
        unione_insiemi->prox = (eleinsieme_t *) malloc(sizeof(eleinsieme_t));
        unione_insiemi = unione_insiemi->prox; /* va sul nuovo nodo di coda */
      }
      else /* nodo successivo vuoto */
      {
        unione_insiemi->prox = NULL; /* azzera riferimento al nodo successivo */
      }
      insieme_2=insieme_2->prox; /* va al nuovo successivo di insieme_2 */
    }
    while (insieme_2); /* insieme_2 non vuoto */
    unione_insiemi=primo;
  }

  return(unione_insiemi);
}

/* definizione della funzione interna input_valido */

int input_valido()
{
  /* definizione variabili locali della funzione */
  int input_ok = 1; /* lavoro: validazione del valore */
  char cestino;     /* lavoro: eventuali valori non ammessi */
  do
  {
    cestino=getchar();
    if (cestino != '\n')
    {
      input_ok=0;
    }
  }
  while (cestino != '\n');

  return input_ok;
}
