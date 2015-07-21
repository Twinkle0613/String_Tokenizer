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
 /***************************getData_Function_Test***************************/

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

void xtest_getSymbol(void){
   StringObject* strO = createStringObject("^UIasdafsad");
	 strO->index = 0;
	 
    char *symbol;
    Token *OpTk = malloc(sizeof(Token));
    OpTk->startColumn = 0;
    OpTk->length = 1;
    symbol = getSymbol (strO,OpTk);
    printf("symbol = %s",symbol);
		TEST_ASSERT_EQUAL_STRING("^",symbol);
	
	}
 /***************************createStringObject_Function_Test***************************/

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
 /***************************createSubString_Function_Test***************************/

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

void xtest_createSubString(void){
  char *str = "1234 4321";
  int start = 5;
  int len = 4;
  char *newStr = createSubString(str,start,len);
  printf("\nnewStr = %s",newStr);
  TEST_ASSERT_EQUAL_STRING("4321",newStr);
}

 /***************************checkOperator_Function_Test***************************/

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
		TEST_ASSERT_EQUAL(0,isOperator(operatorAtrributes['$']));
		TEST_ASSERT_EQUAL(0,isOperator(operatorAtrributes['#']));


}
 /***************************checkFirstCh_Function_Test***************************/

void xtest_checkFirstCh_given_1234_and_currentState_should_be_change_to_IntergerState(void){
		TokenState currentState;
			StringObject *strO = createStringObject("1234");
		checkFirstCh(strO,&currentState,0);
		TEST_ASSERT_EQUAL(IntegerState,currentState);
	
}

void xtest_checkFirstCh_given_ASS_and_currentState_should_be_change_to_IdentifierState(void){
		TokenState currentState;
			StringObject *strO = createStringObject("ASS");
		checkFirstCh(strO,&currentState,0);
		TEST_ASSERT_EQUAL(IdentifierState,currentState);
}

void xtest_checkFirstCh_given_string_starSymbol_should_return_OperatorState(void){
	 StringObject* strO = malloc(sizeof(StringObject));
	 strO->str = "*";
		int startColumn = 0;
	 TokenState currentState;
	 checkFirstCh (strO,&currentState,&startColumn);
	 TEST_ASSERT_EQUAL(OperatorState,currentState);
}
void xtest_checkFirstCh_given_string_8_should_return_IntegerState(void){
	 StringObject* strO = malloc(sizeof(StringObject));
	 strO->str = "8";
		int startColumn = 0;
	 TokenState currentState;
	 checkFirstCh (strO,&currentState,&startColumn);
	 TEST_ASSERT_EQUAL(IntegerState,currentState);
}

void xtest_checkFirstCh_given_string_double_quote_should_return_StringState(void){
	 StringObject* strO = malloc(sizeof(StringObject));
	 strO->str = "\"";
		int startColumn = 0;
	 TokenState currentState;
	 checkFirstCh (strO,&currentState,&startColumn);
	 TEST_ASSERT_EQUAL(StringState,currentState);
   printf("currentState = %d",currentState);
}

void xtest_checkFirstCh_given_string___should_return_IdentifierState(void){
	 StringObject* strO = malloc(sizeof(StringObject));
	 strO->str = "_";
		int startColumn = 0;
	 TokenState currentState;
	 checkFirstCh (strO,&currentState,&startColumn);
	 TEST_ASSERT_EQUAL(IdentifierState,currentState);
   printf("currentState = %d",currentState);
}

void xtest_checkFirstCh_given_string_AB_should_return_IdentifierState(void){
	 StringObject* strO = malloc(sizeof(StringObject));
	 strO->str = "AB";
		int startColumn = 0;
	 TokenState currentState;
	 checkFirstCh (strO,&currentState,&startColumn);
	 TEST_ASSERT_EQUAL(IdentifierState,currentState);
   printf("currentState = %d",currentState);
}
void xtest_checkFirstCh_given_string_dot_should_return_IdentifierState(void){
	 StringObject* strO = malloc(sizeof(StringObject));
	 strO->str = ".";
		int startColumn = 0;
	 TokenState currentState;
	 checkFirstCh (strO,&currentState,&startColumn);
	 TEST_ASSERT_EQUAL(DotState,currentState);
    printf("currentState = %d",currentState);

}
 /*********************CreateToken_Function_Test***************************/
void xtest_createIntegerToken_given_1234_should_return_IntegerToken(void){
   
  IntegerToken *InTk = malloc(sizeof(IntegerToken));
  InTk = (IntegerToken*)createIntegerToken("1234",0,2);
  printf("InTk->value = %d",InTk->value);
  TEST_ASSERT_INTEGER_TOKEN(12,0,2,"1234",InTk);
   
 }
	
void xtest_createOperatorToken_given_symbol_should_return_OperatorToken(void){
   
  OperatorToken *OpTk = malloc(sizeof(OperatorToken));
  OpTk = (OperatorToken*)createOperatorToken("+--",0,1);
  printf("OpTk->symbol = %s",OpTk->symbol);
  TEST_ASSERT_OPERATOR_TOKEN("+",0,1,"+--",OpTk);
   
 }
 
void xtest_createFloatToken_given_1_23_should_return_OperatorToken(void){
   
  FloatToken *FlTk = malloc(sizeof(FloatToken));
  FlTk = (FloatToken*)createFloatToken("1.23",0,4);
  printf("FlTk->value = %f",FlTk->value);
  TEST_ASSERT_FLOAT_TOKEN(1.23,0,4,"1.23",FlTk);
   
 }
 
void xtest_createIdentifierToken_given_asda1234_should_return_OperatorToken(void){
 
  IdentifierToken *IdTk = malloc(sizeof(IdentifierToken));
  IdTk = (IdentifierToken*)createIdentifierToken("asda1234",0,4);
  printf("IdTk->name = %s",IdTk->name);
  TEST_ASSERT_IDENTIFIER_TOKEN("asda",0,4,"asda1234",IdTk);
   
}

void xtest_createStringToken_given_symbol_should_return_OperatorToken(void){
 
  StringToken *StTk = malloc(sizeof(IdentifierToken));
  StTk = (StringToken*)createStringToken("\"asd\"",0,5);
  printf("StTk->name = %s",StTk->name);
  TEST_ASSERT_STRING_TOKEN("\"asd\"",0,5,"\"asd\"",StTk);
   
}
