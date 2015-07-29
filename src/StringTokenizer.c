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
 *                        IdenTk   OpTk    StrTk   InTk
 *
 *    IdenTk = Identifier Token
 *    OpTk = Operator Token
 *    StrTk = String Token
 *    InTk = Integer Token
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
 
#define curChar (strO->str[strO->index])
#define nextChar (strO->str[strO->index+1])
#define prevChar (strO->str[strO->index-1])

//Checker
#define isTokenstate(x) (*x == StringState || *x == IntegerState ||*x == IdentifierState ||*x == DecimalPointState)
#define isknown(x) (isoperator(x) == 0 && isdigit(x) == 0 && isalpha(x) == 0 )
#define isNotspace(x) ( x != '\n' && x != ' ' && x != '\t')
#define isexponent(x) (x == 'e' || x == 'E')
#define ishexdecimal(x) (x == 'x' || x == 'X')
#define isOtcNum(x) (!(x == '8' || x == '9'))
#define isposOrneg(x) ( x == '+' || x == '-')
#define advance(x) ((x->index)++)
#define isNotNULL(x) (x != '\0')
#define isNULL(x) (x == '\0')
                
Token *peepToken(StringObject *strO){
  return strO->tokenStorage;
}

Token *getToken(StringObject *strO){

		if( strO == NULL){
       throwError("The String Object can't be a NULL\n",ERR_STR_OBJECT_CANNOT_BE_NULL_1);
		}
    stringObjectAnchor(strO);
	  Token* newToken = malloc(sizeof(Token)); 
		TokenState currentState = InitialState;
		newToken->startColumn = strO->index;
		int loop = 0;
    //printf("-----------------\n");
   // printf("newToken->startColumn  = %d\n",newToken->startColumn);
		while (loop < 100)
		{
				switch (currentState)
			{
					case InitialState:
          //printf("InitialState\n");
					TransitionForIni(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_OPERATOR_TYPE){	
           strO->tokenStorage = newToken;
						return newToken;
					 }
						break;

					case IntegerState:
          //printf("IntegerState\n");
					TransitionForInt(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_INTEGER_TYPE){	
            strO->tokenStorage = newToken;
						return newToken;
					 }
					break;
          case HexdecimalState:
          //printf("HexdecimalState\n");
					TransitionForHex(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_INTEGER_TYPE){	
           strO->tokenStorage = newToken;
						return newToken;
					 }
           break;
           
          case OctalState:
          //printf("OctalState\n");
					TransitionForOct(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_INTEGER_TYPE){	
           strO->tokenStorage = newToken;
						return newToken;
					 }
           break;
           
					case FloatingState:
          //printf("FloatingState\n");
          TransitionForFloat(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_FLOAT_TYPE){	
          strO->tokenStorage = newToken;
						return newToken;
					 }
					break;
          
          case ExponentState:
          //printf("ExponentState\n");
          TransitionForExpon(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_FLOAT_TYPE){	
          strO->tokenStorage = newToken;
						return newToken;
					 }
          break;
          
          case NegPosExponentState:
          //printf("NegPosExponentState\n");
          TransitionForNegPosExpon(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_FLOAT_TYPE){	
          strO->tokenStorage = newToken;
						return newToken;
					 }
          break;
					case DecimalPointState:
          //printf("DecimalPointState\n");
          TransitionForDecPointState(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_OPERATOR_TYPE){	
          strO->tokenStorage = newToken;
						return newToken;
					 }//end of OperatorState
          break;
          
					case StringState:
          //printf("StringState\n");
          TransitionForStr(&newToken,&currentState,strO);
           if (newToken->type == TOKEN_STRING_TYPE){	
           strO->tokenStorage = newToken;
						return newToken;
					 }
					break;
					
					case IdentifierState:
          //printf("IdentifierState\n");
          TransitionForIden(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_IDENTIFIER_TYPE){
            strO->tokenStorage = newToken;
            return newToken;
          }
					break;
					
					case OperatorState:
          //printf("OperatorState\n");
					TransitionForOp(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_OPERATOR_TYPE){	
           strO->tokenStorage = newToken;
						return newToken;
					 }//end of OperatorState
					break;
					
					case TwinAssignState:
          //printf("TwinAssignState\n");
					TransitionForTwinAssign(&newToken,&currentState,strO);
					if (newToken->type == TOKEN_OPERATOR_TYPE){
            strO->tokenStorage = newToken;
						return newToken;
					}//end of TwinAssignState
					break;
					
					default:InitialState;
					break;
					
		  } //end of switch 
			loop++;
	}//end of while loop

		return newToken;
}//end of program
void TransitionForIni(Token** newToken, TokenState* currentState , StringObject* strO){
					if(strO->str == NULL){
            throwError("The String can't be a NULL\n",ERR_STR_CANNOT_BE_NULL_1);
					}else if(curChar == ' '){
            advance(strO);
						//(*newToken)->startColumn = strO->index;
            stringObjectAnchor(strO);
					}else if(curChar == '\0'){
						*newToken = createEndStrToken("$"); 
					}else if (isknown(curChar) && isNotspace(curChar) &&  isNotNULL(curChar) && curChar != '"' && curChar != '_' ){
            throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
					}else {
            checkFirstCh(strO,currentState,&(strO->startIndex));
						//checkFirstCh(strO,currentState,&((*newToken)->startColumn));
             if( isTokenstate(currentState) ){
               	advance(strO);
              }
					}
}

