#include "CException.h"
#include "ErrorObject.h"
#include "unity.h"
void setUp(void)

{

}



void tearDown(void)

{

}

void xtest_strtol(void){

  char *endptr;

  char* str = "123 4321";

  int value = strtol(str,&endptr,10);

  int value1 = strtol(endptr,&endptr,10);

  printf("str = %s\nvalue = %d ,endptr = %s ,str = %d ,endptr = %d, length = %d\n",str,value,endptr,str,endptr,endptr - str);



}
