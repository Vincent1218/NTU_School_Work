#include <stdio.h>
#include <stdlib.h>

#define SIZE 80 //The size of the array

enum ExpType {OPT,OPERAND};

typedef struct _listnode
{
    int  item;
    enum ExpType type;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item, enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);

void expressionLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExpQ, int seed);

int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    gets(infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    expressionLL(infix, &inExpLL);

    int seed;
    //printf("Enter a seed: \n");
    scanf("%d",&seed);
    printExpLL(inExpLL,seed);

    removeAllNodes(&inExpLL);
    return 0;
}


void expressionLL(char* infix, LinkedList *inExpLL)
{
  if(infix==NULL){
    return;
  }
  if(*infix=='\n'){
    return;
  }
  int count = 0;
  char* tempC;
  char* temp;
  tempC = infix;
  temp = infix;
  while((*tempC)!='\0'){
    count++;
    tempC=tempC+1;
  }
  // printf("%d\n",count);
  tempC = tempC-1;

  int x = 0;

  for(int x = count-1 ; x >= 0 ; x--){
    // printf("%c\n",temp[x]);
    if((temp[x] == '+')||(temp[x] == '-')||(temp[x] == '/')||(temp[x] == '*')||(temp[x] == ')')||(temp[x] == '(')){
      insertNode(inExpLL,temp[x],OPT);
    }
    else{
      // printf("%c\n",temp[x]);
      
      char arr[SIZE];
      for(int z=0; z<SIZE; z++){
        arr[z] = 0;
      }
      int count1 = 1;
      arr[0] = temp[x];

      while(((temp[x-count1])!='\0')&&(temp[x-count1] > 47)&&((temp[x-count1] < 58))){
        arr[count1] = temp[x-count1];
        count1 ++;
      }
      for( int a = 0 ; a < count1/2 ; a++){
        int tempa = arr[a];
        arr[a] = arr[count1-1-a];
        arr[count1-1-a] = tempa;
      }
      x = x-count1+1;
      insertNode(inExpLL,atoi(arr),OPERAND);
    }
  }
}

void printExpLL(LinkedList inExpLL, int seed)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item+ seed);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       ListNode *temp = LLPtr->head;
       LLPtr->head = LLPtr->head->next;

       free(temp);
       LLPtr->size--;
       return 1;
    }
}

int isEmptyLinkedList (LinkedList ll) {
    if(ll.size==0) return 1;
    else return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
	while(deleteNode(LLPtr));
}