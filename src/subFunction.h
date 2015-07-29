#ifndef subFunction_H
#define subFunction_H

//Own module files
#include "Token.h"
#include "subFunction.h"
#include "OperatorChecker.h"
#include "CException.h"

// Library 
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


typedef struct {
	char *str;
	int index;	
  Token* tokenStorage;
}StringObject;


StringObject *createStringObject(char *ch);
char *createSubString(char *str, int start , int length);
void checkFirstCh ( StringObject* strO , TokenState *currentState, int* startColumn);


#endif // subFunction_H

// extern int d; //.h
// extern int arr[] //.h

// int d = 4; // .c
