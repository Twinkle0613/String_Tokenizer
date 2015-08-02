#include "TokenError.h"
#include "TextCode.h"
#include "unity.h"
#include "Token.h"
#include "OperatorChecker.h"
#include "subFunction.h"
#include "StringTokenizer.h"






void setUp(void){}



void tearDown(void){}

void test_StringTokenizer_given_string_1_should_return_IntegerToken(void){



  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1"));

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)35); };

  dumpToken(newToken);

  printf("No.1\n");

 }

void test_StringTokenizer_given_string_1234_should_return_IntegerToken(void){



  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234"));

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)43); };

  printf("No.1\n");

 }



void test_StringTokenizer_given_string_1234space_should_return_IntegerToken(void){



  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234 "));

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234 "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)51); };

  printf("No.2\n");

 }



void test_StringTokenizer_given_string_1234endline_should_return_IntegerToken(void){



  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234\n"));

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234\n"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)59); };

  printf("No.3\n");

 }



void test_StringTokenizer_given_string_1234_0__should_return_IntegerToken(void){

  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("1234\0"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)65); };

  printf("No.4\n");

 }



void test_StringTokenizer_given_string_space_should_return_OperatorToken_that_symbol_is_money(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(" "));

  printf("newToken->symbol = %s\n",newToken->symbol);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)73); };

  printf("No.5\n");

 }





void test_StringTokenizer_given_string_1234_should_return_IntegerToken_and_return_OperatorToken(void){

  printf("No.6\n");



 StringObject *str = createStringObject("1234");



 IntegerToken *newToken1 = (IntegerToken*) getToken(str);

 printf("newToken->value = %d\n",newToken1->value);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)85); };



 OperatorToken *newToken2 = (OperatorToken*) getToken(str);

 printf("newToken->symbol = %s\n",newToken2->symbol);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken2->symbol), (((void *)0)), (_U_UINT)89); };



 OperatorToken *newToken3 =(OperatorToken*) getToken(str);

 printf("newToken->symbol = %s\n",newToken3->symbol);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken3->type)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken3->symbol), (((void *)0)), (_U_UINT)93); };



}



void test_StringTokenizer_given_string_NULL_should_throw_err_STR_CANNOT_BE_NULL(void){



  ErrorObject* err;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject(((void *)0)));

  printf("newToken->value = %d\n",newToken->value);



    if ((((newToken)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)104);;};

    UnityFail( ("Expect ERR_STR_CANNOT_BE_NULL_1 to be thrown. But none thrown."), (_U_UINT)105);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);

     UnityAssertEqualString((const char*)("Error:The String can't be a NULL\n"), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)108);

     UnityAssertEqualNumber((_U_SINT)((ERR_STR_CANNOT_BE_NULL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)123);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)127, UNITY_DISPLAY_STYLE_INT);



    sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

    sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)131);

     freeError(err);

 }

  printf("No.8\n");

}



void test_StringTokenizer_given_string_123star4_should_return_INTEGER_TOKEN(void){

  IntegerToken *newToken =(IntegerToken*) getToken(createStringObject("123*4"));

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("123*4"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)140); };

  printf("No.9\n");

}



void test_StringTokenizer_given_string_return_money(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(""));

  printf("newToken->symbol = %s\n",newToken->symbol);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)148); };

  printf("No.10\n");

}



void test_StringTokenizer_given_string_1234_4321_should_return_2_IntegerToken(void){



 StringObject *str = createStringObject("1234 4321");



    IntegerToken *newToken1 = (IntegerToken*) getToken(str);

    printf("newToken->value = %d\n",newToken1->value);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1234)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234 4321"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)158); };



    IntegerToken *newToken2 = (IntegerToken*) getToken(str);

    printf("newToken->value = %d\n",newToken2->value);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4321)), (_U_SINT)((newToken2->value)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken2->startColumn)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken2->length)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1234 4321"), (const char*)(newToken2->str), (((void *)0)), (_U_UINT)162); };



    OperatorToken *newToken3 =(OperatorToken*) getToken(str);

    printf("newToken->symbol = %s\n",newToken3->symbol);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken3->type)), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken3->symbol), (((void *)0)), (_U_UINT)166); };

  printf("No.11\n");

}



void test_StringTokenizer_given_string_123_4_214_should_return_3_IntegerToken(void){





 StringObject *str = createStringObject("123 4 214");



    IntegerToken *newToken1 = (IntegerToken*) getToken(str);

    printf("newToken->value = %d\n",newToken1->value);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("123 4 214"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)177); };



    IntegerToken *newToken2 = (IntegerToken*) getToken(str);

    printf("newToken->value = %d\n",newToken2->value);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken2->value)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken2->startColumn)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken2->length)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("123 4 214"), (const char*)(newToken2->str), (((void *)0)), (_U_UINT)181); };



        IntegerToken *newToken3 = (IntegerToken*) getToken(str);

    printf("newToken->value = %d\n",newToken3->value);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken3->type)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((214)), (_U_SINT)((newToken3->value)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken3->startColumn)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken3->length)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("123 4 214"), (const char*)(newToken3->str), (((void *)0)), (_U_UINT)185); };



    OperatorToken *newToken4 =(OperatorToken*) getToken(str);

    printf("newToken->symbol = %s\n",newToken4->symbol);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken4->type)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken4->symbol), (((void *)0)), (_U_UINT)189); };

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

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)254, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("^"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)254); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)254, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)254, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("^"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)254); };

  dumpToken(newToken);

  printf("No.17\n");

}

