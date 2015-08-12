#include "CustomAssertion.h"
#include "Token.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>      
#include <stdlib.h>     
#include "OperatorChecker.h"


char *getTokenTypeName(TokenType type){
    char * tokenType;
    switch(type){    
    case TOKEN_UNKNOWN_TYPE:
      tokenType = "TOKEN_UNKNOWN_TYPE";
    break;
    
    case TOKEN_INTEGER_TYPE:
     tokenType = "TOKEN_INTEGER_TYPE";
    break;
    
    case TOKEN_OPERATOR_TYPE:
     tokenType = "TOKEN_OPERATOR_TYPE";
    break;
    
    case TOKEN_FLOAT_TYPE:
     tokenType = "TOKEN_FLOAT_TYPE";
    break;
    
    case TOKEN_STRING_TYPE:
     tokenType = "TOKEN_STRING_TYPE";
    break;

    case TOKEN_IDENTIFIER_TYPE:
     tokenType = "TOKEN_IDENTIFIER_TYPE";
    break;
    
    default:break;
      }
    return tokenType;
}

void testAsserEqualIntegerToken(int value,IntegerToken* actual,int lineNo){
    UNITY_TEST_ASSERT_NOT_NULL(actual,lineNo,"The token should not be NULL!");
    if( TOKEN_INTEGER_TYPE != actual->type){
      CUSTOM_TEST_FAIL(lineNo,"Expected %s was %s. The token type is not the same.",        \
                        getTokenTypeName(TOKEN_INTEGER_TYPE),getTokenTypeName(actual->type)); 
    }
    UNITY_TEST_ASSERT_EQUAL_INT(value,actual->value, lineNo,"The value is not the same.");
 }


void testAsserEqualFloatToken(double value,FloatToken* actual,int lineNo){
    UNITY_TEST_ASSERT_NOT_NULL(actual,lineNo,"The token should not be NULL!");
    if( TOKEN_FLOAT_TYPE != actual->type){
      CUSTOM_TEST_FAIL(lineNo,"Expected %s was %s. The token type is not the same.",        \
                        getTokenTypeName(TOKEN_FLOAT_TYPE),getTokenTypeName(actual->type)); 
    }
    UNITY_TEST_ASSERT_EQUAL_FLOAT(value,actual->value,lineNo,"The value is not the same.");
 }


void testAsserEqualIdentifierToken(const char* str,IdentifierToken* actual,int lineNo){
    UNITY_TEST_ASSERT_NOT_NULL(actual,lineNo,"The token should not be NULL!");
    if( TOKEN_IDENTIFIER_TYPE != actual->type){
      CUSTOM_TEST_FAIL(lineNo,"Expected %s was %s. The token type is not the same.",        \
                        getTokenTypeName(TOKEN_IDENTIFIER_TYPE),getTokenTypeName(actual->type)); 
    }
    UNITY_TEST_ASSERT_EQUAL_INT(strlen(str),actual->length,lineNo,"The length is not the same.");
    customTestAssertEqualString(str,&(actual->str[actual->startColumn]),lineNo,             \
    "Expected %s was %s. The identifier is not the same.",str,actual->name);   
 }

 
void testAsserEqualStringToken(const char* str,StringToken* actual,int lineNo){
    UNITY_TEST_ASSERT_NOT_NULL(actual,lineNo,"The token should not be NULL!");
    if( TOKEN_STRING_TYPE != actual->type){
      CUSTOM_TEST_FAIL(lineNo,"Expected %s was %s. The token type is not the same.",        \
                        getTokenTypeName(TOKEN_STRING_TYPE),getTokenTypeName(actual->type)); 
    }
    UNITY_TEST_ASSERT_EQUAL_INT(strlen(str),actual->length,lineNo,"The length is not the same.");
    customTestAssertEqualString(str,&(actual->str[actual->startColumn]),lineNo,             \
    "Expected %s was %s. The string is not the same.",str,actual->name);   
 }

 
void testAsserEqualOperatorToken(const char* str,OperatorToken* actual,int lineNo){
    UNITY_TEST_ASSERT_NOT_NULL(actual,lineNo,"The token should not be NULL!");
    if( TOKEN_OPERATOR_TYPE != actual->type){
      CUSTOM_TEST_FAIL(lineNo,"Expected %s was %s. The token type is not the same.",        \
                        getTokenTypeName(TOKEN_OPERATOR_TYPE),getTokenTypeName(actual->type)); 
    }
    UNITY_TEST_ASSERT_EQUAL_STRING(str,)
    UNITY_TEST_ASSERT_EQUAL_INT(strlen(str),actual->length,lineNo,"The length is not the same.");
    //customTestAssertEqualString(str,&(actual->str[actual->startColumn]),lineNo,             \
    "Expected %s was %s. The Operator is not the same.",str,actual->symbol);   
 }

 
void customTestAssertEqualString(const char* ExpectedStr,char* actualStr,int lineNo ,char* msg,...){
  
    char *msgBuffer = malloc(1024);
    va_list args;
    va_start(args,msg);
    vsprintf(msgBuffer, msg,args);
    int lengthStr = strlen(ExpectedStr);
    int i = 0;
    while( actualStr[i] != 0 && isspace(actualStr[i]) == 0 && isspace(actualStr[i-1]) == 0 && isOperator(actualStr[i]) == 0|| i < lengthStr ){
    printf("actualStr[%d] = %c,ExpectedStr[%d] = %c\n",i,actualStr[i],i,ExpectedStr[i]);
      if( ExpectedStr[i] != actualStr[i]){
        CUSTOM_TEST_FAIL(lineNo,msgBuffer);
      }
      i++;   
    }
    va_end(args);
}
    

    
    
    
    
    
    
    
    
    
    
    
    