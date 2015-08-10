//Own module files
#include "Token.h"
#include "CException.h"
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
 * Using the getToken(...) function to identify type of string, and create a new token. 
 * Using the peepToken(...) function to store a token that create by getToken function.
 * Using the createStringObject(...) functions to create a string object element. 
 * Using the stateTransition(...) functions to identify the type of first character then change the current state to next state.
 *
 *
 * Eg.
 *     getToken(...):
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
 *    createStringObject(...):
 *
 *                        -----------------------
 *   StringObject ------>|str = "1234"|Index = 0|
 *                       -----------------------
 *
 *
 *    stateTransition(...):
 *      
 *    strO->str = "123 1234"                  strO->str = "ASDSAS"
 *                 ^                                       ^
 *      currentState ---> integerState;            currentState ---> IdentifierState;
 *
 * Function:
 *
 *  Token *peepToken(StringObject *strO);
 *  Token *getToken(StringObject *strO);
 *  StringObject *createStringObject(char *ch);
 *  void stateTransition( StringObject* strO , TokenState *currentState, int* startColumn);
 *
 *  The all of TransitionForXXXXX function that used in the getToken(...) function.
 *  This function that will analyse the current character (strO->str[strO->index]) and then 
 *  change the currentState or define strO->type.
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
 *
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
 *  createStringObject(...):
 *      ch - store the string from user key in.
 * 
 *  stateTransition(...):
 *    strO - store the string was typed by user in strO->str.
 *         - record the position of character in strO->index.
 *         - record the start point in strO->startIndex.
 *         - store the type of newToken when a newToken was created.
 *         - store a token when a newToken was created.
 *
 *  currentState - record the the current state in getToken(...) function. 
 *   startColumn - record the start point for counter in getToken(...) function.
 *
 *
 * Return:
 *    peepToken(...):
 *    Return a token that is storage for getToken(...)
 *    getToken(...):
 *    Return a new token that has identify the type of token.
 *    createStringObject(...):
 *       return string object element that has contain the string that typed by user. 
 *    stateTransition(...):
 *        currentState that will be update and change to other state or remain.
 */
#define startChar            (strO->str[strO->startIndex])
#define curChar               (strO->str[strO->index])
#define nextChar              (strO->str[strO->index+1])
#define prevChar              (strO->str[strO->index-1])
//Checker
#define isTokenstate(x)       ( *x == STRING_STATE || *x == INTEGER_STATE || *x == IDENTIFIER_STATE \
                              ||*x == DECIMALPOINT_STATE || *x == OPERATOR_STATE)
#define isUnknown(x)          ( isOperator(x) == 0 && isdigit(x) == 0 && isalpha(x) == 0 )
#define isNotspace(x)         ( x != '\n' && x != ' ' && x != '\t')
#define isExponent(x)         ( x == 'e' || x == 'E')
#define isHexSymbol(x)        (x == 'x' || x == 'X')
#define isOtcNum(x)           (!(x == '8' || x == '9'))
#define isPolarity(x)         ( x == '+' || x == '-')
#define advanceIndex(x)       ((x->index)++)
#define isNotNULL(x)          (x != '\0')
#define isNULL(x)             (x == '\0')
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
                               
#define insertedToken(x,y)     {                                    \
                                 x->token = y;                      \
                               }
                               
StringObject *createStringObject(char *str){
  StringObject *strO = malloc(sizeof(StringObject));
  strO->str = str;
  strO->index = 0;
  return strO;
}
void stateTransition ( TokenState *currentState, StringObject* strO ){
  if(isdigit(startChar)){
    *currentState = INTEGER_STATE;
  }else if (isalpha(startChar)){
    *currentState = IDENTIFIER_STATE;
  }else if (startChar == '.'){
    *currentState = DECIMALPOINT_STATE; 
  }else if (isOperator(startChar)){
    *currentState = OPERATOR_STATE;
  }else if (startChar == '"'){
    *currentState = STRING_STATE;
  }else if (startChar == '_' || isalpha(startChar)){
    *currentState = IDENTIFIER_STATE; 
  }else{
    *currentState = UNKNOWN_STATE;
  }
}

Token *peepToken(StringObject *strO){
  return strO->token; //The token that was created by getToken(strO) and store into the strO->token.
}

