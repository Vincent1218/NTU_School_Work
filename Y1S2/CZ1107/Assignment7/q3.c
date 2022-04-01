#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
  int vertex;
  struct _listnode *next;
} ListNode;

typedef ListNode QueueNode;

typedef struct _queue{
  int size;
  QueueNode *head;
  QueueNode *tail;
} Queue;



void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
void printQ(QueueNode *cur);


int main()
{
    int Prj, Std, Mtr; //Project, Student and Mentor;
    int maxMatch;
    scanf("%d %d %d", &Std, &Prj, &Mtr);
    // printf("%d %d %dyeah\n", Std, Prj, Mtr);
    int n = Std + Prj + Mtr;
    int f[n+2][n+2];
    int c[n+2][n+2]; 
    int cf[n+2][n+2]; 
    int ps[n+2][n+2]; 

    int f1[n+2][n+2];
    int c1[n+2][n+2]; 
    int cf1[n+2][n+2]; 
    int ps1[n+2][n+2]; 

    int p[n+2]; 
    int p1[n+2]; 

    int np,nm;

    for (int i = 0; i <n+2;i++){
      p[i]=-1;
      p1[i]=-1;
      for (int x = 0; x <n+2;x++){
        f[i][x]=0;
        c[i][x]=0;
        cf[i][x]=0;
        ps[i][x]=1;

        f1[x][i]=0;
        c1[x][i]=0;
        cf1[x][i]=0;
        ps1[x][i]=1;
      }
    }

    for (int i = 0; i < Std; i++){
      scanf("%d %d", &np, &nm);
      // printf("%d %d yeah\n", np, nm);
      for (int x = 0 ; x < np; x++){
        int temp;
        scanf("%d",&temp);
        // printf("%d yeah\n", temp);
        c[Std+temp][i+1] = 1;
        cf[Std+temp][i+1] = 1;
        c1[i+1][Std+temp] = 1;
        cf1[i+1][Std+temp] = 1;
      }
      for (int x = 0 ; x < nm; x++){
        int temp;
        scanf("%d",&temp);
        c[i+1][Std+Prj+temp] = 1;
        cf[i+1][Std+Prj+temp] = 1;
        c1[Std+Prj+temp][i+1] = 1;
        cf1[Std+Prj+temp][i+1] = 1;
      }
    }
    for (int x = 1; x<=Prj; x++){
      c[0][Std+x] = 1;
      cf[0][Std+x] = 1;
      c1[Std+x][0] = 1;
      cf1[Std+x][0] = 1;
    }
    for (int x = 1; x<=Mtr; x++){
      c[Std+Prj+x][n+1]= 1;
      cf[Std+Prj+x][n+1] = 1;
      c1[n+1][Std+Prj+x]= 1;
      cf1[n+1][Std+Prj+x] = 1;
    }
    // for (int i = 0; i <n+2;i++){
    //   for (int x = 0; x <n+2;x++){  
    //     printf("%d ",cf[i][x]);
    //   }
    //   printf("\n");
    // }



    int boolArr[n+2];
    int boolArr1[n+2];
    for ( int x = 0 ; x < n+2; x++){
        boolArr[x] = 0;
        boolArr1[x] = 0;
    }
    boolArr[0] = 1;
    boolArr1[0] = 1;
    int step = 0;
    Queue *qu ;
    qu = malloc(sizeof(Queue));
    enqueue(qu,0);
    while(!isEmptyQueue(*qu)){
      int tempi = getFront(*qu);
      // printf("dasdsdasdaasdfsdfasdfsdfasdfsdafasfasdfasdfafadsfasdfasdfasdfasdfasd%d\n",tempi);
      dequeue(qu);
      for (int i = 0; i <= n+1; i++){
        // printf("boom    %d\n",i);
        if (cf[tempi][i]){
          // printf("booming\n");
          if(i==(n+1)){
            p[i]=tempi;
            tempi = n+1;
            while(p[tempi]){
              boolArr[p[tempi]]=1;

              // printf("%d\n",p[tempi]);
              if(c[p[tempi]][tempi]){
                f[p[tempi]][tempi] = f[p[tempi]][tempi] + 1;
              }
              else{
                f[tempi][p[tempi]] = f[tempi][p[tempi]] - 1;
              }
              if((tempi>=Std+Prj+1)&&(tempi<=n)){
                for ( int x = Std+Prj+1 ; x <= n; x++){
                  if(x!=tempi){
                    // if(cf[p[tempi]][x]==1){
                      ps[p[tempi]][x] = 0;
                    // }
                    // printf("%d %d\n",p[tempi],x);
                  }
                }
              }
              cf[p[tempi]][tempi] = cf[p[tempi]][tempi] - 1;
              cf[tempi][p[tempi]] = cf[tempi][p[tempi]] + 1;
              tempi=p[tempi];
            }
            if(c[0][tempi]){
              f[0][tempi] = f[0][tempi] + 1;
            }
            else{
              f[tempi][0] = f[tempi][0] - 1;
            }
            cf[0][tempi] = cf[0][tempi] - 1;
            cf[tempi][0] = cf[tempi][0] + 1;

            for ( int x = 0 ; x <=n+1; x++){
              p[x]=-1;
            }
            for ( int x = 0 ; x < n+2; x++){
                boolArr[x] = 0;
            }
            removeAllItemsFromQueue(qu);
            enqueue(qu,0);
            break;
          }
          else{
            if((!boolArr[i])&&(ps[tempi][i])){
              p[i]=tempi;
              enqueue(qu,i);
              boolArr[i] = 1;
            }
            else if (!boolArr[i]) {
              int tempi1 = tempi;
              step = 0;
              while(p[tempi1]){
                step++;
                tempi1=p[tempi1];
              }
              if(step>1){
                p[i]=tempi;
                enqueue(qu,i);
                boolArr[i] = 1;
                step = 0;
              }
            }
          }
        }
      }
    }

    // for (int i = 0; i <n+2;i++){
    //   for (int x = 0; x <n+2;x++){  
    //     printf("%d ",f[i][x]);
    //   }
    //   printf("\n");
    // }


    int ans = 0;
    for ( int x = 0 ; x < n+2; x++){
        boolArr[x] = 0;
        boolArr1[x] = 0;
    }
    boolArr[0] = 1;
    boolArr1[0] = 1;
    removeAllItemsFromQueue(qu);
    enqueue(qu,0);
    while(!isEmptyQueue(*qu)){
      int tempi = getFront(*qu);
      // printf("dasdsdasdaasdfsdfasdfsdfasdfsdafasfasdfasdfafadsfasdfasdfasdfasdfasd%d\n",tempi);
      dequeue(qu);
      for (int i = 0; i <= n+1; i++){
        // printf("boom    %d\n",i);
        if (f[tempi][i]){
          // printf("booming\n");
          if(i==(n+1)){
            p[i]=tempi;
            tempi = n+1;
            while(p[tempi]){
              // printf("%d\n",p[tempi]);
              boolArr1[p[tempi]]=1;
              tempi=p[tempi];
            }
            for ( int x = 0 ; x < n+2; x++){
                boolArr[x] = 0;
            }
            ans ++;
            removeAllItemsFromQueue(qu);
            enqueue(qu,0);
            break;
          }
          else{
            if((!boolArr[i])&&(!boolArr1[i])){
              p[i]=tempi;
              enqueue(qu,i);
              boolArr[i] = 1;
            }
          }
        }
      }
    }

    // removeAllItemsFromQueue(qu);
    // for ( int x = 0 ; x < n+2; x++){
    //     boolArr[x] = 0;
    //     boolArr1[x] = 0;
    // }
    // enqueue(qu,n+1);
    // while(!isEmptyQueue(*qu)){
    //   int tempi = getFront(*qu);
    //   // printf("dasdsdasdaasdfsdfasdfsdfasdfsdafasfasdfasdfafadsfasdfasdfasdfasdfasd%d\n",tempi);
    //   dequeue(qu);
    //   for (int i = 0; i <= n+1; i++){
    //     // printf("boom    %d\n",i);
    //     if (cf1[tempi][i]){
    //       // printf("booming\n");
    //       if(i==0){
    //         p1[i]=tempi;
    //         tempi = 0;
    //         while(p1[tempi]!=(n+1)){
    //           boolArr[p1[tempi]]=1;

    //           // printf("%d\n",p1[tempi]);
    //           if(c1[p1[tempi]][tempi]){
    //             f1[p1[tempi]][tempi] = f1[p1[tempi]][tempi] + 1;
    //           }
    //           else{
    //             f1[tempi][p1[tempi]] = f1[tempi][p1[tempi]] - 1;
    //           }
    //           if((tempi>=Std+1)&&(tempi<=Std+Prj)){
    //             for ( int x = Std+1 ; x <= Std+Prj; x++){
    //               if(x!=tempi){
    //                 // if(cf[p[tempi]][x]==1){
    //                   ps1[p1[tempi]][x] = 0;
    //                 // }
    //                 // printf("%d %d\n",p[tempi],x);
    //               }
    //             }
    //           }
    //           cf1[p1[tempi]][tempi] = cf1[p1[tempi]][tempi] - 1;
    //           cf1[tempi][p1[tempi]] = cf1[tempi][p1[tempi]] + 1;
    //           tempi=p1[tempi];
    //         }
    //         if(c1[n+1][tempi]){
    //           f1[n+1][tempi] = f1[n+1][tempi] + 1;
    //         }
    //         else{
    //           f1[tempi][n+1] = f1[tempi][n+1] - 1;
    //         }
    //         cf1[n+1][tempi] = cf1[n+1][tempi] - 1;
    //         cf1[tempi][n+1] = cf1[tempi][n+1] + 1;

    //         for ( int x = 0 ; x <=n+1; x++){
    //           p1[x]=-1;
    //         }
    //         for ( int x = 0 ; x < n+2; x++){
    //             boolArr[x] = 0;
    //         }
    //         removeAllItemsFromQueue(qu);
    //         enqueue(qu,n+1);
    //         break;
    //       }
    //       else{
    //         if((!boolArr[i])&&(ps1[tempi][i])){
    //           p1[i]=tempi;
    //           enqueue(qu,i);
    //           boolArr[i] = 1;
    //         }
    //       }
    //     }
    //   }
    // }

    // int ans1 = 0;
    // for ( int x = 0 ; x < n+2; x++){
    //     boolArr[x] = 0;
    //     boolArr1[x] = 0;
    // }

    // boolArr[0] = 1;
    // boolArr1[0] = 1;
    // removeAllItemsFromQueue(qu);
    // enqueue(qu,n+1);
    // while(!isEmptyQueue(*qu)){
    //   int tempi = getFront(*qu);
    //   // printf("dasdsdasdaasdfsdfasdfsdfasdfsdafasfasdfasdfafadsfasdfasdfasdfasdfasd%d\n",tempi);
    //   dequeue(qu);
    //   for (int i = 0; i <= n+1; i++){
    //     // printf("boom    %d\n",i);
    //     if (f1[tempi][i]){
    //       // printf("booming\n");
    //       if(i==0){
    //         p1[i]=tempi;
    //         tempi = 0;
    //         while(p1[tempi]!=(n+1)){
    //           // printf("%d\n",p[tempi]);
    //           boolArr1[p1[tempi]]=1;
    //           tempi=p1[tempi];
    //         }
    //         for ( int x = 0 ; x < n+2; x++){
    //             boolArr[x] = 0;
    //         }
    //         ans1 ++;
    //         removeAllItemsFromQueue(qu);
    //         enqueue(qu,n+1);
    //         break;
    //       }
    //       else{
    //         if((!boolArr[i])&&(!boolArr1[i])){
    //           p1[i]=tempi;
    //           enqueue(qu,i);
    //           boolArr[i] = 1;
    //         }
    //       }
    //     }
    //   }
    // }
    // if(ans>=ans1){
    //   printf("%d\n", ans);
    // }
    // else{
    //   printf("%d\n", ans1+2);
    // } 
    printf("%d\n", ans);
    return 0;
}

void enqueue(Queue *qPtr, int vertex) {
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    if(newNode==NULL) exit(0);

    newNode->vertex = vertex;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr) {
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;

       free(temp);
       qPtr->size--;
       return 1;
    }
}

int getFront(Queue q){
    return q.head->vertex;
}

int isEmptyQueue(Queue q) {
    if(q.size==0) return 1;
    else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
	while(dequeue(qPtr));
}
