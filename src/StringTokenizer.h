#ifndef StringTokenizer_H
#define StringTokenizer_H
#include "Token.h"
#include "CException.h"
#include <string.h>
#include <ctype.h>
#include "Token.h"
#include "ErrorCode.h"
#include <stdio.h>
#include <malloc.h>



typedef struct {
	char *str;
	int index;	
}StringObject;

typedef enum{
	InitialState,
	IntegerState,
	IdentifierState,
	StringState,
	OperatorState,
	FloatingState
	
}TokenState;

Token *StringTokenizer(StringObject *str);
StringObject *createStringObject(char *str);
void printError(int err);
void TransitionForInt(Token**InTk, TokenState* currentState , StringObject* strO);
#endif // StringTokenizer_H
