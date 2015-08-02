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
 *    Token *createIntegerToken(strO);
 *    Token *createOperatorToken(strO);
 *    Token *createStringToken(strO);
 *    Token *createIdentifierToken(strO);
 *    Token *createFloatToken(strO);
 *    Token *createEndStrToken(char *symbol);
 *
 * Input:
 *	The input for all of createXXXXXToken(...) function execept createEndStrToken().
 *  strO - store the string was typed by user in strO->str.
 *       - record the transiton times in strO->index.
 *       - record the start point in strO->startIndex.
 *       - store the type of newToken when a newToken was created.
 *       - store a token when a newToken was created.
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
