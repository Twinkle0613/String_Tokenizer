#include "StringTokenizer.h"
#include "subFunction.h"
#include "unity.h"
#include "Token.h"




void setUp(void){}

void tearDown(void){}
/*
		str = "1234"
	
				 
				1->2->3->4->\0 
										||										 ----------------------
										V											|  TOKEN_INTEGER_TYPE |
					createIntegerToken()   =  			----------------------
																				 |         1234        |
																				 ----------------------
				
*/
/*
	TEST LIST
	-----------------------------------------------------------------
	NO	strO        TokenType 					        Return/Throw			 	Condition
	-----------------------------------------------------------------
	1		NULL					Error							        -5									Complete						
	-----------------------------------------------------------------
	NO	str					TokenType					        	Return/Throw       Condition
	-----------------------------------------------------------------
	1		"1234"     		InTk						 	        1234  							Complete 
	2		"1234 "    		InTk 							        1234								Complete
	3		"1234\n"    	InTk							        1234								Complete
	4		"1234\0"    	InTk 							        1234								Complete
	5		" "          	OpTk							        $ 									Complete
	6		"1234"      	InTk OpTk OpTk 		        1234 '$' '$'				Complete
	7		NULL        	Error							        -4									Complete
	8		"12A34"       Error							        -1									Complete
	9		"123*4"       Error							        -2									Complete
	10	""            OpTk 							         $ 									Complete
	11  "1234 1234"		InTk InTk	OpTk		        1234 4321 $         Complete
  12  "123 4 214"   InTk InTk	OpTk OpTk       123 4 214 $         Complete    
	-----------------------------------------------------------------
*/
/*strO*/
//1
void test_StringTokenizer_given_strO_NULL_should_throw_err_STR_OBJECT_CANNOT_BE_NULL(void){
	
		CEXCEPTION_T err;
	Try{
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(NULL);
		//printf("newToken->symbol = %c\n",newToken->symbol);
		//TEST_LAST_TOKEN(newToken);
	
	}Catch(err){
		printError(err);
		printf("Number of Error = %d",err);
		TEST_ASSERT_EQUAL(ERR_STR_OBJECT_CANNOT_BE_NULL,err);
		
	}
	
}
/*string*/
void test_StringTokenizer_given_string_1_should_return_IntegerToken(void){

		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("1"));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(1,0,1,"1",newToken);
		dumpToken(newToken);
		printf("No.1\n");
 }
void test_StringTokenizer_given_string_1234_should_return_IntegerToken(void){

		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("1234"));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234",newToken);
		printf("No.1\n");
 }
//2 
void test_StringTokenizer_given_string_1234space_should_return_IntegerToken(void){

		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("1234 "));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234 ",newToken);
		printf("No.2\n");
 }
//3 
void test_StringTokenizer_given_string_1234endline_should_return_IntegerToken(void){

		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("1234\n"));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234\n",newToken);
		printf("No.3\n");
 }
//4
void test_StringTokenizer_given_string_1234_0__should_return_IntegerToken(void){
		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("1234\0"));
		TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234",newToken);
		printf("No.4\n");
 }
//5 
void test_StringTokenizer_given_string_space_should_return_OperatorToken_that_symbol_is_money(void){

		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject(" "));
		printf("newToken->symbol = %s\n",newToken->symbol);
		TEST_LAST_TOKEN(newToken);		
		printf("No.5\n");
	}
	

