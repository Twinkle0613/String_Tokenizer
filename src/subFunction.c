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

void checkFirstCh ( StringObject* strO , TokenState *currentState){
		printf("strO->str[0] = %c\n",strO->str[0]);
		if (isdigit(strO->str[0])){
			printf("IntegerState\n");
			*currentState = IntegerState;
		}else if (isalpha(strO->str[0])){
			*currentState = IdentifierState;
		}
		
}	

char *createSubString(char *str, int start , int tail){
	char *string = malloc(sizeof(char*));
	//char *strncpy(char *s1, const char *s2, size_t n);
	strncpy(string , str , tail - start);
	string[tail - start] = '\0';
	return string;
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

