//Own module files
#include "Token.h"
#include "CException.h"
#include "subFunction.h"
#include "ErrorObject.h"
#include "ErrorObject.c"
#include "StringTokenizer.h"
#include "OperatorChecker.h"
#include "TokenError.h"

//Library
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * In this project, the Finite State Machine(FSM) that used to design the logic for getToken(...) function
 * the Switch case that is a important method to bulid this project.
 *
 * Using the getToken(...) function to identify type of token, and create a new token. 
 * Using the peepToken(...) function to store a token that create by getToken function
 * Eg.
 *                   str = " Name     =    "Herry"    1993   "
 *                            |       |       |        |
 *                           |       |       |        |
 *                        idenTk   opTk    strTk   inTk
 *
 *    idenTk = Identifier Token
 *    opTk = Operator Token
 *    strTk = String Token
 *    inTk = Integer Token
 *
 * Function:
 *
 *  Token *peepToken(StringObject *strO);
 *  Token *getToken(StringObject *strO);
 *
 *  The all of TransitionForXXXXX function that used in the getToken(...) function
 *
 *  void TransitionForInt(Token**newToken, TokenState* currentState , StringObject* strO );
 *  void TransitionForIni(Token** newToken, TokenState* currentState , StringObject* strO);
 *  void TransitionForOp(Token** newToken, TokenState* currentState , StringObject* strO);
 *  void TransitionForTwinAssign(Token** newToken, TokenState* currentState , StringObject* strO);
 *  void TransitionForStr(Token** newToken, TokenState* currentState , StringObject* strO);
 *  void TransitionForIden(Token** StrTk, TokenState* currentState , StringObject* strO);
 *  void TransitionForDecPointState(Token** newToken, TokenState* currentState , StringObject* strO);
 *  void TransitionForFloat(Token** newToken, TokenState* currentState , StringObject* strO);
 *  void TransitionForExpon(Token** newToken, TokenState* currentState , StringObject* strO);
 *  void TransitionForNegPosExpon(Token** newToken, TokenState* currentState , StringObject* strO);
 *  void TransitionForHex(Token** newToken, TokenState* currentState , StringObject* strO);
 *  void TransitionForOct(Token** newToken, TokenState* currentState , StringObject* strO);

 * Input:
 *
 *  TransitionForXXXXX(...):
 *    newToken -  store the token that create by creatXXXXXToken function
 *    currentState - record the the current state in state machine. 
 *    strO - store the string was typed by user in strO->str
 *         - record the transiton times in strO->index 
 *  
 *  peepToken(...):
 *    strO - store the string was typed by user in strO->str
 *         - record the transiton times in strO->index 
 *
 *  getToken(...):
 *    strO - store the string was typed by user in strO->str
 *         - record the transiton times in strO->index 
 *
 *
 *
 * Return:
 *    peepToken(...):
 *    Return a token that is storage for getToken(...)
 *    
 *    getToken(...):
 *    Return a new token that has identify the type of token.
 */
 
#define curChar             (strO->str[strO->index])
#define nextChar            (strO->str[strO->index+1])
#define prevChar            (strO->str[strO->index-1])
//Checker
#define isTokenstate(x)     ( *x == stringState || *x == integerState || *x == identifierState ||*x == decimalPointState || *x == operatorState)
#define isknown(x)          ( isoperator(x) == 0 && isdigit(x) == 0 && isalpha(x) == 0 )
#define isNotspace(x)       ( x != '\n' && x != ' ' && x != '\t')
#define isexponent(x)       ( x == 'e' || x == 'E')
#define ishexdecimal(x)     (x == 'x' || x == 'X')
#define isOtcNum(x)         (!(x == '8' || x == '9'))
#define isposOrneg(x)       ( x == '+' || x == '-')
#define advanceIndex(x)     ((x->index)++)
#define isNotNULL(x)        (x != '\0')
#define isNULL(x)           (x == '\0')
#define advanceForspace(x,y)   {                                    \
                                  if(isspace(x))                    \
                                  advanceIndex(y);                  \
                               }
