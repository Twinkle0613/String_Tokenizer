#ifndef StringTokenizer_H
#define StringTokenizer_H

////Own modules file
#include "OperatorChecker.h"
#include "Token.h"
#include "CException.h"
#include "subFunction.h"
#include "ErrorObject.h"
#include "TextCode.h"
//Library
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <malloc.h>

StringObject *createStringObject(char *ch);
void stateTransition( StringObject* strO , TokenState *currentState, int* startColumn);
Token *peepToken(StringObject *strO);
Token *getToken(StringObject *strO);
void transitionForInt(TokenState* currentState , StringObject* strO );
void transitionForIni(TokenState* currentState , StringObject* strO);
void transitionForOp(TokenState* currentState , StringObject* strO);
void transitionForTwinAssign(TokenState* currentState , StringObject* strO);
void transitionForStr(TokenState* currentState , StringObject* strO);
void transitionForIden(TokenState* currentState , StringObject* strO);
void transitionForDecPointState(TokenState* currentState , StringObject* strO);
void transitionForFloat(TokenState* currentState , StringObject* strO);
void transitionForExpon(TokenState* currentState , StringObject* strO);
void transitionForNegPosExpon(TokenState* currentState , StringObject* strO);
void transitionForHex(TokenState* currentState , StringObject* strO);
void transitionForOct(TokenState* currentState , StringObject* strO);

#endif // StringTokenizer_H
