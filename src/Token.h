#ifndef Token_H
#define Token_H

typedef enum {
	TOKEN_OPERATOR_TYPE,
	TOKEN_INTEGER_TYPE,
	TOKEN_IDENTIFIER_TYPE,
	TOKEN_STRING_TYPE,
	TOKEN_TYPE
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
} Token;

typedef struct {
	TokenType type;
	int value;
} IntegerToken;

typedef struct {
	TokenType type;
	char *symbol;
	Arity arity;
	Token *token[0];
} OperatorToken;

typedef struct{
	TokenType type;
	double value;
} FloatToken;
		
typedef struct{
	TokenType type;
	char *name;
} IdentifierToken,StringToken;


Token *createOperatorToken(char *symbol, Arity AR);
Token *createIntegerToken(int value);
// Token *createStringToken(char *str);
// Token *createIdentifierToken(char *str);
// Token *createFloatingToken(int value);
#endif // Token_H

