#include "unity.h"
#include "StringTokenizer.h"





void setUp(void){}

void tearDown(void){}

void test_createIntergerToken(void){
	

	
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
	TEST_ASSERT_EQUAL(-1,StringTokenizer("A"));
	TEST_ASSERT_EQUAL(0,StringTokenizer("0123")); //Noted
	TEST_ASSERT_EQUAL(0,StringTokenizer("0x123")); //Noted
	
	//CEXCEPTION_T err;
	//Try{}Catch(err){}
}