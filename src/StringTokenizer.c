#include "ErrorCode.h"
#include "Token.h"
#include "StringTokenizer.h"
#include "CException.h"
#include "subFunction.h"

#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define curChar strO->str[strO->index]

Token *StringTokenizer(StringObject *strO){
		if( strO == NULL){
			 Throw(-5); 	// throwError("String Object can't be NULL",ERR_STR_OBJECT_CANNOT_BE_NULL);
		}
	  Token* newToken = malloc(sizeof(Token)); 
		TokenState currentState = InitialState;
		newToken->startColumn = strO->index;
		int loop = 0;
		printf("-----------------\n");
    printf("newToken->startColumn  = %d\n",newToken->startColumn);
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

void TransitionForInt(Token** InTk, TokenState* currentState , StringObject* strO){
						 
					if( isdigit(curChar) ) 
					{
						printf("strO->str[%d] = %c\n",strO->index,strO->str[strO->index]); 
						*currentState = IntegerState;
						(strO->index)++;
					}else if(curChar == ' ' || curChar  == '\n' || curChar == '\0' || isoperator(curChar))
					{
						printf("Create Token\n");
            (*InTk)->length = strO->index - (*InTk)->startColumn;
						if(curChar != '\0' ){
						(strO->index)++;
						}
						*InTk = createIntegerToken(getValue(strO,*InTk),(*InTk)->startColumn,(*InTk)->length,strO->str);
					 }else if ( isalpha(curChar) )
					{	
						Throw(-1); 	// throwError("The String can't include Alpha",ERR_STR_INCLURE_ALPHA);
					}			
}


void TransitionForIni(Token** newToken, TokenState* currentState , StringObject* strO){
						if(strO->str == NULL){
						Throw(-4);	// throwError("The String can't be a NULL",ERR_STR_CANNOT_BE_NULL);
						}else if(curChar == ' '){
							(strO->index)++;
						}else if(curChar == '\0'){
							*newToken = createEndStrToken("$"); 
						}	else {
							checkFirstCh(strO,currentState,&((*newToken)->startColumn));
						}
}



void TransitionForOp(Token** newToken, TokenState* currentState , StringObject* strO){
	
	
}

/*
'+', '-', '', '/', '\', '~', '!', '%', '^', '&', '&&', '{', '}', '[', 
']', '|', '||', '!', '?', '>', '<'. '>=', '<=', '=', '==', '.', ',', '+=',
 '-=', '/=', '=', '|=', '&=', ':', ';', '++', '--', '#', '(', ')', '@'.
 */

 // int isOperator(char symbol){
	 
	 // switch (symbol)
	 // case '+':  return 1; d 
	 // case '-':  return 1; d 
	 // case '*':  return 1; d
	 // case '*=':  return 1; d
	 // case '/':  return 1; d
	 // case '\\': return 1;
	 // case '~':  return 1; d
	 // case '!':  return 1; d
	 // case '%':  return 1; d
	 // case '^':  return 1; d
	 // case '&':  return 1; d
	 // case '&&': return 1; &
	 // case '{':  return 1; d
	 // case '}':  return 1; d
	 // case '[':  return 1; d
	 // case ']':  return 1; d
	 // case '|':  return 1; d
	 // case '||': return 1; | d
	 // case '?':  return 1; d
	 // case '>':  return 1; d
	 // case '<':  return 1; d
	 // case '>=': return 1; = d
	 // case '<=': return 1; = d
	 // case '=':  return 1; d 
	 // case '==': return 1; = d
	 // case '.':  return 1; d
	 // case ',':  return 1; d
	 // case '+=': return 1; = d
	 // case '-=': return 1; = d
	 // case '/=': return 1; = d
	 // case '|=': return 1; = d
	 // case '&=': return 1; = d 
	 // case ':':  return 1; d
	 // case ';':  return 1; d
	 // case '++': return 1; + d
	 // case '--': return 1; - d 
	 // case '#':  return 1;
	 // case '(':  return 1; d
	 // case ')':  return 1; d
	 // case '@':  return 1; d
	 // default :  return 0;
	 
 // }
