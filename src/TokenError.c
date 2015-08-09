#include "TokenError.h"
#include "ErrorObject.h"
#include "CException.h"
#include <stdarg.h>
#include "OperatorChecker.h"
#include <malloc.h>


/**
 * Using the throwTokenizerError(...) function to throw the error message and the error code. 
 * Eg.
 *     Error[6]:Expected Character is digit, but that was 'A' 
 *     "123123A12"
 *            ^ 
 * Function:
 *    void throwTokenizerError(ErrorCode errCode,StringObject *strO ,char *msg , ...);
 *
 * Input:
 *
 *  throwTokenizerError(...):
 *    message - store the message that set by user.
 *    errCode - The code that help user to identify the error.
 *       strO - store the string was typed by user in strO->str.
 *            - record the transiton times in strO->index.
 *
 * Return:
 *   throwTokenizerError(...):
 *       that will throw the error message to warn the user. 
 *    
 */
 
void throwTokenizerError(ErrorCode errCode,StringObject *strO ,char *msg , ...){
  ErrorObject *errObj=malloc(sizeof(ErrorObject));
  char *msgBuffer = malloc(1024);  //This buffer is for store the combine of msg and position of error.
  char *strArrow= malloc(1024);    //This buffer is for store the position of error.
  char *strBuffer;                 //This buffer is for store the msg of error.
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
