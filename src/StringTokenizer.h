#ifndef StringTokenizer_H
#define StringTokenizer_H

#include "Token.h"
#include "CException.h"
#include "ErrorCode.h"
#include "ErrorObject.h"
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

#define TEST_ASSERT_OPERATOR_TOKEN(ExSymbol,ExStartC,ExLen,ExStr,Token)   \
				{																																	\
				TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,Token->type);				  			\
				TEST_ASSERT_EQUAL_STRING(ExSymbol,Token->symbol);				    			\
				TEST_ASSERT_EQUAL(ExStartC,Token->startColumn);			  						\
				TEST_ASSERT_EQUAL(ExLen,Token->length);									  				\
				TEST_ASSERT_EQUAL_STRING(ExStr,Token->str);									  		\
				}
        
#define  TEST_ASSERT_IDENTIFIER_TOKEN(ExName,ExStartC,ExLen,ExStr,Token)   \
        {                                                                 \
				TEST_ASSERT_EQUAL(TOKEN_IDENTIFIER_TYPE,Token->type);				  			\
				TEST_ASSERT_EQUAL_STRING(ExName,Token->name);				    		    	\
				TEST_ASSERT_EQUAL(ExStartC,Token->startColumn);			  						\
				TEST_ASSERT_EQUAL(ExLen,Token->length);									  				\
				TEST_ASSERT_EQUAL_STRING(ExStr,Token->str);									  		\
        }
          
#define  TEST_ASSERT_STRING_TOKEN(ExName,ExStartC,ExLen,ExStr,Token)       \
        {                                                                 \
				TEST_ASSERT_EQUAL(TOKEN_STRING_TYPE,Token->type);				  		   	\
				TEST_ASSERT_EQUAL_STRING(ExName,Token->name);				    		    	\
				TEST_ASSERT_EQUAL(ExStartC,Token->startColumn);			  						\
				TEST_ASSERT_EQUAL(ExLen,Token->length);									  				\
				TEST_ASSERT_EQUAL_STRING(ExStr,Token->str);									  		\
        }
 
#define TEST_ASSERT_FLOAT_TOKEN(ExValue,ExStartC,ExLen,ExStr,Token)        \
				{																																	\
				TEST_ASSERT_EQUAL(TOKEN_FLOAT_TYPE,Token->type);				  			  \
				TEST_ASSERT_EQUAL_FLOAT(ExValue,Token->value);									  			\
				TEST_ASSERT_EQUAL(ExStartC,Token->startColumn);			  						\
				TEST_ASSERT_EQUAL(ExLen,Token->length);									  				\
				TEST_ASSERT_EQUAL_STRING(ExStr,Token->str);									  		\
				}  
       

typedef struct {
	char *str;
	int index;	
  Token* tokenStorage;
}StringObject;

typedef enum{

	InitialState,
	IntegerState,
	IdentifierState,
	StringState,
	OperatorState,
	FloatingState,
	TwinAssignState,
  DecimalPointState,
  ExponentState,
  NegPosExponentState,
  HexdecimalState,
  OctalState,
	UnknownState
	
}TokenState;

Token *getToken(StringObject *str);
void TransitionForInt(Token**newToken, TokenState* currentState , StringObject* strO );
void TransitionForIni(Token** newToken, TokenState* currentState , StringObject* strO);
void TransitionForOp(Token** newToken, TokenState* currentState , StringObject* strO);
void TransitionForTwinAssign(Token** newToken, TokenState* currentState , StringObject* strO);
void TransitionForStr(Token** newToken, TokenState* currentState , StringObject* strO);
void TransitionForIden(Token** StrTk, TokenState* currentState , StringObject* strO);
void TransitionForDecPointState(Token** IdenTk, TokenState* currentState , StringObject* strO);
void TransitionForFloat(Token** FloatTk, TokenState* currentState , StringObject* strO);
void TransitionForExpon(Token** FloatTk, TokenState* currentState , StringObject* strO);
void TransitionForNegPosExpon(Token** FloatTk, TokenState* currentState , StringObject* strO);
void TransitionForHex(Token** FloatTk, TokenState* currentState , StringObject* strO);
void TransitionForOct(Token** FloatTk, TokenState* currentState , StringObject* strO);


// void throwError(char *message, ErrorCode errCode);
// void freeError(ErrorObject* errObj);
#endif // StringTokenizer_H
