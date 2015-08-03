#include "TokenError.h"
#include "ErrorObject.h"
#include "subFunction.h"
#include "CException.h"
#include <stdarg.h>
#include "OperatorChecker.h"

void throwTokenizerError(ErrorCode errCode,StringObject *strO ,char *msg , ...){
  ErrorObject *errObj=malloc(sizeof(ErrorObject));
  char *msgBuffer = malloc(1024);
  char *strArrow= malloc(1024);
  char *strBuffer;
  int msgLength;
  int strLength;
  va_list args;
  va_start(args,msg);
  sprintf(strArrow,"%*s^",strO->index,""); 
  strLength = vsnprintf(strBuffer,0,msg,args);
  strBuffer = malloc(strLength + 1);
  vsprintf(strBuffer, msg, args);
  sprintf(msgBuffer,"Error[%d]:%s\n%s\n%s\n",strO->index,strBuffer,strO->str,strArrow);
  errObj->errorMsg = msgBuffer;
  errObj->errorCode = errCode;
  va_end(args);
  Throw(errObj);
}
