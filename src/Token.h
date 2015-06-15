#ifndef Token_H
#define Token_H


typedef enum {

	TOKEN_INTEGER_TYPE,
	TOKEN_OPERATOR_TYPE,
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
}Token;

typedef struct {
	TokenType type;
	int value;
}IntegerToken;


typedef struct {
	TokenType type;
	char *symbol;
	Arity arity;
//	Associativity assoc;
	Token *token[0];
}OperatorToken;

// symbol can be "++", "*", "[", ":"
Token *createOperatorToken(char *symbol, Arity AR);
Token *createIntegerToken(int value);
#endif // Token_H

