#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 101
int stack[size];
int arr[size];
int top=-1;
void push(int x)
{
   if(top==size)
   {
   	printf("Error:stack is overflow\n");
    return ;
   }
   stack[++top]=x;
}
int pop()
{
	if(top==-1)
	{
     printf("Error:Stack is Empty...cannot pop\n" );
     return -1;
	}
	return stack[top--];
}
int TOP()
{
	return stack[top];
}
void DisplayString()
{

}
int main()
{
    int i=0,n;
     printf("Enter the Numbers of inputs in Array\n");
     scanf("%d",&n);
    printf("Taking inputs in Array\n");
    for(i=0;i<n;i++)
    	scanf("%d",&arr[i]);

    //pushing array into stack from index 0
    for(i=0;i<n;i++)
    	push(arr[i]);
    //poping stack and rewrite into the array
    for(i=0;i<n;i++)
    	arr[i]=pop();
    //Reversing string is accomplished here
    //Displaying The array
    printf("Reversed Array is:\n");
    for(i=0;i<n;i++)
    	printf("%d ",arr[i]);

	getch();
	return 0;
}
