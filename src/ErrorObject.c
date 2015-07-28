#include "ErrorObject.h"
#include "CException.h"
#include <malloc.h>

#define shouldFail 1
void throwError(char *message, ErrorCode errCode){
    //printf("ERROR\n");
     printf("ERROR[%d][%d]: %s",__LINE__,3,message);
    ErrorObject *errObj = malloc(sizeof(ErrorObject));
    errObj->errorMsg = message;
    errObj->errorCode = errCode;
    Throw(errObj);
  }

  
 void freeError(ErrorObject* errObj){
   free(errObj); //inside the free(address)
 }
  

// void pinpointTokenLocation(Token *token){
  
   // int i;
   // printf("%*s",token->startColumn+1,"^");
   // for(i = 0; i < token->length - 1; i++)
     // printf("~");
   // puts("");
// }