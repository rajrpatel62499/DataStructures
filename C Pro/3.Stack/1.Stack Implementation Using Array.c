#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Max_size 100
#define True 1
#define False 0
int A[Max_size];
int tos=-1;

void push(int x)
{
	if(tos==Max_size-1)
		{printf("Error: stack is Overflow");
         return ;}


      A[++tos]=x;//tos++; A[tos]=x;
}
int pop()
{
	if(tos==-1)
	{
		printf("Error:Stack is Empty...Can't Pop up");
		return ;
	}
	return A[tos--];
}
int Is_Empty()
{
	if(tos==-1) return True;
	else return False;
}
int Is_Full()
{
	if(tos==Max_size)return True;
	else return False;
}
int Tos()
{
	return A[tos];
}
void Print()
{
	int i=0;
	printf("Stack is :");
	for(i=0;i<=tos;i++)
	{
		printf("  %d",A[i]);
	}
	printf("\n");
}
void main()
{
  push(3);  Print();
  push(454);  Print();
  push(432);  Print();
  push(-34); Print();
  pop();  Print();
  pop();  Print();
  pop(); Print();

}
