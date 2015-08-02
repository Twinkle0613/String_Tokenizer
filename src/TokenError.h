#ifndef TokenError_H
#define TokenError_H
#include "ErrorObject.h"
#include "subFunction.h"
#include "CException.h"
#include "OperatorChecker.h"
void throwTokenizerError(ErrorCode errCode,StringObject *strO ,char *msg , ...);
#endif // TokenError_H
