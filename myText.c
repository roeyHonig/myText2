#include "myText.h"

int main()
{
    int userChoice;
    char *roeyBuffer = (char *)calloc(bufferbyteSize, sizeof(char));;

    present(userPromptForDataStructure);
    scanf("%d",&userChoice);
    if (userChoice == buffer) {
        // init the appropriate data structure
        present(userPpromptForText);
        
        char ch;
        int i = 0;
        do 
        {
            ch = getchar();
            if (ch != '\n') {
                *(roeyBuffer + i) = ch;
                i++;
            }
        } while(ch != EOF); 
        printf("String = %s", roeyBuffer);
    } else if (userChoice == linkedList) {

    } else {
        printf("Non Valid Choice");
    }
    printf("\n");
    return 0;
}