Token *getToken(StringObject *strO){
  if( strO == NULL){
    throwError("The String Object can't be a NULL\n",ERR_STR_OBJECT_CANNOT_BE_NULL_1);
  }
  startIndexAnchor(strO);                   //Record the start index store into the strO->startIndex.
  TokenState currentState = INITIAL_STATE;  //The begin of FSM will stand in INITIAL_STATE. 
  Token *newToken;
  while (1)
  {
    switch (currentState)
    {
      case INITIAL_STATE:
      //printf("INITIAL_STATE\n");
      transitionForIni(&currentState,strO);    
      if (strO->type  == TOKEN_OPERATOR_TYPE){	    //If strO->type is redefined to TOKEN_OPERATOR_TYPE by transitionForIni(...),
        newToken = createEndStrToken("$");          //that will return a token to newToken.
        strO->token = newToken;                     //The newToken that will store into the strO->Token.
        resetTokenType(strO);                       //After create a token, strO->type that will redefine to TOKEN_UNKNOWN_TYPE. 
        return newToken;
      }
      break;

      case INTEGER_STATE:
      //printf("INTEGER_STATE\n");
      transitionForInt(&currentState,strO);           
      if(strO->type  == TOKEN_INTEGER_TYPE){	  	    //If strO->type is redefined to TOKEN_INTEGER_TYPE by transitionForIni(...),
        newToken = createIntegerToken(strO,DECIMAL);  //that will return token to newToken.
        strO->token = newToken;                       //The newToken that will store into the strO->Token.
        advanceForspace(curChar,strO);                //If current character is space, strO->index will increase by 1.
        resetTokenType(strO);                         //After create a token, strO->type that will define to TOKEN_UNKNOWN_TYPE.
        return newToken;
      }
      break;
      
      case HEXDECIMAL_STATE:
      //printf("HEXDECIMAL_STATE\n");
      transitionForHex(&currentState,strO);
       if(strO->type  == TOKEN_INTEGER_TYPE){	         //If strO->type is redefined to TOKEN_INTEGER_TYPE by transitionForHex(...),
        newToken = createIntegerToken(strO,HEXDECIMAL);//that will return token to newToken.
        strO->token = newToken;                        //The newToken that will store into the strO->Token.
        advanceForspace(curChar,strO);                 //If current character is space, strO->index will increase by 1.
        resetTokenType(strO);                          //After create a token, strO->type that will define to TOKEN_UNKNOWN_TYPE.
        return newToken;
      }
      break;
           
      case OCTAL_STATE:
      //printf("OCTAL_STATE\n");
      transitionForOct(&currentState,strO);
       if(strO->type  == TOKEN_INTEGER_TYPE){	       //If strO->type is redefined to TOKEN_INTEGER_TYPE by transitionForOct(...),
        newToken = createIntegerToken(strO,OCTAL);   //that will return token to newToken.
        strO->token = newToken;                      //The newToken that will store into the strO->Token.
        advanceForspace(curChar,strO);               //If current character is space, strO->index will increase by 1.
        resetTokenType(strO);                        //After create a token, strO->type that will define to TOKEN_UNKNOWN_TYPE.
        return newToken;
      }
      break;
           
      case FLOATING_STATE:
      //printf("FLOATING_STATE\n");
      transitionForFloat(&currentState,strO);       
       if(strO->type  == TOKEN_FLOAT_TYPE){        //If strO->type is redefined to TOKEN_INTEGER_TYPE by transitionForFloat(...),
        newToken = createFloatToken(strO);         //that will return token to newToken.
        strO->token = newToken;                    //The newToken that will store into the strO->Token.
        advanceForspace(curChar,strO);             //If current character is space, strO->index will increase by 1.
        resetTokenType(strO);                      //After create a token, strO->type that will define to TOKEN_UNKNOWN_TYPE.
        return newToken;
      }
      break;
          
      case EXPONENT_STATE:
      // printf("EXPONENT_STATE\n");
      transitionForExpon(&currentState,strO);
       if(strO->type  == TOKEN_FLOAT_TYPE){	      //If strO->type is redefined to TOKEN_INTEGER_TYPE by transitionForExpon(...),
        newToken = createFloatToken(strO);        //that will return token to newToken.
        strO->token = newToken;                   //The newToken that will store into the strO->Token.
        advanceForspace(curChar,strO);            //If current character is space, strO->index will increase by 1.
        resetTokenType(strO);                     //After create a token, strO->type that will define to TOKEN_UNKNOWN_TYPE.
        return newToken;
      }
      break;
          
      case NEGPOSEXPONENT_STATE:
      //printf("NEGPOSEXPONENT_STATE\n");
      transitionForNegPosExpon(&currentState,strO);
      if(strO->type  == TOKEN_FLOAT_TYPE){	      //If strO->type is redefined to TOKEN_INTEGER_TYPE by transitionForNegPosExpon(...),
        newToken = createFloatToken(strO);        //that will return token to newToken.
        strO->token = newToken;                   //The newToken that will store into the strO->Token.
        advanceForspace(curChar,strO);            //If current character is space, strO->index will increase by 1.
        resetTokenType(strO);                     //After create a token, strO->type that will define to TOKEN_UNKNOWN_TYPE.
        return  newToken;
      }
      break;
      
      case DECIMALPOINT_STATE:
      //printf("DECIMALPOINT_STATE\n");
      transitionForDecPointState(&currentState,strO);
      if(strO->type  == TOKEN_OPERATOR_TYPE){	    //If strO->type is redefined to TOKEN_OPERATOR_TYPE by transitionForDecPointState(...),
        newToken = createOperatorToken(strO);     //that will return token to newToken.
        strO->token = newToken;                   //The newToken that will store into the strO->Token.
        advanceForspace(curChar,strO);            //If current character is space, strO->index will increase by 1.
        resetTokenType(strO);                     //After create a token, strO->type that will define to TOKEN_UNKNOWN_TYPE.
        return newToken;
      }
      break;
          
      case STRING_STATE:
      //printf("STRING_STATE\n");
      transitionForStr(&currentState,strO);      
      if (strO->type  == TOKEN_STRING_TYPE){	    //If strO->type is redefined to TOKEN_STRING_TYPE by transitionForStr(...),
        newToken = createStringToken(strO);       //that will return token to newToken.
        strO->token = newToken;                   //The newToken that will store into the strO->Token.
        resetTokenType(strO);                     //After create a token, strO->type that will define to TOKEN_UNKNOWN_TYPE.
        return  newToken;                       
      }
      break;
					
      case IDENTIFIER_STATE:
      //printf("IDENTIFIER_STATE\n");
      transitionForIden(&currentState,strO);      
      if(strO->type  == TOKEN_IDENTIFIER_TYPE){   //If strO->type is redefined to TOKEN_IDENTIFIER_TYPE by transitionForIden(...),
        newToken = createIdentifierToken(strO);   //that will return token to newToken.
        strO->token = newToken;                   //The newToken that will store into the strO->Token.
        advanceForspace(curChar,strO);            //If current character is space, strO->index will increase by 1.
        resetTokenType(strO);                     //After create a token, strO->type that will define to TOKEN_UNKNOWN_TYPE.
        return newToken;
      }
      break;
					
      case OPERATOR_STATE:
      //printf("OPERATOR_STATE\n");
      transitionForOp(&currentState,strO);
      if (strO->type  == TOKEN_OPERATOR_TYPE){	  //If strO->type is redefined to TOKEN_OPERATOR_TYPE by transitionForOp(...),
        newToken = createOperatorToken(strO);     //that will return token to newToken.
        strO->token = newToken;                   //The newToken that will store into the strO->Token.
        resetTokenType(strO);                     //After create a token, strO->type that will define to TOKEN_UNKNOWN_TYPE.
        return newToken;
      }
      break;
					
      case TWINASSIGN_STATE:
      //printf("TWINASSIGN_STATE\n");
      transitionForTwinAssign(&currentState,strO);
      if (strO->type  == TOKEN_OPERATOR_TYPE){    //If strO->type is redefined to TOKEN_OPERATOR_TYPE by transitionForOp(...),
        newToken = createOperatorToken(strO);     //that will return token to newToken.
        strO->token = newToken;                   //The newToken that will store into the strO->Token.
        resetTokenType(strO);                     //After create a token, strO->type that will define to TOKEN_UNKNOWN_TYPE.
        return newToken;
      }
      break;
					
      default:INITIAL_STATE;
      break;
					
		  } 
	}
}
void transitionForIni(TokenState* currentState , StringObject* strO){
  if(strO->str == NULL){
    throwError("Error:The String can't be a NULL\n",ERR_STR_CANNOT_BE_NULL_1);
  }else if(curChar == ' '){     
    advanceIndex(strO);         //strO->index will increase by 1.
    startIndexAnchor(strO);     //Record the start index store into the strO->startIndex.
  }else if(curChar == '\0'){
    strO->type = TOKEN_OPERATOR_TYPE;
  }else if (isUnknown(curChar) && isNotspace(curChar) &&  isNotNULL(curChar) && curChar != '"' && curChar != '_' ){
    throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO, \
    "Expected Character is valid character, but that was unknown character'%c'",curChar);
  }else{
    stateTransition(currentState,strO);
    if( isTokenstate(currentState) ){
      advanceIndex(strO);
    }
  }
}