#define resetTokenType(x)      {                                    \
                                  x->type = TOKEN_UNKNOWN_TYPE;     \
                                  x->startIndex = 0;                \
                               }
#define startIndexAnchor(x)    {                                    \
                                  strO->startIndex = strO->index;   \
                               }
Token *peepToken(StringObject *strO){
  return strO->token;
}

Token *getToken(StringObject *strO){
		if( strO == NULL){
       throwError("The String Object can't be a NULL\n",ERR_STR_OBJECT_CANNOT_BE_NULL_1);
		}
    startIndexAnchor(strO);
		TokenState currentState = initialState;
    Token *newToken;
		while (1)
		{
				switch (currentState)
			{
					case initialState:
          //printf("initialState\n");
					transitionForIni(&currentState,strO);
					 if (strO->type  == TOKEN_OPERATOR_TYPE){	
           newToken = createEndStrToken("$");
           strO->token = newToken;
           resetTokenType(strO);
						return newToken;
					 }
						break;

					case integerState:
          //printf("integerState\n");
					transitionForInt(&currentState,strO);
					 if (strO->type  == TOKEN_INTEGER_TYPE){	
            newToken = createIntegerToken(strO,Decimal);
            strO->token = newToken;
            advanceForspace(curChar,strO);
            resetTokenType(strO);
						return newToken;
					 }
					break;
          case hexdecimalState:
          //printf("hexdecimalState\n");
					transitionForHex(&currentState,strO);
					 if (strO->type  == TOKEN_INTEGER_TYPE){	
           newToken = createIntegerToken(strO,Hexdecimal);
           strO->token = newToken;
           advanceForspace(curChar,strO);
           resetTokenType(strO);
						return newToken;
					 }
           break;
           
          case octalState:
          //printf("octalState\n");
					transitionForOct(&currentState,strO);
					 if (strO->type  == TOKEN_INTEGER_TYPE){	
           newToken = createIntegerToken(strO,Octal);
           strO->token = newToken;
           advanceForspace(curChar,strO);
           resetTokenType(strO);
						return  newToken;
					 }
           break;
           
					case floatingState:
          //printf("floatingState\n");
          transitionForFloat(&currentState,strO);
          if (strO->type  == TOKEN_FLOAT_TYPE){
           newToken = createFloatToken(strO);
           strO->token = newToken;
           advanceForspace(curChar,strO);
            resetTokenType(strO);
						return newToken;
					 }
					break;
          
          case exponentState:
         // printf("exponentState\n");
          transitionForExpon(&currentState,strO);
          if (strO->type  == TOKEN_FLOAT_TYPE){	
            newToken = createFloatToken(strO);
            strO->token = newToken;
            advanceForspace(curChar,strO);
            resetTokenType(strO);
						return newToken;
					 }
          break;
          
          case negPosExponentState:
          //printf("negPosExponentState\n");
          transitionForNegPosExpon(&currentState,strO);
          if (strO->type  == TOKEN_FLOAT_TYPE){	
             newToken = createFloatToken(strO);
             strO->token = newToken;
             advanceForspace(curChar,strO);
             resetTokenType(strO);
             return  newToken;
					 }
          break;
					case decimalPointState:
          //printf("decimalPointState\n");
          transitionForDecPointState(&currentState,strO);
          if (strO->type  == TOKEN_OPERATOR_TYPE){	
             newToken = createOperatorToken(strO);
             strO->token = newToken;
             advanceForspace(curChar,strO);
             resetTokenType(strO);
						return newToken;
					 }
          break;
          
					case stringState:
          //printf("stringState\n");
          transitionForStr(&currentState,strO);
           if (strO->type  == TOKEN_STRING_TYPE){	
             newToken = createStringToken(strO);
             strO->token = newToken;
             resetTokenType(strO);
						 return  newToken;
					 }
					break;
					
					case identifierState:
          //printf("identifierState\n");
          transitionForIden(&currentState,strO);
          if (strO->type  == TOKEN_IDENTIFIER_TYPE){
            newToken = createIdentifierToken(strO);
            strO->token = newToken;
            advanceForspace(curChar,strO);
            resetTokenType(strO);
            return newToken;
          }
					break;
					
					case operatorState:
          //printf("operatorState\n");
					transitionForOp(&currentState,strO);
					 if (strO->type  == TOKEN_OPERATOR_TYPE){	
           newToken = createOperatorToken(strO);
           strO->token = newToken;
           resetTokenType(strO);
						return newToken;
					 }
					break;
					
					case twinAssignState:
          //printf("twinAssignState\n");
					transitionForTwinAssign(&currentState,strO);
					if (strO->type  == TOKEN_OPERATOR_TYPE){
            newToken = createOperatorToken(strO);
            strO->token = newToken;
            resetTokenType(strO);
						return newToken;
					}
					break;
					
					default:initialState;
					break;
					
		  } 
	}
}
void transitionForIni(TokenState* currentState , StringObject* strO){
					if(strO->str == NULL){
            throwError("Error:The String can't be a NULL\n",ERR_STR_CANNOT_BE_NULL_1);
					}else if(curChar == ' '){
            advanceIndex(strO);
            startIndexAnchor(strO);
					}else if(curChar == '\0'){
            strO->type = TOKEN_OPERATOR_TYPE;
					}else if (isknown(curChar) && isNotspace(curChar) &&  isNotNULL(curChar) && curChar != '"' && curChar != '_' ){
           throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO,"Expected Character is valid character, but that was unknown character'%c'",curChar);
					}else {
            stateTransition(strO,currentState,&(strO->startIndex));
             if( isTokenstate(currentState) ){
               	advanceIndex(strO);
              }
					}
}

