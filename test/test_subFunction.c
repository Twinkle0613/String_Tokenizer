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
#include <malloc.h>
#include <string.h>
#include "subFunction.h"
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
		checkFirstCh(strO,&currentState);
		TEST_ASSERT_EQUAL(IntegerState,currentState);
	
}

void xtest_checkStr_given_ASS_and_currentState_should_be_change_to_IdentifierState(void){
		TokenState currentState;
			StringObject *strO = createStringObject("ASS");
		checkFirstCh(strO,&currentState);
		TEST_ASSERT_EQUAL(IdentifierState,currentState);
	
}

