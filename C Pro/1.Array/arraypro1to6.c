#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int menu();
int setThisArray(int array[],int length);
int* setNewArray();
void  displayArray(int *pA);
int  lengthOfArray(int array[]);
int insertAtLast(int array[]);
void insertArPos(int *pA);
int deleteAtLast(int array[]);
void deleteAtPos(int *pA);
int merge2Array(int array1[],int array2[],int n1,int n2);

int main()
{
	int choose;

	do{
	choose=menu();

     switch(choose)
     {
     	case 0:if(1) return;

        case 1:{

                }break;

        case 2:{}break;

        case 3:{}break;

        case 4:{}break;

        case 5:{}break;

        case 6:{}break;

     }

     }while(1);

     getch();
}

int menu()
{
	int choose;
   printf("Menu for Array is given below\n");
   printf("-------------------------------------\n");
   printf("----101>set Array Elements\n");
   printf("----102>Display Array Elements");
   printf("1.Traverse Array\n");
   printf("2.Insert Element At the end\n");
   printf("3.Insert Element At given Poistio\n");
   printf("4.Delete Element From the end\n");
   printf("5.Delete Element From given Poistion\n");
   printf("6.Merge 2 Arrays\n");
   printf("0.Exit\n");
   printf("Choose Any one\n");
   scanf("%d",&choose);

   return choose;
}
/*int setThisArray(int array[],int length)
{
    int i;
    for (i = 0; i < length; ++i)
    {
        printf("array[%d]=",i );
    	scanf("%d",&array[i]);
    }
    return array;
}
*/
int* setNewArray()
{
    int i,n;
	int *ptr;
	printf("Enter Number of Elements :->" );
	scanf("%d",&n);
    ptr=(int*)malloc(n * sizeof(int));

    //Take input from user

   for ( i = 0; i < n; ++i)
   {
   	/* code */
   	printf("array[%d]=\n",i );
   	scanf("%d",(ptr+i));
   }
   return ptr;
 }
void displayArray(int *ptr,)
{
    int i;
 for(i=0;i<lengthOfArray(ptr))
}
