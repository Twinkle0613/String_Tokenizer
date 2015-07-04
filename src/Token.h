#ifndef Token_H
#define Token_H

//<<<<<<< HEAD
//=======
#include <stdint.h>

//>>>>>>> 42bf950670b0fce17cac55432346920c3e1fe5a8
typedef enum {
	TOKEN_UNKNOWN_TYPE,
	TOKEN_INTEGER_TYPE,
	TOKEN_OPERATOR_TYPE,
	TOKEN_FLOAT_TYPE,
	TOKEN_STRING_TYPE,
	TOKEN_IDENTIFIER_TYPE,
	TOKEN_END_OF_STRING
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


Token *createOperatorToken(char *symbol, Arity AR);
Token *createIntegerToken(int value,int start,int length,char *str);
Token *createEndStrToken(char *symbol);
//Token *createIntegerToken(int value);
//<<<<<<< HEAD
// Token *createStringToken(char *str);
// Token *createIdentifierToken(char *str);
// Token *createFloatingToken(int value);

//=======

//>>>>>>> 42bf950670b0fce17cac55432346920c3e1fe5a8
#endif // Token_H

