#include "myText.h"

int main()
{
    int userChoice;
    char *roeyBuffer = (char*)calloc(bufferbyteSize, sizeof(char));
    present(userPromptForDataStructure);
    scanf("%d",&userChoice);
    if (userChoice == buffer) {
        // init the appropriate data structure
        present(userPpromptForText);
        
        char ch;
        int j = 1;
        while (1) {
            int i = 0;
            do 
            {
                ch = getchar();
                if (ch == EOF) 
                    goto jump;
                if (ch != '\n') {
                    *(roeyBuffer + i + (j-1)*bufferbyteSize) = ch;
                    i++;
                }
            } while(i < bufferbyteSize); 
            j++;
            roeyBuffer = (char *)realloc(roeyBuffer, bufferbyteSize * j);
            if (roeyBuffer == NULL)
                goto jump;
        }
    jump: 
        printf("\nString = %s", roeyBuffer);
        free(roeyBuffer);
    } else if (userChoice == linkedList) {
        
    } else {
        printf("Non Valid Choice");
    }
    printf("\n");
    return 0;
}