void test_StringTokenizer_given_string_plus_0_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+\0"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)261, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)261); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)261, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)261, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+\0"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)261); };

  dumpToken(newToken);

  printf("No.18\n");

}





void test_StringTokenizer_given_string_symbol1_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+^"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)270, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)270); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)270, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)270, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+^"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)270); };

  dumpToken(newToken);

  printf("No.19\n");

}



void test_StringTokenizer_given_string_TwinOperator_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("++"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)278, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("++"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)278); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)278, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)278, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("++"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)278); };

  dumpToken(newToken);

   printf("No.20\n");

}



void test_StringTokenizer_given_string_AssignmentOperator_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+="));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)286, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)286); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)286, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)286, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+="), (const char*)(newToken->str), (((void *)0)), (_U_UINT)286); };

  dumpToken(newToken);

  printf("No.21\n");

}





void test_StringTokenizer_given_string_TwinAssignmentOperator_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(">>="));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)295, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(">>="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)295); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)295, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)295, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(">>="), (const char*)(newToken->str), (((void *)0)), (_U_UINT)295); };

  dumpToken(newToken);

  printf("No.22\n");

}



void test_StringTokenizer_given_string_TwinAssignmentOperator_shift_assignemt_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("<<="));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)303, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("<<="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)303); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)303, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)303, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("<<="), (const char*)(newToken->str), (((void *)0)), (_U_UINT)303); };

  dumpToken(newToken);

  printf("No.23\n");

}





void test_StringTokenizer_given_string_space_AssignmentOperator_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(" +-"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)312, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)312); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)312, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)312, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(" +-"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)312); };

  dumpToken(newToken);

  printf("No.24\n");

}



void test_StringTokenizer_given_string_space_space_TwinOperator_should_return_OperatorToken(void){

  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("   ++"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)319, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("++"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)319); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)319, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)319, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("   ++"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)319); };

  dumpToken(newToken);

  printf("No.25\n");



}



void test_StringTokenizer_given_string_singleOperator_should_return_OperatorToken(void){

  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("...."));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)327, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)327); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)327, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)327, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("...."), (const char*)(newToken->str), (((void *)0)), (_U_UINT)327); };

  dumpToken(newToken);

  printf("No.26\n");



}



void test_StringTokenizer_given_string_singleOperator_paket_should_return_OperatorToken(void){

  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("(12214)"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)335, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("("), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)335); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)335, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)335, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("(12214)"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)335); };

  dumpToken(newToken);

  printf("No.27\n");



}



void test_StringTokenizer_given_string_TwinOperator_assignment_should_return_OperatorToken(void){

  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("=========="));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)343, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("=="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)343); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)343, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)343, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("=========="), (const char*)(newToken->str), (((void *)0)), (_U_UINT)343); };

  dumpToken(newToken);

  printf("No.28\n");



}



void test_StringTokenizer_given_string_plus_n_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("+\n"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)352, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)352); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)352, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)352, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+\n"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)352); };

  dumpToken(newToken);

  printf("No.29\n");

}



void test_StringTokenizer_given_string_symbol2_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("^^^^^^^^"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)360, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("^"), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)360); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)360, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)360, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("^^^^^^^^"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)360); };

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

   UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)372);;



  }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)377, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)380);

     freeError(err);

 }

   printf("No.31\n");

}



void test_StringTokenizer_given_string_TwinAssignmentOperator3_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("<<=3"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)389, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("<<="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)389); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)389, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)389, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("<<=3"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)389); };

  dumpToken(newToken);

  printf("No.32\n");

}



void test_StringTokenizer_given_string_AssignmentOperator3_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("      <=3"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)397, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("<="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)397); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)397, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)397, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("      <=3"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)397); };

  dumpToken(newToken);

  printf("No.33\n");

}

void test_StringTokenizer_given_string_Assignment_A_Assignment_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("=A="));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)404, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("="), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)404); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)404, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)404, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("=A="), (const char*)(newToken->str), (((void *)0)), (_U_UINT)404); };

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

   UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)418);;

  }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);

     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)421, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is valid character, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)424);

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

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)437);;

  }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);

     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)440, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is valid character, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)443);

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

     UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)456);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);

      UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)459, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)462);

      freeError(err);

    }

   printf("No.37\n");



}





void test_StringTokenizer_given_string_Assign_doller_should_return_OperatorToken(void){

 ErrorObject* err;

  StringObject* strO = createStringObject("=$");

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  OperatorToken *newToken =(OperatorToken*) getToken(strO);

   UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)475);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     char buffer[256];

     char ErrMsg[256];

      sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)483);

      UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)484, UNITY_DISPLAY_STYLE_INT);

      freeError(err);

 }

   printf("No.38\n");

}







void test_StringTokenizer_given_string_given_double_quote_123s_should_return_stringToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("\"123\""));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)495, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"123\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)495); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)495, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)495, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"123\""), (const char*)(newToken->str), (((void *)0)), (_U_UINT)495); };

  dumpToken(newToken);



   printf("No.39\n");

}





