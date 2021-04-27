#include "myText.h"


int main()
{
    struct bufferDataStructure *bufferDS = initBufferDataStructure();
    struct bufferNode *bufferN = initBufferNodeAndLinkTo(NULL);
    int userChoice;
    present(userPromptForDataStructure);
    scanf("%d",&userChoice);
    int errCode = readText(userChoice, (userChoice == buffer) ? bufferDS : bufferN);
    if (errCode == 0) {
        // No error during read text 
        printText(userChoice, (userChoice == buffer) ? bufferDS : bufferN);
    } else {
        // handle the error code. 
    }   
    free(bufferDS);
    free(bufferN);
    return 0;
}