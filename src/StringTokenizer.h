#ifndef StringTokenizer_H
#define StringTokenizer_H

#include "Token.h"
#include "CException.h"
#include "ErrorCode.h"

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <malloc.h>

#define TEST_LAST_TOKEN(Token)																			\
				{																														\
				TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,Token->type);					\
				TEST_ASSERT_EQUAL_STRING("$",Token->symbol);								\
				}																														\


#define TEST_ASSERT_INTEGER_TOKEN(ExValue,ExStartC,ExLen,ExStr,Token)     \
				{																																	\
				TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,Token->type);				  			\
				TEST_ASSERT_EQUAL(ExValue,Token->value);									  			\
				TEST_ASSERT_EQUAL(ExStartC,Token->startColumn);			  						\
				TEST_ASSERT_EQUAL(ExLen,Token->length);									  				\
				TEST_ASSERT_EQUAL_STRING(ExStr,Token->str);									  		\
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
	FloatingState,
	UnknownState
	
}TokenState;

Token *StringTokenizer(StringObject *str);
void TransitionForInt(Token**InTk, TokenState* currentState , StringObject* strO );
void TransitionForIni(Token** newToken, TokenState* currentState , StringObject* strO);
void TransitionForOp(Token** newToken, TokenState* currentState , StringObject* strO);

#endif // StringTokenizer_H
