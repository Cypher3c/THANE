/*
 * See Licensing and Copyright notice in naev.h
 */



#ifndef ECONOMY_H
#  define ECONOMY_H


#include <stdint.h>


#define ECON_CRED_STRLEN      32 /**< Maximum length a credits2str string can reach. */


/**
 * @struct Commodity
 *
 * @brief Represents a commodity.
 *
 * @todo Use inverse normal?
 */
typedef struct Commodity_ {
   char* name; /**< Name of the commodity. */
   char* description; /**< Description of the commodity. */
   /* Prices. */
   double price; /**< Base price of the commodity. */
} Commodity;


/*
 * Commodity stuff.
 */
Commodity* commodity_get( const char* name );
Commodity* commodity_getW( const char* name );
int commodity_load (void);
void commodity_free (void);


/*
 * Economy stuff.
 */
int economy_init (void);
int economy_update( unsigned int dt );
int economy_refresh (void);
void economy_destroy (void);


/*
 * Misc stuff.
 */
void credits2str( char *str, uint64_t credits, int decimals );
void commodity_Jettison( int pilot, Commodity* com, int quantity );


#endif /* ECONOMY_H */
