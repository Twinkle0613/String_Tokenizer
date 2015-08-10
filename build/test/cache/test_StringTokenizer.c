#include "CustomAssertion.h"
#include "TokenError.h"
#include "TextCode.h"
#include "unity.h"
#include "Token.h"
#include "OperatorChecker.h"
#include "StringTokenizer.h"






void setUp(void){}



void tearDown(void){}

void test_StringTokenizer_given_string_1_should_return_IntegerToken(void){



  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1"));

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)34); };

  dumpToken(newToken);

  printf("No.1\n");

}

void test_StringTokenizer_given_string_1234_should_return_IntegerToken(void){



  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234"));

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)42); };

  printf("No.1\n");

}



void test_StringTokenizer_given_string_1234space_should_return_IntegerToken(void){



  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234 "));

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234 "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)50); };

  printf("No.2\n");

}



void test_StringTokenizer_given_string_1234endline_should_return_IntegerToken(void){



  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234\n"));

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234\n"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)58); };

  printf("No.3\n");

 }



void test_StringTokenizer_given_string_1234_0__should_return_IntegerToken(void){

  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234\0"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)64); };

  printf("No.4\n");

 }



void test_StringTokenizer_given_string_space_should_return_OperatorToken_that_symbol_is_money(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(" "));

  printf("newToken->symbol = %s\n",newToken->symbol);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)72); };

  printf("No.5\n");

 }





void test_StringTokenizer_given_string_1234_should_return_IntegerToken_and_return_OperatorToken(void){





  StringObject *str = createStringObject("1234");



  IntegerToken *newToken1 = (IntegerToken*) getToken(str);

  printf("newToken->value = %d\n",newToken1->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)84); };



  OperatorToken *newToken2 = (OperatorToken*) getToken(str);

  printf("newToken->symbol = %s\n",newToken2->symbol);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken2->symbol), (((void *)0)), (_U_UINT)88); };



  OperatorToken *newToken3 =(OperatorToken*) getToken(str);

  printf("newToken->symbol = %s\n",newToken3->symbol);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken3->type)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken3->symbol), (((void *)0)), (_U_UINT)92); };

  printf("No.6\n");

}



void test_StringTokenizer_given_string_NULL_should_throw_err_STR_CANNOT_BE_NULL(void){



  ErrorObject* err;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

    IntegerToken *newToken =(IntegerToken*) getToken(createStringObject(((void *)0)));

    printf("newToken->value = %d\n",newToken->value);

    if ((((newToken)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)102);;};

  UnityFail( ("Expect ERR_STR_CANNOT_BE_NULL_1 to be thrown. But none thrown."), (_U_UINT)103);;

  }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

  printf("%s",err->errorMsg);

  UnityAssertEqualString((const char*)("Error:The String can't be a NULL\n"), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)106);

  UnityAssertEqualNumber((_U_SINT)((ERR_STR_CANNOT_BE_NULL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

  freeError(err);

 }

  printf("No.7\n");

}



void test_StringTokenizer_given_string_12A34_throw_err_STR_INCLURE_ALPHA(void){

 ErrorObject* err;

  StringObject* strO = createStringObject("12A34");

  char buffer[256];

  char ErrMsg[256];

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  IntegerToken *newToken =(IntegerToken*) getToken(strO);

  printf("newToken->value = %d\n",newToken->value);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)121);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);



    sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

    sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)129);

     freeError(err);

 }

  printf("No.8\n");

}



void test_StringTokenizer_given_string_123star4_should_return_INTEGER_TOKEN(void){

  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("123*4"));

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("123*4"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)138); };

  printf("No.9\n");

}



void test_StringTokenizer_given_string_return_money(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(""));

  printf("newToken->symbol = %s\n",newToken->symbol);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)146); };

  printf("No.10\n");

}



void test_StringTokenizer_given_string_1234_4321_should_return_2_IntegerToken(void){



 StringObject *str = createStringObject("1234 4321");



    IntegerToken *newToken1 = (IntegerToken*) getToken(str);

    printf("newToken->value = %d\n",newToken1->value);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234 4321"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)156); };



    IntegerToken *newToken2 = (IntegerToken*) getToken(str);

    printf("newToken->value = %d\n",newToken2->value);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4321)), (_U_SINT)((newToken2->value)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken2->startColumn)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken2->length)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234 4321"), (const char*)(newToken2->str), (((void *)0)), (_U_UINT)160); };



    OperatorToken *newToken3 =(OperatorToken*) getToken(str);

    printf("newToken->symbol = %s\n",newToken3->symbol);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken3->type)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken3->symbol), (((void *)0)), (_U_UINT)164); };

  printf("No.11\n");

}



void test_StringTokenizer_given_string_123_4_214_should_return_3_IntegerToken(void){





 StringObject *str = createStringObject("123 4 214");



    IntegerToken *newToken1 = (IntegerToken*) getToken(str);

    printf("newToken->value = %d\n",newToken1->value);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("123 4 214"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)175); };



    IntegerToken *newToken2 = (IntegerToken*) getToken(str);

    printf("newToken->value = %d\n",newToken2->value);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken2->value)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken2->startColumn)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken2->length)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("123 4 214"), (const char*)(newToken2->str), (((void *)0)), (_U_UINT)179); };



        IntegerToken *newToken3 = (IntegerToken*) getToken(str);

    printf("newToken->value = %d\n",newToken3->value);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken3->type)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((214)), (_U_SINT)((newToken3->value)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken3->startColumn)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken3->length)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("123 4 214"), (const char*)(newToken3->str), (((void *)0)), (_U_UINT)183); };



    OperatorToken *newToken4 =(OperatorToken*) getToken(str);

    printf("newToken->symbol = %s\n",newToken4->symbol);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken4->type)), (((void *)0)), (_U_UINT)187, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken4->symbol), (((void *)0)), (_U_UINT)187); };

  printf("No.12\n");



}

void test_TransitionForOp_given_string_symbol1_should_return_OperatorToken(void){

   printf("No.14\n");

}



void test_TransitionForOp_given_string_symbol2_should_return_OperatorToken(void){

   printf("No.15\n");

}



void test_TransitionForOp_given_string_given_invalid_symbol2_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){

   printf("No.16\n");

}





