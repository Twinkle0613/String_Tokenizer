#ifndef Token_H
#define Token_H

 

#include <stdint.h>

typedef enum {
	TOKEN_UNKNOWN_TYPE,
	TOKEN_INTEGER_TYPE,
	TOKEN_OPERATOR_TYPE,
	TOKEN_FLOAT_TYPE,
	TOKEN_STRING_TYPE,
	TOKEN_IDENTIFIER_TYPE,
} TokenType;

typedef enum {
	PREFIX, //-2
	INFIX,	//2*2
	POSTFIX	//x++
} Arity;

typedef enum {
	NONE,
	LEFT_TO_RIGHT,
	RIGHT_TO_LEFT,
} Associativity;                                                                                                                                           

typedef struct {
	TokenType type;
  uint32_t startColumn;
  uint32_t length;
	char *str;
} Token;

typedef struct {
	TokenType type;
  uint32_t startColumn;
  uint32_t length;
	int value;
	char *str;
} IntegerToken;

typedef struct {
  TokenType type;
  uint32_t startColumn;
  uint32_t length;
	double value;
	char *str;
} FloatToken;

typedef struct {
	TokenType type;
  uint32_t startColumn;
  uint32_t length;
	char *name;
	char *str;
  Token *token;
} IdentifierToken, StringToken;

typedef struct {
	TokenType type;
  uint32_t startColumn;
  uint32_t length;
	char *str;
	char *symbol;
	Arity arity;
	Token *token[0];
} OperatorToken;

Token *createIntegerToken(char *str,int start,int length);
Token *createOperatorToken(char *str, int start, int length);

// Token *createOperatorToken(char *symbol, int start, int length, char *str);
// Token *createIntegerToken(int value,int start,int length,char *str);
Token *createEndStrToken(char *symbol);
// int isSingle(int Operator);
// int isTwin(int Operator);
// int isAssign(int Operator);
// int isTwinAssign(int Operator);

#endif // Token_H