void test_StringTokenizer_given_string_given_double_quote_symbol_should_return_stringToken(void){



StringToken *newToken =(StringToken*) getToken(createStringObject(" \"1234567890abcdefghijklmnopqrstuvwsyz!@#$%^&*()_+|}{:?><},./';\" "));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)505, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"1234567890abcdefghijklmnopqrstuvwsyz!@#$%^&*()_+|}{:?><},./';\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)505); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)505, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((63)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)505, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(" \"1234567890abcdefghijklmnopqrstuvwsyz!@#$%^&*()_+|}{:?><},./';\" "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)505); };

  dumpToken(newToken);



   printf("No.40\n");

}





void test_StringTokenizer_given_string_given_space_double_quote_symbol_should_return_stringToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("  \"Hello    Hello\""));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)515, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"Hello    Hello\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)515); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)515, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)515, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("  \"Hello    Hello\""), (const char*)(newToken->str), (((void *)0)), (_U_UINT)515); };

  dumpToken(newToken);

   printf("No.41\n");

}



void test_StringTokenizer_given_string_given__double_quote_symbol_space_should_return_stringToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("\"%%%%%%%%%\"        "));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)523, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"%%%%%%%%%\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)523); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)523, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)523, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"%%%%%%%%%\"        "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)523); };

  dumpToken(newToken);

   printf("No.42\n");



}



void test_StringTokenizer_given_string_given_double_quote_string_1234_123_should_return_stringToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("\"1234\"123"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)532, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"1234\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)532); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)532, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)532, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"1234\"123"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)532); };

  dumpToken(newToken);

   printf("No.43\n");



}



void test_StringTokenizer_given_string_given_double_quote_string_space_should_return_stringToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject(" \"\" "));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)541, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"\""), (const char*)(newToken->name), (((void *)0)), (_U_UINT)541); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)541, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)541, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(" \"\" "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)541); };

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

    UnityFail( ("Expect ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1 to be thrown. But none thrown."), (_U_UINT)554);;

      }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_END_OF_STR_WITHOUT_DOUBLE_QUOTE_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)558, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"End of string without double quote\n");

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"         ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)561);

     freeError(err);

      }

   printf("No.45\n");

}



void test_StringTokenizer_given_string_given_ABD1234_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("ABD1234"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)570, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ABD1234"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)570); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)570, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)570, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ABD1234"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)570); };

  dumpToken(newToken);

   printf("No.46\n");



}



void test_StringTokenizer_given_string_given__1234_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("_1234"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)579, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("_1234"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)579); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)579, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)579, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("_1234"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)579); };

  dumpToken(newToken);

   printf("No.47\n");



}



void test_StringTokenizer_given_string_given_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("  A "));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)588, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)588); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)588, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)588, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("  A "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)588); };

  dumpToken(newToken);

   printf("No.48\n");

}



void test_StringTokenizer_given_string_______given_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("_____"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)596, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("_____"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)596); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)596, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)596, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("_____"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)596); };

  dumpToken(newToken);

   printf("No.49\n");

}



void test_StringTokenizer_given_string_A_B_C_1_2_given_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("A_B_C_1_2"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)604, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_B_C_1_2"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)604); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)604, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)604, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_B_C_1_2"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)604); };

  dumpToken(newToken);

   printf("No.50\n");

}



void test_StringTokenizer_given_string_A_ABC_symbol_given_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("A_ABC&+_"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)612, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_ABC"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)612); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)612, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)612, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_ABC&+_"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)612); };

  dumpToken(newToken);

   printf("No.51\n");

}



void test_StringTokenizer_given_string_ABC_ACB_symbol_given_should_return_IdentifierToken(void){

   StringObject *str = createStringObject("ABC\nACB");



  StringToken *newToken =(StringToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)621, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ABC"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)621); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)621, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)621, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ABC\nACB"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)621); };

  dumpToken(newToken);



     newToken = (StringToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)625, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ACB"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)625); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)625, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)625, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ABC\nACB"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)625); };

    dumpToken(newToken);



   printf("No.52\n");

}



void test_StringTokenizer_given_string_A12_B22_symbol_given_should_return_IdentifierToken(void){

   StringObject *str = createStringObject("A12 B22");



  StringToken *newToken =(StringToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)635, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)635); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)635, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)635, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12 B22"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)635); };

  dumpToken(newToken);



     newToken = (StringToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)639, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("B22"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)639); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)639, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)639, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12 B22"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)639); };

    dumpToken(newToken);



    OperatorToken *newToken1 = (OperatorToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)643, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken1->symbol), (((void *)0)), (_U_UINT)643); };

    dumpToken(newToken1);

    newToken1 = (OperatorToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)646, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken1->symbol), (((void *)0)), (_U_UINT)646); };

    dumpToken(newToken1);

   printf("No.53\n");

}



