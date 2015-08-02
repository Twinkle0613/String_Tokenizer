//Own module files
#include "StringTokenizer.h"
#include "subFunction.h"
#include "OperatorChecker.h"
#include "Token.h"
#include "unity.h"
#include "TextCode.h"
#include "TokenError.h"


void setUp(void){}

void tearDown(void){}


// void test_StringTokenizer_given_strO_NULL_should_throw_err_STR_OBJECT_CANNOT_BE_NULL(void){
	
		// CEXCEPTION_T err;
	// Try{
		// OperatorToken *newToken =(OperatorToken*) getToken(NULL);
    // TEST_FAIL_MESSAGE("Expect ERR_STR_OBJECT_CANNOT_BE_NULL_1 to be thrown. But none thrown.");
	// }Catch(err){
     // printf("%s",err->errorMsg);
     // TEST_ASSERT_EQUAL_STRING("The String Object can't be a NULL\n",err->errorMsg);
     // TEST_ASSERT_EQUAL(ERR_STR_OBJECT_CANNOT_BE_NULL_1,err->errorCode); 
     // freeError(err);
	// }
	
// }

void test_StringTokenizer_given_string_1_should_return_IntegerToken(void){

		IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1"));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(1,0,1,"1",newToken);
		dumpToken(newToken);
		printf("No.1\n");
 }
void test_StringTokenizer_given_string_1234_should_return_IntegerToken(void){

		IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234"));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234",newToken);
		printf("No.1\n");
 }
 
void test_StringTokenizer_given_string_1234space_should_return_IntegerToken(void){

		IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234 "));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234 ",newToken);
		printf("No.2\n");
 }
 
void test_StringTokenizer_given_string_1234endline_should_return_IntegerToken(void){

		IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234\n"));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234\n",newToken);
		printf("No.3\n");
 }

void test_StringTokenizer_given_string_1234_0__should_return_IntegerToken(void){
		IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234\0"));
		TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234",newToken);
		printf("No.4\n");
 }

void test_StringTokenizer_given_string_space_should_return_OperatorToken_that_symbol_is_money(void){

		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(" "));
		printf("newToken->symbol = %s\n",newToken->symbol);
		TEST_LAST_TOKEN(newToken);		
		printf("No.5\n");
	}
	

void test_StringTokenizer_given_string_1234_should_return_IntegerToken_and_return_OperatorToken(void){
		printf("No.6\n");

	StringObject *str = createStringObject("1234");

	IntegerToken *newToken1 = (IntegerToken*) getToken(str);
	printf("newToken->value = %d\n",newToken1->value);
	TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234",newToken1);

	OperatorToken *newToken2 = (OperatorToken*) getToken(str);
	printf("newToken->symbol = %s\n",newToken2->symbol);
	TEST_LAST_TOKEN(newToken2);

	OperatorToken *newToken3 =(OperatorToken*) getToken(str);
	printf("newToken->symbol = %s\n",newToken3->symbol);
	TEST_LAST_TOKEN(newToken3);

}

void test_StringTokenizer_given_string_NULL_should_throw_err_STR_CANNOT_BE_NULL(void){

		CEXCEPTION_T err;
	Try{
		IntegerToken *newToken =(IntegerToken*) getToken(createStringObject(NULL));
		printf("newToken->value = %d\n",newToken->value);
		
    TEST_ASSERT_NULL(newToken);
    TEST_FAIL_MESSAGE("Expect ERR_STR_CANNOT_BE_NULL_1 to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
     TEST_ASSERT_EQUAL_STRING("Error:The String can't be a NULL\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_STR_CANNOT_BE_NULL_1,err->errorCode);
     freeError(err);
	}
		printf("No.7\n");
}

void test_StringTokenizer_given_string_12A34_throw_err_STR_INCLURE_ALPHA(void){
	CEXCEPTION_T err;
  StringObject* strO = createStringObject("12A34");
  char buffer[256];
  char ErrMsg[256];
	Try{
		IntegerToken *newToken =(IntegerToken*) getToken(strO);
		printf("newToken->value = %d\n",newToken->value);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
   //  TEST_ASSERT_EQUAL_STRING("Can't contain any alphabet\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);

    sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
    sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
		printf("No.8\n");
}	

void test_StringTokenizer_given_string_123star4_should_return_INTEGER_TOKEN(void){
		IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("123*4"));
		printf("newToken->value = %d\n",newToken->value);
		TEST_ASSERT_INTEGER_TOKEN(123,0,3,"123*4",newToken);
		printf("No.9\n");
}

void test_StringTokenizer_given_string_return_money(void){

		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(""));
		printf("newToken->symbol = %s\n",newToken->symbol);
		TEST_LAST_TOKEN(newToken);
		printf("No.10\n");
}
 
void test_StringTokenizer_given_string_1234_4321_should_return_2_IntegerToken(void){

	StringObject *str = createStringObject("1234 4321");

				IntegerToken *newToken1 = (IntegerToken*) getToken(str);
				printf("newToken->value = %d\n",newToken1->value);
				TEST_ASSERT_INTEGER_TOKEN(1234,0,4,"1234 4321",newToken1);

				IntegerToken *newToken2 = (IntegerToken*) getToken(str);
				printf("newToken->value = %d\n",newToken2->value);
				TEST_ASSERT_INTEGER_TOKEN(4321,5,4,"1234 4321",newToken2);

				OperatorToken *newToken3 =(OperatorToken*) getToken(str);
				printf("newToken->symbol = %s\n",newToken3->symbol);
				TEST_LAST_TOKEN(newToken3);
		printf("No.11\n");
}

void test_StringTokenizer_given_string_123_4_214_should_return_3_IntegerToken(void){


	StringObject *str = createStringObject("123 4 214");

				IntegerToken *newToken1 = (IntegerToken*) getToken(str);
				printf("newToken->value = %d\n",newToken1->value);
				TEST_ASSERT_INTEGER_TOKEN(123,0,3,"123 4 214",newToken1);

				IntegerToken *newToken2 = (IntegerToken*) getToken(str);
				printf("newToken->value = %d\n",newToken2->value);
				TEST_ASSERT_INTEGER_TOKEN(4,4,1,"123 4 214",newToken2);

        IntegerToken *newToken3 = (IntegerToken*) getToken(str);
				printf("newToken->value = %d\n",newToken3->value);
				TEST_ASSERT_INTEGER_TOKEN(214,6,3,"123 4 214",newToken3);
        
				OperatorToken *newToken4 =(OperatorToken*) getToken(str);
				printf("newToken->symbol = %s\n",newToken4->symbol);
				TEST_LAST_TOKEN(newToken4);
		printf("No.12\n");
	
}

// void test_TransitionForOp_given_string_symbol_should_return_OperatorToken(void){
		// printf("No.13\n");

			// Token* OpTk = malloc(sizeof(Token));
			// createOpTk(0,OpTk);
			// TokenState currState = OperatorState;
			// TransitionForOp( &OpTk, &currState, createStringObject("^") );
			// TEST_ASSERT_EQUAL_STRING("^",OpTk->str);
			// dumpToken(OpTk);
			
// }

void test_TransitionForOp_given_string_symbol1_should_return_OperatorToken(void){

			// OperatorToken* OpTk = malloc(sizeof(OperatorToken));
			// Token* newToken = malloc(sizeof(Token));
			// TokenState currState = OperatorState;
      // StringObject* strO = createStringObject("^");
      // strO->startIndex = 0;
			// TransitionForOp( &newToken, &currState,strO);
			// OpTk = (OperatorToken*)newToken;
			// TEST_ASSERT_EQUAL_STRING("^",OpTk->symbol);
			// dumpToken(newToken);
			printf("No.14\n");
}

void test_TransitionForOp_given_string_symbol2_should_return_OperatorToken(void){

			// OperatorToken* OpTk = malloc(sizeof(OperatorToken));
			// Token* newToken = malloc(sizeof(Token));
			// TokenState currState = OperatorState;
      // StringObject* strO = createStringObject("+1234");
      // strO->startIndex = 0;
			// TransitionForOp( &newToken, &currState,strO);
			// OpTk = (OperatorToken*)newToken;
			// TEST_ASSERT_EQUAL_STRING("+",OpTk->symbol);
			// dumpToken(newToken);
			printf("No.15\n");
}

void test_TransitionForOp_given_string_given_invalid_symbol2_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){


			// OperatorToken* OpTk = malloc(sizeof(OperatorToken));
			// Token* newToken = malloc(sizeof(Token));
			// TokenState currState = OperatorState;
      // StringObject* strO = createStringObject("+ +$!@#$%^");
      // strO->startIndex = 0;
			// TransitionForOp( &newToken, &currState,strO);
			// OpTk = (OperatorToken*)newToken;
			// TEST_ASSERT_EQUAL_STRING("+",OpTk->symbol);
			// dumpToken(newToken);

			printf("No.16\n");
}

