#ifndef subFunction_H
#define subFunction_H
#include "StringTokenizer.h"
#include <malloc.h>
#include "Token.h"
#include "CException.h"
#include <string.h>
#include <ctype.h>
#include "ErrorCode.h"
#include <stdio.h>
#include "subFunction.h"
#define issingle(x) (isSingle(operatorAtrributes[x]))
#define isoperator(x) (isOperator(operatorAtrributes[x]))
#define istwin(x) (isTwin(operatorAtrributes[x]))
#define isassign(x) (isAssign(operatorAtrributes[x]))
#define istwinassign(x) (isTwinAssign(operatorAtrributes[x]))
#define SINGLE (1<<0)
#define TWIN (1<<1)
#define ASSIGNMENT (1<<2)
#define TWIN_ASSIGNMENT (1<<3)

extern int operatorAtrributes[];
StringObject *createStringObject(char *ch);
char *createSubString(char *str, int start , int length);
void checkFirstCh ( StringObject* strO , TokenState *currentState, int* startColumn);
int getValue (StringObject* strO, Token* InTk);
char *getSymbol (StringObject* strO,Token* OpTk);

void printError(int err);

int isSingle(int Operator);
int isTwin(int Operator);
int isAssign(int Operator);
int isTwinAssign(int Operator);
int isOperator(int Operator);
#endif // subFunction_H

// extern int d; //.h
// extern int arr[] //.h

// int d = 4; // .c
