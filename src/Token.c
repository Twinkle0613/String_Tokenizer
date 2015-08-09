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
 * Using the createSubString(...) functions to select the any part of string. 

 *
 * Eg.
 *  Integer Token : 123 ,Ox1234 ,01234...
 *  Operator Token : "+","-"...
 *  Identifier Token : "ADS_213","LOS123"
 *  String Token : ""string"",""Hello world""
 *  Float Token : 12.23 ,1e20...
 *  
 *   createSubString(...):
 *      start = 3;
 *      length = 4
 *      str = "12312342123"
 *                ^^^^
 *      subStr = createSubString(char *str, int start , int length);
 *      The subStr that contain "1234".
 *
 *
 * Function:
 *    Token *createIntegerToken(strO);
 *    Token *createOperatorToken(strO);
 *    Token *createStringToken(strO);
 *    Token *createIdentifierToken(strO);
 *    Token *createFloatToken(strO);
 *    Token *createEndStrToken(char *symbol);
 *    char *createSubString(char *str, int start , int len);
 *
 * Input:
 *	The input for all of createXXXXXToken(...) function execept createEndStrToken().
 *  strO - store the string was typed by user in strO->str.
 *       - record the transiton times in strO->index.
 *       - record the start point in strO->startIndex.
 *       - store the type of newToken when a newToken was created.
 *       - store a token when a newToken was created.
 * 
 *  createSubString(...):
 *     str - store the string for user key in.
 *   start - record the start point for counter of getToken(...) function.
 *  length - store the length for string that need to form a token
 *  
 *  createEndStrToken():
 *  symbol - The symbol that are collect when getToken that get last token at the end of string.
 *
 *
 * Return:
 *    createXXXXXToken(...)：
 *       Return a token that was identified the type by getToken(...) function.
 *    createSubString(...):
 *       return the string that was selected by getToken(...) function.
 */
 																										
char *createSubString(char *str, int start , int len){
  char *newStr = malloc(sizeof(char)*(len+1));
  int i = 0;                 //the initial position of character is 0 in newStr.
  int j = start;             //the initial position of character is declare by user.
  while ( j < (len+start) ){
    newStr[i] = str[j];      //Copy a character to newStr.
    i++;
    j++;
  }
  newStr[i] = 0;             //The end of string must be declare to a NULL.
  return newStr;
}

Token *createOperatorToken(StringObject *strO){
  OperatorToken *opTk = malloc(sizeof(OperatorToken)+(sizeof(Token*)*2));
  opTk->type = TOKEN_OPERATOR_TYPE;
  opTk->symbol = createSubString(strO->str,strO->startIndex,strO->index - strO->startIndex);
  opTk->startColumn = strO->startIndex;
  opTk->length = strO->index - strO->startIndex;
  opTk->str = strO->str;	
  return (Token*)opTk;
}

Token *createFloatToken(StringObject *strO){
  FloatToken *flTk = malloc(sizeof(FloatToken));
  flTk->type = TOKEN_FLOAT_TYPE;
  flTk->value = strtod(createSubString(strO->str,strO->startIndex,strO->index - strO->startIndex),NULL);
  flTk->startColumn = strO->startIndex;
  flTk->length = strO->index - strO->startIndex;
  flTk->str = strO->str;	
  return (Token*)flTk;
}

Token *createIntegerToken(StringObject *strO, int base){
  IntegerToken *inTk = malloc(sizeof(IntegerToken));
  inTk->type = TOKEN_INTEGER_TYPE;
  inTk->value = strtol(createSubString(strO->str,strO->startIndex,strO->index - strO->startIndex),NULL,base);
  inTk->startColumn = strO->startIndex;
  inTk->length = strO->index - strO->startIndex;
  inTk->str = strO->str;	
	return (Token*)inTk;
}

Token *createIdentifierToken(StringObject *strO){
  IdentifierToken *idTk = malloc(sizeof(IdentifierToken)+(sizeof(Token*)*1));
  idTk->type = TOKEN_IDENTIFIER_TYPE;
  idTk->name = createSubString(strO->str,strO->startIndex,strO->index - strO->startIndex);
  idTk->startColumn = strO->startIndex;
  idTk->length = strO->index - strO->startIndex;
  idTk->str = strO->str;	
  return (Token*)idTk;
}

Token *createStringToken(StringObject *strO){
  StringToken *stTk = malloc(sizeof(StringToken)+(sizeof(Token*)*1));
  stTk->type = TOKEN_STRING_TYPE;
  stTk->name = createSubString(strO->str,strO->startIndex,strO->index - strO->startIndex);
  stTk->startColumn = strO->startIndex;
  stTk->length = strO->index - strO->startIndex;
  stTk->str = strO->str;	
  return (Token*)stTk;
}

Token *createEndStrToken(char *symbol){
  OperatorToken *endTk = malloc(sizeof(OperatorToken));
  endTk->type = TOKEN_OPERATOR_TYPE;
  endTk->symbol = symbol;
  return (Token*)endTk;
}
