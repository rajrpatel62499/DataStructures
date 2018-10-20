#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int  lin_Search(int L[],int N,int item)
{
	int i=0;
	for(i=0;i<N;i++)
	{
		if(L[i]==item)
		{
	      printf("Item search Successfully At index %d",i);
		return item;
	    }
	}
	printf("Item Not Found!!");
	return ;
}
int main()
{
	int A[]={23,54,65,76,23,73,51,86,32,99};
	int item=11;
	lin_Search(A,10,item);
   return 0;
}
