#include "Token.h"
#include <malloc.h>


/**
 * This Token function is collect the data and convert to a token that will differential data
 * to form different type of token.
 * Eg.
 *
 *  Integer Token : 123 ,Ox1234 ,01234...
 *  Operator Token : "+","-"...
 * Function:
 *  Token *createOperatorToken(char *symbol, Arity AR);
 *  Token *createIntegerToken(int value);
 
 * Input:
 *	createOperatorToken:
 *	symbol - the symbol that type by user
 *  AR     - that is type of arity such as INFIX, PREFIX and POSTFIX
 *
 *  createIntegerToken：
*		value - the value that type by user
 *
 * Return:
 *    that are return a tree that data type is Token
 *
 */

Token *createOperatorToken(char *symbol){
OperatorToken *OpTk = malloc(sizeof(OperatorToken)+(sizeof(Token*)*2));
//	OperatorToken OpTk = {type:TOKEN_OPERATOR_TYPE,symbol: symbol,arity:AR};
		OpTk ->type = TOKEN_OPERATOR_TYPE;
		OpTk ->symbol =symbol;
  	return (Token*)OpTk;
}

Token *createIntegerToken(int value,int start,int length,char *str ){
	IntegerToken *InTk = malloc(sizeof(IntegerToken));
  InTk->length = length;
  InTk->startColumn = start;
	InTk->type = TOKEN_INTEGER_TYPE;
	InTk->value = value;
	InTk->str = str;
	return (Token*)InTk;
}

Token *createEndStrToken(char *symbol){
	OperatorToken *EndTk = malloc(sizeof(OperatorToken));
	EndTk->type = TOKEN_OPERATOR_TYPE;
	EndTk->symbol = symbol;
	return (Token*)EndTk;
}



