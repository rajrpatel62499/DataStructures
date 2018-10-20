#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int size=10;
int A[10];
int N=5;
void insertElementAt(int index,int data)
{
   int i=0;
    if(N<size){

   for(i=N-1;i>=index;i--)
         A[i+1]=A[i];
       A[index]=data;
         N=N+1;
    }else
    {
        printf("Array is FULL ...can't Insert data");
    }
}
void print(int A[])
{
    int i=0;
    for(i=0;i<N;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void main()
{
 int i=0;
 for(i=0;i<N;i++)
 {
     A[i]=i;
 }
print(A);
insertElementAt(2,45);
insertElementAt(6,47);
print(A);
}