//--------------------------------------------
void test_StringTokenizer_given_string_symbol_should_return_OperatorToken(void){
	
		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("^"));
		TEST_ASSERT_OPERATOR_TOKEN("^",0,1,"^",newToken);
		dumpToken(newToken);
		printf("No.17\n");
}
void test_StringTokenizer_given_string_plus_0_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+\0"));
		TEST_ASSERT_OPERATOR_TOKEN("+",0,1,"+\0",newToken);
		dumpToken(newToken);
		printf("No.18\n");
}


void test_StringTokenizer_given_string_symbol1_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+^"));
		TEST_ASSERT_OPERATOR_TOKEN("+",0,1,"+^",newToken);
		dumpToken(newToken);
		printf("No.19\n");
}

void test_StringTokenizer_given_string_TwinOperator_should_return_OperatorToken(void){
				
		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("++"));
		TEST_ASSERT_OPERATOR_TOKEN("++",0,2,"++",newToken);
		dumpToken(newToken);
	  printf("No.20\n");
}

void test_StringTokenizer_given_string_AssignmentOperator_should_return_OperatorToken(void){
				
		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+="));
		TEST_ASSERT_OPERATOR_TOKEN("+=",0,2,"+=",newToken);
		dumpToken(newToken);
		printf("No.21\n");
}


void test_StringTokenizer_given_string_TwinAssignmentOperator_should_return_OperatorToken(void){
				
		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(">>="));
		TEST_ASSERT_OPERATOR_TOKEN(">>=",0,3,">>=",newToken);
		dumpToken(newToken);
		printf("No.22\n");
}

void test_StringTokenizer_given_string_TwinAssignmentOperator_shift_assignemt_should_return_OperatorToken(void){
				
		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("<<="));
		TEST_ASSERT_OPERATOR_TOKEN("<<=",0,3,"<<=",newToken);
		dumpToken(newToken);
		printf("No.23\n");
}


void test_StringTokenizer_given_string_space_AssignmentOperator_should_return_OperatorToken(void){
			
		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(" +-"));
		TEST_ASSERT_OPERATOR_TOKEN("+",1,1," +-",newToken);
		dumpToken(newToken);
		printf("No.24\n");
}

void test_StringTokenizer_given_string_space_space_TwinOperator_should_return_OperatorToken(void){
		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("   ++"));
		TEST_ASSERT_OPERATOR_TOKEN("++",3,2,"   ++",newToken);
		dumpToken(newToken);
		printf("No.25\n");
	
}

void test_StringTokenizer_given_string_singleOperator_should_return_OperatorToken(void){
		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("...."));
		TEST_ASSERT_OPERATOR_TOKEN(".",0,1,"....",newToken);
		dumpToken(newToken);
		printf("No.26\n");
	
}

void test_StringTokenizer_given_string_singleOperator_paket_should_return_OperatorToken(void){
		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("(12214)"));
		TEST_ASSERT_OPERATOR_TOKEN("(",0,1,"(12214)",newToken);
		dumpToken(newToken);
		printf("No.27\n");
	
}

void test_StringTokenizer_given_string_TwinOperator_assignment_should_return_OperatorToken(void){
		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("=========="));
		TEST_ASSERT_OPERATOR_TOKEN("==",0,2,"==========",newToken);
		dumpToken(newToken);
		printf("No.28\n");
	
}