void test_StringTokenizer_given_string_symbol_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("^"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)252, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("^"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)252); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)252, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)252, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("^"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)252); };

  dumpToken(newToken);

  printf("No.17\n");

}

void test_StringTokenizer_given_string_plus_0_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+\0"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)259); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+\0"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)259); };

  dumpToken(newToken);

  printf("No.18\n");

}





void test_StringTokenizer_given_string_symbol1_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+^"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)268, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)268); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)268, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)268, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+^"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)268); };

  dumpToken(newToken);

  printf("No.19\n");

}



void test_StringTokenizer_given_string_TwinOperator_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("++"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)276, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("++"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)276); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)276, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)276, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("++"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)276); };

  dumpToken(newToken);

   printf("No.20\n");

}



void test_StringTokenizer_given_string_AssignmentOperator_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+="));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)284, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)284); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)284, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)284, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+="), (const char*)(newToken->str), (((void *)0)), (_U_UINT)284); };

  dumpToken(newToken);

  printf("No.21\n");

}





void test_StringTokenizer_given_string_TwinAssignmentOperator_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(">>="));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)293, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(">>="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)293); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)293, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)293, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(">>="), (const char*)(newToken->str), (((void *)0)), (_U_UINT)293); };

  dumpToken(newToken);

  printf("No.22\n");

}



void test_StringTokenizer_given_string_TwinAssignmentOperator_shift_assignemt_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("<<="));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)301, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("<<="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)301); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)301, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)301, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("<<="), (const char*)(newToken->str), (((void *)0)), (_U_UINT)301); };

  dumpToken(newToken);

  printf("No.23\n");

}





void test_StringTokenizer_given_string_space_AssignmentOperator_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(" +-"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)310); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(" +-"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)310); };

  dumpToken(newToken);

  printf("No.24\n");

}



void test_StringTokenizer_given_string_space_space_TwinOperator_should_return_OperatorToken(void){

  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("   ++"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)317, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("++"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)317); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)317, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)317, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("   ++"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)317); };

  dumpToken(newToken);

  printf("No.25\n");



}



void test_StringTokenizer_given_string_singleOperator_should_return_OperatorToken(void){

  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("...."));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)325, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)325); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)325, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)325, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("...."), (const char*)(newToken->str), (((void *)0)), (_U_UINT)325); };

  dumpToken(newToken);

  printf("No.26\n");



}



void test_StringTokenizer_given_string_singleOperator_paket_should_return_OperatorToken(void){

  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("(12214)"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)333, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("("), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)333); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)333, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)333, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("(12214)"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)333); };

  dumpToken(newToken);

  printf("No.27\n");



}



void test_StringTokenizer_given_string_TwinOperator_assignment_should_return_OperatorToken(void){

  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("=========="));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)341, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("=="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)341); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)341, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)341, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("=========="), (const char*)(newToken->str), (((void *)0)), (_U_UINT)341); };

  dumpToken(newToken);

  printf("No.28\n");



}



void test_StringTokenizer_given_string_plus_n_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+\n"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)350); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+\n"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)350); };

  dumpToken(newToken);

  printf("No.29\n");

}



void test_StringTokenizer_given_string_symbol2_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("^^^^^^^^"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)358, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("^"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)358); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)358, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)358, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("^^^^^^^^"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)358); };

  dumpToken(newToken);

  printf("No.30\n");

}



void test_StringTokenizer_given_string_symbol3_should_return_OperatorToken(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

 StringObject* strO = createStringObject(">>=$");

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  OperatorToken *newToken =(OperatorToken*) getToken(strO);

   UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)370);;



  }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)375, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)378);

     freeError(err);

 }

   printf("No.31\n");

}



void test_StringTokenizer_given_string_TwinAssignmentOperator3_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("<<=3"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)387, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("<<="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)387); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)387, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)387, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("<<=3"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)387); };

  dumpToken(newToken);

  printf("No.32\n");

}



void test_StringTokenizer_given_string_AssignmentOperator3_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("      <=3"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)395, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("<="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)395); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)395, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)395, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("      <=3"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)395); };

  dumpToken(newToken);

  printf("No.33\n");

}

void test_StringTokenizer_given_string_Assignment_A_Assignment_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("=A="));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)402, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)402); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)402, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)402, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("=A="), (const char*)(newToken->str), (((void *)0)), (_U_UINT)402); };

  dumpToken(newToken);

  printf("No.34\n");

}







void test_StringTokenizer_given_string_doller_plus_plus_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

  StringObject* strO = createStringObject("$++");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  OperatorToken *newToken =(OperatorToken*) getToken(strO);

   UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)416);;

  }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);

     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)419, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is valid character, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)422);

     freeError(err);

 }

  printf("No.35\n");

}



void test_StringTokenizer_given_string_unknown_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

    StringObject* strO =createStringObject("$");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  OperatorToken *newToken =(OperatorToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)435);;

  }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);

     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)438, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is valid character, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)441);

     freeError(err);

 }

  printf("No.36\n");

}



void test_StringTokenizer_given_string_Assign_Assign_doller_should_return_OperatorToken(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

    StringObject* strO =createStringObject(("==$"));

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

      OperatorToken *newToken =(OperatorToken*) getToken(strO);

     UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)454);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);

      UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)457, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)460);

      freeError(err);

    }

   printf("No.37\n");



}





void test_StringTokenizer_given_string_Assign_doller_should_return_OperatorToken(void){

 ErrorObject* err;

  StringObject* strO = createStringObject("=$");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  OperatorToken *newToken =(OperatorToken*) getToken(strO);

   UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)473);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     char buffer[256];

     char ErrMsg[256];

      sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)481);

      UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)482, UNITY_DISPLAY_STYLE_INT);

      freeError(err);

 }

   printf("No.38\n");

}







void test_StringTokenizer_given_string_given_double_quote_123s_should_return_stringToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("\"123\""));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)493, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"123\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)493); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)493, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)493, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"123\""), (const char*)(newToken->str), (((void *)0)), (_U_UINT)493); };

  dumpToken(newToken);



   printf("No.39\n");

}





