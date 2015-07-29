#ifndef Token_H
#define Token_H


//Library
#include <stdint.h>

#define Octal 8
#define Decimal 10
#define Hexdecimal 16



typedef enum{

	InitialState,
	IntegerState,
	IdentifierState,
	StringState,
	OperatorState,
	FloatingState,
	TwinAssignState,
  DecimalPointState,
  ExponentState,
  NegPosExponentState,
  HexdecimalState,
  OctalState,
	UnknownState
	
}TokenState;

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

typedef struct {
  
	TokenType type;
  char *str;
	int index;	
  int startIndex;
  int length;
  
  Token* token;
}StringObject;

 Token *createIntegerToken(StringObject *strO,int base);
 Token *createOperatorToken(StringObject *strO);
 Token *createStringToken(StringObject *strO);
 Token *createIdentifierToken(StringObject *strO);
 Token *createFloatToken(StringObject *strO);
 Token *createEndStrToken(char *symbol);

//Token *createIntegerToken(char *str,int start,int length,int base);
// Token *createOperatorToken(char *str, int start, int length);
// Token *createStringToken(char *str,int start, int length);
// Token *createIdentifierToken(char *str,int start, int length);
// Token *createFloatToken(char *str, int start, int length);
//Token *createEndStrToken(char *symbol);

#endif // Token_H

