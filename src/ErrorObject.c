#include "ErrorObject.h"
#include "CException.h"
#include <malloc.h>
#define shouldFail 1

void throwError(char *message, ErrorCode errCode){
    ErrorObject *errObj = malloc(sizeof(ErrorObject));
    errObj->errorMsg = message;
    errObj->errorCode = errCode;
    Throw(errObj);
  }

  
 void freeError(ErrorObject* errObj){
   free(errObj); //inside the free(address)
 }
  
  
// int doSomething(){
  	// ErrorObject *errObj = malloc(sizeof(ErrorObject));

  // if(shouldFail){
    // throwError("Hey! Something is really wrong here",ERR_STR_INCLURE_ALPHA);
  // }
  // return 1;
   // }
