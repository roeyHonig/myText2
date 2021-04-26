#include "myText.h"


int main()
{
    struct bufferDataStructure *bufferDS = (struct bufferDataStructure*) malloc(1 * sizeof(struct bufferDataStructure));
    bufferDS->currentBuffer = (char*)calloc(bufferbyteSize, sizeof(char));
    bufferDS->incrementBufferSizeInBytes = bufferbyteSize;
    bufferDS->numOfReallocation = 0;
    int userChoice;
    present(userPromptForDataStructure);
    scanf("%d",&userChoice);
    int errCode = readText(userChoice, bufferDS);
    if (errCode == 0) {
        // No error during read text 
        printText(userChoice, bufferDS);
    } else {
        // handle the error code. 
    }   
    free(bufferDS);
    printf("\n");
    return 0;
}