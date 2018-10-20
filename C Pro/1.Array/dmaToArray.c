#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
void main()
{
	int *ptr;
    int length,i,sum=0;
    printf("Enter No of Elements\n");
    scanf("%d",&length);
	ptr=(int*)malloc(length *sizeof(int));
   
   if(ptr==NULL)
   {
   	printf("contiguous memory is not available\n");
   }
   //taking inputs
	for(i=0;i<length;i++)
	{
		printf("array[%d]=",i );
		scanf("%s",&ptr[i]);
		sum+=*(ptr+i);
	}

	printf("-----------------------------------------\n");
	for(i=0;i<length;i++)
	{
		printf("array[%d]=%d\n",i,ptr[i] );
	}

  printf("Sum of array is:%d",sum );
  free(ptr);
}