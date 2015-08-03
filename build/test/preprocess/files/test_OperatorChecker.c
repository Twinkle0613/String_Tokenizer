#include "OperatorChecker.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}





void xtest_isSingle (void){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes['(']))), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes[')']))), (((void *)0)), (_U_UINT)15, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes['[']))), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes[']']))), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes['{']))), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes['}']))), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes['@']))), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes[';']))), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes[':']))), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes['.']))), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes[',']))), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isSingle(operatorAtrributes['~']))), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isSingle(operatorAtrributes['!']))), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isSingle(operatorAtrributes['<']))), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isSingle(operatorAtrributes['+']))), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isSingle(operatorAtrributes['-']))), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

}





void xtest_isTwin (void){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isTwin(operatorAtrributes['=']))), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isTwin(operatorAtrributes['<']))), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isTwin(operatorAtrributes['>']))), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isTwin(operatorAtrributes['+']))), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isTwin(operatorAtrributes['-']))), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isTwin(operatorAtrributes['/']))), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isTwin(operatorAtrributes['&']))), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isTwin(operatorAtrributes['|']))), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwin(operatorAtrributes['(']))), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwin(operatorAtrributes['!']))), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwin(operatorAtrributes['*']))), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwin(operatorAtrributes['^']))), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwin(operatorAtrributes['%']))), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);

}



void xtest_isAssign (void){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isAssign(operatorAtrributes['<']))), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isAssign(operatorAtrributes['>']))), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isAssign(operatorAtrributes['+']))), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isAssign(operatorAtrributes['!']))), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isAssign(operatorAtrributes['*']))), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isAssign(operatorAtrributes['^']))), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isAssign(operatorAtrributes['%']))), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isAssign(operatorAtrributes['=']))), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isAssign(operatorAtrributes['(']))), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isAssign(operatorAtrributes[')']))), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isAssign(operatorAtrributes['[']))), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isAssign(operatorAtrributes[']']))), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isAssign(operatorAtrributes['{']))), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

}





void xtest_isTwinAssign (void){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isTwinAssign(operatorAtrributes['<']))), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isTwinAssign(operatorAtrributes['>']))), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwinAssign(operatorAtrributes['+']))), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwinAssign(operatorAtrributes['!']))), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwinAssign(operatorAtrributes['*']))), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwinAssign(operatorAtrributes['^']))), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwinAssign(operatorAtrributes['%']))), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwinAssign(operatorAtrributes['=']))), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwinAssign(operatorAtrributes['+']))), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwinAssign(operatorAtrributes['-']))), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwinAssign(operatorAtrributes['/']))), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwinAssign(operatorAtrributes['&']))), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isTwinAssign(operatorAtrributes['|']))), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

}

void xtest_isValidOperator(void){

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['<']))), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['>']))), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['+']))), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['-']))), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['/']))), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['&']))), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['|']))), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['!']))), (((void *)0)), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['*']))), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['^']))), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['%']))), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['=']))), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['(']))), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes[')']))), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['[']))), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes[']']))), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['{']))), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['}']))), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['@']))), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes[';']))), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes[':']))), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['.']))), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes[',']))), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isValidOperator(operatorAtrributes['~']))), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isValidOperator(operatorAtrributes['$']))), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((isValidOperator(operatorAtrributes['#']))), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

}
