#include "TokenError.h"
#include "TextCode.h"
#include "StringTokenizer.h"
#include "OperatorChecker.h"
#include "subFunction.h"
#include "CException.h"
#include "Token.h"
#include "unity.h"
















void setUp(void){}



void tearDown(void){}

void xtest_createStringObject_given_string_of_1234_should_return_Token_strO_contain_string_of_1234(void){

 StringObject *strO;

 strO = createStringObject("1234");

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((strO->index)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(("1234")), (_U_SINT)((strO->str)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

 printf("strO->index = %d , strO->str = %c",strO->index,strO->str[1]);

}

void xtest_createSubString_given_Hello_World_into_ch_start_is_0_and_tail_is_3_str_should_be_return_Hel(void){



 char* str;

 char* ch = "Hello World";

 str = createSubString(ch,0,3);

 printf("%s\n",str);

 UnityAssertEqualString((const char*)("Hel"), (const char*)(str), (((void *)0)), (_U_UINT)57);



}



void xtest_createSubString_given_Hello_World_into_ch_start_is_0_and_tail_is_12_str_should_be_return_Hello_World(void){



 char* str;

 char* ch = "Hello World";

 str = createSubString(ch,0,12);

 printf("%s\n",str);

 UnityAssertEqualString((const char*)("Hello World"), (const char*)(str), (((void *)0)), (_U_UINT)67);



}



void xtest_createSubString(void){

  char *str = "1234 4321";

  int start = 5;

  int len = 4;

  char *newStr = createSubString(str,start,len);

  printf("\nnewStr = %s",newStr);

  UnityAssertEqualString((const char*)("4321"), (const char*)(newStr), (((void *)0)), (_U_UINT)77);

}







void xtest_stateTransition_given_1234_and_currentState_should_be_change_to_IntergerState(void){

  TokenState currentState;

   StringObject *strO = createStringObject("1234");

  stateTransition(strO,&currentState,0);

  UnityAssertEqualNumber((_U_SINT)((integerState)), (_U_SINT)((currentState)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);



}



void xtest_stateTransition_given_ASS_and_currentState_should_be_change_to_IdentifierState(void){

  TokenState currentState;

   StringObject *strO = createStringObject("ASS");

  stateTransition(strO,&currentState,0);

  UnityAssertEqualNumber((_U_SINT)((identifierState)), (_U_SINT)((currentState)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

}



void xtest_stateTransition_given_string_starSymbol_should_return_OperatorState(void){

  StringObject* strO = malloc(sizeof(StringObject));

  strO->str = "*";

  int startColumn = 0;

  TokenState currentState;

  stateTransition (strO,&currentState,&startColumn);

  UnityAssertEqualNumber((_U_SINT)((operatorState)), (_U_SINT)((currentState)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

}

void xtest_stateTransition_given_string_8_should_return_IntegerState(void){

  StringObject* strO = malloc(sizeof(StringObject));

  strO->str = "8";

  int startColumn = 0;

  TokenState currentState;

  stateTransition (strO,&currentState,&startColumn);

  UnityAssertEqualNumber((_U_SINT)((integerState)), (_U_SINT)((currentState)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

}



void xtest_stateTransition_given_string_double_quote_should_return_StringState(void){

  StringObject* strO = malloc(sizeof(StringObject));

  strO->str = "\"";

  int startColumn = 0;

  TokenState currentState;

  stateTransition (strO,&currentState,&startColumn);

  UnityAssertEqualNumber((_U_SINT)((stringState)), (_U_SINT)((currentState)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

   printf("currentState = %d",currentState);

}



void xtest_stateTransition_given_string___should_return_IdentifierState(void){

  StringObject* strO = malloc(sizeof(StringObject));

  strO->str = "_";

  int startColumn = 0;

  TokenState currentState;

  stateTransition (strO,&currentState,&startColumn);

  UnityAssertEqualNumber((_U_SINT)((identifierState)), (_U_SINT)((currentState)), (((void *)0)), (_U_UINT)130, UNITY_DISPLAY_STYLE_INT);

   printf("currentState = %d",currentState);

}



void xtest_stateTransition_given_string_AB_should_return_IdentifierState(void){

  StringObject* strO = malloc(sizeof(StringObject));

  strO->str = "AB";

  int startColumn = 0;

  TokenState currentState;

  stateTransition (strO,&currentState,&startColumn);

  UnityAssertEqualNumber((_U_SINT)((identifierState)), (_U_SINT)((currentState)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);

   printf("currentState = %d",currentState);

}

void xtest_stateTransition_given_string_dot_should_return_IdentifierState(void){

  StringObject* strO = malloc(sizeof(StringObject));

  strO->str = ".";

  int startColumn = 0;

  TokenState currentState;

  stateTransition (strO,&currentState,&startColumn);

  UnityAssertEqualNumber((_U_SINT)((decimalPointState)), (_U_SINT)((currentState)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_INT);

    printf("currentState = %d",currentState);



}



void xtest_createIntegerToken_given_1234_should_return_IntegerToken(void){













 }



void xtest_createOperatorToken_given_symbol_should_return_OperatorToken(void){













 }



void xtest_createFloatToken_given_1_23_should_return_OperatorToken(void){













 }



void xtest_createIdentifierToken_given_asda1234_should_return_OperatorToken(void){













}



void xtest_createStringToken_given_symbol_should_return_OperatorToken(void){













}





void xtest_valid_integer(void){

  double v = 1e2;

  printf("v1 = %f\n",v);

  v = 1.e2;

  printf("v2 = %f\n",v);

  v = .123;

  printf("v3 = %f\n",v);

  v = 0.1e2;

  printf("v4 = %f\n",v);

  v = 1e2;

  printf("v5 = %f\n",v);

  v = 0x123A;

  printf("v6 = %f\n",v);

  v = 0124;

  printf("v7 = %f\n",v);

  v =1e+2;

  printf("v8 = %f\n",v);

  v = 1e-2;

  printf("v9 = %f\n",v);

  v = 1.0e-2;

  printf("v10 = %f\n",v);

  v = 1.0e+2;

  printf("v11 = %f\n",v);

  v = 1.E2;

  printf("v12 = %f\n",v);

  v = 123e3;

  printf("v13 = %f\t",v);

    printf("v13 = %f\f",v);

      printf("v13 = %f\v",v);

        printf("v13 = %f\r",v);

}
