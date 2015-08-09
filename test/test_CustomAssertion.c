#include "unity.h"
#include "CustomAssertion.h"
#include <string.h>
#include <stdio.h>      ///* printf */
#include <stdlib.h>     ///* strtol */
#include <malloc.h>
#include "Token.h"
#include "OperatorChecker.h"

void setUp(void)
{
}

void tearDown(void)
{
}
//---------------------testAsserEqualIntegerToken----------------------
void test_testAsserEqualIntegerToken_given_the_value_is_321_and_expect_value_321(void){
  IntegerToken* inTk = malloc(sizeof(IntegerToken));
  inTk->type = TOKEN_INTEGER_TYPE;
  inTk->value = 321;
  testAsserEqualIntegerToken(321,inTk,__LINE__);
  printf("No.1\n");
}

void test_testAsserEqualIntegerToken_given_the_value_is_0XA21_and_expect_value_0XA21(void){
  IntegerToken* inTk = malloc(sizeof(IntegerToken));
  inTk->type = TOKEN_INTEGER_TYPE;
  inTk->value = 0XA21;
  testAsserEqualIntegerToken(0XA21,inTk,__LINE__);
  printf("No.2\n");
}

void test_testAsserEqualIntegerToken_given_the_value_is_0721_and_expect_value_0721(void){
  IntegerToken* inTk = malloc(sizeof(IntegerToken));
  inTk->type = TOKEN_INTEGER_TYPE;
  inTk->value = 0721;
  testAsserEqualIntegerToken(0721,inTk,__LINE__);
  printf("No.3\n");
}

void test_testAsserEqualIntegerToken_given_the_value_is_321_and_expect_value_123 (void){
  IntegerToken* inTk = malloc(sizeof(IntegerToken));
  inTk->type = TOKEN_INTEGER_TYPE;
  inTk->value = 321;
  testAsserEqualIntegerToken(123,inTk,__LINE__);
  printf("No.4\n");
}

void test_testAsserEqualIntegerToken_given_token_is_NULL(void){
  IntegerToken* inTk = NULL;
  testAsserEqualIntegerToken(123,inTk,__LINE__);
  printf("No.5\n");
}

void test_testAsserEqualIntegerToken_given_TOKEN_FLOAT_TYPE(void){
  IntegerToken* inTk = malloc(sizeof(IntegerToken));
  inTk->type = TOKEN_FLOAT_TYPE;
  testAsserEqualIntegerToken(123,inTk,__LINE__);
  printf("No.6\n");
}

//--------------------testAsserEqualFloatToken----------------------------------
void test_testAsserEqualFloatToken_given_TOKEN_INTEGER_TOKEN(void){
  FloatToken* flTk = malloc(sizeof(FloatToken));
  flTk->type = TOKEN_INTEGER_TYPE;
  testAsserEqualFloatToken(123.3,flTk,__LINE__);
  printf("No.7\n");
}

void test_testAsserEqualFloatToken_given_token_is_NULL(void){
  FloatToken* flTk = NULL;
  testAsserEqualFloatToken(123.3,flTk,__LINE__);
  printf("No.8\n");
}

void test_testAsserEqualFloatToken_given_the_value_is_1point23_and_expect_value_123(void){
  FloatToken* flTk = malloc(sizeof(FloatToken));
  flTk->type = TOKEN_FLOAT_TYPE;
  flTk->value = 1.23;
  testAsserEqualFloatToken(123.3,flTk,__LINE__);
  printf("No.9\n");
}

void test_testAsserEqualFloatToken_given_the_value_is_1point23_and_expect_value_1point23(void){
  FloatToken* flTk = malloc(sizeof(FloatToken));
  flTk->type = TOKEN_FLOAT_TYPE;
  flTk->value = 1.23;
  testAsserEqualFloatToken(1.23,flTk,__LINE__);
  printf("No.10\n");
}


//----------------------------testAsserEqualIdentifierToken---------------------

void test_testAsserEqualIdentifierToken_given_the_token_is_NULL(void){
  IdentifierToken* idenTk = NULL;
  testAsserEqualIdentifierToken("A123",idenTk,__LINE__);
  printf("No.11\n");
}

void test_testAsserEqualIdentifierToken_given_the_token_is_tOKEN_FLOAT_TYPE(void){
  IdentifierToken* idenTk = malloc(sizeof(IdentifierToken));
  idenTk->type = TOKEN_FLOAT_TYPE;
  testAsserEqualIdentifierToken("A123",idenTk,__LINE__);
  printf("No.12\n");
}
void test_testAsserEqualIdentifierToken_given_The_length_of_token_is_3_expected_length_of_token_is_4(void){
  IdentifierToken* idenTk = malloc(sizeof(IdentifierToken));
  idenTk->type = TOKEN_IDENTIFIER_TYPE;
  idenTk->length = 3;
  testAsserEqualIdentifierToken("A124",idenTk,__LINE__);
  printf("No.13\n");
}

void test_testAsserEqualIdentifierToken_given_the_string_is_A12_and_expect_A13(void){
  IdentifierToken* idenTk = malloc(sizeof(IdentifierToken));
  idenTk->type = TOKEN_IDENTIFIER_TYPE;
  idenTk->length = 3;
  idenTk->name = "A13";
  idenTk->str = "B231 A13";
  idenTk->startColumn = 5;
  testAsserEqualIdentifierToken("A12",idenTk,__LINE__);
  printf("No.14\n");
}

void test_testAsserEqualIdentifierToken_given_the_string_is_LAI_HWA_NENG_and_expect_NENG(void){
  IdentifierToken* idenTk = malloc(sizeof(IdentifierToken));
  idenTk->type = TOKEN_IDENTIFIER_TYPE;
  idenTk->length = 4;
  idenTk->name = "NENG";
  idenTk->str = "LAI HWA NENG";
  idenTk->startColumn = 8;
  testAsserEqualIdentifierToken("NENG",idenTk,__LINE__);
  printf("No.15\n");
}

