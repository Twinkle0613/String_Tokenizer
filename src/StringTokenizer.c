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
		newToken->startColumn = strO->index;
		int loop = 0;
		printf("-----------------\n");
    printf("newToken->startColumn  = %d\n",newToken->startColumn);

		//printf("strO->index = %d\n",strO->index);
		while (loop < 100)
		{
				switch (currentState)
			{
					case InitialState:

						printf("InitialState\n");
						
						if(strO == NULL){
						Throw(-5);	//	printf("Error: Can't be NULL\n");
						}else if(strO->str == NULL){
						Throw(-4);	//	printf("Error: Can't be NULL\n");
						}else if(strO->str[strO->index] == ' '){
							(strO->index)++;
						}else if(strO->str[strO->index] == '\0'){
							newToken = createOperatorToken("$",PREFIX); 
						  printf("return inside\n");
							return newToken;
						}	else {
							checkFirstCh(strO,&currentState,&(newToken->startColumn));
						}

						break;
					
					case IntegerState:
					{
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
					
		
					if( isdigit(strO->str[strO->index]) ) 
					{
						printf("strO->str[%d] = %c\n",strO->index,strO->str[strO->index]); 
						*currentState = IntegerState;
						(strO->index)++;
					}else if( (strO->str[strO->index] == ' '&& isdigit(strO->str[(strO->index)-1])) || (strO->str[strO->index] == '\n'&& isdigit(strO->str[(strO->index)-1])) || ( strO->str[(strO->index)] == '\0' && isdigit(strO->str[(strO->index)-1])))
					 {
						printf("Create Token\n");
            (*InTk)->length = strO->index - (*InTk)->startColumn;
						 printf("(*InTk)->startColumn  = %d\n",(*InTk)->startColumn);
						 printf("strO->index = %d\n",strO->index);
             printf(" (*InTk)->length = %d\n", (*InTk)->length);
						if(strO->str[strO->index] != '\0' ){
							(strO->index)++;
						}
						//*InTk = createIntegerToken(getValue(strO,*InTk));
						//Token *createIntegerToken(int value,int start,int length,char *str);

						*InTk = createIntegerToken(getValue(strO,*InTk),(*InTk)->startColumn,(*InTk)->length,strO->str);
						//*InTk = createIntegerToken( atoi( createSubString(strO->str, (*InTk)->startColumn, (*InTk)->length ) )); 
           // printf(" (*InTk)->length = %d\n", (*InTk)->length);

					 }else if ( isalpha(strO->str[strO->index]) )
					{	
						Throw(-1); 	//	printf("Error: Can't include Alpha\n");
					}else if (ispunct(strO->str[strO->index]))
					{
						Throw(-2); 	//	printf("Error: Can't include Symbol\n");
					}					
}

 
