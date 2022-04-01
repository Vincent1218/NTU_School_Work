#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200 //The number digit limitation

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _node{
     BTNode* item;
     struct _node *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode** root,char* prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);
char* insertNode(BTNode **root,char* prefix );

void push(Stack *sPtr,  BTNode* item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;

    //printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);
    
    printTree(root);
    printf("\n");
    // printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    // printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

void createExpTree(BTNode** root,char* prefix)
{
  while((prefix!=NULL)&&(*prefix!='\0')){
    
    while(*prefix == ' '){
      prefix = prefix + 1;
    }
    // printf("%c\n",*prefix);
    if(*prefix!='\0'){
      prefix = insertNode( root , prefix );
    }
  }
}

char* insertNode(BTNode **root,char* prefix ){
  while(*prefix == ' '){
    prefix = prefix + 1;
  }
	if (*root == NULL)
	{
		*root = malloc(sizeof(BTNode));
		if (*root != NULL) {
      if((*prefix == '+')||(*prefix == '-')||(*prefix == '*')||(*prefix == '/')){
        (*root)->item = *prefix;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return prefix+1;
      }
      else{
        char arr[SIZE];
        for(int z=0; z<SIZE; z++){
          arr[z] = 0;
        }
        int count1 = 1;  
        // printf("%c\n",*prefix);
        arr[0] = *prefix;
        prefix = prefix +1;

        while(((*prefix)!='\0')&&((*prefix) > 47)&&((*prefix) < 58)){
          arr[count1] = *prefix;
          prefix = prefix+1;
          count1 ++;
        }
        // printf("%c\n",arr[0]);
        (*root)->item = atoi(arr);
        (*root)->left = NULL;
        (*root)->right = NULL;
        return prefix;
      }
		}
	}
  else 
  {
    if ((((((*root)->item) != '+')&&(((*root)->item) != '-')&&(((*root)->item) != '*')&&(((*root)->item) != '/')))||(*prefix=='\0')){
      return prefix;
    }
    else{
      if(((*root)->left)==NULL){
        char* tempP = prefix;
        prefix = insertNode(&((*root)->left), prefix);
        if(tempP != prefix){
          return prefix;
        }
        
      }
      else{
        if(((((*root)->left->item) == '+')||(((*root)->left->item) == '-')||(((*root)->left->item) == '*')||(((*root)->left->item) == '/'))){
          char* tempP = prefix;
          prefix = insertNode(&((*root)->left), prefix);
          if(tempP != prefix){
            return prefix;
          }
        }
        else{
          if(((*root)->right)==NULL){
            char* tempP = prefix;
            prefix = insertNode(&((*root)->right), prefix);
            if(tempP != prefix){
              return prefix;
            }
          }
          else{
            if((((*root)->right->item) == '+')||(((*root)->right->item) == '-')||(((*root)->right->item) == '*')||(((*root)->right->item) == '/')){
              char* tempP = prefix;
              prefix = insertNode(&((*root)->right), prefix);
              if(tempP != prefix){
                return prefix;
              }
            }
          }
        }
      }
      if(((*root)->right)==NULL){
        prefix = insertNode(&((*root)->right), prefix);
        return prefix;
      }
      else{
        if((((*root)->right->item) == '+')||(((*root)->right->item) == '-')||(((*root)->right->item) == '*')||(((*root)->right->item) == '/')){
          prefix = insertNode(&((*root)->right), prefix);
          return prefix;
        }
      }
      return prefix;
    }
  }
}

void printTree(BTNode *node){
  if(node == NULL){
    return;
  }
  printTree(node->left);
  if(node != NULL){
    if(((((node)->item) != '+')&&(((node)->item) != '-')&&(((node)->item) != '*')&&(((node)->item) != '/'))){
      printf("%d ",node->item);
    }
    else{
      printf("%c ",node->item);
    }
    
  }
  else{
    return;
  }
  printTree(node->right);
}


void printTreePostfix(BTNode *node){
  if(node == NULL){
    return;
  }
  printTreePostfix(node->left);
  printTreePostfix(node->right);
  if(node != NULL){
    if(((((node)->item) != '+')&&(((node)->item) != '-')&&(((node)->item) != '*')&&(((node)->item) != '/'))){
      printf("%d ",node->item);
      return;
    }
    else{
      printf("%c ",node->item);
      return;
    }
  }
  else{
    return;
  }
}

double computeTree(BTNode *node){
  if(node == NULL){
    return 0;
  }
  if(((node->item) == 43)||((node->item) == 45)||((node->item) == 42)||((node->item) == 47)){
    if((node->item)==43){
      return (computeTree(node->left)+computeTree(node->right));
    }
    else if((node->item)==45){
      return (computeTree(node->left)-computeTree(node->right));
    }
    else if((node->item)==42){
      return (computeTree(node->left)*computeTree(node->right));
    }
    else if((node->item)==47){
      return (computeTree(node->left)/computeTree(node->right));
    }
  }
  else{
    return (node->item);
  }
}

void push(Stack *sPtr, BTNode *item){
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

BTNode *peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void deleteTree(BTNode **root){
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}