void transitionForInt(TokenState* currentState , StringObject* strO){
  if( isdigit(curChar) && isOtcNum(curChar) == 0 && prevChar == '0'){
    throwTokenizerError(ERR_INVALID_OCTAL_1,strO, \
    "Expected Character is digit less than 8, but that was '%c'",curChar);
  }else if( isdigit(curChar) && isOtcNum(curChar) && prevChar == '0'){
    advanceIndex(strO);
    *currentState = OCTAL_STATE;    
  }else if(curChar == '.'){
    advanceIndex(strO);
    *currentState = FLOATING_STATE;
  }else if( isExponent(curChar) && isdigit(prevChar) ) {
    advanceIndex(strO);
    *currentState = EXPONENT_STATE;
  }else if ( isHexSymbol(curChar) && prevChar == '0'){
    advanceIndex(strO);
    *currentState = HEXDECIMAL_STATE;
  }else if( isdigit(curChar) ) {
    advanceIndex(strO);
    *currentState = INTEGER_STATE;
  }else if( isNULL(curChar) || isspace(curChar)  || isOperator(curChar)){
    // printf("Create Token\n");
    strO->type = TOKEN_INTEGER_TYPE;
  }else if ( isalpha(curChar) ){	
    throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO, \
    "Expected Character is digit, but that was '%c'",curChar);
  }else{
    throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO, \
    "Expected Character is digit, but that was unknown character'%c'",curChar);
  }
}


