#ifndef CustomAssertion_H
#define CustomAssertion_H

#include "unity.h"


#define CUSTOM_TEST_FAIL(lineNo,msg,...)                        \
        {                                                       \
         char buffer[256];                                      \
         sprintf(buffer,msg, ## __VA_ARGS__);                   \
         UNITY_TEST_FAIL(lineNo,buffer);                        \
        }
           //(x,y) = (testStr,testTokenType)
// #define TEST_ASSERT_TOKEN(testStr,testTokenType,Token)    {                       \

                                                    // }
#endif // CustomAssertion_H