void test_StringTokenizer_given_string_A12_and_B22_given_should_return_IdentifierToken(void){

   StringObject *str = createStringObject("A12&B22");



  StringToken *newToken =(StringToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)655, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)655); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)655, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)655, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12&B22"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)655); };

  dumpToken(newToken);

    OperatorToken *newToken1 = (OperatorToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)658, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("&"), (const char*)(newToken1->symbol), (((void *)0)), (_U_UINT)658); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)658, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)658, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12&B22"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)658); };

    dumpToken(newToken1);

     newToken = (StringToken*) getToken(str);

    { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)661, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("B22"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)661); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)661, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)661, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A12&B22"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)661); };

    dumpToken(newToken);

   printf("No.54\n");

}



void test_StringTokenizer_given_string_A_A__symbol_given_should_return_IdentifierToken(void){



  StringToken *newToken =(StringToken*) getToken(createStringObject("A_A_"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)669, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_A_"), (const char*)(newToken->name), (((void *)0)), (_U_UINT)669); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)669, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)669, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("A_A_"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)669); };

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

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)681);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)685, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is identifier, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"        ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)688);

     freeError(err);

 }

 printf("No.56\n");

}



void test_StringTokenizer_given_string_dot__symbol_given_should_return_OperatorToken(void){



  OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("."));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)697, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)697); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)697, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)697, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->str), (((void *)0)), (_U_UINT)697); };

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

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)709);;

    }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)713, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is operator, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)716);



     freeError(err);

 }

 printf("No.58\n");

}



void test_TransitionForDot_given_string_given_digit_should_return_FloatingState(void){

   printf("No.59\n");

}



void test_StringTokenizer_given_string_dot_A_symbol_given_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){



 OperatorToken *newToken =(OperatorToken*) getToken(createStringObject(".A"));

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)740, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)740); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)740, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)740, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".A"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)740); };

 dumpToken(newToken);





 printf("No.60\n");

}





void test_StringTokenizer_given_string_dot_times_8_symbol_given_should_throw_err_STR_CANNOT_CONTAIN_INVALID_SYMBOL(void){



 OperatorToken *newToken =(OperatorToken*) getToken(createStringObject("........"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)751, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)751); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)751, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)751, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("........"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)751); };

  dumpToken(newToken);

 printf("No.61\n");

}



void test_StringTokenizer_given_string_decimal_point_001_symbol_given_should_return_FloatToken(void){



 FloatToken *newToken =(FloatToken*) getToken(createStringObject(".001"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)759, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.001) * (_UF)(0.00001f)), (_UF)((_UF).001), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)759); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)759, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)759, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".001"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)759); };

  dumpToken(newToken);

 printf("No.62\n");

}



void test_StringTokenizer_given_string_decimal_point_01_plus_symbol_given_should_return_FloatToken(void){



 FloatToken *newToken =(FloatToken*) getToken(createStringObject(".01+"));

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)767, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.01) * (_UF)(0.00001f)), (_UF)((_UF).01), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)767); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)767, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)767, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".01+"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)767); };

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)780);;



    }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)785, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)788);

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

  UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)801);;

    }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)805, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)808);

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

     UnityFail( ("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown."), (_U_UINT)822);;

    }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)826, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)829);

     freeError(err);

  }

 printf("No.66\n");

}





void test_StringTokenizer_given_string_double_decimal_point_123_given_should_return_OperatorToken_and_FloatToken_symbol_given_should_return(void){



  StringObject* str = createStringObject("..123");

 OperatorToken *newToken =(OperatorToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)840, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)840); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)840, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)840, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("..123"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)840); };

 dumpToken(newToken);

  FloatToken *newToken1 =(FloatToken*)getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)843, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.123) * (_UF)(0.00001f)), (_UF)((_UF).123), (_UF)((_UF)newToken1->value), (((void *)0)), (_U_UINT)(_U_UINT)843); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)843, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)843, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("..123"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)843); };

 dumpToken(newToken1);

 printf("No.67\n");

}



void test_StringTokenizer_given_string_trible_decimal_point_123_given_should_return_OperatorToken_and_FloatToken_symbol_given_should_return(void){



  StringObject* str = createStringObject("...123  ");

 OperatorToken *newToken =(OperatorToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)852, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)852); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)852, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)852, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("...123  "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)852); };

 dumpToken(newToken);

  newToken =(OperatorToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)855, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)855); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)855, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)855, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("...123  "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)855); };

 dumpToken(newToken);

  FloatToken *newToken1 =(FloatToken*)getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)858, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.123) * (_UF)(0.00001f)), (_UF)((_UF).123), (_UF)((_UF)newToken1->value), (((void *)0)), (_U_UINT)(_U_UINT)858); UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)858, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)858, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("...123  "), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)858); };

 dumpToken(newToken1);

 printf("No.68\n");

}



void test_StringTokenizer_given_string_dot_e123_symbol_given_should_return_OperatorToken_and_IdentifierToken(void){



   StringObject* str = createStringObject(".e123");



  OperatorToken *newToken =(OperatorToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)868, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("."), (const char*)(newToken->symbol), (((void *)0)), (_U_UINT)868); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)868, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)868, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".e123"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)868); };

 dumpToken(newToken);



 IdentifierToken *newToken1 =(IdentifierToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)872, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("e123"), (const char*)(newToken1->name), (((void *)0)), (_U_UINT)872); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)872, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)872, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".e123"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)872); };

 dumpToken(newToken1);



 printf("No.69\n");

}



