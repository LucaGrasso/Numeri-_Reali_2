/***********************************************************/
/*   Programma main di test della libreria numeri_reali    */
/***********************************************************/
/*   Autore: Grasso Luca                                   */
/***********************************************************/


/***********************************************************/
/* inclusione delle librerie                               */
/***********************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "numeri_reali.h" /* inclusione della libreria data come progetto */

/************************************************************/
/* definizione della funzione main                          */
/************************************************************/

int main(void) 
{
  /* dichiarazione delle variabili locali */	
  int k,              /* variabile di servizio (contatore) */
      j,              /* variabile di servizio (contatore) */
      esito_lettura;  /* variabile di validazione dei dati 
	  					 acquisiti da tastiera */
	  					 
  float r;            /* variabile per l'acquisizione 
		      			da tastiera di un numero reale */
		      			
  l_reali* p1;    /* variabili di servizio di tipo puntatore */
  l_reali* p2;    /* alla prima componente di una lista */
  l_reali* p3;    /* concatenata */
 
  l_reali* n1;    /* variabili di servizio di tipo puntatore */
  l_reali* n2;    /* ad una componente generica di una lista */
  l_reali* n3;    /* concatenata */
  
  /***********************************************************/
  /*Informazioni relative al test delle funzioni di libreria */
  /***********************************************************/
  printf("************************************************ \n");
  printf(" Programma di test della libreria: numeri_reali  \n");
  printf("************************************************ \n");
  printf("Funzioni appartenenti alla libreria: \n");
  printf("[1]: insieme_reali \n");
  printf("[2]: stampa_insieme \n");
  printf("[3]: inclusione_elemento \n");
  printf("[4]: inclusione_insieme \n");
  printf("[5]: unione_insiemi \n");
  printf("************************************************\n");
  printf("Il test prevede di invocare sequenzialmente ed in\n");
  printf("ordine di elenco tutte le funzioni di libreria   \n");
  printf("************************************************ \n");
  printf("\n");
  

  /***********************************************************/
  /* Test della funzione: insieme_reali                      */	
  /***********************************************************/
  printf("************************************************\n");
  printf("Test della funzione: insieme_reali \n");
  printf("************************************************\n");
  printf("\t\t Insieme A \n");	
  /* invocazione della funzione insieme_reali */
  p1 = insieme_reali();     
  n1 = p1;	      /*allineamento dei puntatori di servizio*/


  /***********************************************************/
  /* Test della funzione: stampa_insieme */ 
  /***********************************************************/
  /* Come parametro effettivo della funzione si considera    */
  /* l'insieme dei numeri reali generato dalla funzione      */
  /* insieme_reali (insieme A) precedentemente invocata      */	
  /***********************************************************/
  printf("************************************************\n");
  printf("Test delle funzione: stampa_insieme \n");
  printf("************************************************\n");
  printf("\t\t Insieme A \n");
  printf("************************************************\n");
  /* invocazione della funzione stampa_insieme */
  stampa_insieme (n1);    
  

  /***********************************************************/
  /* Test della funzione: inclusione_elemento                */
  /***********************************************************/
  /* Come parametri effettivi della funzione si considerano  */ 
  /* un numero reale acquisito da tastiera e l'insieme dei   */
  /* numeri reali generato dalla funzione insieme_reale      */
  /* precedentemente invocata (insieme A)                    */
  /***********************************************************/
  printf("************************************************\n");
  printf("Test della funzione inclusione_elemento \n");
  printf("************************************************\n");
  printf("Inserisci elemento da verificare nell'insieme A:\n");
  printf("************************************************\n");
  
  /* acquisizione del numero reale da tastiera */
  do
  {	 																		
    esito_lettura = scanf("%f",    
		 	  &r);
  /* validazione del dato acquisito */ 
    if (esito_lettura != 1)       
      printf(" Errore di inserimento!! \n Nuovo elemento: \n");
    while (getchar() != '\n');
  }
  while (esito_lettura !=1);
  
  n1 = p1;	   /* allineamento dei puntatori di servizio */
  
  /* invocazione della funzione inclusione_elemento */
  k = inclusione_elemento(r,
		          p1);    
  
  /* presentazione dei risultati */
  if (k == 0)                      
    printf("Il numero %f non è incluso nell'insieme A \n", r);
  else
    printf("Il numero %f è incluso nell'insieme A \n", r);
	
  
  /*************************************************************/
  /* Test della funzione: inclusione_insieme                   */
  /*************************************************************/
  /* Come parametri effettivi della funzione si considerano    */ 
  /* l'insieme dei numeri reali generato dalla funzione        */
  /* insieme_reali precedentemente invocata (insieme A) ed un  */
  /* insieme di numeri reali acquisiti da tastiera (insieme B) */
 /**************************************************************/
  printf("************************************************\n");
  printf("Test della funzione inclusione_insieme \n");
  printf("************************************************\n");
  printf("\t\t Insieme B \n");
  
  /* invocazione della funzione insieme_reali */
  p2 = insieme_reali();  
  n1 = p1;	     /* allineamento dei puntatori di servizio */
  n2 = p2;	     /* allineamento dei puntatori di servizio */
  
  /* invocazione della funzione inclusione insieme */
  j = inclusione_insieme(n1, 
		         n2);  
 
  /* presentazione dei risultati */
  if (j == 0)  			 
    printf("Insieme A non incluso nell'insieme B \n");
  else
    printf("Insieme A incluso nell'insieme B \n");


  /***********************************************************/
  /* Test della funzione: unione_insiemi                     */
  /***********************************************************/
  /* Come parametri effettivi della funzione si considerano  */
  /* gli insiemi di numeri reali generati dalle precedenti   */
  /* invocazioni della funzione insieme_reale (insieme A e B)*/
  /***********************************************************/
  printf("************************************************\n");
  printf("Test della funzione unione_insiemi \n");
  printf("************************************************\n");
  n1 = p1;	   /* allineamento dei puntatori di servizio */
  n2 = p2;	   /* allineamento dei puntatori di servizio */
  
  /* invocazione della funzione unione_insiemi */
  p3 = unione_insiemi(n1, 
		      n2);   
  
  /* presentazione dei risultati */
  printf("************************************************\n");
  printf("Unione dell'insieme A con l'insieme B \n");
  printf("************************************************\n");
  n3 = p3;	   /* allineamento dei puntatori di servizio */
  /* invocazione della funzione stampa_insieme */
  stampa_insieme (n3);  

  return (0);
}
