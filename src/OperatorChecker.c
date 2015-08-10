#include "OperatorChecker.h"

/**
 * The function in OperatorChecker there are to identify the operator and differential the type of operator.
 * Eg.
 *                               -------------------
 *                              |    Operator      |
 *                              -------------------
 *                              /    |      |      \
 *                            /      |      |       \
 *                          /        |      |        \
 *                      single     twin    assign  twinassign
 *                      ^,{       ==,++     +=,-=   <<=,>>=
 *
 *
 * Array:
 * This a array is use to store some of valid operator that was typed by user. 
 * int operatorAtrributes[]
 *  
 * Function:
 *  int isSingle(int symbol);
 *  int isTwin(int symbol);
 *  int isAssign(int symbol);
 *  int isTwinAssign(int symbol);
 *  int issymbol(int symbol);
 *
 * Input:
 *	The input for all the function 
 *  symbol - the Operator that is assign by the getToken function
 *
 *
 * Return:
 *    isSingle:
 *    if the operator is single type , then that are return 1 
 *    isTwin:
 *    if the operator is Twin type , then that are return 1
 *    isAssign:
 *    if the operator is Assign type , then that are return 1
 *    isTwinAssign:
 *    if the operator is TwinAssign type , then that are return 1
 *    isOperator:
 *    if the operator is a valid operator , then that are return 1
 *
 */
 
int operatorAtrributes[256] = {
  ['<'] = SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT, //< << <= <<= 
  ['>'] = SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT,//> >> >=	>>=  
  ['+'] = SINGLE | TWIN | ASSIGNMENT, // + ++ += 
  ['-'] = SINGLE | TWIN | ASSIGNMENT, // - -- -= 
  ['/'] = SINGLE | TWIN | ASSIGNMENT, // / // /= 
  ['&'] = SINGLE | TWIN | ASSIGNMENT, // & && &= 
  ['|'] = SINGLE | TWIN | ASSIGNMENT, // | || |= 
  ['!'] = SINGLE | ASSIGNMENT,				 // ! !=
  ['*'] = SINGLE | ASSIGNMENT,        // * *= 
  ['^'] = SINGLE | ASSIGNMENT,        // ^ ^= 
  ['%'] = SINGLE | ASSIGNMENT,        // % %=  
  ['='] = SINGLE | TWIN,							 // == 
  ['('] = SINGLE,
  [')'] = SINGLE,
  ['['] = SINGLE,
  [']'] = SINGLE,
  ['{'] = SINGLE,
  ['}'] = SINGLE,
  ['@'] = SINGLE,
  [';'] = SINGLE,
  [':'] = SINGLE,
  ['.'] = SINGLE,
  [','] = SINGLE,
  ['~'] = SINGLE,
  ['?'] = SINGLE
};

int isValidOperator(int symbol){
  if(SINGLE == symbol)
		return 1;
  else if ((SINGLE | TWIN) == symbol)
    return 1;
  else if ((SINGLE | ASSIGNMENT) == symbol)
    return 1;
  else if ((SINGLE | TWIN | ASSIGNMENT) == symbol)
    return 1;
  else if ((SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == symbol)
    return 1;
  else 
    return 0;
}

int isSingle(int symbol){
  if (SINGLE == symbol)
    return 1;
  return 0;
 }

int isTwin(int symbol){
  if ((SINGLE | TWIN) == symbol)
    return 1;
  else if ( (SINGLE | TWIN | ASSIGNMENT) == symbol )
    return 1;
  else if ( (SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == symbol)
    return 1;
  else 
    return 0;
}

int isAssign(int symbol){
  if ((SINGLE | ASSIGNMENT) == symbol)
    return 1;
  else if ((SINGLE | TWIN | ASSIGNMENT) == symbol)
    return 1;
  else if ((SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == symbol)
    return 1;
  else
    return 0;
 }

int isTwinAssign(int symbol){
  if ((SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == symbol)
    return 1;
  return 0;
}
