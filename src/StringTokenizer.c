#include "ErrorCode.h"
#include "Token.h"
#include "StringTokenizer.h"
#include "CException.h"
#include "subFunction.h"
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "ErrorObject.h"
#include "ErrorObject.c"

#define curChar (strO->str[strO->index])
#define nextChar (strO->str[strO->index+1])
#define prevChar (strO->str[strO->index-1])

#define isdigit_OR_alpha(x) (isdigit(x) || isalpha(x))
#define isknown(x) (isoperator(x) == 0 && isdigit(x) == 0 && isalpha(x) == 0 )
#define is_space_newline_null(x) ( x == ' ' || x == '\n' || x == '\0' )
#define isNot_space_newline_null(x) ( x != '\0' && x != '\n' && x != ' ')
#define advance(x) ((x->index)++)
#define isexponent(x) (x == 'e' || x == 'E')
#define ishexdecimal(x) (x == 'x' || x == 'X')
#define isposOrneg(x) ( x == '+' || x == '-')
#define isOtcNum(x) ( !(x == '8' || x == '9'))
#define isAlphaForHex(x) ( x == 'A' || x == 'B' || x == 'C' || x == 'D' || x == 'E' || x == 'F' \
                           || x == 'a' || x == 'b' || x == 'c' || x == 'd' || x == 'e' || x == 'd'  )
                           
Token *getToken(StringObject *strO){

		if( strO == NULL){
			// Throw(ERR_STR_OBJECT_CANNOT_BE_NULL); 
       throwError("The String Object can't be a NULL\n",ERR_STR_OBJECT_CANNOT_BE_NULL_1);
		}
	  Token* newToken = malloc(sizeof(Token)); 
		TokenState currentState = InitialState;
		newToken->startColumn = strO->index;
		int loop = 0;
	//	printf("-----------------\n");
   // printf("newToken->startColumn  = %d\n",newToken->startColumn);
		while (loop < 100)
		{
				switch (currentState)
			{
					case InitialState:
				//	printf("InitialState\n");
					TransitionForIni(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_OPERATOR_TYPE){	
						return newToken;
					 }
						break;

					case IntegerState:
				//	printf("IntegerState\n");
					TransitionForInt(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_INTEGER_TYPE){	
						return newToken;
					 }
					break;
          case HexdecimalState:
      //    printf("HexdecimalState\n");
					TransitionForHex(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_INTEGER_TYPE){	
						return newToken;
					 }
           break;
           
          case OctalState:
       //   printf("OctalState\n");
					TransitionForOct(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_INTEGER_TYPE){	
						return newToken;
					 }
           break;
           
					case FloatingState:
       //   printf("FloatingState\n");
          TransitionForFloat(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_FLOAT_TYPE){	
						return newToken;
					 }
					break;
          
          case ExponentState:
       //   printf("ExponentState\n");
          TransitionForExpon(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_FLOAT_TYPE){	
						return newToken;
					 }
          break;
          
          case NegPosExponentState:
      //   printf("NegPosExponentState\n");
          TransitionForNegPosExpon(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_FLOAT_TYPE){	
						return newToken;
					 }
          break;
					case DecimalPointState:
      //    printf("DecimalPointState\n");
          TransitionForDecPointState(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_OPERATOR_TYPE){	
						return newToken;
					 }//end of OperatorState
          break;
          
					case StringState:
     //     printf("StringState\n");
          TransitionForStr(&newToken,&currentState,strO);
           if (newToken->type == TOKEN_STRING_TYPE){	
						return newToken;
					 }
					break;
					
					case IdentifierState:
      //    printf("IdentifierState\n");
          TransitionForIden(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_IDENTIFIER_TYPE){
            return newToken;
          }
					break;
					
					case OperatorState:
			//		printf("OperatorState\n");
					TransitionForOp(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_OPERATOR_TYPE){	
						return newToken;
					 }//end of OperatorState
					break;
					
					case TwinAssignState:
		//			printf("TwinAssignState\n");
					TransitionForTwinAssign(&newToken,&currentState,strO);
					if (newToken->type == TOKEN_OPERATOR_TYPE){
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
					//	Throw(-4);	
             throwError("The String can't be a NULL\n",ERR_STR_CANNOT_BE_NULL_1);
						}else if(curChar == ' '){
							 advance(strO);
							(*newToken)->startColumn = strO->index;
						}else if(curChar == '\0'){
							*newToken = createEndStrToken("$"); 
						}else if (isknown(curChar) && isNot_space_newline_null(curChar) && curChar != '"' && curChar != '_' ){
              //  Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
               throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
						}else {
							checkFirstCh(strO,currentState,&((*newToken)->startColumn));
              if(*currentState == StringState || *currentState == IntegerState ||*currentState == IdentifierState ||*currentState == DecimalPointState){
                	advance(strO);
              }
						}
}

void TransitionForInt(Token** InTk, TokenState* currentState , StringObject* strO){
       
          if( isdigit(curChar) && isOtcNum(curChar) == 0 && prevChar == '0'){
           // Throw(ERR_INVALID_OCTAL);
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
					}else if( is_space_newline_null(curChar)  || isoperator(curChar)){
						// printf("Create Token\n");
            (*InTk)->length = strO->index - (*InTk)->startColumn;
            *InTk = createIntegerToken (strO->str,(*InTk)->startColumn,(*InTk)->length,Decimal);
						if(curChar == '\n' || curChar == ' '){
						 advance(strO);
						}
					}else if ( isalpha(curChar) ){	
						//Throw(ERR_STR_INCLURE_ALPHA); 	
            throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);
					}else if (isoperator(curChar) == 0){
//            Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
              throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
          }
          
}


//"1234\012423"
//nextChar->curChar
//curChar->prevChar
void TransitionForOp(Token** OpTk, TokenState* currentState , StringObject* strO){
					if ( is_space_newline_null(nextChar)  || isdigit_OR_alpha(nextChar) || issingle(curChar) ){
						// printf("Create Token\n");
						 advance(strO);
						(*OpTk)->length = strO->index - (*OpTk)->startColumn;
            *OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
					}else if ( isoperator(nextChar) == 0)  {
						//Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
               throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
					}else if ( istwin(curChar) || isassign(curChar) ){
						 advance(strO);
						*currentState = TwinAssignState;
          }
}


void TransitionForTwinAssign(Token** OpTk, TokenState* currentState , StringObject* strO){
				if (istwinassign(curChar)){
            advance(strO);
				}else if (curChar == '=' || ((curChar == prevChar)&&istwin(curChar)) ){
            // printf("Create Token\n");
            advance(strO); 
          if(isknown(curChar) && isNot_space_newline_null(curChar) ){
            // Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
              throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);
					}
            (*OpTk)->length = strO->index - (*OpTk)->startColumn;
            *OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
				}else if(isoperator(curChar)){
					// printf("Create Token\n");
            (*OpTk)->length = strO->index - (*OpTk)->startColumn;
            *OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
	
        }
}