void test_StringTokenizer_given_string_plus_n_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+\n"));
		TEST_ASSERT_OPERATOR_TOKEN("+",0,1,"+\n",newToken);
		dumpToken(newToken);
		printf("No.29\n");
}

void test_StringTokenizer_given_string_symbol2_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("^^^^^^^^"));
		TEST_ASSERT_OPERATOR_TOKEN("^",0,1,"^^^^^^^^",newToken);
		dumpToken(newToken);
		printf("No.30\n");
}

void test_StringTokenizer_given_string_symbol3_should_return_OperatorToken(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
	StringObject* strO = createStringObject(">>=$");
  Try{
		OperatorToken *newToken =(OperatorToken*) getToken(strO);
	  TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");

  }Catch(err){
      printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
     sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
			printf("No.31\n");
}

void test_StringTokenizer_given_string_TwinAssignmentOperator3_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("<<=3"));
		TEST_ASSERT_OPERATOR_TOKEN("<<=",0,3,"<<=3",newToken);
		dumpToken(newToken);
		printf("No.32\n");
}

void test_StringTokenizer_given_string_AssignmentOperator3_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("      <=3"));
		TEST_ASSERT_OPERATOR_TOKEN("<=",6,2,"      <=3",newToken);
		dumpToken(newToken);
		printf("No.33\n");
}
void test_StringTokenizer_given_string_Assignment_A_Assignment_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("=A="));
		TEST_ASSERT_OPERATOR_TOKEN("=",0,1,"=A=",newToken);
		dumpToken(newToken);
		printf("No.34\n");
}



void test_StringTokenizer_given_string_doller_plus_plus_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
  StringObject* strO = createStringObject("$++");
	Try{
		OperatorToken *newToken =(OperatorToken*) getToken(strO);
	  TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
  }Catch(err){
      printf("%s",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
     sprintf(ErrMsg,"Expected Character is valid character, but that was unknown character'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
		printf("No.35\n");
}

void test_StringTokenizer_given_string_unknown_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
    StringObject* strO =createStringObject("$");
	Try{
		OperatorToken *newToken =(OperatorToken*) getToken(strO);
	   TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
  }Catch(err){
      printf("%s",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
     sprintf(ErrMsg,"Expected Character is valid character, but that was unknown character'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
		printf("No.36\n");
}

void test_StringTokenizer_given_string_Assign_Assign_doller_should_return_OperatorToken(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
    StringObject* strO =createStringObject(("==$"));
	Try{
      OperatorToken *newToken =(OperatorToken*) getToken(strO);
    	TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
			}Catch(err){
      printf("%s",err->errorMsg);
      TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
      sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);
      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
      freeError(err);
    }
			printf("No.37\n");
            
}


void test_StringTokenizer_given_string_Assign_doller_should_return_OperatorToken(void){
	CEXCEPTION_T err;
  StringObject* strO = createStringObject("=$");
	Try{
		OperatorToken *newToken =(OperatorToken*) getToken(strO);
	  TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
			}Catch(err){
      printf("%s",err->errorMsg);
      // TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     char buffer[256];
     char ErrMsg[256];
      sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);
      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
      TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
      freeError(err);
	}
			printf("No.38\n");
}            

//------------------------------------------------------------------------

void test_StringTokenizer_given_string_given_double_quote_123s_should_return_stringToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject("\"123\""));
		TEST_ASSERT_STRING_TOKEN("\"123\"",0,5,"\"123\"",newToken);
		dumpToken(newToken);

			printf("No.39\n");
}


void test_StringTokenizer_given_string_given_double_quote_symbol_should_return_stringToken(void){

StringToken *newToken =(StringToken*) getToken(createStringObject(" \"1234567890abcdefghijklmnopqrstuvwsyz!@#$%^&*()_+|}{:?><},./';\" "));
		TEST_ASSERT_STRING_TOKEN("\"1234567890abcdefghijklmnopqrstuvwsyz!@#$%^&*()_+|}{:?><},./';\"",1,63," \"1234567890abcdefghijklmnopqrstuvwsyz!@#$%^&*()_+|}{:?><},./';\" ",newToken);
		dumpToken(newToken);

			printf("No.40\n");
}


void test_StringTokenizer_given_string_given_space_double_quote_symbol_should_return_stringToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject("  \"Hello    Hello\""));
		TEST_ASSERT_STRING_TOKEN("\"Hello    Hello\"",2,16,"  \"Hello    Hello\"",newToken);
		dumpToken(newToken);
			printf("No.41\n");
}

void test_StringTokenizer_given_string_given__double_quote_symbol_space_should_return_stringToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject("\"%%%%%%%%%\"        "));
		TEST_ASSERT_STRING_TOKEN("\"%%%%%%%%%\"",0,11,"\"%%%%%%%%%\"        ",newToken);
		dumpToken(newToken);
			printf("No.42\n");

}
//Note!!
void test_StringTokenizer_given_string_given_double_quote_string_1234_123_should_return_stringToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject("\"1234\"123"));
		TEST_ASSERT_STRING_TOKEN("\"1234\"",0,6,"\"1234\"123",newToken);
		dumpToken(newToken);
			printf("No.43\n");

}

void test_StringTokenizer_given_string_given_double_quote_string_space_should_return_stringToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject(" \"\" "));
		TEST_ASSERT_STRING_TOKEN("\"\"",1,2," \"\" ",newToken);
		dumpToken(newToken);
			printf("No.44\n");

}

void test_StringTokenizer_given_string_given_double_quote_string_1234234_should_throw_err_END_OF_STR_WITHOUT_DOUBLE_QUOTE(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
    StringObject* strO = createStringObject("\"1234234 ");
	Try{
		StringToken *newToken =(StringToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1 to be thrown. But none thrown.");
      }Catch(err){
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Error:End of string without double quote\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1,err->errorCode);
     sprintf(ErrMsg,"End of string without double quote\n");
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"         ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
      }
			printf("No.45\n");
}

