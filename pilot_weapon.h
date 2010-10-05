/*
 * See Licensing and Copyright notice in naev.h
 */


#ifndef PILOT_WEAPON_H
#  define PILOT_WEAPON_H


#include "pilot.h"


/* Freedom. */
void pilot_weapSetFree( Pilot* p );

/* Shooting. */
int pilot_shoot( Pilot* p, int level );
void pilot_shootStop( Pilot* p, int level );


/* Updating. */
void pilot_weapSetPress( Pilot* p, int id, int type );
void pilot_weapSetUpdate( Pilot* p );


/* Weapon Set. */
void pilot_weapSetExec( Pilot* p, int id );
int pilot_weapSetModeCheck( Pilot* p, int id );
void pilot_weapSetMode( Pilot* p, int id, int fire );
const char *pilot_weapSetName( Pilot* p, int id );
void pilot_weapSetNameSet( Pilot* p, int id, const char *name );
void pilot_weapSetAdd( Pilot* p, int id, PilotOutfitSlot *o, int level );
void pilot_weapSetRm( Pilot* p, int id, PilotOutfitSlot *o );
int pilot_weapSetCheck( Pilot* p, int id, PilotOutfitSlot *o );
double pilot_weapSetRange( Pilot* p, int id, int level );
double pilot_weapSetSpeed( Pilot* p, int id, int level );
void pilot_weapSetCleanup( Pilot* p, int id );
PilotWeaponSetOutfit* pilot_weapSetList( Pilot* p, int id, int *n );


/* High level. */
void pilot_weaponClear( Pilot *p );
void pilot_weaponAuto( Pilot *p );


#endif /* PILOT_WEAPON_H */
