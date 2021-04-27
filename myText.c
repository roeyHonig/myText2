#include "myText.h"


int main()
{
    struct bufferDataStructure *bufferDS = initBufferDataStructure();
    struct bufferNode *bufferN = initBufferNodeAndLinkTo(NULL);
    int userChoice;
    present(userPromptForDataStructure);
    scanf("%d",&userChoice);
    int errCode = readText(userChoice, (userChoice == buffer) ? bufferDS : bufferN);
    if (errCode == 0) 
        printText(userChoice, (userChoice == buffer) ? bufferDS : bufferN);
    else if (errCode == errorCodeMemoryReallocationFailed) 
        printf("\nInput is too long or system is out of memory\n"); 
    else if (errCode == errorCodeUnknownDataStructure) 
        printf("\nUnknown Data Structure\n");
    free(bufferDS);
    free(bufferN);
    return 0;
}