#ifndef ErrorObject_H
#define ErrorObject_H
//Own module files
#include "Token.h"


typedef enum{
    ERR_STR_OBJECT_CANNOT_BE_NULL_1,
    ERR_STR_CANNOT_BE_NULL_1,
    ERR_CANNOT_CONTAIN_ALPHA,
    ERR_INVALID_UNKNOWN_SYMBOL,
    ERR_INVALID_OCTAL_1,
    ERR_INVALID_HEX_1,
    ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1,
    ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,
    ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1
} ErrorCode;

typedef struct{
	char *errorMsg;
	ErrorCode errorCode;
} ErrorObject;

void freeError(ErrorObject* errObj);
void throwError(char *message, ErrorCode errCode);
//void pinpointTokenLocation(Token *token);
#endif // ErrorObject_H



  