void test_StringTokenizer_given_string_given_ABD1234_should_return_IdentifierToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject("ABD1234"));
		TEST_ASSERT_IDENTIFIER_TOKEN("ABD1234",0,7,"ABD1234",newToken);
		dumpToken(newToken);
			printf("No.46\n");

}

void test_StringTokenizer_given_string_given__1234_should_return_IdentifierToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject("_1234"));
		TEST_ASSERT_IDENTIFIER_TOKEN("_1234",0,5,"_1234",newToken);
		dumpToken(newToken);
			printf("No.47\n");

}

void test_StringTokenizer_given_string_given_should_return_IdentifierToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject("  A "));
		TEST_ASSERT_IDENTIFIER_TOKEN("A",2,1,"  A ",newToken);
		dumpToken(newToken);
			printf("No.48\n");
}

void test_StringTokenizer_given_string_______given_should_return_IdentifierToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject("_____"));
		TEST_ASSERT_IDENTIFIER_TOKEN("_____",0,5,"_____",newToken);
		dumpToken(newToken);
			printf("No.49\n");
}

void test_StringTokenizer_given_string_A_B_C_1_2_given_should_return_IdentifierToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject("A_B_C_1_2"));
		TEST_ASSERT_IDENTIFIER_TOKEN("A_B_C_1_2",0,9,"A_B_C_1_2",newToken);
		dumpToken(newToken);
			printf("No.50\n");
}

void test_StringTokenizer_given_string_A_ABC_symbol_given_should_return_IdentifierToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject("A_ABC&+_"));
		TEST_ASSERT_IDENTIFIER_TOKEN("A_ABC",0,5,"A_ABC&+_",newToken);
		dumpToken(newToken);
			printf("No.51\n");
}

void test_StringTokenizer_given_string_ABC_ACB_symbol_given_should_return_IdentifierToken(void){
  	StringObject *str = createStringObject("ABC\nACB");
    
		StringToken *newToken =(StringToken*) getToken(str);
		TEST_ASSERT_IDENTIFIER_TOKEN("ABC",0,3,"ABC\nACB",newToken);
		dumpToken(newToken);
    
     newToken = (StringToken*) getToken(str);
    TEST_ASSERT_IDENTIFIER_TOKEN("ACB",4,3,"ABC\nACB",newToken);
    dumpToken(newToken);
    
			printf("No.52\n");
}

void test_StringTokenizer_given_string_A12_B22_symbol_given_should_return_IdentifierToken(void){
  	StringObject *str = createStringObject("A12 B22");
    
		StringToken *newToken =(StringToken*) getToken(str);
		TEST_ASSERT_IDENTIFIER_TOKEN("A12",0,3,"A12 B22",newToken);
		dumpToken(newToken);
    
     newToken = (StringToken*) getToken(str);
    TEST_ASSERT_IDENTIFIER_TOKEN("B22",4,3,"A12 B22",newToken);
    dumpToken(newToken);
    
    OperatorToken *newToken1 = (OperatorToken*) getToken(str);
    TEST_LAST_TOKEN(newToken1);
    dumpToken(newToken1);
    newToken1 = (OperatorToken*) getToken(str);
    TEST_LAST_TOKEN(newToken1);
    dumpToken(newToken1);
			printf("No.53\n");
}

void test_StringTokenizer_given_string_A12_and_B22_given_should_return_IdentifierToken(void){
  	StringObject *str = createStringObject("A12&B22");
    
		StringToken *newToken =(StringToken*) getToken(str);
		TEST_ASSERT_IDENTIFIER_TOKEN("A12",0,3,"A12&B22",newToken);
		dumpToken(newToken);
    OperatorToken *newToken1 = (OperatorToken*) getToken(str);
    TEST_ASSERT_OPERATOR_TOKEN("&",3,1,"A12&B22",newToken1);
    dumpToken(newToken1);
     newToken = (StringToken*) getToken(str);
    TEST_ASSERT_IDENTIFIER_TOKEN("B22",4,3,"A12&B22",newToken);
    dumpToken(newToken);
			printf("No.54\n");
}

void test_StringTokenizer_given_string_A_A__symbol_given_should_return_IdentifierToken(void){

		StringToken *newToken =(StringToken*) getToken(createStringObject("A_A_"));
		TEST_ASSERT_IDENTIFIER_TOKEN("A_A_",0,4,"A_A_",newToken);
		dumpToken(newToken);
			printf("No.55\n");
}

void test_StringTokenizer_given_string__AWDC_123_doller_symbol_given_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){
	CEXCEPTION_T err;
   char buffer[256];
   char ErrMsg[256];
   StringObject* strO = createStringObject("AWDC_123$");
	Try{
		StringToken *newToken =(StringToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
	}Catch(err){
      printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
     sprintf(ErrMsg,"Expected Character is identifier, but that was unknown character'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"        ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.56\n");
}

void test_StringTokenizer_given_string_dot__symbol_given_should_return_OperatorToken(void){

		OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("."));
		TEST_ASSERT_OPERATOR_TOKEN(".",0,1,".",newToken);
		dumpToken(newToken);
			printf("No.57\n");
}
      
 void test_StringTokenizer_given_string_dot_dollar_symbol_given_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
  StringObject* strO = createStringObject(".$");
	Try{
		OperatorToken *newToken =(OperatorToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
    }Catch(err){
      printf("%s",err->errorMsg);
    // TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
     sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     
     freeError(err);
	}
	printf("No.58\n");
}

void test_TransitionForDot_given_string_given_digit_should_return_FloatingState(void){

      // printf("-----------------\n");
			// Token* newToken = malloc(sizeof(Token));
      // StringObject* str = createStringObject(".1123");
      // str->index = 1;

			// newToken->startColumn = 0;
			// TokenState currState = OperatorState;
			// TransitionForDecPointState( &newToken, &currState,str);
      // TEST_ASSERT_EQUAL(FloatingState,currState);
			printf("No.59\n");
}

void test_StringTokenizer_given_string_dot_A_symbol_given_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){
	
	OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(".A"));
	TEST_ASSERT_OPERATOR_TOKEN(".",0,1,".A",newToken);
	dumpToken(newToken);
    
    
	printf("No.60\n");
}