void test_StringTokenizer_given_decimal_point_e1_symbol_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e1");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)882, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e1) * (_UF)(0.00001f)), (_UF)((_UF).1e1), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)882); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)882, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)882, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e1"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)882); };

 dumpToken(newToken);



 printf("No.70\n");

}



void test_StringTokenizer_given_decimal_point_e10_and_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e10&");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)892, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e10) * (_UF)(0.00001f)), (_UF)((_UF).1e10), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)892); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)892, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)892, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e10&"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)892); };

 dumpToken(newToken);



 printf("No.71\n");

}





void test_StringTokenizer_given_decimal_point_e10_and_space_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e10 ");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)903, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e10) * (_UF)(0.00001f)), (_UF)((_UF).1e10), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)903); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)903, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)903, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e10 "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)903); };

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

    UnityFail( ("Expect ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1 to be thrown. But none thrown."), (_U_UINT)917);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)921, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'",strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)924);

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)938);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)942, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)945);

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

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)958);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)962, UNITY_DISPLAY_STYLE_INT);



     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)966);

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown."), (_U_UINT)979);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



    UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)983, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)986);

  freeError(err);

  }

 printf("No.76\n");

}



void test_StringTokenizer_given_decimal_point_1eminus10_and_space_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e-1");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)996, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e-1) * (_UF)(0.00001f)), (_UF)((_UF).1e-1), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)996); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)996, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)996, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e-1"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)996); };

 dumpToken(newToken);



 printf("No.77\n");

}



void test_StringTokenizer_given_decimal_point_1eplus10_and_space_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e+1");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1006, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e+1) * (_UF)(0.00001f)), (_UF)((_UF).1e+1), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)1006); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1006, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1006, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e+1"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1006); };

 dumpToken(newToken);



 printf("No.78\n");

}



void test_StringTokenizer_given_decimal_point_1eplus1minus1234_given_should_return_FloatToken(void){



   StringObject* str = createStringObject(".1e+1-1234");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1016, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e+1) * (_UF)(0.00001f)), (_UF)((_UF).1e+1), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)1016); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1016, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1016, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)(".1e+1-1234"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1016); };

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown."), (_U_UINT)1030);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1034, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1037);

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

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1050);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1054, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1057);

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1070);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1074, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1077);

     freeError(err);

 }

 printf("No.82\n");

}



void test_StringTokenizer_given_1dot1124_should_return_FloatToken(void){



   StringObject* str = createStringObject("1123123.1124");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1087, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(1123123.1124) * (_UF)(0.00001f)), (_UF)((_UF)1123123.1124), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)1087); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1087, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1087, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("1123123.1124"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1087); };

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1101);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1105, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1108);

     freeError(err);

 }

 printf("No.84\n");

}





void test_StringTokenizer_given_1e12_given_should_return_IntegerToken(void){



   StringObject* str = createStringObject("21e9");

 FloatToken *newToken =(FloatToken*) getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1119, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(21e9) * (_UF)(0.00001f)), (_UF)((_UF)21e9), (_UF)((_UF)newToken->value), (((void *)0)), (_U_UINT)(_U_UINT)1119); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1119, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1119, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("21e9"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1119); };

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

    UnityFail( ("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown."), (_U_UINT)1133);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OCTAL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1137, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1140);

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1153);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);

     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1156, UNITY_DISPLAY_STYLE_INT);

     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1157, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1160);

     freeError(err);

 }

 printf("No.87\n");

}





void test_StringTokenizer_given_0x12A_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0x12A");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1171, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0x12A)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1171, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1171, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1171, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0x12A"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1171); };

 dumpToken(newToken);





 printf("No.88\n");

}



void test_StringTokenizer_given_0X12B_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0X12B");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1182, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0X12B)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1182, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1182, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1182, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0X12B"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1182); };

 dumpToken(newToken);



 printf("No.89\n");

}



void test_StringTokenizer_given_0XA_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0XA");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1192, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0XA)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1192, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1192, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1192, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0XA"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1192); };

 dumpToken(newToken);



 printf("No.90\n");

}



void test_StringTokenizer_given_0XA1234space_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0XA1234 ");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1202, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0XA1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1202, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1202, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1202, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0XA1234 "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1202); };

 dumpToken(newToken);



 printf("No.91\n");

}



void test_StringTokenizer_given_0XA1234n_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0XA1234\n");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1212, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0XA1234)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1212, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1212, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1212, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0XA1234\n"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1212); };

 dumpToken(newToken);



 printf("No.92\n");

}



void test_StringTokenizer_given_0XA1and_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0XA1&");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1222, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0XA1)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1222, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1222, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1222, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0XA1&"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1222); };

 dumpToken(newToken);



 printf("No.93\n");

}



void test_StringTokenizer_given_0XA1point_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0XA1.");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1232, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0XA1)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1232, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1232, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1232, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0XA1."), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1232); };

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

    UnityFail( ("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown."), (_U_UINT)1245);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_HEX_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1249, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1252);

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

    UnityFail( ("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown."), (_U_UINT)1265);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_HEX_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1269, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1272);



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

    UnityFail( ("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown."), (_U_UINT)1286);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_HEX_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1290, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1293);

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

    UnityFail( ("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown."), (_U_UINT)1306);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_HEX_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1310, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1313);

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

    UnityFail( ("Expect ERR_INVALID_HEX_1 to be thrown. But none thrown."), (_U_UINT)1326);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_HEX_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1330, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1333);

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1348);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1352, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1355);

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

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1368);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1372, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1375);

     freeError(err);

 }

 printf("No.101\n");

}



