#include <stdio.h>
#include <stdlib.h>

#define userPromptForDataStructure 1
#define userPpromptForText 2
#define buffer 1
#define linkedList 2
#define bufferbyteSize 60
#define errorCodeMemoryReallocationFailed  1
#define errorCodeUnknownDataStructure  2

struct bufferDataStructure *initBufferDataStructure();
struct bufferNode *initBufferNodeAndLinkTo(struct bufferNode *previousNode);
void present(int i);
int readText(int dataStructureType, void *dataStructure);
void printText(int dataStructureType, void *dataStructure);

struct bufferDataStructure {
    char *currentBuffer;
    int incrementBufferSizeInBytes;
    int numOfReallocation; 
};

struct bufferNode {
    char *currentBuffer;
    struct bufferNode *next;
    struct bufferNode *previous; 
};