void test_StringTokenizer_given_string_dot_times_8_symbol_given_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){
	
	OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("........"));
		TEST_ASSERT_OPERATOR_TOKEN(".",0,1,"........",newToken);
		dumpToken(newToken);
	printf("No.61\n");
}

void test_StringTokenizer_given_string_decimal_point_001_symbol_given_should_return_FloatToken(void){
	
	FloatToken *newToken =(FloatToken*) getToken(createStringObject(".001"));
		TEST_ASSERT_FLOAT_TOKEN(.001,0,4,".001",newToken);
		dumpToken(newToken);
	printf("No.62\n");
}

void test_StringTokenizer_given_string_decimal_point_01_plus_symbol_given_should_return_FloatToken(void){
	
	FloatToken *newToken =(FloatToken*) getToken(createStringObject(".01+"));
		TEST_ASSERT_FLOAT_TOKEN(.01,0,3,".01+",newToken);
		dumpToken(newToken);
    	printf("No.63\n");

}

void test_StringTokenizer_given_string_decimal_point_01_A_given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
    StringObject* strO = createStringObject(".01A");
	Try{
    FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown.");

    }Catch(err){
     printf("%s",err->errorMsg);
   //  TEST_ASSERT_EQUAL_STRING("Can't contain any alphabet\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.64\n");
}

void test_StringTokenizer_given_string_decimal_point_01_dollar_symbol_given_should_return_FloatToken(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
  StringObject* strO = createStringObject(".01$");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
  TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
    }Catch(err){
      printf("%s",err->errorMsg);
    // TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.65\n");
}


void test_StringTokenizer_given_string_double_decimal_point_01_dollar_symbol_given_should_return_FloatToken(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
  StringObject* strO = createStringObject(".0.1");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
     TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown.");
    }Catch(err){
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain contain two of decimal point in Floating\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
  }
	printf("No.66\n");
}


void test_StringTokenizer_given_string_double_decimal_point_123_given_should_return_OperatorToken_and_FloatToken_symbol_given_should_return(void){
	
  StringObject* str = createStringObject("..123");
	OperatorToken *newToken =(OperatorToken*) getToken(str);
		TEST_ASSERT_OPERATOR_TOKEN(".",0,1,"..123",newToken);
	dumpToken(newToken);
  FloatToken *newToken1 =(FloatToken*)getToken(str);
  TEST_ASSERT_FLOAT_TOKEN(.123,1,4,"..123",newToken1);
	dumpToken(newToken1);
	printf("No.67\n");
}

void test_StringTokenizer_given_string_trible_decimal_point_123_given_should_return_OperatorToken_and_FloatToken_symbol_given_should_return(void){
	
  StringObject* str = createStringObject("...123  ");
	OperatorToken *newToken =(OperatorToken*) getToken(str);
		TEST_ASSERT_OPERATOR_TOKEN(".",0,1,"...123  ",newToken);
	dumpToken(newToken);
  newToken =(OperatorToken*) getToken(str);
	TEST_ASSERT_OPERATOR_TOKEN(".",1,1,"...123  ",newToken);
	dumpToken(newToken);
  FloatToken *newToken1 =(FloatToken*)getToken(str);
  TEST_ASSERT_FLOAT_TOKEN(.123,2,4,"...123  ",newToken1);
	dumpToken(newToken1);
	printf("No.68\n");
}

void test_StringTokenizer_given_string_dot_e123_symbol_given_should_return_OperatorToken_and_IdentifierToken(void){
	
   StringObject* str = createStringObject(".e123");
	
  OperatorToken *newToken =(OperatorToken*) getToken(str);
	TEST_ASSERT_OPERATOR_TOKEN(".",0,1,".e123",newToken);
	dumpToken(newToken);
  
	IdentifierToken *newToken1 =(IdentifierToken*) getToken(str);
	TEST_ASSERT_IDENTIFIER_TOKEN("e123",1,4,".e123",newToken1);
	dumpToken(newToken1);  
    
	printf("No.69\n");
}

void test_StringTokenizer_given_decimal_point_e1_symbol_given_should_return_FloatToken(void){
	
   StringObject* str = createStringObject(".1e1");
	FloatToken *newToken =(FloatToken*) getToken(str);
	TEST_ASSERT_FLOAT_TOKEN(.1e1,0,4,".1e1",newToken);
	dumpToken(newToken);  
    
	printf("No.70\n");
}

void test_StringTokenizer_given_decimal_point_e10_and_given_should_return_FloatToken(void){
	
   StringObject* str = createStringObject(".1e10&");
	FloatToken *newToken =(FloatToken*) getToken(str);
	TEST_ASSERT_FLOAT_TOKEN(.1e10,0,5,".1e10&",newToken);
	dumpToken(newToken);  
    
	printf("No.71\n");
}


void test_StringTokenizer_given_decimal_point_e10_and_space_given_should_return_FloatToken(void){
	
   StringObject* str = createStringObject(".1e10 ");
	FloatToken *newToken =(FloatToken*) getToken(str);
	TEST_ASSERT_FLOAT_TOKEN(.1e10,0,5,".1e10 ",newToken);
	dumpToken(newToken);  
    
	printf("No.72\n");
}


void test_StringTokenizer_given_decimal_point_e_and_space_given_should_throw_err_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
    StringObject* strO = createStringObject(".1e ");
	Try{
    FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1 to be thrown. But none thrown.");
   }Catch(err){
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Behind exponential must be a digit\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1,err->errorCode);
      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'",strO->str[strO->index]);
      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.73\n");
}

void test_StringTokenizer_given_decimal_point__1e2_given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
  
   StringObject* strO = createStringObject(".1e2A");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown.");
   }Catch(err){
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain any alphabet\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.74\n");
}

