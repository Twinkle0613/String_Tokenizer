#include "unity.h"
#include "StringTokenizer.h"
#include "mock_Token.h"




void setUp(void){}

void tearDown(void){}

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

void test_createIntegerToken(void){
	
	
		IntegerToken	*Tk = malloc(sizeof(IntegerToken));
	 
		Tk->value = 1234123;
		Tk->type = TOKEN_INTEGER_TYPE;
		createIntegerToken_ExpectAndReturn(1234123,(Token*)Tk);
		
	CEXCEPTION_T err;

	Try{
		
			IntegerToken *InTk = malloc(sizeof(IntegerToken));
			InTk = (IntegerToken*)StringTokenizer("1234123\n");
			printf("InTk->value = %d",InTk->value);
			TEST_ASSERT_EQUAL(1234123,InTk->value);
			
/* 		
			IntegerToken *InTk = malloc(sizeof(IntegerToken));
			InTk =(IntegerToken*)createIntegerToken(9); 
*/
		
	}Catch(err){

			 switch(err){
  case ERR_STR_INCLURE_ISALPHA:
    printf("The string cannot have Alpha\n");
     break;
  case ERR_TEXT_IS_EMPTY:
     
     printf("The text cannot be empty\n");
    break;
  
  case ERR_NOT_A_NUMBER:
    printf("The text cannot be number\n");
    break;
  case ERR_CANNOT_BE_FLOAT_NUMBER:
    printf("The text cannot be Float number\n");
    break;
     default:
     printf("Unknown Error caught! Error code is :%d\n", err);
     break;
    }
			
	
	}
	
	
	
	
}