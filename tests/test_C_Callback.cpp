#include <stdio.h>
#include <string.h>
#include <gtest/gtest.h>
#include <C_Callback.h>

// Test printNumberInDec function
TEST(C_Callback, testPrintNumberInDec)
{
    char buffer[100];
    int number = 42;
    printNumberInDec(number, buffer, sizeof(buffer));
    printf("PrintNumberInDec: %s\n", buffer);
    // Add assertions to check the output
    ASSERT_STREQ(buffer, "Number: 42\n");
}

// Test printNumberInHex function
TEST(C_Callback, testPrintNumberInHex)
{
    char buffer[100];
    int number = 42;
    printNumberInHex(number, buffer, sizeof(buffer));
    printf("PrintNumberInHex: %s\n", buffer);
    // Add assertions to check the output
    ASSERT_STREQ(buffer, "Number: 0x2A\n");

}

 // Test setCallback and runCallback functions
 TEST(C_Callback, testCallbackFunctions)
 {
     char buffer[100];
     int number = 42;

     // Test when callback function is not set
     registerCallback(NULL);
     runCallback(number, buffer, sizeof(buffer));
     printf("Callback Function (NULL): %s\n", buffer);
     // Add assertions to check the output
     ASSERT_STREQ(buffer, "No callback function set\n");

     // Test when callback function is set
     registerCallback((CallbackFunction) printNumberInDec);
     runCallback(number, buffer, sizeof(buffer));
     printf("Callback Function (printNumberInDec): %s\n", buffer);
     // Add assertions to check the output
     ASSERT_STREQ(buffer, "Number: 42\n");

     // Test when callback function is set
     registerCallback((CallbackFunction)printNumberInHex);
     runCallback(number, buffer, sizeof(buffer));
     printf("Callback Function (printNumberInDec): %s\n", buffer);
     // Add assertions to check the output
     ASSERT_STREQ(buffer, "Number: 0x2A\n");
 }
