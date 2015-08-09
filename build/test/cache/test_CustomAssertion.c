#include "OperatorChecker.h"
#include "Token.h"
#include "CustomAssertion.h"
#include "unity.h"






void setUp(void)

{

}



void tearDown(void)

{

}



void test_testAsserEqualIntegerToken_given_the_value_is_321_and_expect_value_321(void){

  IntegerToken* inTk = malloc(sizeof(IntegerToken));

  inTk->type = TOKEN_INTEGER_TYPE;

  inTk->value = 321;

  testAsserEqualIntegerToken(321,inTk,22);

  printf("No.1\n");

}



void test_testAsserEqualIntegerToken_given_the_value_is_0XA21_and_expect_value_0XA21(void){

  IntegerToken* inTk = malloc(sizeof(IntegerToken));

  inTk->type = TOKEN_INTEGER_TYPE;

  inTk->value = 0XA21;

  testAsserEqualIntegerToken(0XA21,inTk,30);

  printf("No.2\n");

}



void test_testAsserEqualIntegerToken_given_the_value_is_0721_and_expect_value_0721(void){

  IntegerToken* inTk = malloc(sizeof(IntegerToken));

  inTk->type = TOKEN_INTEGER_TYPE;

  inTk->value = 0721;

  testAsserEqualIntegerToken(0721,inTk,38);

  printf("No.3\n");

}



void test_testAsserEqualIntegerToken_given_the_value_is_321_and_expect_value_123 (void){

  IntegerToken* inTk = malloc(sizeof(IntegerToken));

  inTk->type = TOKEN_INTEGER_TYPE;

  inTk->value = 321;

  testAsserEqualIntegerToken(123,inTk,46);

  printf("No.4\n");

}



void test_testAsserEqualIntegerToken_given_token_is_NULL(void){

  IntegerToken* inTk = ((void *)0);

  testAsserEqualIntegerToken(123,inTk,52);

  printf("No.5\n");

}



void test_testAsserEqualIntegerToken_given_TOKEN_FLOAT_TYPE(void){

  IntegerToken* inTk = malloc(sizeof(IntegerToken));

  inTk->type = TOKEN_FLOAT_TYPE;

  testAsserEqualIntegerToken(123,inTk,59);

  printf("No.6\n");

}





void test_testAsserEqualFloatToken_given_TOKEN_INTEGER_TOKEN(void){

  FloatToken* flTk = malloc(sizeof(FloatToken));

  flTk->type = TOKEN_INTEGER_TYPE;

  testAsserEqualFloatToken(123.3,flTk,67);

  printf("No.7\n");

}



void test_testAsserEqualFloatToken_given_token_is_NULL(void){

  FloatToken* flTk = ((void *)0);

  testAsserEqualFloatToken(123.3,flTk,73);

  printf("No.8\n");

}



void test_testAsserEqualFloatToken_given_the_value_is_1point23_and_expect_value_123(void){

  FloatToken* flTk = malloc(sizeof(FloatToken));

  flTk->type = TOKEN_FLOAT_TYPE;

  flTk->value = 1.23;

  testAsserEqualFloatToken(123.3,flTk,81);

  printf("No.9\n");

}



void test_testAsserEqualFloatToken_given_the_value_is_1point23_and_expect_value_1point23(void){

  FloatToken* flTk = malloc(sizeof(FloatToken));

  flTk->type = TOKEN_FLOAT_TYPE;

  flTk->value = 1.23;

  testAsserEqualFloatToken(1.23,flTk,89);

  printf("No.10\n");

}









void test_testAsserEqualIdentifierToken_given_the_token_is_NULL(void){

  IdentifierToken* idenTk = ((void *)0);

  testAsserEqualIdentifierToken("A123",idenTk,98);

  printf("No.11\n");

}



void test_testAsserEqualIdentifierToken_given_the_token_is_tOKEN_FLOAT_TYPE(void){

  IdentifierToken* idenTk = malloc(sizeof(IdentifierToken));

  idenTk->type = TOKEN_FLOAT_TYPE;

  testAsserEqualIdentifierToken("A123",idenTk,105);

  printf("No.12\n");

}