void transitionForOp(TokenState* currentState , StringObject* strO){
  if ( isNULL(curChar) || isspace(curChar) || isalnum(curChar) || isSingleOperator(prevChar) ){
    // printf("Create Token\n");
    strO->type = TOKEN_OPERATOR_TYPE;
  }else if ( isOperator(curChar) == 0){
    throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO, \
    "Expected Character is operator, but that was unknown character'%c'",curChar);
  }else if ( isTwinOperator(prevChar) || isAssignOperator(prevChar) ){
    *currentState = TWINASSIGN_STATE;
  }
}

void transitionForTwinAssign(TokenState* currentState , StringObject* strO){
  if (isTwinassign(curChar)){
    advanceIndex(strO);
  }else if (curChar == '=' || ((curChar == prevChar)&&isTwinOperator(curChar)) ){
    // printf("Create Token\n");
    advanceIndex(strO); 
    if(isUnknown(curChar) && isNotspace(curChar) &&  isNotNULL(curChar) ){
      throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO, \
      "Expected Character is operator, but that was unknown character'%c'",curChar);
    }
    strO->type = TOKEN_OPERATOR_TYPE;
  }else if(isOperator(curChar)){
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
    *currentState = STRING_STATE;
  }else if(curChar == '\0'){
  throwTokenizerError(ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1,strO, \
  "End of string without double quote");
  }
}

void transitionForIden(TokenState* currentState , StringObject* strO){
  if(isalnum(curChar)||curChar == '_'){
    advanceIndex(strO);
    *currentState = IDENTIFIER_STATE;
  }else if ( isNULL(curChar) || isspace(curChar)  || isOperator(curChar)){
    //printf("Create Token\n");
    strO->type = TOKEN_IDENTIFIER_TYPE;
  }else if ( isOperator(curChar) == 0){
    throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO, \
    "Expected Character is identifier, but that was unknown character'%c'",curChar);
  }
}

void transitionForDecPointState(TokenState* currentState , StringObject* strO){
  if( isNULL(curChar) || isspace(curChar) || isOperator(curChar) || isalpha(curChar)){
    // printf("Create Token\n");
    strO->type = TOKEN_OPERATOR_TYPE;
  }else if(isdigit(curChar)){
    advanceIndex(strO);
    *currentState = FLOATING_STATE;
  }else if( isOperator(curChar) == 0){
    throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO, \
    "Expected Character is operator, but that was unknown character'%c'",curChar);
  }
}

