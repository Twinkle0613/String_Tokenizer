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


Token *StringTokenizer(StringObject *strO){
		
	  Token* newToken = malloc(sizeof(Token));
		TokenState currentState = InitialState;
		int loop = 0;
		
		while (loop < 10)
		{
				switch (currentState)
			{
					case InitialState:
						printf("-----------------\n");
						printf("InitialState\n");
						checkFirstCh(strO,&currentState);

						break;
					
					case IntegerState:
					{
				//	printf("newToken->type = %d\n",newToken->type);		
					printf("IntegerState\n");
					TransitionForInt(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_INTEGER_TYPE){	
						 printf("newToken->type = %d\n",newToken->type);		
						 printf("return inside\n");
						return newToken;
					 }
					break;
					}//end of Integer State 
			   			
						
					case FloatingState:
					break;
						
					case StringState:
					break;
					
					case IdentifierState:
					break;
					
					case OperatorState:
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
					
					*InTk = malloc(sizeof(Token));
					
						if( isdigit(strO->str[strO->index]) ) 
					{

						printf("strO->str[%d] = %c\n",strO->index,strO->str[strO->index]); 
						*currentState = IntegerState;
						++(strO->index);
		
					}else if( (strO->str[strO->index] == ' '&& isdigit(strO->str[(strO->index)-1])) || (strO->str[strO->index] == '\n'&& isdigit(strO->str[(strO->index)-1])) || ( strO->str[(strO->index)] == '\0' && isdigit(strO->str[(strO->index)-1])))
					 {
						printf("Create Token\n");
						(strO->index)++;
						*InTk = createIntegerToken( atoi( strO->str ) ); 
						
					 }else if ( isalpha(strO->str[strO->index]) )
					{	
						Throw(-1); 	//	printf("Error: Can't include Alpha\n");
					}else if (ispunct(strO->str[strO->index]))
					{
						Throw(-2); 	//	printf("Error: Can't include Symbol\n");
					}else if( strO->str[0] == '\0')
					{	
						Throw(-3);  //	printf("Error: Can't be Empty \n");
					}else if ( strO->str == 0 )
					{
						Throw(-4);	//	printf("Error: Can't be NULL\n");
					}
					
}

 
/*  					if( isdigit(strO->str[strO->index]) ) 
					{
						printf("[%c]\n",strO->str[strO->index]); 
						currentState = IntegerState;
						printf("strO->index = %d\n",strO->index);
						(strO->index)++;
		
					}else if ( isalpha(strO->str[strO->index]) )
					{
					//	printf("Error: Can't include Alpha\n");
						Throw(-1);
					}else if (ispunct(strO->str[strO->index]))
					{
					//	printf("Error: Can't include Symbol\n");
						Throw(-2);
					}else if( strO->str[0] == '\0')
					{	
					//	printf("Error: Can't be Empty \n");
						Throw(-3);
					}else if ( strO->str == 0)
					{
					//	printf("Error: Can't be NULL\n");
					Throw(-4);
					}
					else if( (strO->str[strO->index] == ' '&& isdigit(strO->str[(strO->index)-1])) || (strO->str[strO->index] == '\n'&& isdigit(strO->str[(strO->index)-1])) || ( strO->str[strO->index+1] == '\0' && isdigit(strO->str[(strO->index)-1])))
					 {
					//	if the string get space, end_line(\n) and \0, create a Integer Token
						printf("Create Token\n");
						 tk = createIntegerToken( atoi( strO->str ) ); 
						 return tk;
					 // } */