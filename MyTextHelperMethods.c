#include "myText.h"

struct bufferDataStructure *initBufferDataStructure() {
    struct bufferDataStructure *bufferDS = (struct bufferDataStructure*) malloc(1 * sizeof(struct bufferDataStructure));
    bufferDS->currentBuffer = (char*)calloc(bufferbyteSize, sizeof(char));
    bufferDS->incrementBufferSizeInBytes = bufferbyteSize;
    bufferDS->numOfReallocation = 0;
    return bufferDS;
}

struct bufferNode *initBufferNodeAndLinkTo(struct bufferNode *previousNode) {
    struct bufferNode *bufferN = (struct bufferNode*) malloc(1 * sizeof(struct bufferNode));
    bufferN->currentBuffer = (char*)calloc(bufferbyteSize, sizeof(char));
    bufferN->next = NULL;
    bufferN->previous = previousNode;
    //previousNode->next = bufferN;
    return bufferN;
}

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
        struct bufferNode *bufferN = (struct bufferNode *)dataStructure;
        struct bufferNode *tempBufferN = bufferN;
        present(userPpromptForText); // TOOD: maybe just put outside if
        char ch; // TOOD: maybe just put outside if
        while (1) {
            int i = 0;
            do 
            {
                ch = getchar();
                if (ch == EOF) 
                    goto endOfFunction;
                if (ch != '\n') {                    
                    *(tempBufferN->currentBuffer + i) = ch;
                    i++;
                }
            } while(i < bufferbyteSize); 
            struct bufferNode *nextBufferN = initBufferNodeAndLinkTo(tempBufferN);
            tempBufferN->next = nextBufferN;
            tempBufferN = nextBufferN;
            if (nextBufferN->currentBuffer == NULL)
                return errorCodeMemoryReallocationFailed;
        }
    } else {
        return errorCodeUnknownDataStructure;
    }
    endOfFunction: 
    return 0;
}

void printText(int dataStructureType, void *dataStructure) {
    printf("\n");
    if (dataStructureType == buffer) {
        struct bufferDataStructure *bufferDS = (struct bufferDataStructure*)dataStructure;
        printf("%s", bufferDS->currentBuffer);
        //printf("\nnumOfReallocation = %d", bufferDS->numOfReallocation);
    } else if (dataStructureType == linkedList) {
        struct bufferNode *bufferN = (struct bufferNode *)dataStructure;
        struct bufferNode *nextBufferN = bufferN;
        do {
            bufferN = nextBufferN;
            nextBufferN = bufferN->next;
            printf("%s", bufferN->currentBuffer);
        } while (nextBufferN != NULL); // TODO: just while (nextBufferN)
    } 
    printf("\n");
    return;
}