void transitionForFloat(TokenState* currentState , StringObject* strO){
  if( curChar == '.'){
    throwTokenizerError(ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,strO, \
    "Expected Character is digit, but that was floating point'%c'",curChar);
  }else if(isdigit(curChar)){
    advanceIndex(strO);
    *currentState = FLOATING_STATE;
  }else if( isExponent(curChar) && isdigit(prevChar) ) {
    advanceIndex(strO);
    *currentState = EXPONENT_STATE;
  }else if( isNULL(curChar) || isspace(curChar)  || isOperator(curChar) ){
    // printf("Create Token\n");
    strO->type = TOKEN_FLOAT_TYPE;
  }else if( isalpha(curChar) ){
    throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO, \
    "Expected Character is digit, but that was '%c'",curChar);
  }else{
    throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO, \
    "Expected Character is digit, but that was unknown character'%c'",curChar);
  }
}

void transitionForExpon(TokenState* currentState , StringObject* strO){
  if( curChar == '.'){
    throwTokenizerError(ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,strO, \
    "Expected Character is digit, but that was floating point'%c'",curChar);
  }else if( isPolarity(curChar) && isExponent(prevChar) ){
    advanceIndex(strO);
    *currentState = NEGPOSEXPONENT_STATE;
  }else if(isdigit(curChar) == 0 && isExponent(prevChar)){
    throwTokenizerError(ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1,strO, \
    "Expected Character is digit, but that was '%c'",curChar);
  }else if (isdigit(curChar)){
    advanceIndex(strO);
    *currentState = EXPONENT_STATE;
  }else if( isNULL(curChar) || isspace(curChar) || isOperator(curChar) ){
    // printf("Create Token\n");
    strO->type = TOKEN_FLOAT_TYPE;
  }else if(isalpha(curChar)){
    throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO, \
    "Expected Character is digit, but that was '%c'",curChar);
  }else{
    throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO, \
    "Expected Character is digit, but that was unknown character'%c'",curChar);
  }
}

void transitionForNegPosExpon(TokenState* currentState , StringObject* strO){
  if( curChar == '.'){
    throwTokenizerError(ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,strO, \
    "Expected Character is digit, but that was floating point'%c'",curChar);
  }else if (isdigit(curChar)){
    advanceIndex(strO);
    *currentState = NEGPOSEXPONENT_STATE;
  }else if( isNULL(curChar) || isspace(curChar) || isOperator(curChar) ){
    // printf("Create Token\n");
    strO->type = TOKEN_FLOAT_TYPE;
  }else if(isalpha(curChar)){
    throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO, \
    "Expected Character is digit, but that was '%c'",curChar);
  }else{
    throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO, \
    "Expected Character is digit, but that was unknown character'%c'",curChar);
  }
}

void transitionForHex(TokenState* currentState , StringObject* strO){
  if( isxdigit(curChar) == 0 && isHexSymbol(prevChar)){
    throwTokenizerError(ERR_INVALID_HEX_1,strO, \
    "Expected Character is digit, but that was '%c'",curChar);
  }else if( isxdigit(curChar) ){
    advanceIndex(strO);
    *currentState = HEXDECIMAL_STATE;
  }else if( isNULL(curChar) || isspace(curChar) || isOperator(curChar)){
    // printf("Create Token\n");
    strO->type = TOKEN_INTEGER_TYPE;
  }else if ( isalpha(curChar) ){	
    throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO, \
    "Expected Character is digit, but that was '%c'",curChar);
  }else{
    throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO, \
    "Expected Character is digit, but that was unknown character'%c'",curChar);
  }
}

void transitionForOct(TokenState* currentState , StringObject* strO){
  if( isdigit(curChar) && isOtcNum(curChar) == 0 ){
    throwTokenizerError(ERR_INVALID_OCTAL_1,strO, \
    "Expected Character is digit less than 8, but that was '%c'",curChar);
  }else if( isdigit(curChar) && isOtcNum(curChar) ){
    advanceIndex(strO);
    *currentState = OCTAL_STATE;    
  }else if( isNULL(curChar) || isspace(curChar) || isOperator(curChar)){
    //printf("Create Token\n");
    strO->type = TOKEN_INTEGER_TYPE;
  }else if( isalpha(curChar) ){	
    throwTokenizerError(ERR_CANNOT_CONTAIN_ALPHA,strO, \
    "Expected Character is digit, but that was '%c'",curChar);
  }else{
    throwTokenizerError(ERR_INVALID_UNKNOWN_SYMBOL,strO, \
    "Expected Character is digit, but that was unknown character'%c'",curChar);
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

