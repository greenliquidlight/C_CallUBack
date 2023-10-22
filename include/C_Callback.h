#ifndef CALLBACK_DEMO_H
#define CALLBACK_DEMO_H

typedef const char* (*CallbackFunction)(int, char*, size_t);

// Simple function that prints a number to the console
void printNumberInDec(int number, char* buffer, size_t bufferSize);

// Simple function that prints a number to the console in hex
void printNumberInHex(int number, char* buffer, size_t bufferSize);

// Function that takes a function pointer as an argument and
// set the callback function to the one passed in
void setCallback(CallbackFunction callback);

#endif // CALLBACK_DEMO_H