void TransitionForStr(Token** StrTk, TokenState* currentState , StringObject* strO){
        if(curChar == '"'){
           // printf("Create Token\n");
          advance(strO);
          (*StrTk)->length = strO->index - (*StrTk)->startColumn;
           *StrTk = createStringToken(strO->str,(*StrTk)->startColumn,(*StrTk)->length);
        }else if(isprint(curChar)){
            advance(strO);
            *currentState = StringState;
        }else if(curChar == '\0'){
        //  Throw(ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE);
           throwError("End of string without double quote\n",ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1);
        }
}

void TransitionForIden(Token** IdenTk, TokenState* currentState , StringObject* strO){
    if(isdigit_OR_alpha(curChar)||curChar == '_'){
      advance(strO);
       *currentState = IdentifierState;
    }else if ( is_space_newline_null(curChar)  || isoperator(curChar))
		{
			// printf("Create Token\n");
      (*IdenTk)->length = strO->index - (*IdenTk)->startColumn;
     *IdenTk = createIdentifierToken (strO->str,(*IdenTk)->startColumn,(*IdenTk)->length);
      if(curChar == '\n' || curChar == ' '){
        advance(strO);
        }
     }else if ( isoperator(curChar) == 0){
     // Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
         throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);

     }

}

void TransitionForDecPointState(Token** OpTk, TokenState* currentState , StringObject* strO){
  if( is_space_newline_null(curChar)  || isoperator(curChar) || isalpha(curChar)){
			// printf("Create Token\n");
      (*OpTk)->length = strO->index - (*OpTk)->startColumn;
     *OpTk = createOperatorToken (strO->str,(*OpTk)->startColumn,(*OpTk)->length);
      if(curChar == '\n' || curChar == ' '){
        advance(strO);
        }
     }else if(isdigit(curChar)){
       advance(strO);
       *currentState = FloatingState;
     }else if( isoperator(curChar) == 0){
      // Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
       throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);

     }
}

void TransitionForFloat(Token** FloatTk, TokenState* currentState , StringObject* strO){
    
    if( curChar == '.'){
     //  Throw(ERR_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT);
          throwError("Can't contain contain two of decimal point in Floating\n",ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING);
    }else if(isdigit(curChar)){
      advance(strO);
      *currentState = FloatingState;
    }else if( isexponent(curChar) && isdigit(prevChar) ) {
      advance(strO);
      *currentState = ExponentState;
    }else if( is_space_newline_null(curChar)  || isoperator(curChar) ){
       // printf("Create Token\n");
       (*FloatTk)->length = strO->index - (*FloatTk)->startColumn;
       *FloatTk = createFloatToken(strO->str,(*FloatTk)->startColumn,(*FloatTk)->length);
       if(curChar == '\n' || curChar == ' '){
        advance(strO);
       }
    }else if( isalpha(curChar) ){
     //  Throw(ERR_INTEGER_CANNOT_CONTAIN_ALPHA); 
       	 throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);

    }else if( isoperator(curChar) == 0){
     //  Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
          throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);

     }
  
}