void test_StringTokenizer_given_string_given_double_quote_symbol_should_return_stringToken(void){



StringToken *newToken =(StringToken*) getToken(createStringObject(" \"1234567890abcdefghijklmnopqrstuvwsyz!@#$%^&*()_+|}{:?><},./';\" "));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)503, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"1234567890abcdefghijklmnopqrstuvwsyz!@#$%^&*()_+|}{:?><},./';\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)503); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)503, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((63)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)503, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(" \"1234567890abcdefghijklmnopqrstuvwsyz!@#$%^&*()_+|}{:?><},./';\" "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)503); };

  dumpToken(newToken);



   printf("No.40\n");

}





void test_StringTokenizer_given_string_given_space_double_quote_symbol_should_return_stringToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("  \"Hello    Hello\""));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)513, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"Hello    Hello\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)513); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)513, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)513, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("  \"Hello    Hello\""), (const char*)(newToken->str), (((void *)0)), (_U_UINT)513); };

  dumpToken(newToken);

   printf("No.41\n");

}



void test_StringTokenizer_given_string_given__double_quote_symbol_space_should_return_stringToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("\"%%%%%%%%%\"        "));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)521, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"%%%%%%%%%\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)521); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)521, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)521, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"%%%%%%%%%\"        "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)521); };

  dumpToken(newToken);

   printf("No.42\n");



}



void test_StringTokenizer_given_string_given_double_quote_string_1234_123_should_return_stringToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("\"1234\"123"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)530, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"1234\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)530); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)530, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)530, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"1234\"123"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)530); };

  dumpToken(newToken);

   printf("No.43\n");



}



void test_StringTokenizer_given_string_given_double_quote_string_space_should_return_stringToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject(" \"\" "));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)539, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)539); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)539, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)539, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(" \"\" "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)539); };

  dumpToken(newToken);

   printf("No.44\n");



}



void test_StringTokenizer_given_string_given_double_quote_string_1234234_should_throw_err_END_OF_STR_WITHOUT_DOUBLE_QUOTE(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

    StringObject* strO = createStringObject("\"1234234 ");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  StringToken *newToken =(StringToken*) getToken(strO);

    UnityFail( ("Expect ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1 to be thrown. But none thrown."), (_U_UINT)552);;

      }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)556, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"End of string without double quote");

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"         ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)559);

     freeError(err);

      }

   printf("No.45\n");

}



void test_StringTokenizer_given_string_given_ABD1234_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("ABD1234"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)568, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ABD1234"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)568); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)568, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)568, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ABD1234"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)568); };

  dumpToken(newToken);

   printf("No.46\n");



}



void test_StringTokenizer_given_string_given__1234_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("_1234"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)577, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("_1234"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)577); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)577, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)577, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("_1234"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)577); };

  dumpToken(newToken);

   printf("No.47\n");



}



void test_StringTokenizer_given_string_given_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("  A "));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)586, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)586); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)586, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)586, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("  A "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)586); };

  dumpToken(newToken);

   printf("No.48\n");

}



void test_StringTokenizer_given_string_______given_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("_____"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)594, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("_____"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)594); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)594, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)594, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("_____"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)594); };

  dumpToken(newToken);

   printf("No.49\n");

}



void test_StringTokenizer_given_string_A_B_C_1_2_given_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("A_B_C_1_2"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)602, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_B_C_1_2"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)602); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)602, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)602, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_B_C_1_2"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)602); };

  dumpToken(newToken);

   printf("No.50\n");

}



void test_StringTokenizer_given_string_A_ABC_symbol_given_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("A_ABC&+_"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)610, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_ABC"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)610); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)610, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)610, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_ABC&+_"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)610); };

  dumpToken(newToken);

   printf("No.51\n");

}



void test_StringTokenizer_given_string_ABC_ACB_symbol_given_should_return_IdentifierToken(void){

   StringObject *str = createStringObject("ABC\nACB");



  StringToken *newToken =(StringToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)619, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ABC"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)619); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)619, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)619, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ABC\nACB"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)619); };

  dumpToken(newToken);



     newToken = (StringToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)623, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ACB"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)623); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)623, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)623, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ABC\nACB"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)623); };

    dumpToken(newToken);



   printf("No.52\n");

}



void test_StringTokenizer_given_string_A12_B22_symbol_given_should_return_IdentifierToken(void){

   StringObject *str = createStringObject("A12 B22");



  StringToken *newToken =(StringToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)633, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)633); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)633, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)633, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12 B22"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)633); };

  dumpToken(newToken);



     newToken = (StringToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)637, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("B22"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)637); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)637, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)637, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12 B22"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)637); };

    dumpToken(newToken);



    OperatorToken *newToken1 = (OperatorToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)641, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken1->symbol), (((void *)0)), (_U_UINT)641); };

    dumpToken(newToken1);

    newToken1 = (OperatorToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)644, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken1->symbol), (((void *)0)), (_U_UINT)644); };

    dumpToken(newToken1);

   printf("No.53\n");

}



void test_StringTokenizer_given_string_A12_and_B22_given_should_return_IdentifierToken(void){

   StringObject *str = createStringObject("A12&B22");



  StringToken *newToken =(StringToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)653, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)653); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)653, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)653, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12&B22"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)653); };

  dumpToken(newToken);

    OperatorToken *newToken1 = (OperatorToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)656, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("&"), (const char*)(newToken1->symbol), (((void *)0)), (_U_UINT)656); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)656, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)656, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12&B22"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)656); };

    dumpToken(newToken1);

     newToken = (StringToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)659, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("B22"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)659); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)659, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)659, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12&B22"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)659); };

    dumpToken(newToken);

   printf("No.54\n");

}



void test_StringTokenizer_given_string_A_A__symbol_given_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("A_A_"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)667, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_A_"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)667); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)667, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)667, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_A_"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)667); };

  dumpToken(newToken);

   printf("No.55\n");

}



void test_StringTokenizer_given_string__AWDC_123_doller_symbol_given_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){

 ErrorObject* err;

   char buffer[256];

   char ErrMsg[256];

   StringObject* strO = createStringObject("AWDC_123$");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  StringToken *newToken =(StringToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)679);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)683, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is identifier, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"        ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)686);

     freeError(err);

 }

 printf("No.56\n");

}



