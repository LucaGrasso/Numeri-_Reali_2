/**************************************************************************/
/* File Header della libreria				  							  */
/*																		  */
/* intestazione della libreria per la gestione di insiemi di numeri reali */
/*																		  */
/**************************************************************************/

/***********************************************************/
/*   Autore: Grasso Luca                                   */
/***********************************************************/

/************************************/
/* Definizione dei tipi esportati */
/************************************/

typedef struct lista_reali
{
	float 	numero;								
	struct  lista_reali* succ_p; 					
}l_reali;

/********************************************/
/* ridichiarazione delle funzioni esportate */
/********************************************/

extern l_reali *insieme_reali (void);

extern void stampa_insieme(l_reali* n);

extern int inclusione_elemento(float r, 
			       l_reali* n);
						 
extern int inclusione_insieme(l_reali* n1, 
			      l_reali* n2);

extern l_reali* unione_insiemi(l_reali* n1, 
			       l_reali* n2);
