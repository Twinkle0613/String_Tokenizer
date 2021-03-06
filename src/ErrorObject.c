//Own module files
#include "ErrorObject.h"
#include "CException.h"


//Labrary
#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * Using the throwError(...) function to throw the error message and the error code. 
 * Using the freeError(...) function to free inside address of allocation.
 * Eg.
 *            str = NULL;
 *           Error: The String Object can't be a NULL!
 *                         
 * Function:
 *    void freeError(ErrorObject* errObj);
 *    void throwError(char *message, ErrorCode errCode);
 *
 * Input:
 *
 *  freeError(...):
 *    errObj - the address of allocation will be to free
 * 
 *  throwError(...):
 *    message - store the message that set by user.
 *    errCode - The code that help user to identify the error.
 *    
 * Return:
 *    throwError(...):
 *       that will throw the error message to warn the user. 
 *    
 *
 */
void throwError(char *message, ErrorCode errCode){
  ErrorObject *errObj = malloc(sizeof(ErrorObject));
  errObj->errorMsg = message;
  errObj->errorCode = errCode;
  Throw(errObj);
  }

  
void freeError(ErrorObject* errObj){
  free(errObj); //inside the free(address)
}
  


