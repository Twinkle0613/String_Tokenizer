#include "unity.h"
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



void setUp(void){}

void tearDown(void){}

/*
							
												 -----------------------
    StringObject ------>|str = "1234"|Index = 0|
												-----------------------

*/

void xtest_createStringObject_given_string_of_1234_should_return_Token_strO_contain_string_of_1234(void){
	StringObject *strO;
	strO = createStringObject("1234");
	TEST_ASSERT_EQUAL(0,strO->index);
	TEST_ASSERT_EQUAL("1234",strO->str);
	printf("strO->index = %d , strO->str = %c",strO->index,strO->str[1]);
}

/*
				start = 0  tail = 3
			   ----------------
	ch-->	| "Hello World" |
			  ----------------
						|| strncpy(str,ch,tail - start);
					  V
				------------
srt--> |	 "Hel"	 |
			 ------------
*/
void xtest_createSubString_given_Hello_World_into_ch_start_is_0_and_tail_is_3_str_should_be_return_Hel(void){
	
	char* str;
	char* ch = "Hello World";
	str = createSubString(ch,0,3);
	printf("%s\n",str);
	TEST_ASSERT_EQUAL_STRING("Hel",str);
	
}

void xtest_createSubString_given_Hello_World_into_ch_start_is_0_and_tail_is_12_str_should_be_return_Hello_World(void){
	
	char* str;
	char* ch = "Hello World";
	str = createSubString(ch,0,12);
	printf("%s\n",str);
	TEST_ASSERT_EQUAL_STRING("Hello World",str);
  
}

void xtest_checkStr_given_1234_and_currentState_should_be_change_to_IntergerState(void){
		TokenState currentState;
			StringObject *strO = createStringObject("1234");
		checkFirstCh(strO,&currentState,0);
		TEST_ASSERT_EQUAL(IntegerState,currentState);
	
}

void xtest_checkStr_given_ASS_and_currentState_should_be_change_to_IdentifierState(void){
		TokenState currentState;
			StringObject *strO = createStringObject("ASS");
		checkFirstCh(strO,&currentState,0);
		TEST_ASSERT_EQUAL(IdentifierState,currentState);
}

void xtest_createSubString(void){
  char *str = "1234 4321";
  int start = 5;
  int len = 4;
  char *newStr = createSubString(str,start,len);
  printf("\nnewStr = %s",newStr);
  TEST_ASSERT_EQUAL_STRING("4321",newStr);
}

void xtest_getValue(void){
	
	int value ;
	 StringObject *strO = malloc(sizeof(StringObject));
	strO->str = "1234 4321";
	Token *InTk = malloc(sizeof(Token));
	 InTk->startColumn = 5;
	 InTk->length = 4;
	 value = getValue(strO,InTk);
	printf("value = %d",value);
   TEST_ASSERT_EQUAL(4321,value);
	
}

void xtest_isSingle (void){
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['(']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes[')']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['[']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes[']']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['{']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['}']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['@']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes[';']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes[':']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['.']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes[',']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['~']));
	TEST_ASSERT_EQUAL(0,isSingle(operatorAtrributes['!']));
	TEST_ASSERT_EQUAL(0,isSingle(operatorAtrributes['<']));
	TEST_ASSERT_EQUAL(0,isSingle(operatorAtrributes['+']));
	TEST_ASSERT_EQUAL(0,isSingle(operatorAtrributes['-']));	
}


void xtest_isTwin (void){
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['=']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['<']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['>']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['+']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['-']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['/']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['&']));
    TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['|']));
		TEST_ASSERT_EQUAL(0,isTwin(operatorAtrributes['(']));
		TEST_ASSERT_EQUAL(0,isTwin(operatorAtrributes['!']));
		TEST_ASSERT_EQUAL(0,isTwin(operatorAtrributes['*']));
		TEST_ASSERT_EQUAL(0,isTwin(operatorAtrributes['^']));
		TEST_ASSERT_EQUAL(0,isTwin(operatorAtrributes['%']));		
}

void xtest_isAssign (void){

		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['<']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['>']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['+']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['!']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['*']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['^']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['%']));		
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes['=']));
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes['(']));
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes[')']));
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes['[']));
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes[']']));
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes['{']));
}


void xtest_isTwinAssign (void){	
		TEST_ASSERT_EQUAL(1,isTwinAssign(operatorAtrributes['<']));
		TEST_ASSERT_EQUAL(1,isTwinAssign(operatorAtrributes['>']));	
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['+']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['!']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['*']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['^']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['%']));		
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['=']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['+']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['-']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['/']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['&']));
    TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['|']));
}
void xtest_isOperator(void){
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['<']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['>']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['+']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['-']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['/']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['&']));
    TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['|']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['!']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['*']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['^']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['%']));	
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['=']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['(']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes[')']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['[']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes[']']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['{']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['}']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['@']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes[';']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes[':']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['.']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes[',']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['~']));		
}
void test_checkFirstCh_given_string_starSymbol_should_return_OperatorState(void){
	 StringObject* strO = malloc(sizeof(StringObject));
	 strO->str = "*";
		int startColumn = 0;
	 TokenState currentState;
	 checkFirstCh (strO,&currentState,&startColumn);
	 TEST_ASSERT_EQUAL(OperatorState,currentState);
}
void test_checkFirstCh_given_string_8_should_return_IntegerState(void){
	 StringObject* strO = malloc(sizeof(StringObject));
	 strO->str = "8";
		int startColumn = 0;
	 TokenState currentState;
	 checkFirstCh (strO,&currentState,&startColumn);
	 TEST_ASSERT_EQUAL(IntegerState,currentState);
}



