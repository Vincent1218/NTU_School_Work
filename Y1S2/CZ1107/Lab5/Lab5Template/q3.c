#include <stdio.h>
#include <stdlib.h>

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

void in2Pre(char*, char*);

int main()
{
    char infix[SIZE];
    char prefix[SIZE];

    printf("Enter an infix expression:\n");
    gets(infix);

    in2Pre(infix,prefix);
    printf("The prefix expression is \n");
    printf("%s\n",prefix);

    return 0;
}

void in2Pre(char* infix, char* prefix)
{
    char* temps;
    temps = infix;
    int count = 0;
    while(*temps!='\0'){
        temps = temps+1;
        count ++;
    }
    int precount = 0;
    Stack *S;
    S = malloc(sizeof(Stack));

    int temp1 = 0;
    for ( int i = count-1; i >=0; i-- ){
        if((infix[i]=='+')||(infix[i]=='-')||(infix[i]=='*')||(infix[i]=='/')){
            if (( infix[i] == '+' ) ||( infix[i] == '-' )){
                temp1 = 0;
            }
            else{
                temp1 = 1;
            }
            while((!isEmptyStack(*S))&&(peek(*S)!=')')){
                if((peek(*S)=='*')||(peek(*S)=='/')){
                    if(temp1==0){
                        prefix[precount] = peek(*S);
                        pop(S);
                        precount++;
                    }
                    else{
                        break;
                    }
                }
                else if((peek(*S)=='+')||(peek(*S)=='-')){
                    if(temp1==0){
                        prefix[precount] = peek(*S);
                        pop(S);
                        precount++;
                    }
                    else{
                        break;
                    }
                }
            }
            push(S,infix[i]);
        }
        else if (infix[i] == ')'){
            push(S,infix[i]);
        }
        else if(infix[i] == '('){
            while(peek(*S)!=')'){
                prefix[precount] = peek(*S);
                precount++;
                pop(S);
            }
            pop(S);
        }
        else{
            prefix[precount] = infix[i];
            precount ++;
        }
    }
    while(!isEmptyStack(*S)){
        prefix[precount] = peek(*S);
        precount ++;
        pop(S);
    }
    for ( int x = 0; x< precount/2 ; x++){
        char tempc;
        tempc = prefix[(precount-1)-x];
        prefix[(precount-1)-x] = prefix[x];
        prefix[x] = tempc;

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