void test_testAsserEqualIdentifierToken_given_The_length_of_token_is_3_expected_length_of_token_is_4(void){

  IdentifierToken* idenTk = malloc(sizeof(IdentifierToken));

  idenTk->type = TOKEN_IDENTIFIER_TYPE;

  idenTk->length = 3;

  testAsserEqualIdentifierToken("A124",idenTk,112);

  printf("No.13\n");

}



void test_testAsserEqualIdentifierToken_given_the_string_is_A12_and_expect_A13(void){

  IdentifierToken* idenTk = malloc(sizeof(IdentifierToken));

  idenTk->type = TOKEN_IDENTIFIER_TYPE;

  idenTk->length = 3;

  idenTk->name = "A13";

  idenTk->str = "B231 A13";

  idenTk->startColumn = 5;

  testAsserEqualIdentifierToken("A12",idenTk,123);

  printf("No.14\n");

}



void test_testAsserEqualIdentifierToken_given_the_string_is_LAI_HWA_NENG_and_expect_NENG(void){

  IdentifierToken* idenTk = malloc(sizeof(IdentifierToken));

  idenTk->type = TOKEN_IDENTIFIER_TYPE;

  idenTk->length = 4;

  idenTk->name = "NENG";

  idenTk->str = "LAI HWA NENG";

  idenTk->startColumn = 8;

  testAsserEqualIdentifierToken("NENG",idenTk,134);

  printf("No.15\n");

}







void test_testAsserEqualStringToken_the_token_is_tOKEN_IDENTIFIER_TYPE(void){

  StringToken* strTk = malloc(sizeof(StringToken));

  strTk->type = TOKEN_IDENTIFIER_TYPE;

  testAsserEqualStringToken("\"1234\"",strTk,143);

  printf("No.16\n");

}



void test_testAsserEqualStringToken_the_token_is_NULL(void){

  StringToken* strTk = ((void *)0);

  testAsserEqualStringToken("\"1234\"",strTk,149);

  printf("No.17\n");

}





void test_testAsserEqualStringToken_the_length_of_token_is_4_expecte_length_of_token_is_6(void){

  StringToken* strTk = malloc(sizeof(StringToken));

  strTk->type = TOKEN_STRING_TYPE;

  strTk->length = 4;

  testAsserEqualStringToken("\"1234\"",strTk,158);

  printf("No.18\n");

}





void test_testAsserEqualStringToken_given_the_string_is_A232_and_expect_1234(void){

  StringToken* strTk = malloc(sizeof(StringToken));

  strTk->type = TOKEN_STRING_TYPE;

  strTk->length = 6;

  strTk->startColumn =6;

  strTk->str ="12342 \"A232\"";

  strTk->name = "\"A232\"";

  testAsserEqualStringToken("\"1234\"",strTk,170);

  printf("No.19\n");

}





void test_testAsserEqualStringToken_given_the_string_is_LAI_H3A_N3NG_and_expect_LAI_H3A_N3NG(void){

  StringToken* strTk = malloc(sizeof(StringToken));

  strTk->type = TOKEN_STRING_TYPE;

  strTk->length = 14;

  strTk->startColumn =13;

  strTk->str ="12342 \"A232\" \"LAI H3A NENG\" ";

  strTk->name = "\"LAI H3A NENG\"";

  testAsserEqualStringToken("\"LAI H3A N3NG\"",strTk,182);

  printf("No.20\n");

}

void test_double(void){

  char* str = "1234 ABC-A232";

  char* str1 = "ABC";

  char* actualStr = &str[5];

  int i = 0;

  int j = 0;

  int lengthStr = strlen(str1);



 while( actualStr[j] != 0 && isspace(actualStr[j]) == 0 && isspace(actualStr[i-1]) == 0 &&(isValidOperator(operatorAtrributes[actualStr[j]])) == 0|| i < lengthStr ){

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

  customTestAssertEqualString("ABC",&(idenToken->str[idenToken->startColumn]),251,"The string is not the same");

    printf("No.25\n");

  }
