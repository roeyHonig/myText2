#include "myText.h"

void present(int i) {
    if (i == userPromptForDataStructure)
        printf("This program will temporariley save text input from the keyboard to a dynamic data structure and print it out to the screen in a 60 characters per line format.\nPlease choose the dynamic data structure you'd like to use (1 - buffer, 2 - linked list): ");
    else if (i == userPpromptForText) 
        printf("Enter text: ");
}

int readText(int dataStructureType, void *dataStructure) {
    if (dataStructureType == buffer) {
        // init the appropriate data structure
        present(userPpromptForText);
        char *roeyBuffer = (char*)dataStructure;
        char ch;
        int j = 1;
        while (1) {
            int i = 0;
            do 
            {
                ch = getchar();
                if (ch == EOF) 
                    goto endOfFunction;
                if (ch != '\n') {
                    *(roeyBuffer + i + (j-1)*bufferbyteSize) = ch;
                    i++;
                }
            } while(i < bufferbyteSize); 
            j++;
            roeyBuffer = (char *)realloc(roeyBuffer, bufferbyteSize * j);
            if (roeyBuffer == NULL)
                return errorCodeMemoryReallocationFailed;
        }
    } else if (dataStructureType == linkedList) {
        
    } else {
        return errorCodeUnknownDataStructure;
    }
    endOfFunction: 
    return 0;
}

void printText(int dataStructureType, void *dataStructure) {
    char *roeyBuffer = (char*)dataStructure;
    if (dataStructureType == buffer) {
        printf("\nString = %s", roeyBuffer);
    } else if (dataStructureType == linkedList) {
        
    } 
    return;
}