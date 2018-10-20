#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
char stack[size];
int tos=-1;
void push(char ch)
{
	stack[++tos]=ch;
}
char pop()
{
	return stack[tos--];
}
void main()
{
  char string[size];
  int strlength;
  int i=0;
  printf("Enter a string :");
  scanf("%s",string);
  strlength=strlen(string);
 printf("%d",strlength);
  //push the characters one by one to stack
  for(i=0;i<=strlength;i++)
    push(string[i]);
//pop the stack and store into the string array
for(i=0;i<=strlength;i++)
   string[i]=pop();

//Display string
  printf("Reversed string is:%s",string);


	getch();

}
