#include "myText.h"

/*
 * Function:  initBufferDataStructure 
 * --------------------
 * Constructor method to initialize bufferDataStructure
 * 
 * returns: pointer to struct bufferDataStructure
 */
struct bufferDataStructure *initBufferDataStructure() {
    struct bufferDataStructure *bufferDS = (struct bufferDataStructure*) malloc(1 * sizeof(struct bufferDataStructure));
    bufferDS->currentBuffer = (char*)calloc(bufferbyteSize, sizeof(char));
    bufferDS->incrementBufferSizeInBytes = bufferbyteSize;
    bufferDS->numOfReallocation = 0;
    return bufferDS;
}

/*
 * Function:  initBufferNodeAndLinkTo 
 * --------------------
 * Constructor method to initialize bufferNode structure
 * 
 * previousNode: the bufferNode which our new structure pointer previous field will point to.
 *
 * returns: pointer to struct bufferNode
 */
struct bufferNode *initBufferNodeAndLinkTo(struct bufferNode *previousNode) {
    struct bufferNode *bufferN = (struct bufferNode*) malloc(1 * sizeof(struct bufferNode));
    bufferN->currentBuffer = (char*)calloc(bufferbyteSize, sizeof(char));
    bufferN->next = NULL;
    bufferN->previous = previousNode;
    return bufferN;
}

/*
 * Function:  present 
 * --------------------
 * Present suitable user prompt 
 * 
 * i: integer representing diffrent prompts  
 *
 * returns: void
 */
void present(int i) {
    if (i == userPromptForDataStructure)
        printf("This program will temporariley save text input from the keyboard to a dynamic data structure and print it out to the screen in a 60 characters per line format.\nPlease choose the dynamic data structure you'd like to use (1 - buffer, 2 - linked list): ");
    else if (i == userPpromptForText) 
        printf("Enter text. To finish, press CTRL+d (linux) or CTRL+z (windows): ");
}

/*
 * Function:  readText 
 * --------------------
 * Will prompt the user to enter text via the keyboard and will store the text in the choosen data structure 
 * 
 * dataStructureType: integer representing diffrent data types available for storying dynamic content   
 * dataStructure: A pointer to the specific selected data structure   
 *
 * returns: int - 0 for No errors. or any other number for a specific error code
 */
int readText(int dataStructureType, void *dataStructure) {
    char ch;
    if (dataStructureType == buffer) {
        present(userPpromptForText); 
        struct bufferDataStructure *bufferDS = (struct bufferDataStructure*)dataStructure;
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
        present(userPpromptForText); 
        struct bufferNode *bufferN = (struct bufferNode *)dataStructure;
        struct bufferNode *tempBufferN = bufferN;
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

/*
 * Function:  printText 
 * --------------------
 * Will print the text stored inside the data structure 
 * 
 * dataStructureType: integer representing diffrent data types available for storying dynamic content   
 * dataStructure: A pointer to the specific selected data structure   
 *
 * returns: void
 */
void printText(int dataStructureType, void *dataStructure) {
    printf("\n");
    if (dataStructureType == buffer) {
        struct bufferDataStructure *bufferDS = (struct bufferDataStructure*)dataStructure;
        printf("%s", bufferDS->currentBuffer);
    } else if (dataStructureType == linkedList) {
        struct bufferNode *bufferN = (struct bufferNode *)dataStructure;
        struct bufferNode *nextBufferN = bufferN;
        do {
            bufferN = nextBufferN;
            nextBufferN = bufferN->next;
            printf("%s", bufferN->currentBuffer);
        } while (nextBufferN); 
    } 
    printf("\n");
    return;
}