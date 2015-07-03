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

#define TEST_LAST_TOKEN(Token)																			\
				{																														\
				TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,Token->type);					\
				TEST_ASSERT_EQUAL_STRING("$",Token->symbol);								\
				}																														\

#define TEST_INTEGER_TOKEN(Expect,Token)														\
				{																														\
				TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,Token->type);				  \
				TEST_ASSERT_EQUAL(Expect,Token->value);									  	\
				}

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
void TransitionForInt(Token**InTk, TokenState* currentState , StringObject* strO );

#endif // StringTokenizer_H