void test_StringTokenizer_given_string_dot__symbol_given_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("."));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)695, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)695); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)695, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)695, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->str), (((void *)0)), (_U_UINT)695); };

  dumpToken(newToken);

   printf("No.57\n");

}



 void test_StringTokenizer_given_string_dot_dollar_symbol_given_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

  StringObject* strO = createStringObject(".$");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  OperatorToken *newToken =(OperatorToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)707);;

    }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)711, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)714);



     freeError(err);

 }

 printf("No.58\n");

}



void test_TransitionForDot_given_string_given_digit_should_return_FloatingState(void){

   printf("No.59\n");

}



void test_StringTokenizer_given_string_dot_A_symbol_given_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){



 OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(".A"));

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)738, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)738); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)738, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)738, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".A"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)738); };

 dumpToken(newToken);





 printf("No.60\n");

}





void test_StringTokenizer_given_string_dot_times_8_symbol_given_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){



 OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("........"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)749, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)749); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)749, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)749, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("........"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)749); };

  dumpToken(newToken);

 printf("No.61\n");

}



void test_StringTokenizer_given_string_decimal_point_001_symbol_given_should_return_FloatToken(void){



 FloatToken *newToken =(FloatToken*) getToken(createStringObject(".001"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)757, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.001) * (_UF)(0.00001f)), (_UF)((_UF).001), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)757); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)757, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)757, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".001"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)757); };

  dumpToken(newToken);

 printf("No.62\n");

}



void test_StringTokenizer_given_string_decimal_point_01_plus_symbol_given_should_return_FloatToken(void){



 FloatToken *newToken =(FloatToken*) getToken(createStringObject(".01+"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)765, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.01) * (_UF)(0.00001f)), (_UF)((_UF).01), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)765); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)765, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)765, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".01+"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)765); };

  dumpToken(newToken);

     printf("No.63\n");



}



void test_StringTokenizer_given_string_decimal_point_01_A_given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

    StringObject* strO = createStringObject(".01A");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

    FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)778);;



    }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)783, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)786);

     freeError(err);

 }

 printf("No.64\n");

}



void test_StringTokenizer_given_string_decimal_point_01_dollar_symbol_given_should_return_FloatToken(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

  StringObject* strO = createStringObject(".01$");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

  UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)799);;

    }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)803, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)806);

     freeError(err);

 }

 printf("No.65\n");

}





void test_StringTokenizer_given_string_double_decimal_point_01_dollar_symbol_given_should_return_FloatToken(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

  StringObject* strO = createStringObject(".0.1");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

     UnityFail( ("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown."), (_U_UINT)820);;

    }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)824, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)827);

     freeError(err);

  }

 printf("No.66\n");

}





void test_StringTokenizer_given_string_double_decimal_point_123_given_should_return_OperatorToken_and_FloatToken_symbol_given_should_return(void){



  StringObject* str = createStringObject("..123");

 OperatorToken *newToken =(OperatorToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)838, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)838); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)838, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)838, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("..123"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)838); };

 dumpToken(newToken);

  FloatToken *newToken1 =(FloatToken*)getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)841, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.123) * (_UF)(0.00001f)), (_UF)((_UF).123), (_UF)((_UF)newToken1->value), (((void *)0)), (_U_UINT)(_U_UINT)841); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)841, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)841, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("..123"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)841); };

 dumpToken(newToken1);

 printf("No.67\n");

}



void test_StringTokenizer_given_string_trible_decimal_point_123_given_should_return_OperatorToken_and_FloatToken_symbol_given_should_return(void){



  StringObject* str = createStringObject("...123  ");

 OperatorToken *newToken =(OperatorToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)850, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)850); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)850, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)850, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("...123  "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)850); };

 dumpToken(newToken);

  newToken =(OperatorToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)853, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)853); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)853, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)853, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("...123  "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)853); };

 dumpToken(newToken);

  FloatToken *newToken1 =(FloatToken*)getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)856, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.123) * (_UF)(0.00001f)), (_UF)((_UF).123), (_UF)((_UF)newToken1->value), (((void *)0)), (_U_UINT)(_U_UINT)856); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)856, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)856, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("...123  "), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)856); };

 dumpToken(newToken1);

 printf("No.68\n");

}



void test_StringTokenizer_given_string_dot_e123_symbol_given_should_return_OperatorToken_and_IdentifierToken(void){



   StringObject* str = createStringObject(".e123");



  OperatorToken *newToken =(OperatorToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)866, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)866); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)866, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)866, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".e123"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)866); };

 dumpToken(newToken);



 IdentifierToken *newToken1 =(IdentifierToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)870, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("e123"), (const char*)(newToken1->name), (((void *)0)), (_U_UINT)870); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)870, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)870, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".e123"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)870); };

 dumpToken(newToken1);



 printf("No.69\n");

}



void test_StringTokenizer_given_decimal_point_e1_symbol_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e1");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)880, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e1) * (_UF)(0.00001f)), (_UF)((_UF).1e1), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)880); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)880, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)880, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e1"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)880); };

 dumpToken(newToken);



 printf("No.70\n");

}



void test_StringTokenizer_given_decimal_point_e10_and_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e10&");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)890, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e10) * (_UF)(0.00001f)), (_UF)((_UF).1e10), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)890); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)890, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)890, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e10&"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)890); };

 dumpToken(newToken);



 printf("No.71\n");

}





void test_StringTokenizer_given_decimal_point_e10_and_space_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e10 ");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)901, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e10) * (_UF)(0.00001f)), (_UF)((_UF).1e10), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)901); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)901, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)901, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e10 "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)901); };

 dumpToken(newToken);



 printf("No.72\n");

}





void test_StringTokenizer_given_decimal_point_e_and_space_given_should_throw_err_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

    StringObject* strO = createStringObject(".1e ");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

    FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1 to be thrown. But none thrown."), (_U_UINT)915);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)919, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'",strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)922);

     freeError(err);

 }

 printf("No.73\n");

}



void test_StringTokenizer_given_decimal_point__1e2_given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];



   StringObject* strO = createStringObject(".1e2A");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)936);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)940, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)943);

     freeError(err);

 }

 printf("No.74\n");

}



void test_StringTokenizer_given_decimal_point__1e2_doller_given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

   StringObject* strO = createStringObject(".1e2$");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)956);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)960, UNITY_DISPLAY_STYLE_INT);



     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)964);

     freeError(err);

 }

 printf("No.75\n");

}