void TransitionForInt(Token** InTk, TokenState* currentState , StringObject* strO){
       
          if( isdigit(curChar) && isOtcNum(curChar) == 0 && prevChar == '0'){
            throwError("This is invalid octal integer\n",ERR_INVALID_OCTAL_1);
          }else if( isdigit(curChar) && isOtcNum(curChar) && prevChar == '0'){
            advance(strO);
            *currentState = OctalState;    
          }else if(curChar == '.'){
						advance(strO);
           *currentState = FloatingState;
          }else if( isexponent(curChar) && isdigit(prevChar) ) {
            advance(strO);
            *currentState = ExponentState;
          }else if ( ishexdecimal(curChar) && prevChar == '0'){
            advance(strO);
            *currentState = HexdecimalState;
          }else if( isdigit(curChar) ) {
						 advance(strO);
						*currentState = IntegerState;
					}else if( isNULL(curChar) || isspace(curChar)  || isoperator(curChar)){
						// printf("Create Token\n");
            strO->length = strO->index - strO->startIndex;
            *InTk = createIntegerToken(strO,Decimal);
           // *InTk = createIntegerToken (strO->str,strO->startIndex,strO->length,Decimal);
            //(*InTk)->length = strO->index - (*InTk)->startColumn;
            //*InTk = createIntegerToken (strO->str,(*InTk)->startColumn,(*InTk)->length,Decimal);
						if(curChar == '\n' || curChar == ' '){
						 advance(strO);
						}
					}else if ( isalpha(curChar) ){	
            throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);

					}else{
            throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
          }
          
}

//nextChar->curChar
//curChar->prevChar
void TransitionForOp(Token** OpTk, TokenState* currentState , StringObject* strO){
					if ( isNULL(nextChar) || isspace(nextChar) || isalnum(nextChar) || issingleOperator(curChar) ){
						// printf("Create Token\n");
						 advance(strO);
            strO->length = strO->index - strO->startIndex;
            *OpTk = createOperatorToken(strO);
						//(*OpTk)->length = strO->index - (*OpTk)->startColumn;
            //*OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
					}else if ( isoperator(nextChar) == 0)  {
            throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
					}else if ( istwinOperator(curChar) || isassignOperator(curChar) ){
						advance(strO);
						*currentState = TwinAssignState;
          }
}

void TransitionForTwinAssign(Token** OpTk, TokenState* currentState , StringObject* strO){
          if (istwinassign(curChar)){
            advance(strO);
          }else if (curChar == '=' || ((curChar == prevChar)&&istwinOperator(curChar)) ){
            // printf("Create Token\n");
            advance(strO); 
          if(isknown(curChar) && isNotspace(curChar) &&  isNotNULL(curChar) ){
            throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
					}
            strO->length = strO->index - strO->startIndex;
            *OpTk = createOperatorToken(strO);
           // (*OpTk)->length = strO->index - (*OpTk)->startColumn;
           // *OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
          }else if(isoperator(curChar)){
            // printf("Create Token\n");
            strO->length = strO->index - strO->startIndex;
            *OpTk = createOperatorToken(strO);
           // (*OpTk)->length = strO->index - (*OpTk)->startColumn;
            //*OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
          }
}

