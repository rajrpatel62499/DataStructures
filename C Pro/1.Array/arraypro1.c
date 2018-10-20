#include<stdio.h>
#include<conio.h>
void display(int array[]);
void main()
{
	int array[10];
    int i;
	printf("Enter elements of array\n" );
    
    for(i=0;i<10;i++)
    {
        printf("array[%d]=",i);
        scanf("%d",&array[i]);
    	    }

    display(array);
  getch();

}

void display(int array[])
{
   int i;
   for(i=0;i<10;i++)
   {
   	printf("array[%d]= %d\n",i,array[i]);
   }
}