void test_StringTokenizer_given_decimal_point__1e2_doller_given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
   StringObject* strO = createStringObject(".1e2$");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
   }Catch(err){
      printf("%s",err->errorMsg);
    // TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);

     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.75\n");
}

void test_StringTokenizer_given_decimal_point_1e2_decimal_point_1234_doller_given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){
	CEXCEPTION_T err;
	  char buffer[256];
    char ErrMsg[256];
   StringObject* strO = createStringObject(".1e2.1234");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown.");
   }Catch(err){
     printf("%s",err->errorMsg);
//     TEST_ASSERT_EQUAL_STRING("Can't contain contain two of decimal point in Floating\n",err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
  freeError(err);
  }
	printf("No.76\n");
}

void test_StringTokenizer_given_decimal_point_1eminus10_and_space_given_should_return_FloatToken(void){
	
   StringObject* str = createStringObject(".1e-1");
	FloatToken *newToken =(FloatToken*) getToken(str);
	TEST_ASSERT_FLOAT_TOKEN(.1e-1,0,5,".1e-1",newToken);
	dumpToken(newToken);  
    
	printf("No.77\n");
}

void test_StringTokenizer_given_decimal_point_1eplus10_and_space_given_should_return_FloatToken(void){
	
   StringObject* str = createStringObject(".1e+1");
	FloatToken *newToken =(FloatToken*) getToken(str);
	TEST_ASSERT_FLOAT_TOKEN(.1e+1,0,5,".1e+1",newToken);
	dumpToken(newToken);  
    
	printf("No.78\n");
}

void test_StringTokenizer_given_decimal_point_1eplus1minus1234_given_should_return_FloatToken(void){
	
   StringObject* str = createStringObject(".1e+1-1234");
	FloatToken *newToken =(FloatToken*) getToken(str);
	TEST_ASSERT_FLOAT_TOKEN(.1e+1,0,5,".1e+1-1234",newToken);
	dumpToken(newToken);  
    
	printf("No.79\n");
}

void test_StringTokenizer_given_decimal_point_1eminus2_point_123_decimal_point_1234_doller_given_should_throw_err_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
    
   StringObject* strO = createStringObject(".1e-2.123");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown.");
   }Catch(err){
     printf("%s",err->errorMsg);
   //  TEST_ASSERT_EQUAL_STRING("Can't contain contain two of decimal point in Floating\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);    
    freeError(err);
  }
	printf("No.80\n");
}

void test_StringTokenizer_given_decimal_point_1eminus2__given_should_throw_err_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
   StringObject* strO = createStringObject(".1e-2_");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
   }Catch(err){
      printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
      sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);
      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.81\n");
}

void test_StringTokenizer_given_decimal_point_1eminus2ASDSA__given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){
	CEXCEPTION_T err;
   char buffer[256];
   char ErrMsg[256];
   StringObject* strO = createStringObject(".1e-2ASDSA");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown.");
   }Catch(err){
     printf("%s",err->errorMsg);
    // TEST_ASSERT_EQUAL_STRING("Can't contain any alphabet\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.82\n");
}

void test_StringTokenizer_given_1dot1124_should_return_FloatToken(void){
	
   StringObject* str = createStringObject("1123123.1124");
	FloatToken *newToken =(FloatToken*) getToken(str);
	TEST_ASSERT_FLOAT_TOKEN(1123123.1124,0,12,"1123123.1124",newToken);
	dumpToken(newToken);  
    
	printf("No.83\n");
}

void test_StringTokenizer_given_1_decimal_point_12A__given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
   StringObject* strO = createStringObject("1.12A");
  
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown.");
   }Catch(err){
     printf("%s",err->errorMsg);
    // TEST_ASSERT_EQUAL_STRING("Can't contain any alphabet\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);
      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.84\n");
}


void test_StringTokenizer_given_1e12_given_should_return_IntegerToken(void){

   StringObject* str = createStringObject("21e9");
	FloatToken *newToken =(FloatToken*) getToken(str);
	TEST_ASSERT_FLOAT_TOKEN(21e9,0,4,"21e9",newToken);
  dumpToken(newToken);  

	printf("No.85\n");
}

void test_StringTokenizer_given_09_should_throw_err_INVALID_OCTAL(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
   StringObject* strO = createStringObject("09");
    
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown.");
   }Catch(err){
     printf("%s",err->errorMsg);
    // TEST_ASSERT_EQUAL_STRING("This is invalid octal integer\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_OCTAL_1,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.86\n");
}

void test_StringTokenizer_given_0A_should_throw_err_STR_INCLURE_ALPHA(void){
	CEXCEPTION_T err;
   char buffer[256];
   char ErrMsg[256];
   StringObject* strO = createStringObject("0BSD");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown.");
   }Catch(err){
     printf("%s",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.87\n");
}


void test_StringTokenizer_given_0x12A_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0x12A");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0x12A,0,5,"0x12A",newToken);
	dumpToken(newToken);  

	
	printf("No.88\n");
}

void test_StringTokenizer_given_0X12B_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0X12B");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0X12B,0,5,"0X12B",newToken);
	dumpToken(newToken);  

	printf("No.89\n");
}

void test_StringTokenizer_given_0XA_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0XA");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0XA,0,3,"0XA",newToken);
	dumpToken(newToken);  
	
	printf("No.90\n");
}

void test_StringTokenizer_given_0XA1234space_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0XA1234 ");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0XA1234,0,7,"0XA1234 ",newToken);
	dumpToken(newToken);  
	
	printf("No.91\n");
}

void test_StringTokenizer_given_0XA1234n_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0XA1234\n");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0XA1234,0,7,"0XA1234\n",newToken);
	dumpToken(newToken);  
	
	printf("No.92\n");
}

void test_StringTokenizer_given_0XA1and_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0XA1&");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0XA1,0,4,"0XA1&",newToken);
	dumpToken(newToken);  
	
	printf("No.93\n");
}

void test_StringTokenizer_given_0XA1point_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0XA1.");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0XA1,0,4,"0XA1.",newToken);
	dumpToken(newToken);  
	
	printf("No.94\n");
}