void test_StringTokenizer_given_decimal_point_1e2_decimal_point_1234_doller_given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){

 ErrorObject* err;

   char buffer[256];

    char ErrMsg[256];

   StringObject* strO = createStringObject(".1e2.1234");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown."), (_U_UINT)977);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



    UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)981, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)984);

  freeError(err);

  }

 printf("No.76\n");

}



void test_StringTokenizer_given_decimal_point_1eminus10_and_space_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e-1");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)994, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e-1) * (_UF)(0.00001f)), (_UF)((_UF).1e-1), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)994); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)994, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)994, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e-1"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)994); };

 dumpToken(newToken);



 printf("No.77\n");

}



void test_StringTokenizer_given_decimal_point_1eplus10_and_space_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e+1");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1004, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e+1) * (_UF)(0.00001f)), (_UF)((_UF).1e+1), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)1004); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1004, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1004, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e+1"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1004); };

 dumpToken(newToken);



 printf("No.78\n");

}



void test_StringTokenizer_given_decimal_point_1eplus1minus1234_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e+1-1234");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1014, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e+1) * (_UF)(0.00001f)), (_UF)((_UF).1e+1), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)1014); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1014, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1014, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e+1-1234"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1014); };

 dumpToken(newToken);



 printf("No.79\n");

}



void test_StringTokenizer_given_decimal_point_1eminus2_point_123_decimal_point_1234_doller_given_should_throw_err_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];



   StringObject* strO = createStringObject(".1e-2.123");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown."), (_U_UINT)1028);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1032, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1035);

    freeError(err);

  }

 printf("No.80\n");

}



void test_StringTokenizer_given_decimal_point_1eminus2__given_should_throw_err_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

   StringObject* strO = createStringObject(".1e-2_");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1048);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1052, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1055);

     freeError(err);

 }

 printf("No.81\n");

}



void test_StringTokenizer_given_decimal_point_1eminus2ASDSA__given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){

 ErrorObject* err;

   char buffer[256];

   char ErrMsg[256];

   StringObject* strO = createStringObject(".1e-2ASDSA");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1068);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1072, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1075);

     freeError(err);

 }

 printf("No.82\n");

}



void test_StringTokenizer_given_1dot1124_should_return_FloatToken(void){



   StringObject* str = createStringObject("1123123.1124");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1085, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(1123123.1124) * (_UF)(0.00001f)), (_UF)((_UF)1123123.1124), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)1085); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1085, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1085, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1123123.1124"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1085); };

 dumpToken(newToken);



 printf("No.83\n");

}



void test_StringTokenizer_given_1_decimal_point_12A__given_should_throw_err_INTEGER_CANNOT_CONTAIN_ALPHA(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

   StringObject* strO = createStringObject("1.12A");



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1099);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1103, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1106);

     freeError(err);

 }

 printf("No.84\n");

}





void test_StringTokenizer_given_1e12_given_should_return_IntegerToken(void){



   StringObject* str = createStringObject("21e9");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1117, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(21e9) * (_UF)(0.00001f)), (_UF)((_UF)21e9), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)1117); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1117, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1117, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("21e9"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1117); };

  dumpToken(newToken);



 printf("No.85\n");

}



void test_StringTokenizer_given_09_should_throw_err_INVALID_OCTAL(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

   StringObject* strO = createStringObject("09");



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown."), (_U_UINT)1131);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OCTAL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1135, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1138);

     freeError(err);

 }

 printf("No.86\n");

}



void test_StringTokenizer_given_0A_should_throw_err_STR_INCLURE_ALPHA(void){

 ErrorObject* err;

   char buffer[256];

   char ErrMsg[256];

   StringObject* strO = createStringObject("0BSD");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1151);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);

     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1154, UNITY_DISPLAY_STYLE_INT);

     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1155, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1158);

     freeError(err);

 }

 printf("No.87\n");

}





void test_StringTokenizer_given_0x12A_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0x12A");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1169, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0x12A)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1169, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1169, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1169, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0x12A"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1169); };

 dumpToken(newToken);





 printf("No.88\n");

}



void test_StringTokenizer_given_0X12B_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0X12B");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1180, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0X12B)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1180, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1180, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1180, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0X12B"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1180); };

 dumpToken(newToken);



 printf("No.89\n");

}



void test_StringTokenizer_given_0XA_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0XA");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1190, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0XA)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1190, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1190, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1190, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0XA"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1190); };

 dumpToken(newToken);



 printf("No.90\n");

}



void test_StringTokenizer_given_0XA1234space_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0XA1234 ");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1200, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0XA1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1200, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1200, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1200, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0XA1234 "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1200); };

 dumpToken(newToken);



 printf("No.91\n");

}



void test_StringTokenizer_given_0XA1234n_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0XA1234\n");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1210, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0XA1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1210, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1210, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1210, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0XA1234\n"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1210); };

 dumpToken(newToken);



 printf("No.92\n");

}



void test_StringTokenizer_given_0XA1and_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0XA1&");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1220, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0XA1)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1220, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1220, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1220, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0XA1&"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1220); };

 dumpToken(newToken);



 printf("No.93\n");

}



void test_StringTokenizer_given_0XA1point_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0XA1.");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1230, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0XA1)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1230, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1230, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1230, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0XA1."), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1230); };

 dumpToken(newToken);



 printf("No.94\n");

}



void test_StringTokenizer_given_0XS_should_return_IntegerToken(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

  StringObject* strO = createStringObject("0XS");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown."), (_U_UINT)1243);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_HEX_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1247, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1250);

     freeError(err);

 }

 printf("No.95\n");

}



void test_StringTokenizer_given_0Xand_should_return_IntegerToken(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

  StringObject* strO = createStringObject("0X&");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown."), (_U_UINT)1263);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_HEX_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1267, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1270);



     freeError(err);

 }

 printf("No.96\n");

}



void test_StringTokenizer_given_0X_should_return_IntegerToken(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

  StringObject* strO = createStringObject("0X");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown."), (_U_UINT)1284);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_HEX_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1288, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1291);

     freeError(err);

 }

 printf("No.97\n");

}



