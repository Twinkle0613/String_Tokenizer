#include "OperatorChecker.h"
#include "CException.h"
#include "subFunction.h"
#include "ErrorObject.h"
#include "TokenError.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void xtest_throwTokenizerError(void){



   ErrorObject* err;

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

       doSomething();

    }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

       printf("%s",err->errorMsg);

        freeError(err);

     }



}





void xtest_Error(void){



  printf("%*s^",2,"");





}