void test_StringTokenizer_given_0XS_should_return_IntegerToken(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
  StringObject* strO = createStringObject("0XS");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("This is invalid Hexdecimal integer\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_HEX_1,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.95\n");
}

void test_StringTokenizer_given_0Xand_should_return_IntegerToken(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
  StringObject* strO = createStringObject("0X&");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("This is invalid Hexdecimal integer\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_HEX_1,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     
     freeError(err);
	}
	printf("No.96\n");
}

void test_StringTokenizer_given_0X_should_return_IntegerToken(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
  StringObject* strO = createStringObject("0X");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
    // TEST_ASSERT_EQUAL_STRING("This is invalid Hexdecimal integer\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_HEX_1,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.97\n");
}

void test_StringTokenizer_given_0Xspace_should_return_IntegerToken(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
  StringObject* strO = createStringObject("0X ");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("This is invalid Hexdecimal integer\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_HEX_1,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.98\n");
}

void test_StringTokenizer_given_0Xnewline_should_return_IntegerToken(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
  StringObject* strO = createStringObject("0X\n");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
   //  TEST_ASSERT_EQUAL_STRING("This is invalid Hexdecimal integer\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_HEX_1,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.99\n");
}



void test_StringTokenizer_given_0XADU_should_return_IntegerToken(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256]; 
  StringObject* strO = createStringObject("0XADU");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
    // TEST_ASSERT_EQUAL_STRING("Can't contain any alphabet\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.100\n");
}

void test_StringTokenizer_given_0XADdoller_should_return_IntegerToken(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256]; 
  StringObject* strO = createStringObject("0XAD$");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
	}Catch(err){
      printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.101\n");
}

void test_StringTokenizer_given_0124_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0123");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0123,0,4,"0123",newToken);
	dumpToken(newToken);  
	
	printf("No.102\n");
}

void test_StringTokenizer_given_0823_should_return_IntegerToken(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
  StringObject* strO = createStringObject("0823");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("This is invalid octal integer\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_OCTAL_1,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
  }
	printf("No.103\n");

}

void test_StringTokenizer_given_0923_should_return_IntegerToken(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
  StringObject* strO = createStringObject("0923");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
    // TEST_ASSERT_EQUAL_STRING("This is invalid octal integer\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_OCTAL_1,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
  }
	printf("No.104\n");

}
void test_StringTokenizer_given_0723_should_return_IntegerToken(void){
	CEXCEPTION_T err;
	Try{
  StringObject* str = createStringObject("0723");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0723,0,4,"0723",newToken);
  	dumpToken(newToken);  

	}Catch(err){
     printf("%s",err->errorMsg);
     TEST_ASSERT_EQUAL_STRING("This is invalid octal integer\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_OCTAL_1,err->errorCode);
     freeError(err);
  }
	printf("No.105\n");

}

void test_StringTokenizer_given_0212and_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0212&");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0212,0,4,"0212&",newToken);
	dumpToken(newToken);  
	
	printf("No.106\n");
}

void test_StringTokenizer_given_0312space_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0312 ");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0312,0,4,"0312 ",newToken);
	dumpToken(newToken);  
	
	printf("No.107\n");
}

void test_StringTokenizer_given_0412newline_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0412\n");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0412,0,4,"0412\n",newToken);
	dumpToken(newToken);  
	
	printf("No.108\n");
}


void test_StringTokenizer_given_072823_should_return_IntegerToken(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
  StringObject* strO = createStringObject("072823");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("This is invalid octal integer\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_OCTAL_1,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
  }
	printf("No.109\n");

}

void test_StringTokenizer_given_072doller23_should_return_IntegerToken(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
  StringObject* strO = createStringObject("072$23");
	Try{
	IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
      sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);
      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
  }
	printf("No.110\n");

}

void test_StringTokenizer_given_072A23_should_return_IntegerToken(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
  StringObject* strO = createStringObject("072A23");
	IntegerToken *newToken;
	Try{
    newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown.");

	}Catch(err){
     //printf("Error[%d][%d]:%s\n%s\n",__LINE__,str->index,err->errorMsg,str->str);
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain any alphabet\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);
      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
  }
	printf("No.111\n");

}