void test_StringTokenizer_given_0Xspace_should_return_IntegerToken(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

  StringObject* strO = createStringObject("0X ");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown."), (_U_UINT)1304);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_HEX_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1308, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1311);

     freeError(err);

 }

 printf("No.98\n");

}



void test_StringTokenizer_given_0Xnewline_should_return_IntegerToken(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

  StringObject* strO = createStringObject("0X\n");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown."), (_U_UINT)1324);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_HEX_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1328, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1331);

     freeError(err);

 }

 printf("No.99\n");

}







void test_StringTokenizer_given_0XADU_should_return_IntegerToken(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

  StringObject* strO = createStringObject("0XADU");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1346);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1350, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1353);

     freeError(err);

 }

 printf("No.100\n");

}



void test_StringTokenizer_given_0XADdoller_should_return_IntegerToken(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

  StringObject* strO = createStringObject("0XAD$");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1366);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1370, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1373);

     freeError(err);

 }

 printf("No.101\n");

}



void test_StringTokenizer_given_0124_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0123");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1383, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0123)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1383, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1383, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1383, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0123"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1383); };

 dumpToken(newToken);



 printf("No.102\n");

}



void test_StringTokenizer_given_0823_should_return_IntegerToken(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

  StringObject* strO = createStringObject("0823");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown."), (_U_UINT)1396);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OCTAL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1400, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1403);

     freeError(err);

  }

 printf("No.103\n");



}



void test_StringTokenizer_given_0923_should_return_IntegerToken(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

  StringObject* strO = createStringObject("0923");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown."), (_U_UINT)1417);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OCTAL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1421, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1424);

     freeError(err);

  }

 printf("No.104\n");



}

void test_StringTokenizer_given_0723_should_return_IntegerToken(void){

 ErrorObject* err;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  StringObject* str = createStringObject("0723");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1435, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0723)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1435, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1435, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1435, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0723"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1435); };

   dumpToken(newToken);



 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);

     UnityAssertEqualString((const char*)("This is invalid octal integer\n"), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1440);

     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OCTAL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1441, UNITY_DISPLAY_STYLE_INT);

     freeError(err);

  }

 printf("No.105\n");



}



void test_StringTokenizer_given_0212and_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0212&");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1452, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0212)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1452, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1452, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1452, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212&"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1452); };

 dumpToken(newToken);



 printf("No.106\n");

}



void test_StringTokenizer_given_0312space_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0312 ");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1462, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0312)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1462, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1462, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1462, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0312 "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1462); };

 dumpToken(newToken);



 printf("No.107\n");

}



void test_StringTokenizer_given_0412newline_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0412\n");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1472, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0412)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1472, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1472, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1472, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0412\n"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1472); };

 dumpToken(newToken);



 printf("No.108\n");

}





void test_StringTokenizer_given_072823_should_return_IntegerToken(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

  StringObject* strO = createStringObject("072823");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown."), (_U_UINT)1486);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OCTAL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1490, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1493);

     freeError(err);

  }

 printf("No.109\n");



}



void test_StringTokenizer_given_072doller23_should_return_IntegerToken(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

  StringObject* strO = createStringObject("072$23");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1507);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1511, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1514);

     freeError(err);

  }

 printf("No.110\n");



}



void test_StringTokenizer_given_072A23_should_return_IntegerToken(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

  StringObject* strO = createStringObject("072A23");

 IntegerToken *newToken;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

    newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1529);;



 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){



     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1535, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1538);

     freeError(err);

  }

 printf("No.111\n");



}



