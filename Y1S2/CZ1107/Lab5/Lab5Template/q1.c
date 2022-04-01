#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 80 //The limit of expression length

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

void in2Post(char*, char*);

int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix expression:\n");
    gets(infix);

    in2Post(infix,postfix);
    printf("The postfix expression is \n");
    printf("%s\n",postfix);
    return 0;
}

void in2Post(char* infix, char* postfix)
{
    char* temp;
    temp = infix;

    int count = 0;

    int temp1,temp2;
    temp1 = 0;
    temp2 = 0;

    Stack *S;
    S = malloc(sizeof(Stack));

    while(*temp != '\0'){
        if((*temp == '+')||(*temp == '-')||(*temp == '*')||(*temp == '/')){
            if((*temp == '+')||(*temp == '-')){
                temp1 = 0;
            }
            else{
                temp1 = 1;
            }
            while((!isEmptyStack(*S))&&(peek(*S)!='(')){
                printf("1\n");
                if((peek(*S)=='*')||(peek(*S)=='/')){
                    if(temp1==0){
                        postfix[count] = peek(*S);
                        pop(S);
                        count++;
                    }
                    else{
                        break;
                    }
                }
                else if((peek(*S)=='+')||(peek(*S)=='-')){
                    if(temp1==0){
                        postfix[count] = peek(*S);
                        pop(S);
                        count++;
                    }
                    else{
                        break;
                    }
                }
            }
            push(S,*temp);
        }
        else if(*temp == '('){
            push(S,*temp);
        }
        else if(*temp == ')'){
            while(peek(*S)!='('){
                printf("2\n");
                postfix[count] = peek(*S);
                count++;
                pop(S);
            }
            pop(S);
        }
        else{
            printf("sadssda\n");
            postfix[count] = *temp;
            count ++;
        }
        
        temp = temp+1;
    }
    while(!(isEmptyStack(*S))){
        printf("3\n");
        postfix[count] = peek(*S);
        count++;
        pop(S);
    }

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
