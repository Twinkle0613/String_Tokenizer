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
/*
	TEST LIST
	-----------------------------------------------------------------
	NO	strO        TokenType 					        Return/Throw			 	Condition
	-----------------------------------------------------------------
	1		NULL					Error							        -5									Complete						
	-----------------------------------------------------------------
	NO	str					TokenType					        	Return/Throw       Condition
	-----------------------------------------------------------------
	1		"1234"     		InTk						 	        1234  							Complete 
	2		"1234 "    		InTk 							        1234								Complete
	3		"1234\n"    	InTk							        1234								Complete
	4		"1234\0"    	InTk 							        1234								Complete
	5		" "          	OpTk							        $ 									Complete
	6		"1234"      	InTk OpTk OpTk 		        1234 '$' '$'				Complete
	7		NULL        	Error							        -4									Complete
	8		"12A34"       Error							        -1									Complete
	9		"123*4"       Error							        -2									Complete
	10	""            OpTk 							         $ 									Complete
	11  "1234 1234"		InTk InTk	OpTk		        1234 4321 $         Complete
  12  "123 4 214"   InTk InTk	OpTk OpTk       123 4 214 $         Complete    
	-----------------------------------------------------------------
*/
/*strO*/
//1
void xtest_StringTokenizer_given_strO_NULL_should_throw_err_STR_OBJECT_CANNOT_BE_NULL(void){
	
		CEXCEPTION_T err;
	Try{
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(NULL);
		//printf("newToken->symbol = %c\n",newToken->symbol);
		//TEST_LAST_TOKEN(newToken);
	
	}Catch(err){
		printError(err);
		printf("Number of Error = %d",err);
		TEST_ASSERT_EQUAL(ERR_STR_OBJECT_CANNOT_BE_NULL,err);
	}
	
}
/*string*/
void xtest_StringTokenizer_given_string_1234_should_return_IntegerToken(void){
	printf("No.1\n");
	CEXCEPTION_T err;
	Try{
		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("1234"));
		printf("newToken->value = %d\n",newToken->value);
		
		TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234",newToken);

	}Catch(err){
		printError(err);
	}
 }
//2 
void xtest_StringTokenizer_given_string_1234space_should_return_IntegerToken(void){
	printf("No.2\n");
	CEXCEPTION_T err;
	Try{
		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("1234 "));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234 ",newToken);

	}Catch(err){
		printError(err);
	}
 }
//3 
void xtest_StringTokenizer_given_string_1234endline_should_return_IntegerToken(void){
	printf("No.3\n");

	CEXCEPTION_T err;

	Try{
			IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("1234\n"));
			printf("newToken->value = %d\n",newToken->value);
			TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234\n",newToken);
	}Catch(err){
		printError(err);
	}
	
 }
//4
void xtest_StringTokenizer_given_string_1234_0__should_return_IntegerToken(void){
	printf("No.4\n");

	CEXCEPTION_T err;
	Try{
		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("1234\0"));
		TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234",newToken);
		printf("newToken->value = %d\n",newToken->value);
		printf("newToken->length = %d\n",newToken->length);
		printf("newToken->startColunm = %d\n",newToken->startColumn);
		printf("newToken->str = %s\n",newToken->str);
		
	}Catch(err){
		printError(err);
	}
	
 }
