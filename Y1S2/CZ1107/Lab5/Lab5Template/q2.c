#include <stdio.h>
#include <stdlib.h>

#define SIZE 80 //The limit of expression length

typedef struct _stackNode{
    double item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, double item);
int pop(Stack *sPtr);
double peek(Stack s);
int isEmptyStack(Stack s);

double exePostfix(char*);

int main()
{
    char postfix[SIZE];

    printf("Enter a postfix expression:\n");
    gets(postfix);

    printf("The answer is %.2lf.\n",exePostfix(postfix));

    return 0;
}


double exePostfix(char* postfix)
{
	double ans;

    Stack *S;
    S = malloc(sizeof(Stack));

    while(*postfix!='\0'){
        if((*postfix=='+')||(*postfix=='-')||(*postfix=='*')||(*postfix=='/')){
            double temp1;
            double temp2;
            temp1 = peek(*S);

            pop(S);
            temp2 = peek(*S);

            pop(S);
            if((*postfix=='+')){
                push(S,temp1+temp2);
            }
            if((*postfix=='-')){
                push(S,temp2-temp1);
            }
            if((*postfix=='*')){
                push(S,temp1*temp2);
            }
            if((*postfix=='/')){
                push(S,temp2/temp1);
            }
        }
        else{
            push(S,(double)(*(postfix)-'0'));
        }
        postfix = postfix+1;
    }
    ans = peek(*S);

}

void push(Stack *sPtr, double item){
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

double peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}
