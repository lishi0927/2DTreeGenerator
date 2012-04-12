/*
 * Created on January 8, 2012, 9:49 PM
 * By Laurent Victorino < laurent.victorino@gmail.com >
 */

#ifndef MACROS_H
#define	MACROS_H

#include "defines.h"

#define SCREEN2GL_X( X )  ( ( ( 2.f / SCREEN_W ) * (X) ) -1.f )
#define SCREEN2GL_Y( Y )  ( ( ( 2.f / SCREEN_H ) * (Y) ) -1.f )
#define SCREEN2GL_Z( Z )  ( ( ( 2.f / SCREEN_H ) * (Z) ) -1.f )


#endif	/* MACROS_H */

