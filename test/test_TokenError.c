#include "unity.h"
#include "TokenError.h"
#include "ErrorObject.h"
#include "subFunction.h"
#include "CException.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_throwTokenizerError(void){
  
  	ErrorObject* err; 
    Try{
      //  doSomething();
    }Catch(err){
       printf("%s",err->errorMsg);
        freeError(err);
     }
 
}