void TransitionForStr(Token** StrTk, TokenState* currentState , StringObject* strO){
          if(curChar == '"'){
           // printf("Create Token\n");
            advance(strO);
            strO->length = strO->index - strO->startIndex;
            *StrTk = createStringToken(strO);
            //(*StrTk)->length = strO->index - (*StrTk)->startColumn;
            //*StrTk = createStringToken(strO->str,(*StrTk)->startColumn,(*StrTk)->length);
          }else if(isprint(curChar)){
            advance(strO);
            *currentState = StringState;
          }else if(curChar == '\0'){
            throwError("End of string without double quote\n",ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1);
          }
}

void TransitionForIden(Token** IdenTk, TokenState* currentState , StringObject* strO){
          if(isalnum(curChar)||curChar == '_'){
            advance(strO);
            *currentState = IdentifierState;
          }else if ( isNULL(curChar) || isspace(curChar)  || isoperator(curChar)){
            //printf("Create Token\n");
            strO->length = strO->index - strO->startIndex;
            *IdenTk = createIdentifierToken(strO);
            //(*IdenTk)->length = strO->index - (*IdenTk)->startColumn;
            //*IdenTk = createIdentifierToken (strO->str,(*IdenTk)->startColumn,(*IdenTk)->length);
            if(curChar == '\n' || curChar == ' '){
            advance(strO);
            }
          }else if ( isoperator(curChar) == 0){
            throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
          }

}

void TransitionForDecPointState(Token** OpTk, TokenState* currentState , StringObject* strO){
          if( isNULL(curChar) || isspace(curChar) || isoperator(curChar) || isalpha(curChar)){
            // printf("Create Token\n");
            strO->length = strO->index - strO->startIndex;
            *OpTk = createOperatorToken(strO);
            //(*OpTk)->length = strO->index - (*OpTk)->startColumn;
            //*OpTk = createOperatorToken (strO->str,(*OpTk)->startColumn,(*OpTk)->length);
            if(curChar == '\n' || curChar == ' '){
              advance(strO);
            }
          }else if(isdigit(curChar)){
              advance(strO);
              *currentState = FloatingState;
          }else if( isoperator(curChar) == 0){
              throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
          }
}

void TransitionForFloat(Token** FloatTk, TokenState* currentState , StringObject* strO){
    
          if( curChar == '.'){
            throwError("Can't contain contain two of decimal point in Floating\n",ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING);
          }else if(isdigit(curChar)){
            advance(strO);
            *currentState = FloatingState;
          }else if( isexponent(curChar) && isdigit(prevChar) ) {
            advance(strO);
            *currentState = ExponentState;
          }else if( isNULL(curChar) || isspace(curChar)  || isoperator(curChar) ){
            // printf("Create Token\n");
            strO->length = strO->index - strO->startIndex;
            *FloatTk = createFloatToken(strO);
            //(*FloatTk)->length = strO->index - (*FloatTk)->startColumn;
            //*FloatTk = createFloatToken(strO->str,(*FloatTk)->startColumn,(*FloatTk)->length);
            if(curChar == '\n' || curChar == ' '){
              advance(strO);
             }
          }else if( isalpha(curChar) ){
             throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);
          }else{
            throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
          }
  
}

void TransitionForExpon(Token** FloatTk, TokenState* currentState , StringObject* strO){
  
          if( curChar == '.'){
            throwError("Can't contain contain two of decimal point in Floating\n",ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING);
          }else if( isposOrneg(curChar) && isexponent(prevChar) ){
            advance(strO);
            *currentState = NegPosExponentState;
          }else if(isdigit(curChar) == 0 && isexponent(prevChar)){
             throwError("Behind exponential must be a digit\n",ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1);
          }else if (isdigit(curChar)){
            advance(strO);
            *currentState = ExponentState;
          }else if( isNULL(curChar) || isspace(curChar) || isoperator(curChar) ){
            // printf("Create Token\n");
            strO->length = strO->index - strO->startIndex;
            *FloatTk = createFloatToken(strO);
            //(*FloatTk)->length = strO->index - (*FloatTk)->startColumn;
            //*FloatTk = createFloatToken(strO->str,(*FloatTk)->startColumn,(*FloatTk)->length);
            if(curChar == '\n' || curChar == ' '){
              advance(strO);
             }
          }else if(isalpha(curChar)){
            throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);
          }else{
            throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
          }

}

