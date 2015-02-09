/******************************************************************************/
/* RETARGET.C: 'Retarget' layer for target-dependent low level functions      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005 Keil Software. All rights reserved.                     */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <stdio.h>

extern int  sendchar(int ch);  /* in Serial.c */
extern int  getkey(void);      /* in Serial.c */

struct __FILE { void* handle; /* Add whatever you need here */ };
FILE __stdout={(void *)sendchar};
FILE __stdin={(void *)getkey};

typedef int (*__inputFile_t)(void);
typedef int (*__outputFile_t)(int);

int fputc(int ch, FILE *f) {
  return ((__outputFile_t)(f->handle))(ch);
}

int fgetc(FILE *f) {
  return ((__inputFile_t)(f->handle))();
}


int ferror(FILE *f) {
  /* Your implementation of ferror */
  return EOF;
}
