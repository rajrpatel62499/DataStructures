#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int rear=-1;
int front=-1;
#define MAX_SIZE 5
int A[MAX_SIZE];
int isFull()
{
  if(rear==MAX_SIZE-1)return 1;
  else return 0;
}
int isEmpty()
{
    if(front==-1&&rear==-1)
        return 1;
    else
        return 0;
}
int size()
{
   if(isEmpty())
    return 0;
   else
    return (rear-front+1);
}
void enQueue(int data)
{
    if(isFull())
    {
        printf("Queue is overflow...Can't Enqueue data\n");
    }else
    {
        printf("Enqueueing...\n");
        if(isEmpty())
        {
            front=rear=0;
        }else
        {
            rear=rear+1;
        }
        A[rear]=data;
    }
}
int deQueue()
{
    int data;
    if(isEmpty())
    {
        printf("Queue is Empty..can't Dequeue data");
    }else
    {
        printf("Dequeuing...\n");
        data=A[front];
        if(front==rear)
        {
            front=rear=-1;
        }else
        {
          front=front+1;
        }
        return data;
    }

}
void print()
{
 int count=0,index;
 int s=size();
 printf("Queue is :");
 for(count=0;count<s;count++)
 {
     index=front+count;
     printf("%d ",A[index]);
 }
 printf("\n");
}
 void main()
 {
  int i=0;
  for(i=0;i<MAX_SIZE;i++)
  {
      enQueue((i+1));
      printf("size is: %d",size());
      print();
  }
  for(i=0;i<MAX_SIZE;i++)
  {
     deQueue();
      printf("size is: %d",size());
      print();
  }

 }

