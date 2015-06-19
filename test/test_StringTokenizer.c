#include "unity.h"
#include "StringTokenizer.h"
#include "Token.h"




void setUp(void){}

void tearDown(void){}

/*
							
												 -----------------------
    StringObject ------>|str = "1234"|Index = 0|
												-----------------------

*/

void test_createStringObject(void){
	StringObject *strO;
	strO = createStringObject("1234");
	TEST_ASSERT_EQUAL(0,strO->index);
	TEST_ASSERT_EQUAL("1234",strO->str);
	printf("strO->index = %d , strO->str = %c",strO->index,strO->str[1]);
}



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
	StringObject *str = createStringObject("1234");
	TEST_ASSERT_EQUAL(0,str->index);
	TEST_ASSERT_EQUAL("1234",str->str);
	
	Try{
		
		newToken =(IntegerToken*) StringTokenizer(str);
    TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,newToken->type);
		TEST_ASSERT_EQUAL(1234,newToken->value);
		
		
	}Catch(err){
				switch(err)
					{
						case ERR_STR_INCLURE_ALPHA:
						printf("The string cannot have Alpha\n");
						break;
						case ERR_STR_INCLUDE_SYMBOL:
						printf("Error: Can't include Symbol\n");
						break;
						case ERR_STR_CANNOT_BE_EMPTY:
						printf("Error: Can't be Empty \n");
						break;
						case ERR_STR_CANNOT_BE_NULL:
						printf("Error: Can't be NULL\n");
						break;
						default:
						printf("Unknown Error caught! Error code is :%d\n", err);
						break;
					}
	}
	
	
 }
 
 
 /*
		str = "1234 "
	
				 
				1->2->3->4->' ' 
										||										 ----------------------
										V											|  TOKEN_INTEGER_TYPE |
					createIntegerToken()   =  			----------------------
																				 |         1234        |
																				 ----------------------
				
*/

/*
		str = "1234\n"
	
				 
				1->2->3->4->\n 
										||										 ----------------------
										V											|  TOKEN_INTEGER_TYPE |
					createIntegerToken()   =  			----------------------
																				 |         1234        |
																				 ----------------------
				
*/


 
/* void xtest_transition_of_state_machine(void){
	
	TEST_ASSERT_EQUAL(0,StringTokenizer("123124123"));
	TEST_ASSERT_EQUAL(0,StringTokenizer("1231 24123"));
	TEST_ASSERT_EQUAL(0,StringTokenizer("1231 24123 "));
	TEST_ASSERT_EQUAL(0,StringTokenizer("1231 24123   "));
	TEST_ASSERT_EQUAL(-1,StringTokenizer("1231 24A"));
	TEST_ASSERT_EQUAL(-1,StringTokenizer("1231A24123 "));
	TEST_ASSERT_EQUAL(-1,StringTokenizer(""));
	TEST_ASSERT_EQUAL(0,StringTokenizer(" "));
	TEST_ASSERT_EQUAL(-1,StringTokenizer("."));
	TEST_ASSERT_EQUAL(-1,StringTokenizer("123 .1243")); //Noted
	TEST_ASSERT_EQUAL(0,StringTokenizer("1231\n24123  \n"));
	TEST_ASSERT_EQUAL(0,StringTokenizer("1231\n24123\n"));
	TEST_ASSERT_EQUAL(0,StringTokenizer("ASDF123424123  \n"));
	TEST_ASSERT_EQUAL(-1,StringTokenizer("A"));
	TEST_ASSERT_EQUAL(0,StringTokenizer("0123")); //Noted
	TEST_ASSERT_EQUAL(-1,StringTokenizer("0x123")); //Noted
	
	//CEXCEPTION_T err;
	//Try{}Catch(err){}
} */

/* void test_createIntegerToken(void){
	
		// mock_Token
		// IntegerToken	*Tk = malloc(sizeof(IntegerToken));
	 
		// Tk->value = 1234123;
		// Tk->type = TOKEN_INTEGER_TYPE;
		// createIntegerToken_ExpectAndReturn(1234123,(Token*)Tk);
		
	CEXCEPTION_T err;

	Try{
		
			IntegerToken *InTk = malloc(sizeof(IntegerToken));
			InTk = (IntegerToken*)StringTokenizer("12341 23 123 13");
			printf("InTk->value = %d",InTk->value);
			TEST_ASSERT_EQUAL(12341,InTk->value);
			
			}Catch(err){

					switch(err)
					{
						case ERR_STR_INCLURE_ISALPHA:
						printf("The string cannot have Alpha\n");
						break;
			
			
						default:
						printf("Unknown Error caught! Error code is :%d\n", err);
						break;
					}
			
			
			}
	
	
	
	
} */