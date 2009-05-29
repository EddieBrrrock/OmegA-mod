/*
===========================================================================
Copyright (C) 2009 Karl Kuglin

This file is part of the Open Arena source code.

Open Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Open Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Open Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

//Cvars Needed
extern  vmCvar_t    g_sprees; //Used for specifiying the config file
extern  vmCvar_t    g_altExcellent; //Turns on Multikills instead of Excellent
extern  vmCvar_t    g_spreeDiv; // Interval of a "streak" that form the spree triggers

//definitions
//These are the levels of the killing sprees, naming conventions are popular ones.
// I'd say 32 sprees is a lot!!! 
#define MAX_KSPREE      32
#define MAX_DSPREE      32

#define CENTER_PRINT    1
#define CHAT            2


typedef struct killspree
{
    int                 spreeLevel;
    int                 streakCount; //Added programatically based off SpreeDivisor. 
    char                spreeMsg[ MAX_STRING_CHARS ];
    char                sound2Play[ MAX_STRING_CHARS ];
    int                 position;
} killspree_t;


typedef struct deathspree
{
    int                 spreeLevel;
    int                 streakCount; //Added programatically based off SpreeDivisor.
    char                spreeMsg[ MAX_STRING_CHARS ];
    char                sound2Play[ MAX_STRING_CHARS ];
    int                 position;
} deathspree_t;

//function declarations
qboolean    G_ReadAltKillSettings( gentity_t *ent, int skiparg );
void        G_RunStreakLogic( gentity_t *attacker, gentity_t *victim );
void        G_CheckForSpree( gentity_t *ent, int streak2Test, qboolean checkKillSpree );