void test_StringTokenizer_given_Long_STR_should_return_IntegerToken(void){

 ErrorObject* err;



  StringObject* str = createStringObject("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ");



  IdentifierToken* newToken0 =(IdentifierToken*)getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken0->type)), (((void *)0)), (_U_UINT)1551, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string"), (const char*)(newToken0->name), (((void *)0)), (_U_UINT)1551); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken0->startColumn)), (((void *)0)), (_U_UINT)1551, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken0->length)), (((void *)0)), (_U_UINT)1551, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken0->str), (((void *)0)), (_U_UINT)1551); };

  dumpToken(newToken0);



  IdentifierToken* peepToken1 =(IdentifierToken*)peepToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((peepToken1->type)), (((void *)0)), (_U_UINT)1555, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string"), (const char*)(peepToken1->name), (((void *)0)), (_U_UINT)1555); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((peepToken1->startColumn)), (((void *)0)), (_U_UINT)1555, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((peepToken1->length)), (((void *)0)), (_U_UINT)1555, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken1->str), (((void *)0)), (_U_UINT)1555); };

  dumpToken(peepToken1);



  IntegerToken *newToken1 =(IntegerToken*) getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)1559, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12342)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)1559, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)1559, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)1559, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)1559); };

  dumpToken(newToken1);



  IntegerToken *peepToken2 =(IntegerToken*) peepToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((peepToken2->type)), (((void *)0)), (_U_UINT)1563, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12342)), (_U_SINT)((peepToken2->value)), (((void *)0)), (_U_UINT)1563, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((peepToken2->startColumn)), (((void *)0)), (_U_UINT)1563, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((peepToken2->length)), (((void *)0)), (_U_UINT)1563, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken2->str), (((void *)0)), (_U_UINT)1563); };

  dumpToken(peepToken2);



  IdentifierToken* newToken2 =(IdentifierToken*)getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)1567, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ser1234"), (const char*)(newToken2->name), (((void *)0)), (_U_UINT)1567); UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((newToken2->startColumn)), (((void *)0)), (_U_UINT)1567, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((newToken2->length)), (((void *)0)), (_U_UINT)1567, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken2->str), (((void *)0)), (_U_UINT)1567); };

  dumpToken(newToken2);



  peepToken1 =(IdentifierToken*)peepToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((peepToken1->type)), (((void *)0)), (_U_UINT)1571, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ser1234"), (const char*)(peepToken1->name), (((void *)0)), (_U_UINT)1571); UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((peepToken1->startColumn)), (((void *)0)), (_U_UINT)1571, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((peepToken1->length)), (((void *)0)), (_U_UINT)1571, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken1->str), (((void *)0)), (_U_UINT)1571); };

  dumpToken(peepToken1);



  IntegerToken *newToken3 =(IntegerToken*) getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken3->type)), (((void *)0)), (_U_UINT)1575, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken3->value)), (((void *)0)), (_U_UINT)1575, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((21)), (_U_SINT)((newToken3->startColumn)), (((void *)0)), (_U_UINT)1575, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken3->length)), (((void *)0)), (_U_UINT)1575, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken3->str), (((void *)0)), (_U_UINT)1575); };

  dumpToken(newToken3);



  peepToken2 =(IntegerToken*) peepToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((peepToken2->type)), (((void *)0)), (_U_UINT)1579, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((peepToken2->value)), (((void *)0)), (_U_UINT)1579, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((21)), (_U_SINT)((peepToken2->startColumn)), (((void *)0)), (_U_UINT)1579, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((peepToken2->length)), (((void *)0)), (_U_UINT)1579, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken2->str), (((void *)0)), (_U_UINT)1579); };

  dumpToken(peepToken2);





  OperatorToken *newToken4 = (OperatorToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken4->type)), (((void *)0)), (_U_UINT)1584, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(newToken4->symbol), (((void *)0)), (_U_UINT)1584); UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((newToken4->startColumn)), (((void *)0)), (_U_UINT)1584, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken4->length)), (((void *)0)), (_U_UINT)1584, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken4->str), (((void *)0)), (_U_UINT)1584); };

  dumpToken(newToken4);



   OperatorToken *peepToken3 = (OperatorToken*) peepToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((peepToken3->type)), (((void *)0)), (_U_UINT)1588, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(peepToken3->symbol), (((void *)0)), (_U_UINT)1588); UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((peepToken3->startColumn)), (((void *)0)), (_U_UINT)1588, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((peepToken3->length)), (((void *)0)), (_U_UINT)1588, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken3->str), (((void *)0)), (_U_UINT)1588); };

  dumpToken(peepToken3);



   StringToken* newToken5 =(StringToken*)getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken5->type)), (((void *)0)), (_U_UINT)1592, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"1234\""), (const char*)(newToken5->name), (((void *)0)), (_U_UINT)1592); UnityAssertEqualNumber((_U_SINT)((24)), (_U_SINT)((newToken5->startColumn)), (((void *)0)), (_U_UINT)1592, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken5->length)), (((void *)0)), (_U_UINT)1592, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken5->str), (((void *)0)), (_U_UINT)1592); };

   dumpToken(newToken5);



    StringToken* peepToken4 =(StringToken*)peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((peepToken4->type)), (((void *)0)), (_U_UINT)1596, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"1234\""), (const char*)(peepToken4->name), (((void *)0)), (_U_UINT)1596); UnityAssertEqualNumber((_U_SINT)((24)), (_U_SINT)((peepToken4->startColumn)), (((void *)0)), (_U_UINT)1596, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((peepToken4->length)), (((void *)0)), (_U_UINT)1596, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken4->str), (((void *)0)), (_U_UINT)1596); };

   dumpToken(peepToken4);



   FloatToken* newToken6 =(FloatToken*)getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken6->type)), (((void *)0)), (_U_UINT)1600, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(123.32) * (_UF)(0.00001f)), (_UF)((_UF)123.32), (_UF)((_UF)newToken6->value), (((void *)0)), (_U_UINT)(_U_UINT)1600); UnityAssertEqualNumber((_U_SINT)((31)), (_U_SINT)((newToken6->startColumn)), (((void *)0)), (_U_UINT)1600, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken6->length)), (((void *)0)), (_U_UINT)1600, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken6->str), (((void *)0)), (_U_UINT)1600); };

   dumpToken(newToken6);



   FloatToken* peepToken5 =(FloatToken*)peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((peepToken5->type)), (((void *)0)), (_U_UINT)1604, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(123.32) * (_UF)(0.00001f)), (_UF)((_UF)123.32), (_UF)((_UF)peepToken5->value), (((void *)0)), (_U_UINT)(_U_UINT)1604); UnityAssertEqualNumber((_U_SINT)((31)), (_U_SINT)((peepToken5->startColumn)), (((void *)0)), (_U_UINT)1604, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((peepToken5->length)), (((void *)0)), (_U_UINT)1604, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken5->str), (((void *)0)), (_U_UINT)1604); };

   dumpToken(peepToken5);



   FloatToken* newToken7 =(FloatToken*)getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken7->type)), (((void *)0)), (_U_UINT)1608, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e2) * (_UF)(0.00001f)), (_UF)((_UF).1e2), (_UF)((_UF)newToken7->value), (((void *)0)), (_U_UINT)(_U_UINT)1608); UnityAssertEqualNumber((_U_SINT)((38)), (_U_SINT)((newToken7->startColumn)), (((void *)0)), (_U_UINT)1608, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken7->length)), (((void *)0)), (_U_UINT)1608, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken7->str), (((void *)0)), (_U_UINT)1608); };

   dumpToken(newToken7);



   peepToken5 =(FloatToken*)peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((peepToken5->type)), (((void *)0)), (_U_UINT)1612, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e2) * (_UF)(0.00001f)), (_UF)((_UF).1e2), (_UF)((_UF)peepToken5->value), (((void *)0)), (_U_UINT)(_U_UINT)1612); UnityAssertEqualNumber((_U_SINT)((38)), (_U_SINT)((peepToken5->startColumn)), (((void *)0)), (_U_UINT)1612, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((peepToken5->length)), (((void *)0)), (_U_UINT)1612, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken5->str), (((void *)0)), (_U_UINT)1612); };

   dumpToken(peepToken5);



   newToken4 = (OperatorToken*) getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken4->type)), (((void *)0)), (_U_UINT)1616, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken4->symbol), (((void *)0)), (_U_UINT)1616); };

   dumpToken(newToken4);



   newToken4 = (OperatorToken*) peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken4->type)), (((void *)0)), (_U_UINT)1620, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken4->symbol), (((void *)0)), (_U_UINT)1620); };

   dumpToken(newToken4);



 printf("No.112\n");



}



