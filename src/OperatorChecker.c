#include "OperatorChecker.h"



 /*********************************checkOperator_Function*********************************/

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
