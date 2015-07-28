#include "unity.h"
#include "OperatorChecker.h"

void setUp(void)
{
}

void tearDown(void)
{
}

 /***************************checkOperator_Function_Test***************************/

void xtest_isSingle (void){
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['(']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes[')']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['[']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes[']']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['{']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['}']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['@']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes[';']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes[':']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['.']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes[',']));
	TEST_ASSERT_EQUAL(1,isSingle(operatorAtrributes['~']));
	TEST_ASSERT_EQUAL(0,isSingle(operatorAtrributes['!']));
	TEST_ASSERT_EQUAL(0,isSingle(operatorAtrributes['<']));
	TEST_ASSERT_EQUAL(0,isSingle(operatorAtrributes['+']));
	TEST_ASSERT_EQUAL(0,isSingle(operatorAtrributes['-']));	
}


void xtest_isTwin (void){
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['=']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['<']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['>']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['+']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['-']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['/']));
		TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['&']));
    TEST_ASSERT_EQUAL(1,isTwin(operatorAtrributes['|']));
		TEST_ASSERT_EQUAL(0,isTwin(operatorAtrributes['(']));
		TEST_ASSERT_EQUAL(0,isTwin(operatorAtrributes['!']));
		TEST_ASSERT_EQUAL(0,isTwin(operatorAtrributes['*']));
		TEST_ASSERT_EQUAL(0,isTwin(operatorAtrributes['^']));
		TEST_ASSERT_EQUAL(0,isTwin(operatorAtrributes['%']));		
}

void xtest_isAssign (void){

		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['<']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['>']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['+']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['!']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['*']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['^']));
		TEST_ASSERT_EQUAL(1,isAssign(operatorAtrributes['%']));		
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes['=']));
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes['(']));
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes[')']));
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes['[']));
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes[']']));
		TEST_ASSERT_EQUAL(0,isAssign(operatorAtrributes['{']));
}


void xtest_isTwinAssign (void){	
		TEST_ASSERT_EQUAL(1,isTwinAssign(operatorAtrributes['<']));
		TEST_ASSERT_EQUAL(1,isTwinAssign(operatorAtrributes['>']));	
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['+']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['!']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['*']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['^']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['%']));		
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['=']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['+']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['-']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['/']));
		TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['&']));
    TEST_ASSERT_EQUAL(0,isTwinAssign(operatorAtrributes['|']));
}
void xtest_isOperator(void){
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['<']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['>']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['+']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['-']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['/']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['&']));
    TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['|']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['!']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['*']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['^']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['%']));	
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['=']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['(']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes[')']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['[']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes[']']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['{']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['}']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['@']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes[';']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes[':']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['.']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes[',']));
		TEST_ASSERT_EQUAL(1,isOperator(operatorAtrributes['~']));		
		TEST_ASSERT_EQUAL(0,isOperator(operatorAtrributes['$']));
		TEST_ASSERT_EQUAL(0,isOperator(operatorAtrributes['#']));


}