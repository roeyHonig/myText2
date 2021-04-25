#include "myText.h"

int main()
{
    int userChoice;
    char roeyCharAray[60];

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
                roeyCharAray[i] = ch;
                i++;
            }
        } while(ch != EOF); 

        for (i = 0; i < 60; ++i)
        {
            printf("%c", roeyCharAray[i]);
        } 
        
    } else if (userChoice == linkedList) {

    } else {
        printf("Non Valid Choice");
    }
    //printf("%lu\n", sizeof(int));
    printf("\n");
    return 0;
}