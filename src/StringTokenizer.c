#include "ErrorCode.h"
#include "Token.h"
#include "StringTokenizer.h"
#include "CException.h"
#include "subFunction.h"

#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define curChar (strO->str[strO->index])
#define nextChar (strO->str[strO->index+1])
#define prevChar (strO->str[strO->index-1])
#define isdigit_OR_alpha(x) (isdigit(x) || isalpha(x))
#define isSpace_OR_0_OR_n(x) ( x == ' ' || x == '\n' || x == '\0' )
#define isknown(x) (isoperator(x) == 0 && isdigit(x) == 0 && isalpha(x) == 0 && x != '\0' && x != '\n' && x != ' ' )
//#define getSymbol(X,Y) (createSubString(X->str,Y->startColumn,Y->length))

Token *StringTokenizer(StringObject *strO){
		if( strO == NULL){
			 Throw(-5); 	// throwError("String Object can't be NULL",ERR_STR_OBJECT_CANNOT_BE_NULL);
		}
	  Token* newToken = malloc(sizeof(Token)); 
		TokenState currentState = InitialState;
		newToken->startColumn = strO->index;
		int loop = 0;
		printf("-----------------\n");
   // printf("newToken->startColumn  = %d\n",newToken->startColumn);
		while (loop < 100)
		{
				switch (currentState)
			{
					case InitialState:
					{
					printf("InitialState\n");
					TransitionForIni(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_OPERATOR_TYPE){	
						return newToken;
					 }
						break;
					}//end of InitialState
					case IntegerState:
					{
					printf("IntegerState\n");
					TransitionForInt(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_INTEGER_TYPE){	
						return newToken;
					 }
					break;
					}//end of IntegerState 
			   			
						
					case FloatingState:
					break;
						
					case StringState:
					break;
					
					case IdentifierState:
					break;
					
					case OperatorState:
					printf("OperatorState\n");
					TransitionForOp(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_OPERATOR_TYPE){	
						return newToken;
					 }
					break;
					
					case TwinAssignState:
					printf("TwinAssignState\n");
					TransitionForTwinAssign(&newToken,&currentState,strO);
					if (newToken->type == TOKEN_OPERATOR_TYPE){
						return newToken;
					}
					break;
					
					default:InitialState;
					break;
					
		  } //end of switch 
			loop++;
	}//end of while loop
		printf("return outside\n");
		return newToken;
}//end of program

void TransitionForIni(Token** newToken, TokenState* currentState , StringObject* strO){
						if(strO->str == NULL){
						Throw(-4);	// throwError("The String can't be a NULL",ERR_STR_CANNOT_BE_NULL);
						}else if(curChar == ' '){
							(strO->index)++;
							(*newToken)->startColumn = strO->index;
						}else if(curChar == '\0'){
							*newToken = createEndStrToken("$"); 
						}else if (isknown(curChar)){
								Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
						}else {
							checkFirstCh(strO,currentState,&((*newToken)->startColumn));
						}
}

void TransitionForInt(Token** InTk, TokenState* currentState , StringObject* strO){
						 
					if( isdigit(curChar) ) 
					{
					//	printf("strO->str[%d] = %c\n",strO->index,strO->str[strO->index]); 
						*currentState = IntegerState;
						(strO->index)++;
					}else if( isSpace_OR_0_OR_n(curChar)  || isoperator(curChar))
					{
						printf("Create Token\n");
            (*InTk)->length = strO->index - (*InTk)->startColumn;
						if(curChar != '\0' ){
						(strO->index)++;
						}
				//###		*InTk = createIntegerToken(getValue(strO,*InTk),(*InTk)->startColumn,(*InTk)->length,strO->str);
            *InTk = createIntegerToken (strO->str,(*InTk)->startColumn,(*InTk)->length);
					 }else if ( isalpha(curChar) )
					{	
						Throw(-1); 	// throwError("The String can't include Alpha",ERR_STR_INCLURE_ALPHA);
					}			

}


//"1234\012423"

void TransitionForOp(Token** OpTk, TokenState* currentState , StringObject* strO){
					printf("curChar = %c\n",curChar);
					if ( isSpace_OR_0_OR_n(nextChar)  || isdigit_OR_alpha(nextChar) || issingle(curChar) ){
						printf("Create Token\n");
						(strO->index)++;
						(*OpTk)->length = strO->index - (*OpTk)->startColumn;
						//###*OpTk = createOperatorToken(getSymbol(strO,*OpTk),(*OpTk)->startColumn,(*OpTk)->length,strO->str);
            *OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
					}else if ( istwin(curChar) || isassign(curChar) ){
						(strO->index)++;
						*currentState = TwinAssignState;
					}else if ( isoperator(nextChar) == 0)  {
						Throw(ERR_STR_CANNOT_CONTAIN_INVALID_OPERATOR);
					}
}


void TransitionForTwinAssign(Token** OpTk, TokenState* currentState , StringObject* strO){
				if (istwinassign(curChar)){
					(strO->index)++;
				//	advance(strO);
				}else if (curChar == '=' || ((curChar == prevChar)&&istwin(curChar)) ){
					printf("Create Token\n");
					(strO->index)++;  
					//printf("curChar = %c\n",curChar);
          if(isknown(curChar)){
              Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
					}
					(*OpTk)->length = strO->index - (*OpTk)->startColumn;
				//###	*OpTk = createOperatorToken( getSymbol(strO,*OpTk),(*OpTk)->startColumn,(*OpTk)->length,strO->str);
          *OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
				}else if(isoperator(curChar)){
					printf("Create Token\n");
					(*OpTk)->length = strO->index - (*OpTk)->startColumn;
				//###*OpTk = createOperatorToken(getSymbol(strO,*OpTk),(*OpTk)->startColumn,(*OpTk)->length,strO->str);
            *OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
	
        }
}

void dumpToken(Token* newToken){
	char* tokenType;
	switch(newToken->type){
	case TOKEN_UNKNOWN_TYPE:
				tokenType = "TOKEN_UNKNOWN_TYPE";
				break;
	case TOKEN_INTEGER_TYPE:
					tokenType = "TOKEN_INTEGER_TYPE";
					IntegerToken* InTk = (IntegerToken*)newToken;
					printf("value = %d,",InTk->value);
				break;
	case TOKEN_OPERATOR_TYPE:
					tokenType = "TOKEN_OPERATOR_TYPE";
					OperatorToken* OpTk = (OperatorToken*)newToken;
					printf("symbol = %s,",OpTk->symbol);
				break;
	case TOKEN_FLOAT_TYPE:
					tokenType = "TOKEN_FLOAT_TYPE";
				break;
	case TOKEN_STRING_TYPE:
					tokenType = "TOKEN_STRING_TYPE";
				break;
	case TOKEN_IDENTIFIER_TYPE:
					tokenType = "TOKEN_IDENTIFIER_TYPE";
				break;
	default:break;
	}
	printf("[%s]\n",tokenType);
}