void transitionForInt(TokenState* currentState , StringObject* strO){
       
          if( isdigit(curChar) && isOtcNum(curChar) == 0 && prevChar == '0'){
            throwTokenizerError(ERR_INVALID_OCTAL_1,strO,"Expected Character is digit less than 8, but that was '%c'",curChar);
          }else if( isdigit(curChar) && isOtcNum(curChar) && prevChar == '0'){
            advanceIndex(strO);
            *currentState = octalState;    
          }else if(curChar == '.'){
						advanceIndex(strO);
           *currentState = floatingState;
          }else if( isexponent(curChar) && isdigit(prevChar) ) {
            advanceIndex(strO);
            *currentState = exponentState;
          }else if ( ishexdecimal(curChar) && prevChar == '0'){
            advanceIndex(strO);
            *currentState = hexdecimalState;
          }else if( isdigit(curChar) ) {
						 advanceIndex(strO);
						*currentState = integerState;
					}else if( isNULL(curChar) || isspace(curChar)  || isoperator(curChar)){
						// printf("Create Token\n");
             strO->type = TOKEN_INTEGER_TYPE;
					}else if ( isalpha(curChar) ){	
            throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO,"Expected Character is digit, but that was '%c'",curChar);
					}else{
            throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO,"Expected Character is digit, but that was unknown character'%c'",curChar);
          }
          
}

//nextChar->curChar
//curChar->prevChar
void transitionForOp(TokenState* currentState , StringObject* strO){
					if ( isNULL(curChar) || isspace(curChar) || isalnum(curChar) || issingleOperator(prevChar) ){
						// printf("Create Token\n");
            strO->type = TOKEN_OPERATOR_TYPE;
					}else if ( isoperator(curChar) == 0)  {
            throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO,"Expected Character is operator, but that was unknown character'%c'",curChar);
					}else if ( istwinOperator(prevChar) || isassignOperator(prevChar) ){
						*currentState = twinAssignState;
          }
}

