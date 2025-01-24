/* INF1900-6674 : Debug.h
 * Nom des auteurs: Anders Antoine, Nimet Tshienda Mulji et Tsarra Glory Randrianandraina 
   Date: 2024-04-17
 * Description du programme: Le but de cette classe est d'aider le déboggage de l'application qui utilisera éventuellement la librairie 
 *
 * 
*/

void printf(char* data);

#define DEBUG 
#ifdef DEBUG

#define DEBUG_PRINT(data) printf(data) 

#else
#define DEBUG_PRINT(data) do {} while (0)
#endif