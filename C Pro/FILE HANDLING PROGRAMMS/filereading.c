#include<stdio.h>
#include<string.h>

void main()
{
	FILE *fpointer;
	char ch;
	fpointer=fopen("raj.txt","r");
	fclose(
	if(fpointer==NULL)
	{
		printf("file doesn't Exist");
	}
	
	while((ch=fgetc(fpointer))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(fpointer);
	
}