//6
void test_StringTokenizer_given_string_1234_should_return_IntegerToken_and_return_OperatorToken(void){
		printf("No.6\n");

	StringObject *str = createStringObject("1234");

	IntegerToken *newToken1 = (IntegerToken*) StringTokenizer(str);
	printf("newToken->value = %d\n",newToken1->value);
	TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234",newToken1);

	OperatorToken *newToken2 = (OperatorToken*) StringTokenizer(str);
	printf("newToken->symbol = %s\n",newToken2->symbol);
	TEST_LAST_TOKEN(newToken2);

	OperatorToken *newToken3 =(OperatorToken*) StringTokenizer(str);
	printf("newToken->symbol = %s\n",newToken3->symbol);
	TEST_LAST_TOKEN(newToken3);

}
//7
void test_StringTokenizer_given_string_NULL_should_throw_err_STR_CANNOT_BE_NULL(void){

		CEXCEPTION_T err;
	Try{
		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject(NULL));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_NULL(newToken);
	}Catch(err){
		printError(err);
		printf("Number of Error = %d",err);
		TEST_ASSERT_EQUAL(ERR_STR_CANNOT_BE_NULL,err);
	}
		printf("No.7\n");
}
//8
void test_StringTokenizer_given_string_12A34_throw_err_STR_INCLURE_ALPHA(void){

	CEXCEPTION_T err;
	Try{
		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("12A34"));
		printf("newToken->value = %d\n",newToken->value);
					TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234\n",newToken);
	}Catch(err){
		printError(err);
		printf("Number of Error = %d",err);
		TEST_ASSERT_EQUAL(ERR_STR_INCLURE_ALPHA,err);
	}
		printf("No.8\n");
}	
//9
void test_StringTokenizer_given_string_123star4_should_return_INTEGER_TOKEN(void){
		IntegerToken *newToken =(IntegerToken*) StringTokenizer(createStringObject("123*4"));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(123,0,3,"123*4",newToken);
		printf("No.9\n");
}
//10
void test_StringTokenizer_given_string_return_money(void){

		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject(""));
		printf("newToken->symbol = %s\n",newToken->symbol);
		TEST_LAST_TOKEN(newToken);
		printf("No.10\n");
}
//11 
void test_StringTokenizer_given_string_1234_4321_should_return_2_IntegerToken(void){

	StringObject *str = createStringObject("1234 4321");

				IntegerToken *newToken1 = (IntegerToken*) StringTokenizer(str);
				printf("newToken->value = %d\n",newToken1->value);
				TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234 4321",newToken1);

				IntegerToken *newToken2 = (IntegerToken*) StringTokenizer(str);
				printf("newToken->value = %d\n",newToken2->value);
				TEST_ASSERT_INTEGER_TOKEN(4321,5,4,"1234 4321",newToken2);

				OperatorToken *newToken3 =(OperatorToken*) StringTokenizer(str);
				printf("newToken->symbol = %s\n",newToken3->symbol);
				TEST_LAST_TOKEN(newToken3);
		printf("No.11\n");
}
//12
void test_StringTokenizer_given_string_123_4_214_should_return_3_IntegerToken(void){


	StringObject *str = createStringObject("123 4 214");

				IntegerToken *newToken1 = (IntegerToken*) StringTokenizer(str);
				printf("newToken->value = %d\n",newToken1->value);
				TEST_ASSERT_INTEGER_TOKEN(123,0,3,"123 4 214",newToken1);

				IntegerToken *newToken2 = (IntegerToken*) StringTokenizer(str);
				printf("newToken->value = %d\n",newToken2->value);
				TEST_ASSERT_INTEGER_TOKEN(4,4,1,"123 4 214",newToken2);

        IntegerToken *newToken3 = (IntegerToken*) StringTokenizer(str);
				printf("newToken->value = %d\n",newToken3->value);
				TEST_ASSERT_INTEGER_TOKEN(214,6,3,"123 4 214",newToken3);
        
				OperatorToken *newToken4 =(OperatorToken*) StringTokenizer(str);
				printf("newToken->symbol = %s\n",newToken4->symbol);
				TEST_LAST_TOKEN(newToken4);
		printf("No.12\n");
	
}
//13
// void test_TransitionForOp_given_string_symbol_should_return_OperatorToken(void){
		// printf("No.13\n");

			// Token* OpTk = malloc(sizeof(Token));
			// createOpTk(0,OpTk);
			// TokenState currState = OperatorState;
			// TransitionForOp( &OpTk, &currState, createStringObject("^") );
			// TEST_ASSERT_EQUAL_STRING("^",OpTk->str);
			// dumpToken(OpTk);
			
// }
//14
void test_TransitionForOp_given_string_symbol1_should_return_OperatorToken(void){

			OperatorToken* OpTk = malloc(sizeof(OperatorToken));
			Token* newToken = malloc(sizeof(Token));
			newToken->startColumn = 0;
			TokenState currState = OperatorState;
			TransitionForOp( &newToken, &currState,createStringObject("^"));
			OpTk = (OperatorToken*)newToken;
			TEST_ASSERT_EQUAL_STRING("^",OpTk->symbol);
			dumpToken(newToken);
			printf("No.14\n");
}

void test_TransitionForOp_given_string_symbol2_should_return_OperatorToken(void){

			OperatorToken* OpTk = malloc(sizeof(OperatorToken));
			Token* newToken = malloc(sizeof(Token));
			newToken->startColumn = 0;
			TokenState currState = OperatorState;
			TransitionForOp( &newToken, &currState,createStringObject("+1234"));
			OpTk = (OperatorToken*)newToken;
			TEST_ASSERT_EQUAL_STRING("+",OpTk->symbol);
			dumpToken(newToken);
			printf("No.15\n");
}

void test_TransitionForOp_given_string_given_invalid_symbol2_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){

			CEXCEPTION_T err;
			OperatorToken* OpTk = malloc(sizeof(OperatorToken));
			Token* newToken = malloc(sizeof(Token));
			newToken->startColumn = 0;
			TokenState currState = OperatorState;
			Try{
				TransitionForOp( &newToken, &currState,createStringObject("+ +$!@#$%^"));
				OpTk = (OperatorToken*)newToken;
				TEST_ASSERT_EQUAL_STRING("+",OpTk->symbol);
				dumpToken(newToken);
			}Catch(err){
				printError(err);
				TEST_ASSERT_EQUAL(ERR_STR_CANNOT_CONTAIN_INVALID_OPERATOR,err);

			}
			printf("No.16\n");
}


void test_StringTokenizer_given_string_symbol_should_return_OperatorToken(void){
	
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("^"));
		TEST_ASSERT_OPERATOR_TOKEN("^",0,1,"^",newToken);
		dumpToken(newToken);
		printf("No.17\n");
}
void test_StringTokenizer_given_string_plus_0_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("+\0"));
		TEST_ASSERT_OPERATOR_TOKEN("+",0,1,"+\0",newToken);
		dumpToken(newToken);
		printf("No.18\n");
}


