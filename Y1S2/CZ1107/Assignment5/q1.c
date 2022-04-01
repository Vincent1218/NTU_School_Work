#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define SIZE 80 //The size of the array

enum ExpType {OPT,OPERAND};

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

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

void insertNode(LinkedList *llPtr, int item,enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);


void in2PreLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExp);

int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    gets(infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);
    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void in2PreLL(char* infix, LinkedList *inExpLL)
{
  if(infix==NULL){
    return;
  }
  if(*infix=='\n'){
    return;
  }

  Stack *tempS ;
  tempS = malloc(sizeof(Stack));
  tempS->size = 0;
  tempS->head = NULL;
  // push(tempS,1);
  // printf("%d\n",pop(tempS));

  int count = 0;
  char* temp;
  temp = infix;
  count = strlen(infix);


  for(int x = count-1 ; x >= 0 ; x--){
    // printf("%c\n",*tempC);
    if((temp[x] == '+')||(temp[x] == '-')||(temp[x] == '/')||(temp[x] == '*')){
      int temp1,temp2;
      if((temp[x]=='+')||(temp[x]=='-')){
        temp1 = 0;
      }
      else{
        temp1 = 1;
      }
      if(!(isEmptyStack(*tempS))){
        if((peek(*tempS)=='+')||(peek(*tempS)=='-')){
          temp2 = 0;
        }
        else{
          temp2 = 1;
        }
        while((!(isEmptyStack(*tempS)))&&(peek(*tempS)!=')')&&(temp1<=temp2)){
          insertNode(inExpLL,peek(*tempS),OPT);
          pop(tempS);
          if((!(isEmptyStack(*tempS)))&&(peek(*tempS)!=')')){
            if((peek(*tempS)=='+')||(peek(*tempS)=='-')){
              temp2 = 0;
            }
            else{
              temp2 = 1;
            }
          }

        }
      }
      push(tempS,temp[x]);
    }
    else if(temp[x] == ')'){
      push(tempS,')');
    }
    else if(temp[x] == '('){
      if(!(isEmptyStack(*tempS))){
        while(peek(*tempS)!=')'){
          insertNode(inExpLL,peek(*tempS),OPT);
          pop(tempS);
        }
        pop(tempS);        
      }

    }
    else{
      // printf("%c\n",temp[x]);
      char arr[SIZE];
      for(int z=0; z<SIZE; z++){
        arr[z] = 0;
      }
      int count1 = 1;
      arr[0] = temp[x];
      while((temp[x-count1] > 47)&&((temp[x-count1] < 58))&&(x-count1>=0)){
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

  while(!(isEmptyStack(*tempS))){
    insertNode(inExpLL,peek(*tempS),OPT);
    pop(tempS);
  }

}

void printExpLL(LinkedList inExpLL)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item);
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
    if(LLPtr==NULL || LLPtr->size==0){
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

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

