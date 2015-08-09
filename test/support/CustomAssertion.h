#ifndef CustomAssertion_H
#define CustomAssertion_H

#include "unity.h"
#include "Token.h"


char *getTokenTypeName(TokenType type);
void customTestAssertEqualString(const char* ExpectedStr,char* actualStr,int lineNo ,char* msg,...);
void testAssertEqualStringToken(const char* ExpectedStr,char* actualStr,int lineNo ,char* msg,...);
void testAsserEqualIntegerToken(int value,IntegerToken* actual,int lineNo);
void testAsserEqualFloatToken(double value,FloatToken* actual,int lineNo);
void testAsserEqualIdentifierToken(const char* str,IdentifierToken* actual,int lineNo);
void testAsserEqualOperatorToken(const char* str,OperatorToken* actual,int lineNo);


#define CUSTOM_TEST_FAIL(lineNo,msg,...)                        \
        {                                                       \
         char buffer[256];                                      \
         sprintf(buffer,msg, ## __VA_ARGS__);                   \
         UNITY_TEST_FAIL(lineNo,buffer);                        \
        }

#endif // CustomAssertion_H
