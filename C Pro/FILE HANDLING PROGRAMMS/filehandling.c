#include <stdio.h>
#include<string.h>
int main()
{
    FILE *fsource,*ftarget;
    char data[10]="rajrpatel";
    int length=strlen(data);
    int i;
    char ch;
    fsource=fopen("Diary.txt","r");//
    ftarget=fopen("raj.txt","a"); //I opened in append mode so ftarget pointer will be point after the last character of the file
    /*for(i=0;i<length;i++)
       fputc(data[i],fptr);

    fptr=fopen("raj.txt","r");
*/
    while( (ch=fgetc(fsource)) != EOF)
    {
        fputc(ch,ftarget);
    }

    fclose(fsource);
	fclose(ftarget);

    return 0;
}