void test_StringTokenizer_given_0124_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0123");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1385, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0123)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1385, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1385, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1385, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0123"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1385); };

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

    UnityFail( ("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown."), (_U_UINT)1398);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OCTAL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1402, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1405);

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

    UnityFail( ("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown."), (_U_UINT)1419);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OCTAL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1423, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str," ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1426);

     freeError(err);

  }

 printf("No.104\n");



}

void test_StringTokenizer_given_0723_should_return_IntegerToken(void){

 ErrorObject* err;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  StringObject* str = createStringObject("0723");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1437, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0723)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1437, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1437, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1437, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0723"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1437); };

   dumpToken(newToken);



 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);

     UnityAssertEqualString((const char*)("This is invalid octal integer\n"), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1442);

     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OCTAL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1443, UNITY_DISPLAY_STYLE_INT);

     freeError(err);

  }

 printf("No.105\n");



}



void test_StringTokenizer_given_0212and_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0212&");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1454, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0212)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1454, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1454, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1454, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212&"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1454); };

 dumpToken(newToken);



 printf("No.106\n");

}



void test_StringTokenizer_given_0312space_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0312 ");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1464, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0312)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1464, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1464, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1464, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0312 "), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1464); };

 dumpToken(newToken);



 printf("No.107\n");

}



void test_StringTokenizer_given_0412newline_should_return_IntegerToken(void){



  StringObject* str = createStringObject("0412\n");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1474, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0412)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1474, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1474, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1474, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0412\n"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1474); };

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

    UnityFail( ("Expect ERR_INVALID_OCTAL_1 to be thrown. But none thrown."), (_U_UINT)1488);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_OCTAL_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1492, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit less than 8, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1495);

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

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1509);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1513, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1516);

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1531);;



 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){



     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1537, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1540);

     freeError(err);

  }

 printf("No.111\n");



}