void TransitionForExpon(Token** FloatTk, TokenState* currentState , StringObject* strO){
  
    if( curChar == '.'){
     //  Throw(ERR_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT);
        throwError("Can't contain contain two of decimal point in Floating\n",ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING);

    }else if( isposOrneg(curChar) && isexponent(prevChar) ){
       advance(strO);
      *currentState = NegPosExponentState;
    }else if(isdigit(curChar) == 0 && isexponent(prevChar)){
//      Throw(ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT);
        // throwError("Behind exponential must be a digit\n",ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1);

    }else if (isdigit(curChar)){
       advance(strO);
      *currentState = ExponentState;
    }else if( is_space_newline_null(curChar)  || isoperator(curChar) ){
        // printf("Create Token\n");
       (*FloatTk)->length = strO->index - (*FloatTk)->startColumn;
       *FloatTk = createFloatToken(strO->str,(*FloatTk)->startColumn,(*FloatTk)->length);
       if(curChar == '\n' || curChar == ' '){
        advance(strO);
       }
    }else if(isalpha(curChar)){
//       Throw(ERR_INTEGER_CANNOT_CONTAIN_ALPHA); 
        throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);

    }else if( isoperator(curChar) == 0){
      // Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
        throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);

     }

}

void TransitionForNegPosExpon(Token** FloatTk, TokenState* currentState , StringObject* strO){
      if( curChar == '.'){
       //   Throw(ERR_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT);
             throwError("Can't contain contain two of decimal point in Floating\n",ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING);

      }else if (isdigit(curChar)){
          advance(strO);
          *currentState = ExponentState;
      }else if( is_space_newline_null(curChar)  || isoperator(curChar) ){
            // printf("Create Token\n");
          (*FloatTk)->length = strO->index - (*FloatTk)->startColumn;
          *FloatTk = createFloatToken(strO->str,(*FloatTk)->startColumn,(*FloatTk)->length);
          if(curChar == '\n' || curChar == ' '){
            advance(strO);
          }
      }else if(isalpha(curChar)){
     //     Throw(ERR_INTEGER_CANNOT_CONTAIN_ALPHA); 
          throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);

      }else if( isoperator(curChar) == 0){
       //   Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
         throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);

      }
}
void TransitionForHex(Token** InTk, TokenState* currentState , StringObject* strO){
      if( isdigit(curChar) == 0 && isAlphaForHex(curChar) == 0 && ishexdecimal(prevChar)){
      //  Throw(ERR_INVALID_HEX);
           throwError("This is invalid Hexdecimal integer\n",ERR_INVALID_HEX_1);
      }else if( isdigit(curChar) || isAlphaForHex(curChar) ){
          advance(strO);
          *currentState = HexdecimalState;
      }else if( is_space_newline_null(curChar)  || isoperator(curChar)){
						// printf("Create Token\n");
            (*InTk)->length = strO->index - (*InTk)->startColumn;
            *InTk = createIntegerToken (strO->str,(*InTk)->startColumn,(*InTk)->length,Hexdecimal);
						if(curChar == '\n' || curChar == ' '){
						 advance(strO);
						}
			}else if ( isalpha(curChar) ){	
				//		Throw(ERR_STR_INCLURE_ALPHA); 
			          throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);

      }else if (isoperator(curChar) == 0){
      //      Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
            throwError("Can't contain invalid unknown symbol\n",ERR_INVALID_UNKNOWN_SYMBOL);

      }

}

void TransitionForOct(Token** InTk, TokenState* currentState , StringObject* strO){
      
      if( isdigit(curChar) && isOtcNum(curChar) == 0 ){
         //   Throw(ERR_INVALID_OCTAL);
               throwError("This is invalid octal integer\n",ERR_INVALID_OCTAL_1);
       }else if( isdigit(curChar) && isOtcNum(curChar) ){
            advance(strO);
            *currentState = OctalState;    
       }else if( is_space_newline_null(curChar)  || isoperator(curChar)){
						//printf("Create Token\n");
            (*InTk)->length = strO->index - (*InTk)->startColumn;
            *InTk = createIntegerToken (strO->str,(*InTk)->startColumn,(*InTk)->length,Octal);
						if(curChar == '\n' || curChar == ' '){
						 advance(strO);
						}
			}else if ( isalpha(curChar) ){	
			//			Throw(ERR_STR_INCLURE_ALPHA); 	
            throwError("Can't contain any alphabet\n",ERR_CANNOT_CONTAIN_ALPHA);
			}else if (isoperator(curChar) == 0){
      //      Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
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
