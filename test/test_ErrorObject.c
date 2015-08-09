#include "unity.h"
#include "ErrorObject.h"
#include "CException.h"
#include <malloc.h>
void setUp(void)
{
}

void tearDown(void)
{
}



// void test_dosomething(void){
	// ErrorObject* err; 
 // Try{
   // doSomething();
    // TEST_FAIL_MESSAGE("Expect ERR_DUNNO_WHAT_HAPPEN to be thrown. But none thrown.");
  // }Catch(err){
         // printf("%s",err->errorMsg);
    // TEST_ASSERT_EQUAL_STRING("Hey! Something is really wrong here",err->errorMsg);
     // TEST_ASSERT_EQUAL(ERR_STR_INCLURE_ALPHA,err->errorCode);
    // freeError(err);
  // }	
// }
// void test_pinpointTokenLocation(void){
  
  // *Token token = malloc(sizeof(Token));
  
  
// }

void xtest_strtol(void){
  char *endptr;
  char* str = "123 4321";
  int value = strtol(str,&endptr,10);
  int value1 = strtol(endptr,&endptr,10);
  printf("str = %s\nvalue = %d ,endptr = %s ,str = %d ,endptr = %d, length = %d\n",str,value,endptr,str,endptr,endptr - str);
 // printf("str = %s\nvalue1 = %d ,endptr = %s ,str = %,endptr = %d, length = %d\n",str,value,endptr,str,endptr,endptr - str);
}

