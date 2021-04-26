#include "myText.h"

int main()
{
    int userChoice;
    char *roeyBuffer = (char*)calloc(bufferbyteSize, sizeof(char));
    present(userPromptForDataStructure);
    scanf("%d",&userChoice);
    int errCode = readText(userChoice, roeyBuffer);
    if (errCode == 0) {
        // No error during read text 
        printText(userChoice, roeyBuffer);
    } else {
        // handle the error code. 
    }   
    free(roeyBuffer);
    printf("\n");
    return 0;
}