void test_StringTokenizer_given_Long_STR_should_return_IntegerToken(void){

 ErrorObject* err;



  StringObject* str = createStringObject("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  ");



  IdentifierToken* newToken0 =(IdentifierToken*)getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken0->type)), (((void *)0)), (_U_UINT)1553, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string"), (const char*)(newToken0->name), (((void *)0)), (_U_UINT)1553); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken0->startColumn)), (((void *)0)), (_U_UINT)1553, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken0->length)), (((void *)0)), (_U_UINT)1553, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken0->str), (((void *)0)), (_U_UINT)1553); };

  dumpToken(newToken0);



  IdentifierToken* peepToken1 =(IdentifierToken*)peepToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((peepToken1->type)), (((void *)0)), (_U_UINT)1557, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string"), (const char*)(peepToken1->name), (((void *)0)), (_U_UINT)1557); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((peepToken1->startColumn)), (((void *)0)), (_U_UINT)1557, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((peepToken1->length)), (((void *)0)), (_U_UINT)1557, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken1->str), (((void *)0)), (_U_UINT)1557); };

  dumpToken(peepToken1);



  IntegerToken *newToken1 =(IntegerToken*) getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)1561, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12342)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)1561, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)1561, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)1561, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)1561); };

  dumpToken(newToken1);



  IntegerToken *peepToken2 =(IntegerToken*) peepToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((peepToken2->type)), (((void *)0)), (_U_UINT)1565, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12342)), (_U_SINT)((peepToken2->value)), (((void *)0)), (_U_UINT)1565, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((peepToken2->startColumn)), (((void *)0)), (_U_UINT)1565, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((peepToken2->length)), (((void *)0)), (_U_UINT)1565, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken2->str), (((void *)0)), (_U_UINT)1565); };

  dumpToken(peepToken2);



  IdentifierToken* newToken2 =(IdentifierToken*)getToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)1569, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ser1234"), (const char*)(newToken2->name), (((void *)0)), (_U_UINT)1569); UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((newToken2->startColumn)), (((void *)0)), (_U_UINT)1569, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((newToken2->length)), (((void *)0)), (_U_UINT)1569, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken2->str), (((void *)0)), (_U_UINT)1569); };

  dumpToken(newToken2);



  peepToken1 =(IdentifierToken*)peepToken(str);

 { UnityAssertEqualNumber((_U_SINT)((TOKEN_IDENTIFIER_TYPE)), (_U_SINT)((peepToken1->type)), (((void *)0)), (_U_UINT)1573, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("ser1234"), (const char*)(peepToken1->name), (((void *)0)), (_U_UINT)1573); UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((peepToken1->startColumn)), (((void *)0)), (_U_UINT)1573, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((peepToken1->length)), (((void *)0)), (_U_UINT)1573, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken1->str), (((void *)0)), (_U_UINT)1573); };

  dumpToken(peepToken1);



  IntegerToken *newToken3 =(IntegerToken*) getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken3->type)), (((void *)0)), (_U_UINT)1577, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken3->value)), (((void *)0)), (_U_UINT)1577, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((21)), (_U_SINT)((newToken3->startColumn)), (((void *)0)), (_U_UINT)1577, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken3->length)), (((void *)0)), (_U_UINT)1577, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken3->str), (((void *)0)), (_U_UINT)1577); };

  dumpToken(newToken3);



  peepToken2 =(IntegerToken*) peepToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((peepToken2->type)), (((void *)0)), (_U_UINT)1581, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((peepToken2->value)), (((void *)0)), (_U_UINT)1581, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((21)), (_U_SINT)((peepToken2->startColumn)), (((void *)0)), (_U_UINT)1581, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((peepToken2->length)), (((void *)0)), (_U_UINT)1581, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken2->str), (((void *)0)), (_U_UINT)1581); };

  dumpToken(peepToken2);





  OperatorToken *newToken4 = (OperatorToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken4->type)), (((void *)0)), (_U_UINT)1586, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(newToken4->symbol), (((void *)0)), (_U_UINT)1586); UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((newToken4->startColumn)), (((void *)0)), (_U_UINT)1586, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((newToken4->length)), (((void *)0)), (_U_UINT)1586, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken4->str), (((void *)0)), (_U_UINT)1586); };

  dumpToken(newToken4);



   OperatorToken *peepToken3 = (OperatorToken*) peepToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((peepToken3->type)), (((void *)0)), (_U_UINT)1590, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("+"), (const char*)(peepToken3->symbol), (((void *)0)), (_U_UINT)1590); UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((peepToken3->startColumn)), (((void *)0)), (_U_UINT)1590, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((peepToken3->length)), (((void *)0)), (_U_UINT)1590, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken3->str), (((void *)0)), (_U_UINT)1590); };

  dumpToken(peepToken3);



   StringToken* newToken5 =(StringToken*)getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((newToken5->type)), (((void *)0)), (_U_UINT)1594, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"1234\""), (const char*)(newToken5->name), (((void *)0)), (_U_UINT)1594); UnityAssertEqualNumber((_U_SINT)((24)), (_U_SINT)((newToken5->startColumn)), (((void *)0)), (_U_UINT)1594, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken5->length)), (((void *)0)), (_U_UINT)1594, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken5->str), (((void *)0)), (_U_UINT)1594); };

   dumpToken(newToken5);



    StringToken* peepToken4 =(StringToken*)peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_STRING_TYPE)), (_U_SINT)((peepToken4->type)), (((void *)0)), (_U_UINT)1598, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("\"1234\""), (const char*)(peepToken4->name), (((void *)0)), (_U_UINT)1598); UnityAssertEqualNumber((_U_SINT)((24)), (_U_SINT)((peepToken4->startColumn)), (((void *)0)), (_U_UINT)1598, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((peepToken4->length)), (((void *)0)), (_U_UINT)1598, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken4->str), (((void *)0)), (_U_UINT)1598); };

   dumpToken(peepToken4);



   FloatToken* newToken6 =(FloatToken*)getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken6->type)), (((void *)0)), (_U_UINT)1602, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(123.32) * (_UF)(0.00001f)), (_UF)((_UF)123.32), (_UF)((_UF)newToken6->value), (((void *)0)), (_U_UINT)(_U_UINT)1602); UnityAssertEqualNumber((_U_SINT)((31)), (_U_SINT)((newToken6->startColumn)), (((void *)0)), (_U_UINT)1602, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((newToken6->length)), (((void *)0)), (_U_UINT)1602, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken6->str), (((void *)0)), (_U_UINT)1602); };

   dumpToken(newToken6);



   FloatToken* peepToken5 =(FloatToken*)peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((peepToken5->type)), (((void *)0)), (_U_UINT)1606, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(123.32) * (_UF)(0.00001f)), (_UF)((_UF)123.32), (_UF)((_UF)peepToken5->value), (((void *)0)), (_U_UINT)(_U_UINT)1606); UnityAssertEqualNumber((_U_SINT)((31)), (_U_SINT)((peepToken5->startColumn)), (((void *)0)), (_U_UINT)1606, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((peepToken5->length)), (((void *)0)), (_U_UINT)1606, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken5->str), (((void *)0)), (_U_UINT)1606); };

   dumpToken(peepToken5);



   FloatToken* newToken7 =(FloatToken*)getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((newToken7->type)), (((void *)0)), (_U_UINT)1610, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e2) * (_UF)(0.00001f)), (_UF)((_UF).1e2), (_UF)((_UF)newToken7->value), (((void *)0)), (_U_UINT)(_U_UINT)1610); UnityAssertEqualNumber((_U_SINT)((38)), (_U_SINT)((newToken7->startColumn)), (((void *)0)), (_U_UINT)1610, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken7->length)), (((void *)0)), (_U_UINT)1610, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(newToken7->str), (((void *)0)), (_U_UINT)1610); };

   dumpToken(newToken7);



   peepToken5 =(FloatToken*)peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_FLOAT_TYPE)), (_U_SINT)((peepToken5->type)), (((void *)0)), (_U_UINT)1614, UNITY_DISPLAY_STYLE_INT); UnityAssertFloatsWithin((_UF)((_UF)(.1e2) * (_UF)(0.00001f)), (_UF)((_UF).1e2), (_UF)((_UF)peepToken5->value), (((void *)0)), (_U_UINT)(_U_UINT)1614); UnityAssertEqualNumber((_U_SINT)((38)), (_U_SINT)((peepToken5->startColumn)), (((void *)0)), (_U_UINT)1614, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((peepToken5->length)), (((void *)0)), (_U_UINT)1614, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("string 12342 ser1234 1+ \"1234\" 123.32 .1e2  "), (const char*)(peepToken5->str), (((void *)0)), (_U_UINT)1614); };

   dumpToken(peepToken5);



   newToken4 = (OperatorToken*) getToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken4->type)), (((void *)0)), (_U_UINT)1618, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken4->symbol), (((void *)0)), (_U_UINT)1618); };

   dumpToken(newToken4);



   newToken4 = (OperatorToken*) peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_OPERATOR_TYPE)), (_U_SINT)((newToken4->type)), (((void *)0)), (_U_UINT)1622, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("$"), (const char*)(newToken4->symbol), (((void *)0)), (_U_UINT)1622); };

   dumpToken(newToken4);



 printf("No.112\n");



}



