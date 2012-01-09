/*
 * Created on January 8, 2012, 9:49 PM
 * By Laurent Victorino < laurent.victorino@gmail.com >
 */

#ifndef MACROS_H
#define	MACROS_H

#include "defines.h"

#define SCREEN2GL_X( X )  ( ( ( 2.0 / SCREEN_W ) * (X) ) -1.0 )
#define SCREEN2GL_Y( Y )  ( ( ( 2.0 / SCREEN_H ) * (Y) ) -1.0 )


#endif	/* MACROS_H */

