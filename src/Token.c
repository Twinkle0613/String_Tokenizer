//Own module files
#include "Token.h"
#include "StringTokenizer.h"

//Library
#include <malloc.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Using the creatXXXXXToken function to create a token that was identified the type by getToken(...) function.  
 *
 *
 * Eg.
 *  Integer Token : 123 ,Ox1234 ,01234...
 *  Operator Token : "+","-"...
 *  Identifier Token : "ADS_213","LOS123"
 *  String Token : ""string"",""Hello world""
 *  Float Token : 12.23 ,1e20...
 *  
 * Function:
 *    Token *createIntegerToken(char *str,int start,int length,int base);
 *    Token *createOperatorToken(char *str, int start, int length);
 *    Token *createStringToken(char *str,int start, int length);
 *    Token *createIdentifierToken(char *str,int start, int length);
 *    Token *createFloatToken(char *str, int start, int length);
 *    Token *createEndStrToken(char *symbol);
 *
 * Input:
 *	The input for all of createXXXXXToken(...) function execept createEndStrToken().
 *	 str - That is a string was typed by user.
 *   start - That collect the initial position of counter for getToken ().  
 *   length - That length of string for token. 
 *
 *  createEndStrToken():
 *  symbol - The symbol that are collect when getToken that get last token at the end of string.
 *
 *
 * Return:
 *    createXXXXXToken(...)：
        Return a token that was identified the type by getToken(...) function.
 *
 */
 																										



Token *createOperatorToken(char *str, int start, int length){
    OperatorToken *OpTk = malloc(sizeof(OperatorToken)+(sizeof(Token*)*2));
    OpTk->type = TOKEN_OPERATOR_TYPE;
    OpTk->symbol = createSubString(str,start,length);
    OpTk->startColumn = start;
    OpTk->length = length;
    OpTk->str = str;	
    return (Token*)OpTk;
}

Token *createFloatToken(char *str, int start, int length){
    FloatToken *FlTk = malloc(sizeof(FloatToken));
    FlTk->type = TOKEN_FLOAT_TYPE;
    FlTk->value = strtod(createSubString(str,start,length),NULL);
    FlTk->startColumn = start;
    FlTk->length = length;
    FlTk->str = str;	
    return (Token*)FlTk;
}

//Token *createIntegerToken(char *str,int start,int length){
Token *createIntegerToken(char *str,int start,int length, int base){
    IntegerToken *InTk = malloc(sizeof(IntegerToken));
    InTk->type = TOKEN_INTEGER_TYPE;
    //InTk->value = atoi( createSubString(str,start,length) );
    InTk->value = strtol( createSubString(str,start,length),NULL,base );
    InTk->startColumn = start;
    InTk->length = length;
    InTk->str = str;
	return (Token*)InTk;
}

Token *createIdentifierToken(char *str,int start, int length){
    IdentifierToken *IdTk = malloc(sizeof(IdentifierToken)+(sizeof(Token*)*1));
    IdTk->type = TOKEN_IDENTIFIER_TYPE;
    IdTk->name = createSubString(str,start,length);
    IdTk->startColumn = start;
    IdTk->length = length;
    IdTk->str = str;
  return (Token*)IdTk;
}

Token *createStringToken(char *str,int start, int length){
    StringToken *StTk = malloc(sizeof(StringToken)+(sizeof(Token*)*1));
    StTk->type = TOKEN_STRING_TYPE;
    StTk->name = createSubString(str,start,length);
    StTk->startColumn = start;
    StTk->length = length;
    StTk->str = str;
  return (Token*)StTk;
}

Token *createEndStrToken(char *symbol){
    OperatorToken *EndTk = malloc(sizeof(OperatorToken));
    EndTk->type = TOKEN_OPERATOR_TYPE;
    EndTk->symbol = symbol;
    return (Token*)EndTk;
}


	// throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,"Expected Character that is a digit, but that was '\c'",curChar);
  
// void throwTokenizerError(ErrorCode errCode,StringObject *strO,char *msg , ...){
  
  // ErrorObject *errObj=malloc(sizeof(ErrorObject));
  // char *msgBuffer = malloc(1024);
  // char *strBuffer;
  // char *strArrow;
  // int msgLength;
  // int strLength;
  
  // va_list args;
  // va_start(args,msg);
  
  // sprintf(strArrow,"%*s",strO->index,"^"); 
  
  // strLength = vsnprintf(strBuffer,0,msg,args);
  // strBuffer = malloc(strLength + 1);
  // vsprintf(strBuffer, msg, args);

  // vsprintf(msgBuffer,"Error[%d]:%s\n%s\n%s",i,strBuffer,strO->str,strArrow);
  
  // errObj->errorMsg=msgBuffer;
  // errObj->errorCode=errCode;

  // va_end(args);
  // Throw(errObj);
// }