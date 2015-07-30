#include "unity.h"
#include "TokenError.h"
#include "ErrorObject.h"
#include "subFunction.h"
#include "CException.h"
#include "OperatorChecker.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void xtest_throwTokenizerError(void){
  
  	CEXCEPTION_T err; 
    Try{
       doSomething();
    }Catch(err){
       printf("%s",err->errorMsg);
        freeError(err);
     }
 
}