void test_StringTokenizer_given_Long_STR_should_return_IntegerToken(void){
	CEXCEPTION_T err;

  StringObject* str = createStringObject("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ");
	
  IdentifierToken* newToken0 =(IdentifierToken*)getToken(str);
	TEST_ASSERT_IDENTIFIER_TOKEN("string",0,6,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",newToken0);
  dumpToken(newToken0);  
  
  IdentifierToken* peepToken1 =(IdentifierToken*)peepToken(str);
	TEST_ASSERT_IDENTIFIER_TOKEN("string",0,6,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",peepToken1);
  dumpToken(peepToken1);  

  IntegerToken *newToken1 =(IntegerToken*) getToken(str);
   TEST_ASSERT_INTEGER_TOKEN(12342,7,5,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",newToken1);
  dumpToken(newToken1);  
  
  IntegerToken *peepToken2 =(IntegerToken*) peepToken(str);
  TEST_ASSERT_INTEGER_TOKEN(12342,7,5,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",peepToken2);
  dumpToken(peepToken2);  
  
  IdentifierToken* newToken2 =(IdentifierToken*)getToken(str);
	TEST_ASSERT_IDENTIFIER_TOKEN("ser1234",13,7,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",newToken2);
  dumpToken(newToken2);  
  
  peepToken1 =(IdentifierToken*)peepToken(str);
	TEST_ASSERT_IDENTIFIER_TOKEN("ser1234",13,7,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",peepToken1);
  dumpToken(peepToken1);  
  
  IntegerToken *newToken3 =(IntegerToken*) getToken(str);
   TEST_ASSERT_INTEGER_TOKEN(1,21,1,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",newToken3);
  dumpToken(newToken3);  
  
  peepToken2 =(IntegerToken*) peepToken(str);
  TEST_ASSERT_INTEGER_TOKEN(1,21,1,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",peepToken2);
  dumpToken(peepToken2);  
  
  
  OperatorToken *newToken4 = (OperatorToken*) getToken(str);
  TEST_ASSERT_OPERATOR_TOKEN("+",22,1,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",newToken4);
  dumpToken(newToken4);  
  
   OperatorToken *peepToken3 = (OperatorToken*) peepToken(str);
  TEST_ASSERT_OPERATOR_TOKEN("+",22,1,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",peepToken3);
  dumpToken(peepToken3);  
  
   StringToken* newToken5 =(StringToken*)getToken(str);
   TEST_ASSERT_STRING_TOKEN("\"1234\"",24,6,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",newToken5);
   dumpToken(newToken5);  

    StringToken* peepToken4 =(StringToken*)peepToken(str);
   TEST_ASSERT_STRING_TOKEN("\"1234\"",24,6,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",peepToken4);
   dumpToken(peepToken4);  
   
   FloatToken* newToken6 =(FloatToken*)getToken(str);
   TEST_ASSERT_FLOAT_TOKEN(123.32,31,6,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",newToken6);
   dumpToken(newToken6);  
   
   FloatToken* peepToken5 =(FloatToken*)peepToken(str);
   TEST_ASSERT_FLOAT_TOKEN(123.32,31,6,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",peepToken5);
   dumpToken(peepToken5);  
   
   FloatToken* newToken7 =(FloatToken*)getToken(str);
   TEST_ASSERT_FLOAT_TOKEN(.1e2,38,4,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",newToken7);
   dumpToken(newToken7); 
   
   peepToken5 =(FloatToken*)peepToken(str);
   TEST_ASSERT_FLOAT_TOKEN(.1e2,38,4,"string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ",peepToken5);
   dumpToken(peepToken5);  

   newToken4 = (OperatorToken*) getToken(str);
   TEST_LAST_TOKEN(newToken4);
   dumpToken(newToken4);  
  
   newToken4 = (OperatorToken*) peepToken(str);
   TEST_LAST_TOKEN(newToken4);
   dumpToken(newToken4);  
  
	printf("No.112\n");

}

void test_peepToken_given_0212_12342_should_return_IntegerToken(void){
   StringObject* str = createStringObject("0212 12342");
	IntegerToken *newToken =(IntegerToken*) getToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0212,0,4,"0212 12342",newToken);
	dumpToken(newToken);  
	
  IntegerToken *newToken1 =(IntegerToken*) peepToken(str);
  TEST_ASSERT_INTEGER_TOKEN(0212,0,4,"0212 12342",newToken1);
	dumpToken(newToken1); 
  
  IntegerToken *newToken2 =(IntegerToken*) peepToken(str);
   TEST_ASSERT_INTEGER_TOKEN(0212,0,4,"0212 12342",newToken2);
	dumpToken(newToken2);  
  
  newToken =(IntegerToken*) getToken(str);
  printf("newToken->type = %d\n",newToken->type);
  printf("newToken->value = %d\n",newToken->value);
  TEST_ASSERT_INTEGER_TOKEN(12342,5,5,"0212 12342",newToken);
	dumpToken(newToken);  
	
  newToken1 =(IntegerToken*) peepToken(str);
  TEST_ASSERT_INTEGER_TOKEN(12342,5,5,"0212 12342",newToken1);
	dumpToken(newToken1); 
  
  newToken2 =(IntegerToken*) peepToken(str);
   TEST_ASSERT_INTEGER_TOKEN(12342,5,5,"0212 12342",newToken2);
	dumpToken(newToken2);  
  
  
	printf("No.113\n");
  
  
}


    // char buffer[256];
    // char ErrMsg[256];
     // sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     // sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");
     // TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
void test_StringTokenizer_given_string_12A_throw_err_STR_INCLURE_ALPHA(void){
    char buffer[256];
    char ErrMsg[256];

	CEXCEPTION_T err;
   StringObject* strO = createStringObject("12A");
	Try{
		IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
		printf("No.114\n");
}	


void test_StringTokenizer_given_string_12doller_throw_err_STR_INCLURE_ALPHA(void){
    char buffer[256];
    char ErrMsg[256];
	CEXCEPTION_T err;
   StringObject* strO = createStringObject("1223$");
	Try{
		IntegerToken *newToken =(IntegerToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown.");
	}Catch(err){
     printf("%s",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
		printf("No.115\n");
}	


void test_StringTokenizer_given_string_point1emunispoint_symbol_given_should_return_FloatToken(void){
	CEXCEPTION_T err;
  char buffer[256];
  char ErrMsg[256];
  StringObject* strO = createStringObject(".1e-.");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
     TEST_FAIL_MESSAGE("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown.");
    }Catch(err){
     printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain contain two of decimal point in Floating\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING,err->errorCode);
     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);
     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");
     TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
  }
	printf("No.116\n");
}


void test_StringTokenizer_given_decimal_point_1eplus2__given_should_throw_err_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
   StringObject* strO = createStringObject(".1e&_");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
   }Catch(err){
      printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1,err->errorCode);
      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.117\n");
}

void test_StringTokenizer_given_decimal_point_1eplusA23__given_should_throw_err_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
   StringObject* strO = createStringObject(".1e+1A23");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
   }Catch(err){
      printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_CANNOT_CONTAIN_ALPHA,err->errorCode);
      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);
      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.118\n");
}

void test_StringTokenizer_given_decimal_point_1eplus123doller__given_should_throw_err_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT(void){
	CEXCEPTION_T err;
    char buffer[256];
    char ErrMsg[256];
   StringObject* strO = createStringObject(".1e+123$");
	Try{
	FloatToken *newToken =(FloatToken*) getToken(strO);
    TEST_FAIL_MESSAGE("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown.");
   }Catch(err){
      printf("%s",err->errorMsg);
     //TEST_ASSERT_EQUAL_STRING("Can't contain invalid unknown symbol\n",err->errorMsg);
     TEST_ASSERT_EQUAL(ERR_INVALID_UNKNOWN_SYMBOL,err->errorCode);
      sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);
      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"       ^");
      TEST_ASSERT_EQUAL_STRING(buffer,err->errorMsg);
     freeError(err);
	}
	printf("No.119\n");
}