void test_peepToken_given_0212_12342_should_return_IntegerToken(void){

   StringObject* str = createStringObject("0212 12342");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1630, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0212)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1630, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1630, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1630, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1630); };

 dumpToken(newToken);



  IntegerToken *newToken1 =(IntegerToken*) peepToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)1634, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0212)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)1634, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)1634, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)1634, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)1634); };

 dumpToken(newToken1);



  IntegerToken *newToken2 =(IntegerToken*) peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)1638, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0212)), (_U_SINT)((newToken2->value)), (((void *)0)), (_U_UINT)1638, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken2->startColumn)), (((void *)0)), (_U_UINT)1638, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken2->length)), (((void *)0)), (_U_UINT)1638, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken2->str), (((void *)0)), (_U_UINT)1638); };

 dumpToken(newToken2);



  newToken =(IntegerToken*) getToken(str);

  printf("newToken->type = %d\n",newToken->type);

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1644, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12342)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1644, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1644, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1644, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1644); };

 dumpToken(newToken);



  newToken1 =(IntegerToken*) peepToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)1648, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12342)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)1648, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)1648, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)1648, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)1648); };

 dumpToken(newToken1);



  newToken2 =(IntegerToken*) peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)1652, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12342)), (_U_SINT)((newToken2->value)), (((void *)0)), (_U_UINT)1652, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken2->startColumn)), (((void *)0)), (_U_UINT)1652, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken2->length)), (((void *)0)), (_U_UINT)1652, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken2->str), (((void *)0)), (_U_UINT)1652); };

 dumpToken(newToken2);





 printf("No.113\n");





}















void test_StringTokenizer_given_string_12A_throw_err_STR_INCLURE_ALPHA(void){

    char buffer[256];

    char ErrMsg[256];



 ErrorObject* err;

   StringObject* strO = createStringObject("12A");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1675);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);

     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1678, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1681);

     freeError(err);

 }

  printf("No.114\n");

}





void test_StringTokenizer_given_string_12doller_throw_err_STR_INCLURE_ALPHA(void){

    char buffer[256];

    char ErrMsg[256];

 ErrorObject* err;

   StringObject* strO = createStringObject("1223$");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  IntegerToken *newToken =(IntegerToken*) getToken(strO);

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1695);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);

     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1698, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1701);

     freeError(err);

 }

  printf("No.115\n");

}





void test_StringTokenizer_given_string_point1emunispoint_symbol_given_should_return_FloatToken(void){

 ErrorObject* err;

  char buffer[256];

  char ErrMsg[256];

  StringObject* strO = createStringObject(".1e-.");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

     UnityFail( ("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown."), (_U_UINT)1715);;

    }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1719, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1722);

     freeError(err);

  }

 printf("No.116\n");

}





void test_StringTokenizer_given_decimal_point_1eplus2__given_should_throw_err_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

   StringObject* strO = createStringObject(".1e&_");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1736);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1740, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1743);

     freeError(err);

 }

 printf("No.117\n");

}



void test_StringTokenizer_given_decimal_point_1eplusA23__given_should_throw_err_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

   StringObject* strO = createStringObject(".1e+1A23");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1756);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1760, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1763);

     freeError(err);

 }

 printf("No.118\n");

}



void test_StringTokenizer_given_decimal_point_1eplus123doller__given_should_throw_err_INTEGER_CANNOT_CONTAIN_SECOND_DECIMAL_POINT(void){

 ErrorObject* err;

    char buffer[256];

    char ErrMsg[256];

   StringObject* strO = createStringObject(".1e+123$");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

 FloatToken *newToken =(FloatToken*) getToken(strO);

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1776);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1780, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"       ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1783);

     freeError(err);

 }

 printf("No.119\n");

}





void test_StringTokenizer_given_234_should_return_IntegerToken(void){

  StringObject* str = createStringObject("234");

  IntegerToken *newToken =(IntegerToken*) getToken(str);

  testAsserEqualIntegerToken(234,newToken,1793);

  dumpToken(newToken);

  printf("No.120\n");

}





void test_StringTokenizer_given_0XA34_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0XA34");

  IntegerToken *newToken =(IntegerToken*) getToken(str);

  testAsserEqualIntegerToken(0XA34,newToken,1802);

  dumpToken(newToken);

  printf("No.121\n");

}



void test_StringTokenizer_given_0777_should_return_IntegerToken(void){

  StringObject* str = createStringObject("0777");

  IntegerToken *newToken =(IntegerToken*) getToken(str);

  testAsserEqualIntegerToken(0777,newToken,1810);

  dumpToken(newToken);

  printf("No.122\n");

}





void test_StringTokenizer_given_1e7_should_return_IntegerToken(void){

  StringObject* str = createStringObject("1e7");

  FloatToken *newToken =(FloatToken*) getToken(str);

  testAsserEqualFloatToken(1e7,newToken,1819);

  dumpToken(newToken);

  printf("No.123\n");

}



void test_StringTokenizer_given_1dot78_should_return_IntegerToken(void){

  StringObject* str = createStringObject("1.78");

  FloatToken *newToken =(FloatToken*) getToken(str);

  testAsserEqualFloatToken(1.78,newToken,1827);

  dumpToken(newToken);

  printf("No.124\n");

}



void test_StringTokenizer_given_1dot7e3_should_return_IntegerToken(void){

  StringObject* str = createStringObject("1.7e3");

  FloatToken *newToken =(FloatToken*) getToken(str);

  testAsserEqualFloatToken(1.7e3,newToken,1835);

  dumpToken(newToken);

  printf("No.125\n");

}



void test_StringTokenizer_given_string_A12_B22_given_should_return_IdentifierToken(void){

  StringObject *str = createStringObject("A12 B22");

  StringToken *newToken =(StringToken*) getToken(str);

  testAsserEqualIdentifierToken("A12",newToken,1843);

  dumpToken(newToken);

  newToken = (StringToken*) getToken(str);

  testAsserEqualIdentifierToken("B22",newToken,1846);

  dumpToken(newToken);

  printf("No.126\n");

}



void test_StringTokenizer_given_string_given_double_quote_123sAV_should_return_stringToken(void){

  StringToken *newToken =(StringToken*) getToken(createStringObject("\"123sAV+\"+  ABCS"));

  testAsserEqualStringToken("\"123sAV+\"",newToken,1853);

  dumpToken(newToken);

 printf("No.127\n");

}