void test_peepToken_given_0212_12342_should_return_IntegerToken(void){

   StringObject* str = createStringObject("0212 12342");

 IntegerToken *newToken =(IntegerToken*) getToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1632, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0212)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1632, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1632, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1632, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1632); };

 dumpToken(newToken);



  IntegerToken *newToken1 =(IntegerToken*) peepToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)1636, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0212)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)1636, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)1636, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)1636, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)1636); };

 dumpToken(newToken1);



  IntegerToken *newToken2 =(IntegerToken*) peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)1640, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0212)), (_U_SINT)((newToken2->value)), (((void *)0)), (_U_UINT)1640, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((newToken2->startColumn)), (((void *)0)), (_U_UINT)1640, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((newToken2->length)), (((void *)0)), (_U_UINT)1640, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken2->str), (((void *)0)), (_U_UINT)1640); };

 dumpToken(newToken2);



  newToken =(IntegerToken*) getToken(str);

  printf("newToken->type = %d\n",newToken->type);

  printf("newToken->value = %d\n",newToken->value);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken->type)), (((void *)0)), (_U_UINT)1646, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12342)), (_U_SINT)((newToken->value)), (((void *)0)), (_U_UINT)1646, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->startColumn)), (((void *)0)), (_U_UINT)1646, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken->length)), (((void *)0)), (_U_UINT)1646, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken->str), (((void *)0)), (_U_UINT)1646); };

 dumpToken(newToken);



  newToken1 =(IntegerToken*) peepToken(str);

  { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken1->type)), (((void *)0)), (_U_UINT)1650, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12342)), (_U_SINT)((newToken1->value)), (((void *)0)), (_U_UINT)1650, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken1->startColumn)), (((void *)0)), (_U_UINT)1650, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken1->length)), (((void *)0)), (_U_UINT)1650, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken1->str), (((void *)0)), (_U_UINT)1650); };

 dumpToken(newToken1);



  newToken2 =(IntegerToken*) peepToken(str);

   { UnityAssertEqualNumber((_U_SINT)((TOKEN_INTEGER_TYPE)), (_U_SINT)((newToken2->type)), (((void *)0)), (_U_UINT)1654, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((12342)), (_U_SINT)((newToken2->value)), (((void *)0)), (_U_UINT)1654, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken2->startColumn)), (((void *)0)), (_U_UINT)1654, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((newToken2->length)), (((void *)0)), (_U_UINT)1654, UNITY_DISPLAY_STYLE_INT); UnityAssertEqualString((const char*)("0212 12342"), (const char*)(newToken2->str), (((void *)0)), (_U_UINT)1654); };

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1677);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);

     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1680, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"  ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1683);

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

    UnityFail( ("Expect ERR_CANNOT_CONTAIN_ALPHA to be thrown. But none thrown."), (_U_UINT)1697);;

 }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);

     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1700, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1703);

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

     UnityFail( ("Expect ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING to be thrown. But none thrown."), (_U_UINT)1717);;

    }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

     printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_TWO_DECIMAL_POINT_IN_A_FLOATING)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1721, UNITY_DISPLAY_STYLE_INT);

     sprintf(ErrMsg,"Expected Character is digit, but that was floating point'%c'", strO->str[strO->index]);

     sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"    ^");

     UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1724);

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

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1738);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_BEHIND_EXPONENTIAL_MUST_BE_A_DIGIT_1)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1742, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"   ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1745);

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

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1758);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_CANNOT_CONTAIN_ALPHA)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1762, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was '%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"     ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1765);

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

    UnityFail( ("Expect ERR_INVALID_UNKNOWN_SYMBOL to be thrown. But none thrown."), (_U_UINT)1778);;

   }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

      printf("%s",err->errorMsg);



     UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_UNKNOWN_SYMBOL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)1782, UNITY_DISPLAY_STYLE_INT);

      sprintf(ErrMsg,"Expected Character is digit, but that was unknown character'%c'", strO->str[strO->index]);

      sprintf(buffer,"Error[%d]:%s\n%s\n%s\n",strO->index,ErrMsg,strO->str,"       ^");

      UnityAssertEqualString((const char*)(buffer), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)1785);

     freeError(err);

 }

 printf("No.119\n");

}