//5 
void xtest_StringTokenizer_given_string_space_should_return_OperatorToken_that_symbol_is_money(void){
	printf("No.5\n");

	CEXCEPTION_T err;
	Try{
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject(" "));
		printf("newToken->symbol = %s\n",newToken->symbol);
		TEST_LAST_TOKEN(newToken);

		//TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,newToken->type);
		//TEST_ASSERT_EQUAL('$',newToken->symbol);
	
	}Catch(err){
		printError(err);
		
	}
	
}
//6
void xtest_StringTokenizer_given_string_1234_should_return_IntegerToken_and_return_OperatorToken(void){
	printf("No.6\n");

	CEXCEPTION_T err;
	StringObject *str = createStringObject("1234");
		Try{
				IntegerToken *newToken1 = (IntegerToken*) StringTokenizer(str);
				printf("newToken->value = %d\n",newToken1->value);
							TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234",newToken1);

				OperatorToken *newToken2 = (OperatorToken*) StringTokenizer(str);
				printf("newToken->symbol = %s\n",newToken2->symbol);
				TEST_LAST_TOKEN(newToken2);

				OperatorToken *newToken3 =(OperatorToken*) StringTokenizer(str);
				printf("newToken->symbol = %s\n",newToken3->symbol);
				TEST_LAST_TOKEN(newToken3);

				}Catch(err){
					printError(err);
			}	
}
//7
void xtest_StringTokenizer_given_string_NULL_should_throw_err_STR_CANNOT_BE_NULL(void){
		printf("No.7\n");

		CEXCEPTION_T err;
	Try{
		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject(NULL));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_NULL(newToken);
	}Catch(err){
		printError(err);
		printf("Number of Error = %d",err);
		TEST_ASSERT_EQUAL(ERR_STR_CANNOT_BE_NULL,err);
	}
}
//8
void xtest_StringTokenizer_given_string_12A34_throw_err_STR_INCLURE_ALPHA(void){
		printf("No.8\n");

	CEXCEPTION_T err;
	Try{
		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("12A34"));
		printf("newToken->value = %d\n",newToken->value);
					TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234\n",newToken);
	}Catch(err){
		printError(err);
		printf("Number of Error = %d",err);
		TEST_ASSERT_EQUAL(ERR_STR_INCLURE_ALPHA,err);
	}
}	
//9
void xtest_StringTokenizer_given_string_123star4_thorw_err_STR_INCLUDE_SYMBOL(void){
		printf("No.9\n");

		CEXCEPTION_T err;
	Try{
		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("123*4"));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(123,0,3,"123*4",newToken);

	}Catch(err){
		printError(err);
		printf("Number of Error = %d",err);
		//TEST_ASSERT_EQUAL(ERR_STR_INCLUDE_SYMBOL,err);
	}
}
//10
void xtest_StringTokenizer_given_string_return_money(void){
		printf("No.10\n");

	CEXCEPTION_T err;
	Try{
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject(""));
		printf("newToken->symbol = %s\n",newToken->symbol);
		TEST_LAST_TOKEN(newToken);
	}Catch(err){
		printError(err);
		printf("Number of Error = %d",err);
		TEST_ASSERT_EQUAL(ERR_STR_INCLUDE_SYMBOL,err);
	}

}
//11 
void xtest_StringTokenizer_given_string_1234_4321_should_return_2_IntegerToken(void){
		printf("No.11\n");

		CEXCEPTION_T err;
	StringObject *str = createStringObject("1234 4321");
		Try{
				IntegerToken *newToken1 = (IntegerToken*) StringTokenizer(str);
				printf("newToken->value = %d\n",newToken1->value);
				TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234 4321",newToken1);

				IntegerToken *newToken2 = (IntegerToken*) StringTokenizer(str);
				printf("newToken->value = %d\n",newToken2->value);
				TEST_ASSERT_INTEGER_TOKEN(4321,5,4,"1234 4321",newToken2);

				OperatorToken *newToken3 =(OperatorToken*) StringTokenizer(str);
				printf("newToken->symbol = %s\n",newToken3->symbol);
				TEST_LAST_TOKEN(newToken3);

				}Catch(err){
					printError(err);
			}	
	
}
//12
void xtest_StringTokenizer_given_string_123_4_214_should_return_3_IntegerToken(void){
		printf("No.12\n");

		CEXCEPTION_T err;
	StringObject *str = createStringObject("123 4 214");
		Try{
				IntegerToken *newToken1 = (IntegerToken*) StringTokenizer(str);
				printf("newToken->value = %d\n",newToken1->value);
				TEST_ASSERT_INTEGER_TOKEN(123,0,3,"123 4 214",newToken1);

				IntegerToken *newToken2 = (IntegerToken*) StringTokenizer(str);
				printf("newToken->value = %d\n",newToken2->value);
				TEST_ASSERT_INTEGER_TOKEN(4,4,1,"123 4 214",newToken2);

        IntegerToken *newToken3 = (IntegerToken*) StringTokenizer(str);
				printf("newToken->value = %d\n",newToken3->value);
				TEST_ASSERT_INTEGER_TOKEN(214,6,3,"123 4 214",newToken3);
        
				OperatorToken *newToken4 =(OperatorToken*) StringTokenizer(str);
				printf("newToken->symbol = %s\n",newToken4->symbol);
				TEST_LAST_TOKEN(newToken4);

				}Catch(err){
					printError(err);
			}	
	
}
