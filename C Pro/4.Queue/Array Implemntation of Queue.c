#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct ArrayQueue
{
  int front,rear;
  int capacity;
  int* array;
};
int queueSize(struct ArrayQueue* Q)
{
   int count=0;
   if(isEmptyQueue(Q))
   {
       return 0;
   }
   while(Q->front!=Q->rear)
   {
       count++;
       Q->front=(Q->front+1)%Q->capacity;
   }
   return ++count;
}
void printQueue(struct ArrayQueue* Q)
{
    int i=0;
  if(isEmptyQueue(Q))
  {
    printf("Queue is Empty");
    return ;
  }
  printf("Queue is : ");
  for(i=0;i<queueSize(Q);i++)
  {
    printf("%d ",Q->front);
    Q->front= (Q->front+1)%Q->capacity;
  }
  printf("% d\n",Q->front);

return;
}
struct ArrayQueue* createQueue(int capacity)
{
  struct ArrayQueue* Q=(struct ArrayQueue*)malloc(sizeof(struct ArrayQueue));
  if(Q==NULL){printf("Failed to Memory Allocation for Queue"); return NULL;}
  Q->front=Q->rear=-1; //set front and rear to -1
  Q->capacity=capacity;
  Q->array=(int*)malloc(Q->capacity * sizeof(int));
  if(Q->array==NULL){printf("Failed to Memory Allocation of Array for Queue"); return NULL;}
  return Q;
}
int isFullQueue(struct ArrayQueue* Q)
{
  return (( (Q->rear+1) %Q->capacity) == Q->front);
  }
int isEmptyQueue(struct ArrayQueue* Q)
{
    return (Q->front==-1 && Q->rear==-1);
}
struct ArrayQueue* enQueue(struct ArrayQueue* Q,int data)
{
    if(isFullQueue(Q))
    { printf("Queue is Full...Can't Enqueue data\n");
      return Q;
    }
    if(isEmptyQueue(Q))
    {
        Q->rear=Q->front=0;
    }else
    {
        Q->rear=(Q->rear+1)%Q->capacity;
    }

     Q->array[Q->rear]=data;
  printQueue(Q);
            return Q;
}
struct ArrayQueue* deQueue(struct ArrayQueue* Q)
{
    int data=-1;
    if(isEmptyQueue(Q))
    {
     printf("Queue is Empty...Can't deQueue Data\n");
     return Q;
    }
    data=Q->front;
    if(Q->front==Q->rear)
        Q->front=Q->rear=-1;
    else
        Q->front = (Q->front+1)%Q->capacity;


    return Q ;
}


int main()
{
    struct ArrayQueue* Q=createQueue(5);
    int i=0;
    //printQueue(Q);
    printf("%d",isEmptyQueue(Q));
    printf("\n%d\n",queueSize(Q));
    printf("%d %d %d\n",Q->front,Q->rear,Q->capacity);

    Q=enQueue(Q,34);
    Q=enQueue(Q,45);
    Q=enQueue(Q,22);
    Q=enQueue(Q,33);
    Q=enQueue(Q,99);
    Q=enQueue(Q,11);
      printQueue(Q);
 getch();
 return 0;
}
