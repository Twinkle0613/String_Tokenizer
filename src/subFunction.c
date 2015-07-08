#include "subFunction.h"
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
#include "unity.h"



int getValue (StringObject* strO, Token* InTk){
		int value;
		value = atoi( createSubString(strO->str, InTk->startColumn, InTk->length ) );
		return value;
}

void checkFirstCh ( StringObject* strO , TokenState *currentState, int* startColumn){
	
	printf("strO->str[%d] = %c\n",*startColumn,strO->str[*startColumn]);
		if (isdigit(strO->str[*startColumn])){
			*currentState = IntegerState;
		}else if (isalpha(strO->str[*startColumn])){
			*currentState = IdentifierState;
		}

}

char *createSubString(char *str, int start , int len){
	
  char *newStr = malloc(sizeof(char)*(len+1));
	int i = 0;
	int j = start;
	
	while ( j < (len+start) ){
	newStr[i] = str[j];
  printf("str[%d] = %c ,newStr[%d] = %c\n",j,str[j],i,newStr[i]);
    i++;
		j++;
  }
  newStr[i] = 0;
	return newStr;

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
						printf("Error: String can't include Alpha\n");
						// char *str = "String can't include Alpha";
						// char *str2 ="2+3-4 123A";
						// char *str3 ="         ^";
						
						// printf("ERROR[%d][%d]: %s\n%s\n%s\n",3,3,str,str2,str3);
						// char buffer[256];
						// sprintf(buffer,"ERROR[%d][%d]: %s\n%s\n%s\n",3,3,str,str2,str3);
						// UNITY_TEST_FAIL(__LINE__,buffer);
						
						break;
						case ERR_STR_INCLUDE_SYMBOL:
						printf("Error: String can't include Symbol\n");
						break;
						case ERR_STR_CANNOT_BE_EMPTY:
						printf("Error: String can't be Empty \n");
						break;
						case ERR_STR_CANNOT_BE_NULL:
						printf("Error: String can't be NULL\n");
						break;
						case ERR_STR_OBJECT_CANNOT_BE_NULL:
						printf("Error: String Object can't be NULL\n");
						break;
						default:
						printf("Unknown Error caught! Error code is :%d\n", err);
						break;
					}
	
}

//#define currChar strO->str[strO->index]
//#define nextChar strO->str[strO->index+1]
//#define prevChar strO->str[strO->index-1]
// int isOperator(StringObject* strO){

	 // switch (currChar)
	 
	 // case '+':  if( nextChar == '+' || nextChar == '=' ) //'++'||'+='
	 //							return 0;
	 //            else if (prevChar == '+' )
	 //             return 1;
	 //						 else
	 //							return 1;
	 
	 // case '-':  if(nextChar == '-' || nextChar == '=' ) //'--'||'-='
	 //							return 0;
	 //						 else if (prevChar == '-' )
	 //             return 1;
	 //            else
	 //             return 1;
	  
	 // case '/':  if(nextChar == '=' ) //'/='
	 //							return 0;
	 //							else if (prevChar == '=' )
	 //             return 1;
	 //             else
	 //             return 1;
 
	 // case '&': if(nextChar == '&' || nextChar == '=' ) //'&&'||'&='
	 //							return 0;
	 //						 else if (prevChar == '&' )
	 //             return 1;
	 //            else
	 //             return 1;
 
	 // case '|':  if(nextChar == '|' || nextChar == '=' ) //'||' || '|='
	 //							return 0;
	 //            else if (prevChar == '|' )
	 //             return 1;
	 //            else
	 //             return 1;
	  
	 // case '>':  if(nextChar == '=' ) //'>='
	 //							return 0;
	 //            else if (prevChar == '>' )
	 //             return 1;
	 //            else
	 //             return 1;
 
	 // case '<':  if(nextChar == '=' ) //'<='//<<<
	 //							return 0;
	 //            else if (prevChar == '<' )
	 //             return 1;
	 //            else
	 //             return 1;
  
	 // case '=':  if(nextChar == '=' ) //'=='
	 //							return 0;
	 //            else
	 //             return 1;
 
	 // case '}':  return 1;
	 // case '{':  return 1;
	 // case '[':  return 1;
	 // case ']':  return 1;
	 // case '?':  return 1;
	 // case '' :  return 1;
	 // case '\\': return 1;
	 // case '~':  return 1;
	 // case '!':  return 1;
	 // case '%':  return 1;
	 // case '^':  return 1;
	 // case '.':  return 1;
	 // case ',':  return 1;
	 // case ':':  return 1;
	 // case ';':  return 1;
	 // case '#':  return 1;
	 // case '(':  return 1;
	 // case ')':  return 1;
	 // case '@':  return 1;
	 
	 
	 
	 // default :  return 0;
	 
 // }


