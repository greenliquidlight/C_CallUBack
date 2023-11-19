#ifndef CALLBACK_DEMO_H
#define CALLBACK_DEMO_H

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

DLL_EXPORT void YourFunction();  // Example function declaration

#ifdef __cplusplus
extern "C" {
#endif

typedef const void (*CallbackFunction)(int, char*, size_t);

// Simple function that prints a number to the console
DLL_EXPORT CallbackFunction printNumberInDec(int number, char* buffer, size_t bufferSize);

// Simple function that prints a number to the console in hex
DLL_EXPORT CallbackFunction printNumberInHex(int number, char* buffer, size_t bufferSize);

// Function that takes a function pointer as an argument and
// set the callback function to the one passed in
DLL_EXPORT void setCallback(CallbackFunction callback);

// Run the callback function with the given number
DLL_EXPORT void runCallback(int number, char* buffer, size_t bufferSize);

#ifdef __cplusplus
} 
#endif

#endif // CALLBACK_DEMO_H