//-------------------------testAsserEqualStringToken------------------------------------------

void test_testAsserEqualStringToken_the_token_is_tOKEN_IDENTIFIER_TYPE(void){
  StringToken* strTk = malloc(sizeof(StringToken));
  strTk->type = TOKEN_IDENTIFIER_TYPE;
  testAsserEqualStringToken("\"1234\"",strTk,__LINE__);
  printf("No.16\n");
}

void test_testAsserEqualStringToken_the_token_is_NULL(void){
  StringToken* strTk = NULL;
  testAsserEqualStringToken("\"1234\"",strTk,__LINE__);
  printf("No.17\n");
}


void test_testAsserEqualStringToken_the_length_of_token_is_4_expecte_length_of_token_is_6(void){
  StringToken* strTk = malloc(sizeof(StringToken));
  strTk->type = TOKEN_STRING_TYPE;
  strTk->length = 4;
  testAsserEqualStringToken("\"1234\"",strTk,__LINE__);
  printf("No.18\n");
}


void test_testAsserEqualStringToken_given_the_string_is_A232_and_expect_1234(void){
  StringToken* strTk = malloc(sizeof(StringToken));
  strTk->type = TOKEN_STRING_TYPE;
  strTk->length = 6;
  strTk->startColumn =6;
  strTk->str ="12342 \"A232\"";
  strTk->name = "\"A232\"";
  testAsserEqualStringToken("\"1234\"",strTk,__LINE__);
  printf("No.19\n");
}


void test_testAsserEqualStringToken_given_the_string_is_LAI_H3A_N3NG_and_expect_LAI_H3A_N3NG(void){
  StringToken* strTk = malloc(sizeof(StringToken));
  strTk->type = TOKEN_STRING_TYPE;
  strTk->length = 14;
  strTk->startColumn =13;
  strTk->str ="12342 \"A232\" \"LAI H3A NENG\" ";
  strTk->name = "\"LAI H3A NENG\"";
  testAsserEqualStringToken("\"LAI H3A N3NG\"",strTk,__LINE__);
  printf("No.20\n");
}


void test_testAsserEqualStringToken_given_the_string_is_LAI_H3A_N3NG_and_expect_LAI_H3A_N3NG(void){
  StringToken* strTk = malloc(sizeof(StringToken));
  strTk->type = TOKEN_STRING_TYPE;
  strTk->length = 14;
  strTk->startColumn =13;
  strTk->str ="12342 \"A232\" \"LAI HWA NENG\" ";
  strTk->name = "\"LAI HWA NENG\"";
  testAsserEqualStringToken("\"LAI H3A N3NG\"",strTk,__LINE__);
  printf("No.20\n");
}


//-----------------------testAsserEqualOperatorToken--------------------------------------------------
// void test_testAsserEqualOperatorTokenthe_token_is_tOKEN_IDENTIFIER_TYPE(void){
  
  // OperatorToken *opTk = malloc(sizeof(OperatorToken));
  // opTk->type = TOKEN_IDENTIFIER_TYPE;
  // testAsserEqualOperatorToken("+",opTk,__LINE__);
// }

// void test_testAsserEqualOperatorTokenthe_token_is_NULL(void){
  
  // OperatorToken *opTk = NULL;
  // testAsserEqualOperatorToken("+",opTk,__LINE__);
  //printf("No.21\n");
// }


// void test_testAsserEqualOperatorTokenthe_the_length_of_token_is_1_expecte_length_of_token_is_2(void){
  
  // OperatorToken *opTk = malloc(sizeof(OperatorToken));
  // opTk->type = TOKEN_OPERATOR_TYPE;
  // opTk->length = 2;
  // opTk->startColumn = 0;
  // opTk->str = "+ 1234";
  // opTk->symbol = "+";
  // testAsserEqualOperatorToken("+",opTk,__LINE__);
    //printf("No.22\n");
// }


// void test_testAsserEqualOperatorTokenthe_given_string_1234plus321_expected_symbol_is_plus(void){
  
  // OperatorToken *opTk = malloc(sizeof(OperatorToken));
  // opTk->type = TOKEN_OPERATOR_TYPE;
  // opTk->length = 1;
  // opTk->startColumn = 4;
  // opTk->str = "1234+321";
  // opTk->symbol = "+";
  // testAsserEqualOperatorToken("+",opTk,__LINE__);
       //printf("No.23\n");
// }


void test_double(void){
  char* str = "1234 ABC-A232";
  char* str1 = "ABC";
  char* actualStr = &str[5];
  int i = 0;
  int j = 0;
  int lengthStr = strlen(str1);
  
 while( actualStr[j] != 0 && isspace(actualStr[j]) == 0 && isspace(actualStr[i-1]) == 0 &&isOperator(actualStr[j]) == 0|| i < lengthStr ){
    printf("actualStr[%d] = %c,str1[%d] = %c\n",j,actualStr[j],i,str1[i]);
    if(str1[i] != actualStr[j]){
      printf("This %c and %c is not the same\n",actualStr[i],str1[i]);
    }
     j++;   
     i++;
  }   
    printf("No.24\n");
}

void xtest_testAsserEqualStringToken_given_A123_ABC_B23(void){
  IdentifierToken* idenToken = malloc(sizeof(IdentifierToken));
  idenToken->str = "2123 ABC A12324";
  idenToken->startColumn = 5;
  customTestAssertEqualString("ABC",&(idenToken->str[idenToken->startColumn]),__LINE__,"The string is not the same");  
    printf("No.25\n");
  }