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


Token *StringTokenizer(StringObject *strO){
	
	  Token* tk = malloc(sizeof(Token));
		TokenState currentState = InitialState;
		int num = 0;
		
		while (num < 10)
		{
			
				switch (currentState)
			{
					case InitialState:
						printf("-----------------\n");
						printf("InitialState\n");
						if (isdigit(strO->str[0])){
							currentState = IntegerState;
							}
						break;
					
					case IntegerState:
					{
				
					printf("IntegerState\n");
					TransitionForInt(&tk,&currentState,strO);
					 if (tk->type == TOKEN_INTEGER_TYPE){
						return tk;
					 }
					break;
					}//end of Integer State 
			   		
						
					default:InitialState;
					break;
					
		  } //end of switch 
			num++;
	}//end of while loop
					
		return tk;
}//end of program


void TransitionForInt(Token** InTk, TokenState* currentState , StringObject* strO){
	
					 *InTk = malloc(sizeof(Token));
					
						if( isdigit(strO->str[strO->index]) ) 
					{
						printf("[%c]\n",strO->str[strO->index]); 
						*currentState = IntegerState;
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
						*InTk = createIntegerToken( atoi( strO->str ) ); 
						//printf("InTk->type = %d\n", *InTk->type);
					 }
}


StringObject *createStringObject(char *ch){
		StringObject *strO = malloc(sizeof(StringObject));
		strO->str = ch;
		strO->index = 0;
		return strO;
		}
		
		
void printError(int err){
	
					switch(err)
					{
						case ERR_STR_INCLURE_ALPHA:
						printf("Error: Can't include Alpha\n");
						break;
						case ERR_STR_INCLUDE_SYMBOL:
						printf("Error: Can't include Symbol\n");
						break;
						case ERR_STR_CANNOT_BE_EMPTY:
						printf("Error: Can't be Empty \n");
						break;
						case ERR_STR_CANNOT_BE_NULL:
						printf("Error: Can't be NULL\n");
						break;
						default:
						printf("Unknown Error caught! Error code is :%d\n", err);
						break;
					}
	
}

/* Token *StringTokenizer(char *str)
{
	
  Token* tk = malloc(sizeof(Token));
	int i = 0;
	printf("\n--------------------------");
	printf("\nlength of str = %d\n", strlen(str));
	

	
	while(i <= strlen(str) )
	{
		printf("[%d],",i);
	
	
		if( isdigit(str[i]) ) 
		{
			//the string is Digit
		//	StrO->str[StrO->index] = str[i];
			
	printf("[%c]\n",str[i]); 
		//	StrO->index = StrO->index + 1 ; 
		  //current_state = IntegerState;
		
		}else if ( isalpha(str[i] ) || str[0] == '\0' ||  str == NULL || ispunct(str[i]))
		{
			// the string include Alpha and Symbol
			printf("Error\n");
			
			Throw(-1);
		
		}else if( (str[i] == ' '&& isdigit(str[i-1])) || (str[i] == '\n'&& isdigit(str[i-1]) ) ||( str[i] == '\0' && isdigit(str[i-1])  ) )
		{
			// if the string get space, end_line(\n) and \0, create a Integer Token
			printf("Create Token\n");
			tk = createIntegerToken( atoi(str) ); 
			//atoi(ptrNumberText) => convert the character to integer		
		}
		
		
		i++;	
	
	}
	
   return tk;
	 
}
 */

 
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