void transitionForTwinAssign(TokenState* currentState , StringObject* strO){
          if (istwinassign(curChar)){
            advanceIndex(strO);
          }else if (curChar == '=' || ((curChar == prevChar)&&istwinOperator(curChar)) ){
            advanceIndex(strO); 
          if(isknown(curChar) && isNotspace(curChar) &&  isNotNULL(curChar) ){
            throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO,"Expected Character is operator, but that was unknown character'%c'",curChar);
					}
            strO->type = TOKEN_OPERATOR_TYPE;
          }else if(isoperator(curChar)){
            // printf("Create Token\n");
            strO->type = TOKEN_OPERATOR_TYPE;
          }
}

void transitionForStr(TokenState* currentState , StringObject* strO){
          if(curChar == '"'){
           // printf("Create Token\n");
            advanceIndex(strO);
            strO->type = TOKEN_STRING_TYPE;
          }else if(isprint(curChar)){
            advanceIndex(strO);
            *currentState = stringState;
          }else if(curChar == '\0'){
           throwTokenizerError(ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1,strO,"End of string without double quote\n");
         
         }
}

void transitionForIden(TokenState* currentState , StringObject* strO){
          if(isalnum(curChar)||curChar == '_'){
            advanceIndex(strO);
            *currentState = identifierState;
          }else if ( isNULL(curChar) || isspace(curChar)  || isoperator(curChar)){
            //printf("Create Token\n");
             strO->type = TOKEN_IDENTIFIER_TYPE;
          }else if ( isoperator(curChar) == 0){
            throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO,"Expected Character is identifier, but that was unknown character'%c'",curChar);

          }

}

void transitionForDecPointState(TokenState* currentState , StringObject* strO){
          if( isNULL(curChar) || isspace(curChar) || isoperator(curChar) || isalpha(curChar)){
            // printf("Create Token\n");
            strO->type = TOKEN_OPERATOR_TYPE;
          }else if(isdigit(curChar)){
              advanceIndex(strO);
              *currentState = floatingState;
          }else if( isoperator(curChar) == 0){
            throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO,"Expected Character is operator, but that was unknown character'%c'",curChar);
          }
}

void transitionForFloat(TokenState* currentState , StringObject* strO){
          if( curChar == '.'){
            throwTokenizerError(ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,strO,"Expected Character is digit, but that was floating point'%c'",curChar);
          }else if(isdigit(curChar)){
            advanceIndex(strO);
            *currentState = floatingState;
          }else if( isexponent(curChar) && isdigit(prevChar) ) {
            advanceIndex(strO);
            *currentState = exponentState;
          }else if( isNULL(curChar) || isspace(curChar)  || isoperator(curChar) ){
            // printf("Create Token\n");
            strO->type = TOKEN_FLOAT_TYPE;
          }else if( isalpha(curChar) ){
           throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO,"Expected Character is digit, but that was '%c'",curChar);
          }else{
           throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO,"Expected Character is digit, but that was unknown character'%c'",curChar);
          }
  
}

void transitionForExpon(TokenState* currentState , StringObject* strO){
          if( curChar == '.'){
            throwTokenizerError(ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,strO,"Expected Character is digit, but that was floating point'%c'",curChar);
         }else if( isposOrneg(curChar) && isexponent(prevChar) ){
            advanceIndex(strO);
            *currentState = negPosExponentState;
          }else if(isdigit(curChar) == 0 && isexponent(prevChar)){
           throwTokenizerError(ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1,strO,"Expected Character is digit, but that was '%c'",curChar);
         }else if (isdigit(curChar)){
           advanceIndex(strO);
           *currentState = exponentState;
          }else if( isNULL(curChar) || isspace(curChar) || isoperator(curChar) ){
            // printf("Create Token\n");
            strO->type = TOKEN_FLOAT_TYPE;
          }else if(isalpha(curChar)){
           throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO,"Expected Character is digit, but that was '%c'",curChar);
          }else{
           throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO,"Expected Character is digit, but that was unknown character'%c'",curChar);

          }

}

