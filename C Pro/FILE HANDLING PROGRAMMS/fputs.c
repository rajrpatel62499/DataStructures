#include<stdio.h>
#include<conio.h>

void main()
{
	FILE *fpointer;
	int n;
	char *str;
	printf("Enter Number of character you want to Store\n");
	scanf("%d",&n);
	str=*(void)malloc(n *sizeof(char));
	fpointer=fopen("fputs.txt","w");
	
	if(fpointer==NULL)
	{
		printf("file not Exits");
	}else
	{
    	printf("Enter String You want to write into Text file\n");
		gets(str);
		fputs(str,fpointer);
		printf("Data is Successfully Written");
	}
}