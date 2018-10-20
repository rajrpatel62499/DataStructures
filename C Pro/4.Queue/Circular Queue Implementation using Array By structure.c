#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Queue
{
    int front;
    int rear;
    int capacity;
    int *array;
};



struct Queue* createQueue(int capacity)
{
    struct Queue *q1=(struct Queue*)malloc( sizeof(struct Queue));
    q1->front=-1;
    q1->rear=-1;
    q1->capacity=capacity;
    q1->array=(int*)malloc(capacity * sizeof(int));
    return q1;
}
int isFull(struct Queue* q1)
{
   if((q1->rear+1)%q1->capacity==q1->front)
        return 1;
   else
    return 0;
}
int isEmpty(struct Queue* q1)
{
    if(q1->rear==-1 && q1->front==-1)
        return 1;
    else
        return 0;
}
void  enQueue(struct Queue* q1,int data)
{
    if(isFull(q1))
    {
        printf("Queue is overflow...can't Enqueue data\n");
    }else{
   printf("Enqueuing....");
    if(isEmpty(q1))
    {
        q1->front=q1->rear=0;
    }else
    {
      q1->rear=(q1->rear+1)%q1->capacity;
    }
    q1->array[q1->rear]=data;

    }

}
int deQueue(struct Queue* q1)
{
    int data;
 if(isEmpty(q1))
 {
     printf("Queue is Empty...Can't Dequeue data");
 }else
 {
    printf("Dequeueing...");
    data=q1->array[q1->front];
     if(q1->front==q1->rear)
     {
         q1->front=q1->rear=-1;
     }else
     {
         q1->front= ( (q1->front+1)%q1->capacity);
     }
 }
 return data;
}
int size(struct Queue* q1)
{
    return ( (q1->capacity+q1->rear-q1->front) % q1->capacity + 1);
}
void print(struct Queue* q1)
{
    int count=0,index;
    int s=size(q1);
    printf("Queue is: ");
    if(isEmpty(q1))
    {
        printf("Queue is Empty Now...Contain garbage value:");

    }
    for(count=0;count<s;count++)
    {
        index= (q1->front +count)%q1->capacity;
        printf("%d ",q1->array[index]);
    }
    printf("\n");
}
void main()
{
    int data;
    struct Queue* q1=createQueue(5);
   enQueue(q1,1); print(q1);
   enQueue(q1,2); print(q1);
   enQueue(q1,3); print(q1);
   enQueue(q1,4); print(q1 );
   enQueue(q1,5); print(q1);
    printf("\n\n");
   data= deQueue(q1);  printf("dequeue data is: %d\n",data); print(q1);
   data=deQueue(q1);   printf("dequeue data is: %d\n",data);  print(q1);
   data=deQueue(q1);   printf("dequeue data is: %d\n",data);  print(q1);
   data=deQueue(q1);   printf("dequeue data is: %d\n",data); print(q1);
   data=deQueue(q1);   printf("dequeue data is: %d\n",data); print(q1);
 print(q1);
}
