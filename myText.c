#include "myText.h"


int main()
{
    struct bufferDataStructure *bufferDS = initBufferDataStructure();
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
    return 0;
}