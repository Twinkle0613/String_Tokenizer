#include "StringTokenizer.h"
#include "subFunction.h"
#include "CException.h"
#include "ErrorCode.h"
#include "Token.h"
#include "OperatorChecker.h"
#include "unity.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <malloc.h>
#define startChar (strO->str[*startColumn])
//#include <assert.h>
//assert( funcName != NULL);

 /***********************************getData_Function********************************/

int getValue (StringObject* strO, Token* InTk){
		int value;
		value = atoi( createSubString(strO->str, InTk->startColumn, InTk->length ) );
		return value;
}

char *getSymbol (StringObject* strO,Token* OpTk){
		char *symbol = malloc(sizeof(char)*(OpTk->length)+1);
		symbol = createSubString(strO->str, OpTk->startColumn, OpTk->length );
	//	printf("symbol = %s\n",symbol);
		return symbol;
}
 /***************************createStringObject_Function***************************/

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
 // printf("str[%d] = %c ,newStr[%d] = %c\n",j,str[j],i,newStr[i]);
    i++;
		j++;
  }
  newStr[i] = 0;
	return newStr;

}

 /*********************************printError_Function*********************************/

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
						case ERR_STR_CANNOT_CONTAIN_INVALID_OPERATOR:
						printf("Error: String can't contain invalid operator\n");
						break;
						case ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL:
						printf("Error: String can't contain invalid symbol\n");
						break;
            case ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE:
            printf("Error: End of String without close double quote\n");
            break;
            case ERR_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT:
            printf("Error: Floating can't contain second decimal point\n");
            break;
            case ERR_INTEGER_CANNOT_CONTAIN_ALPHA:
            printf("Error: Integer can't contain alpha\n");
            break;
            case ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT:
            printf("Error: Behind the exponential must be a digit\n");
            break;
            case ERR_INVALID_OCTAL:
            printf("Error: This is invalid octal\n");
            break;
            case ERR_INVALID_HEX:
            printf("Error: This is invalid Hexdecimal\n");
            break;
						default:
						printf("Unknown Error caught! Error code is :%d\n", err);
						break;
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
}
     // printf("%s",err->errorMsg);
     // TEST_ASSERT_EQUAL_STRING("The String Object can't be a NULL\n",err->errorMsg);
     // TEST_ASSERT_EQUAL(ERR_STR_OBJECT_CANNOT_BE_NULL_1,err->errorCode);  
  
     // printf("%s",err->errorMsg);
     // TEST_ASSERT_EQUAL_STRING("The String can't be a NULL\n",err->errorMsg);
     // TEST_ASSERT_EQUAL(ERR_STR_CANNOT_BE_NULL_1,err->errorCode);

     // printf("%s",err->errorMsg);
     // TEST_ASSERT_EQUAL_STRING("Can't contain any alphabet\n",err->errorMsg);
     // TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);
     
     // printf("%s",err->errorMsg);
     // TEST_ASSERT_EQUAL_STRING("This is invalid octal integer\n",err->errorMsg);
     // TEST_ASSERT_EQUAL(ERR_INVALID_OCTAL_1,err->errorCode);
     
     // printf("%s",err->errorMsg);
     // TEST_ASSERT_EQUAL_STRING("This is invalid Hexdecimal integer\n",err->errorMsg);
     // TEST_ASSERT_EQUAL(ERR_INVALID_HEX_1,err->errorCode);
     
     // printf("%s",err->errorMsg);
     // TEST_ASSERT_EQUAL_STRING("End of string without double quote\n",err->errorMsg);
     // TEST_ASSERT_EQUAL(ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1,err->errorCode);
     
     // printf("%s",err->errorMsg);
     // TEST_ASSERT_EQUAL_STRING("Can't contain contain two of decimal point in Floating\n",err->errorMsg);
     // TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,err->errorCode);
     
     // printf("%s",err->errorMsg);
     // TEST_ASSERT_EQUAL_STRING("Behind exponential must be a digit\n",err->errorMsg);
     // TEST_ASSERT_EQUAL(ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1,err->errorCode);
     
      // printf("%s",err->errorMsg);
     // TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     // TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
 /*********************************checkOperator_Function*********************************/
/*
int operatorAtrributes[256] = {
	
	 ['<'] = SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT, //< << <= <<= 
	 ['>'] = SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT,//> >> >=	>>=  
	 ['+'] = SINGLE | TWIN | ASSIGNMENT, // + ++ += 
	 ['-'] = SINGLE | TWIN | ASSIGNMENT, // - -- -= 
	 ['/'] = SINGLE | TWIN | ASSIGNMENT, // / // /= 
	 ['&'] = SINGLE | TWIN | ASSIGNMENT, // & && &= 
	 ['|'] = SINGLE | TWIN | ASSIGNMENT, // | || |= 
	 ['!'] = SINGLE | ASSIGNMENT,				 // ! !=
	 ['*'] = SINGLE | ASSIGNMENT,        // * *= 
   ['^'] = SINGLE | ASSIGNMENT,        // ^ ^= 
	 ['%'] = SINGLE | ASSIGNMENT,        // % %=  
	 ['='] = SINGLE | TWIN,								// == 
	 ['('] = SINGLE,
	 [')'] = SINGLE,
	 ['['] = SINGLE,
	 [']'] = SINGLE,
	 ['{'] = SINGLE,
	 ['}'] = SINGLE,
	 ['@'] = SINGLE,
	 [';'] = SINGLE,
	 [':'] = SINGLE,
	 ['.'] = SINGLE,
	 [','] = SINGLE,
	 ['~'] = SINGLE,
	 ['?'] = SINGLE
};

int isOperator(int Operator){
			if(SINGLE == Operator)
				return 1;
			else if ((SINGLE | TWIN) == Operator)
				return 1;
			else if ((SINGLE | ASSIGNMENT) == Operator)
				return 1;
			else if ((SINGLE | TWIN | ASSIGNMENT) == Operator)
			  return 1;
			else if ((SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == Operator)
				return 1;
			else 
				return 0;
}

int isSingle(int Operator){
			if (SINGLE == Operator)
				 return 1;
			   return 0;
 }

int isTwin(int Operator){
			if ((SINGLE | TWIN) == Operator)
				return 1;
			else if ( (SINGLE | TWIN | ASSIGNMENT) == Operator )
			  return 1;
			else if ( (SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == Operator)
				return 1;
			else 
				return 0;
}

int isAssign(int Operator){
			if ((SINGLE | ASSIGNMENT) == Operator)
				 return 1;
			else if ((SINGLE | TWIN | ASSIGNMENT) == Operator)
				 return 1;
			else if ((SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == Operator)
				 return 1;
			else
			   return 0;
 }

int isTwinAssign(int Operator){
			if ((SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == Operator)
				return 1;
			  return 0;
}
*/
//#define currChar strO->str[strO->index]
//#define nextChar strO->str[strO->index+1]
//#define prevChar strO->str[strO->index-1]
// int isOperator(StringObject* strO){




