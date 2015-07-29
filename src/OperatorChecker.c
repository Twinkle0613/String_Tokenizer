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
 *  int isSingle(int Operator);
 *  int isTwin(int Operator);
 *  int isAssign(int Operator);
 *  int isTwinAssign(int Operator);
 *  int isOperator(int Operator);
 *
 * Input:
 *	The input for all the function 
 *  Operator - the Operator that is assign by the getToken function
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
	 ['='] = SINGLE | TWIN,								// == 
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

int isOperator(int Operator){
			if(SINGLE == Operator)
				return 1;
			else if ((SINGLE | TWIN) == Operator)
				return 1;
			else if ((SINGLE | ASSIGNMENT) == Operator)
				return 1;
			else if ((SINGLE | TWIN | ASSIGNMENT) == Operator)
			  return 1;
			else if ((SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == Operator)
				return 1;
			else 
				return 0;
}

int isSingle(int Operator){
			if (SINGLE == Operator)
				 return 1;
			   return 0;
 }

int isTwin(int Operator){
			if ((SINGLE | TWIN) == Operator)
				return 1;
			else if ( (SINGLE | TWIN | ASSIGNMENT) == Operator )
			  return 1;
			else if ( (SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == Operator)
				return 1;
			else 
				return 0;
}

int isAssign(int Operator){
			if ((SINGLE | ASSIGNMENT) == Operator)
				 return 1;
			else if ((SINGLE | TWIN | ASSIGNMENT) == Operator)
				 return 1;
			else if ((SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == Operator)
				 return 1;
			else
			   return 0;
 }

int isTwinAssign(int Operator){
			if ((SINGLE | TWIN | ASSIGNMENT |TWIN_ASSIGNMENT) == Operator)
				return 1;
			  return 0;
}
