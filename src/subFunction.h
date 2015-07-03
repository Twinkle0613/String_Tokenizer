#ifndef subFunction_H
#define subFunction_H
#include "StringTokenizer.h"
#include <malloc.h>
#include "Token.h"
#include "CException.h"
#include <string.h>
#include <ctype.h>
#include "Token.h"
#include "ErrorCode.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "subFunction.h"

StringObject *createStringObject(char *ch);
void printError(int err);
char *createSubString(char *str, int start , int length);
void checkFirstCh ( StringObject* strO , TokenState *currentState, int* startColumn);
int getValue (StringObject* strO, Token* InTk);

#endif // subFunction_H
