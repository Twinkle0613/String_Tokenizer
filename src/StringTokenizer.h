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

Token *peepToken(StringObject *strO);
Token *getToken(StringObject *strO);
void TransitionForInt(TokenState* currentState , StringObject* strO );
void TransitionForIni(TokenState* currentState , StringObject* strO);
void TransitionForOp(TokenState* currentState , StringObject* strO);
void TransitionForTwinAssign(TokenState* currentState , StringObject* strO);
void TransitionForStr(TokenState* currentState , StringObject* strO);
void TransitionForIden(TokenState* currentState , StringObject* strO);
void TransitionForDecPointState(TokenState* currentState , StringObject* strO);
void TransitionForFloat(TokenState* currentState , StringObject* strO);
void TransitionForExpon(TokenState* currentState , StringObject* strO);
void TransitionForNegPosExpon(TokenState* currentState , StringObject* strO);
void TransitionForHex(TokenState* currentState , StringObject* strO);
void TransitionForOct(TokenState* currentState , StringObject* strO);

#endif // StringTokenizer_H
