#include "ErrorCode.h"
#include "Token.h"
#include "StringTokenizer.h"
#include "CException.h"
#include "subFunction.h"

#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define curChar (strO->str[strO->index])
#define nextChar (strO->str[strO->index+1])
#define prevChar (strO->str[strO->index-1])

#define isdigit_OR_alpha(x) (isdigit(x) || isalpha(x))
#define isknown(x) (isoperator(x) == 0 && isdigit(x) == 0 && isalpha(x) == 0 )
#define is_space_newline_null(x) ( x == ' ' || x == '\n' || x == '\0' )
#define isNot_space_newline_null(x) ( x != '\0' && x != '\n' && x != ' ')
#define advance(x) ((x->index)++)

Token *getToken(StringObject *strO){
		if( strO == NULL){
			 Throw(-5); 	// throwError("String Object can't be NULL",ERR_STR_OBJECT_CANNOT_BE_NULL);
		}
	  Token* newToken = malloc(sizeof(Token)); 
		TokenState currentState = InitialState;
		newToken->startColumn = strO->index;
		int loop = 0;
		printf("-----------------\n");
   // printf("newToken->startColumn  = %d\n",newToken->startColumn);
		while (loop < 100)
		{
				switch (currentState)
			{
					case InitialState:
					printf("InitialState\n");
					TransitionForIni(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_OPERATOR_TYPE){	
						return newToken;
					 }
						break;

					case IntegerState:
					printf("IntegerState\n");
					TransitionForInt(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_INTEGER_TYPE){	
						return newToken;
					 }
					break;

					case FloatingState:
          printf("FloatingState\n");
          TransitionForFloat(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_FLOAT_TYPE){	
						return newToken;
					 }
					break;

					case DecimalPointState:
          printf("DecimalPointState\n");
          TransitionForDecPointState(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_OPERATOR_TYPE){	
						return newToken;
					 }//end of OperatorState
          break;
          
					case StringState:
          printf("StringState\n");
          TransitionForStr(&newToken,&currentState,strO);
           if (newToken->type == TOKEN_STRING_TYPE){	
						return newToken;
					 }
					break;
					
					case IdentifierState:
          printf("IdentifierState\n");
          TransitionForIden(&newToken,&currentState,strO);
          if (newToken->type == TOKEN_IDENTIFIER_TYPE){
            return newToken;
          }
					break;
					
					case OperatorState:
					printf("OperatorState\n");
					TransitionForOp(&newToken,&currentState,strO);
					 if (newToken->type == TOKEN_OPERATOR_TYPE){	
						return newToken;
					 }//end of OperatorState
					break;
					
					case TwinAssignState:
					printf("TwinAssignState\n");
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
		printf("return outside\n");
		return newToken;
}//end of program

void TransitionForIni(Token** newToken, TokenState* currentState , StringObject* strO){
						if(strO->str == NULL){
						Throw(-4);	// throwError("The String can't be a NULL",ERR_STR_CANNOT_BE_NULL);
						}else if(curChar == ' '){
							 advance(strO);
							(*newToken)->startColumn = strO->index;
						}else if(curChar == '\0'){
							*newToken = createEndStrToken("$"); 
						}else if (isknown(curChar) && isNot_space_newline_null(curChar) && curChar != '"' && curChar != '_' ){
                Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
						}else {
							checkFirstCh(strO,currentState,&((*newToken)->startColumn));
              if(*currentState == StringState || *currentState == IntegerState ||*currentState == IdentifierState ||*currentState == DecimalPointState){
                	advance(strO);
              }
						}
}

void TransitionForInt(Token** InTk, TokenState* currentState , StringObject* strO){
						 
					if( isdigit(curChar) ) {
					//	printf("strO->str[%d] = %c\n",strO->index,strO->str[strO->index]); 
						*currentState = IntegerState;
						 advance(strO);
					}else if( is_space_newline_null(curChar)  || isoperator(curChar)){
						printf("Create Token\n");
            (*InTk)->length = strO->index - (*InTk)->startColumn;
						if(curChar == '\n' || curChar == ' '){
						 advance(strO);
						}
            *InTk = createIntegerToken (strO->str,(*InTk)->startColumn,(*InTk)->length);
					}else if ( isalpha(curChar) ){	
						Throw(ERR_STR_INCLURE_ALPHA); 	// throwError("The String can't include Alpha",ERR_STR_INCLURE_ALPHA);
					}else if (isoperator(curChar) == 0){
            Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
          }

}


//"1234\012423"
//nextChar->curChar
//curChar->prevChar
void TransitionForOp(Token** OpTk, TokenState* currentState , StringObject* strO){
					if ( is_space_newline_null(nextChar)  || isdigit_OR_alpha(nextChar) || issingle(curChar) ){
						printf("Create Token\n");
						 advance(strO);
						(*OpTk)->length = strO->index - (*OpTk)->startColumn;
            *OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
					}else if ( isoperator(nextChar) == 0)  {
						Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
					}else if ( istwin(curChar) || isassign(curChar) ){
						 advance(strO);
						*currentState = TwinAssignState;
          }
}


void TransitionForTwinAssign(Token** OpTk, TokenState* currentState , StringObject* strO){
				if (istwinassign(curChar)){
            advance(strO);
				}else if (curChar == '=' || ((curChar == prevChar)&&istwin(curChar)) ){
            printf("Create Token\n");
            advance(strO); 
          if(isknown(curChar) && isNot_space_newline_null(curChar) ){
             Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
					}
            (*OpTk)->length = strO->index - (*OpTk)->startColumn;
            *OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
				}else if(isoperator(curChar)){
					printf("Create Token\n");
            (*OpTk)->length = strO->index - (*OpTk)->startColumn;
            *OpTk = createOperatorToken(strO->str,(*OpTk)->startColumn,(*OpTk)->length);
	
        }
}

void TransitionForStr(Token** StrTk, TokenState* currentState , StringObject* strO){
        if(curChar == '"'){
           printf("Create Token\n");
          advance(strO);
          (*StrTk)->length = strO->index - (*StrTk)->startColumn;
           *StrTk = createStringToken(strO->str,(*StrTk)->startColumn,(*StrTk)->length);
        }else if(isprint(curChar)){
            advance(strO);
            *currentState = StringState;
        }else if(curChar == '\0'){
            Throw(ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE);
        }
}

void TransitionForIden(Token** IdenTk, TokenState* currentState , StringObject* strO){
    if(isdigit_OR_alpha(curChar)||curChar == '_'){
      advance(strO);
       *currentState = IdentifierState;
    }else if ( is_space_newline_null(curChar)  || isoperator(curChar))
		{
			printf("Create Token\n");
      (*IdenTk)->length = strO->index - (*IdenTk)->startColumn;
      if(curChar == '\n' || curChar == ' '){
        advance(strO);
        }
     *IdenTk = createIdentifierToken (strO->str,(*IdenTk)->startColumn,(*IdenTk)->length);
     }else if ( isoperator(curChar) == 0){
       Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
     }

}

void TransitionForDecPointState(Token** OpTk, TokenState* currentState , StringObject* strO){
  if( is_space_newline_null(curChar)  || isoperator(curChar) || isalpha(curChar)){
			printf("Create Token\n");
      (*OpTk)->length = strO->index - (*OpTk)->startColumn;
      if(curChar == '\n' || curChar == ' '){
        advance(strO);
        }
     *OpTk = createOperatorToken (strO->str,(*OpTk)->startColumn,(*OpTk)->length);
     }else if(isdigit(curChar)){
       advance(strO);
       *currentState = FloatingState;
     }else if( isoperator(curChar) == 0){
       Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
     }
}

void TransitionForFloat(Token** FloatTk, TokenState* currentState , StringObject* strO){
  
    if(isdigit(curChar)){
        advance(strO);
       *currentState = FloatingState;
    }else if( is_space_newline_null(curChar)  || isoperator(curChar) ){
			printf("Create Token\n");
      (*FloatTk)->length = strO->index - (*FloatTk)->startColumn;
      if(curChar == '\n' || curChar == ' '){
        advance(strO);
        }
     *FloatTk = createFloatToken(strO->str,(*FloatTk)->startColumn,(*FloatTk)->length);
     }else if( curChar == '.'){
       Throw(ERR_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT);
     }else if( isalpha(curChar) ){
       Throw(ERR_INTEGER_CANNOT_CONTAIN_ALPHA);
     
     }else if( isoperator(curChar) == 0){
       Throw(ERR_STR_CANNOT_CONTAIN_INVALID_SYMBOL);
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
					printf("value = %d,",InTk->value);
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
