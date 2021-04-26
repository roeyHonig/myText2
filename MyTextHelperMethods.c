#include "myText.h"

void present(int i) {
    if (i == userPromptForDataStructure)
        printf("This program will temporariley save text input from the keyboard to a dynamic data structure and print it out to the screen in a 60 characters per line format.\nPlease choose the dynamic data structure you'd like to use (1 - buffer, 2 - linked list): ");
    else if (i == userPpromptForText) 
        printf("Enter text: ");
}

int readText(int dataStructureType, void *dataStructure) {
    if (dataStructureType == buffer) {
        struct bufferDataStructure *bufferDS = (struct bufferDataStructure*)dataStructure;
        present(userPpromptForText);
        char ch;
        while (1) {
            int i = 0;
            do 
            {
                ch = getchar();
                if (ch == EOF) 
                    goto endOfFunction;
                if (ch != '\n') {                    
                    *(bufferDS->currentBuffer + i + ((bufferDS->numOfReallocation) * (bufferDS->incrementBufferSizeInBytes))) = ch;
                    
                    i++;
                }
            } while(i < bufferbyteSize); 
            (bufferDS->numOfReallocation)++;
            bufferDS->currentBuffer = (char *)realloc(bufferDS->currentBuffer, bufferDS->incrementBufferSizeInBytes * (bufferDS->numOfReallocation + 1));
            if (bufferDS->currentBuffer == NULL)
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
    if (dataStructureType == buffer) {
        struct bufferDataStructure *bufferDS = (struct bufferDataStructure*)dataStructure;
        printf("\nString = %s", bufferDS->currentBuffer);
        printf("\nnumOfReallocation = %d", bufferDS->numOfReallocation);
    } else if (dataStructureType == linkedList) {
        
    } 
    return;
}