void TransitionForNegPosExpon(Token** FloatTk, TokenState* currentState , StringObject* strO){
          if( curChar == '.'){
            throwError("Can't contain contain two of decimal point in Floating\n",ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING);

          }else if (isdigit(curChar)){
            advance(strO);
            *currentState = ExponentState;
          }else if( isNULL(curChar) || isspace(curChar) || isoperator(curChar) ){
            // printf("Create Token\n");
            strO->length = strO->index - strO->startIndex;
            *FloatTk = createFloatToken(strO);
            //(*FloatTk)->length = strO->index - (*FloatTk)->startColumn;
            //*FloatTk = createFloatToken(strO->str,(*FloatTk)->startColumn,(*FloatTk)->length);
              if(curChar == '\n' || curChar == ' '){
              advance(strO);
              } 
           }else if(isalpha(curChar)){
            throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);
           }else{
            throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
           }
}
void TransitionForHex(Token** InTk, TokenState* currentState , StringObject* strO){
          if( isxdigit(curChar) == 0 && ishexdecimal(prevChar)){
            throwError("This is invalid Hexdecimal integer\n",ERR_INVALID_HEX_1);
          }else if( isxdigit(curChar) ){
            advance(strO);
            *currentState = HexdecimalState;
          }else if( isNULL(curChar) || isspace(curChar) || isoperator(curChar)){
             // printf("Create Token\n");
            strO->length = strO->index - strO->startIndex;
            *InTk = createIntegerToken(strO,Hexdecimal);
            //*InTk = createIntegerToken(strO->str,strO->startIndex,strO->length,Hexdecimal);
            //(*InTk)->length = strO->index - (*InTk)->startColumn;
            //*InTk = createIntegerToken (strO->str,(*InTk)->startColumn,(*InTk)->length,Hexdecimal);
						if(curChar == '\n' || curChar == ' '){
						 advance(strO);
						}
          }else if ( isalpha(curChar) ){	
			       throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);
          }else{
             throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
          }
}

void TransitionForOct(Token** InTk, TokenState* currentState , StringObject* strO){
      
          if( isdigit(curChar) && isOtcNum(curChar) == 0 ){
            throwError("This is invalid octal integer\n",ERR_INVALID_OCTAL_1);
          }else if( isdigit(curChar) && isOtcNum(curChar) ){
             advance(strO);
            *currentState = OctalState;    
          }else if( isNULL(curChar) || isspace(curChar) || isoperator(curChar)){
						//printf("Create Token\n");
            strO->length = strO->index - strO->startIndex;
            *InTk = createIntegerToken(strO,Octal);
           // *InTk = createIntegerToken(strO->str,strO->startIndex,strO->length,Octal);            
            //(*InTk)->length = strO->index - (*InTk)->startColumn;
            //*InTk = createIntegerToken (strO->str,(*InTk)->startColumn,(*InTk)->length,Octal);
						if(curChar == '\n' || curChar == ' '){
						 advance(strO);
						}
          }else if ( isalpha(curChar) ){	
            throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);
          }else{
            throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
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
              IntegerToken* InTk = (IntegerToken*)newToken;
              printf("value = %d\n",InTk->value);
              printf("value(HEX) = 0x%X\n",InTk->value);
              printf("value(OCT) = 0%o,",InTk->value);
            break;
            case TOKEN_OPERATOR_TYPE:
              tokenType = "TOKEN_OPERATOR_TYPE";
              OperatorToken* OpTk = (OperatorToken*)newToken;
              printf("symbol = %s,",OpTk->symbol);
            break;
            case TOKEN_FLOAT_TYPE:
              tokenType = "TOKEN_FLOAT_TYPE";
              FloatToken* FlTk = (FloatToken*)newToken;
              printf("value = %f,",FlTk->value);
            break;
            case TOKEN_STRING_TYPE:
              tokenType = "TOKEN_STRING_TYPE";
              StringToken* StTk = (StringToken*)newToken;
              printf("name = %s,",StTk->name);
            break;
            case TOKEN_IDENTIFIER_TYPE:
              tokenType = "TOKEN_IDENTIFIER_TYPE";
              IdentifierToken* IdTk = (IdentifierToken*)newToken;
              printf("name = %s,",IdTk->name);
            break;
            default:break;
            }
            printf("[%s]\n",tokenType);
}
