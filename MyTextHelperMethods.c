#include "myText.h"

void present(int i) {
    if (i == userPromptForDataStructure)
        printf("This program will temporariley save text input from the keyboard to a dynamic data structure and print it out to the screen in a 60 characters per line format.\nPlease choose the dynamic data structure you'd like to use (1 - buffer, 2 - linked list): ");
    else if (i == userPpromptForText) 
        printf("Enter text: ");
}