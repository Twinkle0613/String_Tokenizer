//Own module files
#include "subFunction.h"
#include "CException.h"
#include "OperatorChecker.h"
#include "Token.h"
#include "unity.h"

// Library 
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <malloc.h>

#define startChar (strO->str[*startColumn])
//#include <assert.h>
//assert( funcName != NULL);

/**
 * In the subFunction, the functions there are tool to develop the getToken(...) function.
 * Using the createStringObject(...) functions to create a string object element. 
 * Using the checkFirstCh(...) functions to identify the tyoe of first character then from initial state go to next state.
 * Using the createSubString(...) functions to select the any part of string. 
 * Eg.
 *
 *    createStringObject(...):
 *
 *											 -----------------------
 *   StringObject ------>|str = "1234"|Index = 0|
 *												-----------------------
 *
 *   createSubString(...):
 *      start = 3;
 *      length = 4
 *      str = "12312342123"
 *                ^^^^
 *      subStr = createSubString(char *str, int start , int length);
 *      The subStr that contain "1234".
 *
 *    checkFirstCh(...):
 *      
 *    strO->str = "123 1234"                  strO->str = "ASDSAS"
 *                 ^                                       ^
 *    
 *      currentState ---> integerState;            currentState ---> IdentifierState;
 *
 *
 *
 * Function:
 *   StringObject *createStringObject(char *ch);
 *   char *createSubString(char *str, int start , int length);
 *   void checkFirstCh ( StringObject* strO , TokenState *currentState, int* startColumn);
 *
 * Input:
 *
 *  createStringObject(...):
 *    ch - store the string from user key in.
 * 
 *  createSubString(...):
 *    str - store the string for user key in.
 *    start - record the start point for counter of getToken(...) function.
 *    length - store the length for string that need to form a token
 *  
 *  checkFirstCh(...):
 *    strO - store the string was typed by user in strO->str
 *         - record the transiton times in strO->index 
 *    currentState - record the the current state in getToken(...) function. 
 *    startColumn - record the start point for counter in getToken(...) function.
 *
 *
 * Return:
 *    createStringObject(...):
 *       return string object element that has contain the string that typed by user 
 *    createSubString(...):
 *       return the string that was selected by getToken(...) function.
 *    checkFirstCh(...):
 *        currentState that will be update and change to other state or remain.

 */
 
void stringObjectAnchor(StringObject* strO){
  strO->startIndex = strO->index;
  printf("strO->startIndex = %d\n",strO->startIndex);
}
 /***************************createStringObject_Function***************************/
 //anchor
StringObject *createStringObject(char *ch){
		StringObject *strO = malloc(sizeof(StringObject));
		strO->str = ch;
		strO->index = 0;
		return strO;
		}
 /*****************************checkFirstCh_Function******************************/

void checkFirstCh ( StringObject* strO , TokenState *currentState, int* startColumn){
	
//	printf("strO->str[%d] = %c\n",*startColumn,strO->str[*startColumn]);
		if (isdigit(startChar)){
			*currentState = IntegerState;
		}else if (isalpha(startChar)){
			*currentState = IdentifierState;
		}else if (startChar == '.'){
     *currentState = DecimalPointState; 
    }else if (isoperator(startChar)){
			*currentState = OperatorState;
    }else if (startChar == '"'){
      *currentState = StringState;
    }else if (startChar == '_' || isalpha(startChar)){
      *currentState = IdentifierState; 
		}else 
			*currentState = UnknownState;
}
 /***************************createSubString_Function***************************/

char *createSubString(char *str, int start , int len){
	
  char *newStr = malloc(sizeof(char)*(len+1));
	int i = 0;
	int j = start;
	
	while ( j < (len+start) ){
	newStr[i] = str[j];
    i++;
		j++;
  }
  newStr[i] = 0;
	return newStr;

}

  // 1.throwError("The String Object can't be a NULL\n",ERR_STR_OBJECT_CANNOT_BE_NULL_1);
  // 2.throwError("The String can't be a NULL\n",ERR_STR_CANNOT_BE_NULL_1);
	// 3.throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);
  // 4.throwError("This is invalid octal integer\n",ERR_INVALID_OCTAL_1);
  // 5.throwError("This is invalid Hexdecimal integer\n",ERR_INVALID_HEX_1);
  // 6.throwError("End of string without double quote\n",ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1);
  // 7.throwError("Can't contain contain two of decimal point in Floating\n",ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING);
  // 8.throwError("Behind exponential must be a digit\n",ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1);
  // 9.throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);