void test_StringTokenizer_given_string_symbol1_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("+^"));
		TEST_ASSERT_OPERATOR_TOKEN("+",0,1,"+^",newToken);
		dumpToken(newToken);
		printf("No.19\n");
}

void test_StringTokenizer_given_string_TwinOperator_should_return_OperatorToken(void){
				
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("++"));
		TEST_ASSERT_OPERATOR_TOKEN("++",0,2,"++",newToken);
		dumpToken(newToken);
	  printf("No.20\n");
}

void test_StringTokenizer_given_string_AssignmentOperator_should_return_OperatorToken(void){
				
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("+="));
		TEST_ASSERT_OPERATOR_TOKEN("+=",0,2,"+=",newToken);
		dumpToken(newToken);
		printf("No.21\n");
}


void test_StringTokenizer_given_string_TwinAssignmentOperator_should_return_OperatorToken(void){
				
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject(">>="));
		TEST_ASSERT_OPERATOR_TOKEN(">>=",0,3,">>=",newToken);
		dumpToken(newToken);
		printf("No.22\n");
}

void test_StringTokenizer_given_string_TwinAssignmentOperator_shift_assignemt_should_return_OperatorToken(void){
				
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("<<="));
		TEST_ASSERT_OPERATOR_TOKEN("<<=",0,3,"<<=",newToken);
		dumpToken(newToken);
		printf("No.23\n");
}


void test_StringTokenizer_given_string_space_AssignmentOperator_should_return_OperatorToken(void){
			
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject(" +-"));
		TEST_ASSERT_OPERATOR_TOKEN("+",1,1," +-",newToken);
		dumpToken(newToken);
		printf("No.24\n");
}

void test_StringTokenizer_given_string_space_space_TwinOperator_should_return_OperatorToken(void){
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("   ++"));
		TEST_ASSERT_OPERATOR_TOKEN("++",3,2,"   ++",newToken);
		dumpToken(newToken);
		printf("No.25\n");
	
}

void test_StringTokenizer_given_string_singleOperator_should_return_OperatorToken(void){
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("...."));
		TEST_ASSERT_OPERATOR_TOKEN(".",0,1,"....",newToken);
		dumpToken(newToken);
		printf("No.26\n");
	
}

void test_StringTokenizer_given_string_singleOperator_paket_should_return_OperatorToken(void){
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("(12214)"));
		TEST_ASSERT_OPERATOR_TOKEN("(",0,1,"(12214)",newToken);
		dumpToken(newToken);
		printf("No.27\n");
	
}

void test_StringTokenizer_given_string_TwinOperator_assignment_should_return_OperatorToken(void){
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("=========="));
		TEST_ASSERT_OPERATOR_TOKEN("==",0,2,"==========",newToken);
		dumpToken(newToken);
		printf("No.28\n");
	
}

void test_StringTokenizer_given_string_plus_n_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("+\n"));
		TEST_ASSERT_OPERATOR_TOKEN("+",0,1,"+\n",newToken);
		dumpToken(newToken);
		printf("No.29\n");
}

void test_StringTokenizer_given_string_symbol2_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("^^^^^^^^"));
		TEST_ASSERT_OPERATOR_TOKEN("^",0,1,"^^^^^^^^",newToken);
		dumpToken(newToken);
		printf("No.30\n");
}

void test_StringTokenizer_given_string_symbol3_should_return_OperatorToken(void){
	CEXCEPTION_T err;
	Try{
		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject(">>=$#"));
		TEST_ASSERT_OPERATOR_TOKEN(">>=",0,3,">>=$#",newToken);
		dumpToken(newToken);

	}Catch(err){
		printError(err);
		printf("Number of Error = %d\n",err);
		TEST_ASSERT_EQUAL(ERR_STR_CANNOT_CONTAIN_INVALID_OPERATOR,err);
		
	}
			printf("No.31\n");
}

void test_StringTokenizer_given_string_TwinAssignmentOperator3_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("<<=3"));
		TEST_ASSERT_OPERATOR_TOKEN("<<=",0,3,"<<=3",newToken);
		dumpToken(newToken);
		printf("No.32\n");
}

void test_StringTokenizer_given_string_AssignmentOperator3_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("      <=3"));
		TEST_ASSERT_OPERATOR_TOKEN("<=",6,2,"      <=3",newToken);
		dumpToken(newToken);
		printf("No.33\n");
}
void test_StringTokenizer_given_string_Assignment_A_Assignment_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("=A="));
		TEST_ASSERT_OPERATOR_TOKEN("=",0,1,"=A=",newToken);
		dumpToken(newToken);
		printf("No.34\n");
}

void test_StringTokenizer_given_string_inValid_operator_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) StringTokenizer(createStringObject("#"));
		TEST_ASSERT_OPERATOR_TOKEN("<=",6,2,"#",newToken);
		dumpToken(newToken);
		printf("No.35\n");
}


