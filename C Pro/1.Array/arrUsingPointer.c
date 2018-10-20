#include<stdlib.h>
#include<stdio.h>
void setArray(int*);
void main()
{
	int data[5]={0};
    int i,*ptr;
    ptr=data;
     setArray(ptr);

     for(i=0;i<5;i++)
     {
     	printf("data[%d]=%d\n",i,data[i] );
     }

     getch();
}

void setArray(int* ptr)
{
  int i;

  for(i=0;i<5;i++)
  {
  	printf("myArray[%d]=",i );
  	scanf("%d",(ptr+i) );
  }

}