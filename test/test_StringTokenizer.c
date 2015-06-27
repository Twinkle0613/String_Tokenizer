#include "unity.h"
#include "StringTokenizer.h"
#include "Token.h"
#include "subFunction.h"




void setUp(void){}

void tearDown(void){}


/*
		str = "1234"
	
				 
				1->2->3->4->\0 
										||										 ----------------------
										V											|  TOKEN_INTEGER_TYPE |
					createIntegerToken()   =  			----------------------
																				 |         1234        |
																				 ----------------------
				
*/

void test_StringTokenizer_given_string_1234_should_return_IntegerToken(void){
	CEXCEPTION_T err;
	IntegerToken *newToken = malloc(sizeof(IntegerToken));
	Try{
		newToken =(IntegerToken*) StringTokenizer(createStringObject("1234"));
		printf("newToken->value = %d\n",newToken->value);
    TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,newToken->type);
		TEST_ASSERT_EQUAL(1234,newToken->value);
	}Catch(err){
		printError(err);
	}
 }
 
void test_StringTokenizer_given_string_1234space_should_return_IntegerToken(void){
	CEXCEPTION_T err;
	IntegerToken *newToken = malloc(sizeof(IntegerToken));	
	Try{
		newToken =(IntegerToken*) StringTokenizer(createStringObject("1234 "));
		printf("newToken->value = %d\n",newToken->value);
    TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,newToken->type);
		TEST_ASSERT_EQUAL(1234,newToken->value);
	}Catch(err){
		printError(err);
	}
 }
 
void test_StringTokenizer_given_string_1234endline_should_return_IntegerToken(void){
	CEXCEPTION_T err;
	IntegerToken *newToken = malloc(sizeof(IntegerToken));
	Try{
		newToken =(IntegerToken*) StringTokenizer(createStringObject("1234\n"));
		printf("newToken->value = %d\n",newToken->value);
    TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,newToken->type);
		TEST_ASSERT_EQUAL(1234,newToken->value);
	}Catch(err){
		printError(err);
	}
	
 }

 
void test_StringTokenizer_given_string_12A34endline_should_return_IntegerToken(void){
	CEXCEPTION_T err;
	IntegerToken *newToken = malloc(sizeof(IntegerToken));
	Try{
		newToken =(IntegerToken*) StringTokenizer(createStringObject("12A34\n"));
		printf("newToken->value = %d\n",newToken->value);
    TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,newToken->type);
		TEST_ASSERT_EQUAL(1234,newToken->value);
	}Catch(err){
		printError(err);
		TEST_ASSERT_EQUAL(ERR_STR_INCLURE_ALPHA,err);

	}
}	

void test_StringTokenizer_given_string__should_return_IntegerToken(void){
	CEXCEPTION_T err;
	IntegerToken *newToken = malloc(sizeof(IntegerToken));
	Try{
		newToken =(IntegerToken*) StringTokenizer(createStringObject(" "));
		printf("newToken->value = %d\n",newToken->value);
    TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,newToken->type);
		TEST_ASSERT_EQUAL(1234,newToken->value);
	}Catch(err){
		printError(err);
		TEST_ASSERT_EQUAL(ERR_STR_CANNOT_BE_EMPTY,err);

	}
	
}
