#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <C_Callback.h>

// local function pointer that will be used to call the callback function
static CallbackFunction callbackFunction = NULL;

// Print a number to a string
CallbackFunction printNumberInDec(int number, char* buffer, size_t bufferSize)
{
    snprintf(buffer, bufferSize, "Number: %d\n", number);
}

// Prints a number to a string in hex
CallbackFunction printNumberInHex(int number, char* buffer, size_t bufferSize)
{
    snprintf(buffer, bufferSize, "Number: 0x%X\n", number);
}

// Function that takes a function pointer as an argument and 
// set the callback function to the one passed in
void registerCallback(CallbackFunction callback)
{
    callbackFunction = callback;
}

void runCallback(int number, char* buffer, size_t bufferSize)
{
    if (callbackFunction != NULL)
    {
        callbackFunction(number, buffer, bufferSize);
    }
    else
    {
        snprintf(buffer, bufferSize, "No callback function set\n");
    }
}