void transitionForNegPosExpon(TokenState* currentState , StringObject* strO){
          if( curChar == '.'){
            throwTokenizerError(ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,strO,"Expected Character is digit, but that was floating point'%c'",curChar);
          }else if (isdigit(curChar)){
            advanceIndex(strO);
            *currentState = negPosExponentState;
          }else if( isNULL(curChar) || isspace(curChar) || isoperator(curChar) ){
            // printf("Create Token\n");
            strO->type = TOKEN_FLOAT_TYPE;
           }else if(isalpha(curChar)){
            throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO,"Expected Character is digit, but that was '%c'",curChar);
           }else{
            throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO,"Expected Character is digit, but that was unknown character'%c'",curChar);
           }
}
void transitionForHex(TokenState* currentState , StringObject* strO){
          if( isxdigit(curChar) == 0 && ishexdecimal(prevChar)){
            throwTokenizerError(ERR_INVALID_HEX_1,strO,"Expected Character is digit, but that was '%c'",curChar);
          }else if( isxdigit(curChar) ){
            advanceIndex(strO);
            *currentState = hexdecimalState;
          }else if( isNULL(curChar) || isspace(curChar) || isoperator(curChar)){
             // printf("Create Token\n");
            strO->type = TOKEN_INTEGER_TYPE;
          }else if ( isalpha(curChar) ){	
            throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO,"Expected Character is digit, but that was '%c'",curChar);
          }else{
            throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO,"Expected Character is digit, but that was unknown character'%c'",curChar);
          }
}

void transitionForOct(TokenState* currentState , StringObject* strO){
          if( isdigit(curChar) && isOtcNum(curChar) == 0 ){
            throwTokenizerError(ERR_INVALID_OCTAL_1,strO,"Expected Character is digit less than 8, but that was '%c'",curChar);
          }else if( isdigit(curChar) && isOtcNum(curChar) ){
             advanceIndex(strO);
            *currentState = octalState;    
          }else if( isNULL(curChar) || isspace(curChar) || isoperator(curChar)){
						//printf("Create Token\n");
            strO->type = TOKEN_INTEGER_TYPE;
          }else if ( isalpha(curChar) ){	
            throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO,"Expected Character is digit, but that was '%c'",curChar);

          }else{
            throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO,"Expected Character is digit, but that was unknown character'%c'",curChar);
          } 
}
void dumpToken(Token* newToken){
          char* tokenType;
          switch(newToken->type){
            case TOKEN_UNKNOWN_TYPE:
              tokenType = "TOKEN_UNKNOWN_TYPE";
            break;
            case TOKEN_INTEGER_TYPE:
              tokenType = "TOKEN_INTEGER_TYPE";
              IntegerToken* inTk = (IntegerToken*)newToken;
              printf("value = %d\n",inTk->value);
              printf("value(HEX) = 0x%X\n",inTk->value);
              printf("value(OCT) = 0%o,",inTk->value);
            break;
            case TOKEN_OPERATOR_TYPE:
              tokenType = "TOKEN_OPERATOR_TYPE";
              OperatorToken* opTk = (OperatorToken*)newToken;
              printf("symbol = %s,",opTk->symbol);
            break;
            case TOKEN_FLOAT_TYPE:
              tokenType = "TOKEN_FLOAT_TYPE";
              FloatToken* flTk = (FloatToken*)newToken;
              printf("value = %f,",flTk->value);
            break;
            case TOKEN_STRING_TYPE:
              tokenType = "TOKEN_STRING_TYPE";
              StringToken* stTk = (StringToken*)newToken;
              printf("name = %s,",stTk->name);
            break;
            case TOKEN_IDENTIFIER_TYPE:
              tokenType = "TOKEN_IDENTIFIER_TYPE";
              IdentifierToken* idTk = (IdentifierToken*)newToken;
              printf("name = %s,",idTk->name);
            break;
            default:break;
            }
            printf("[%s]\n",tokenType);
}
