#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* GetNewNode(int x)
{
	struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}
struct Node*  push(struct Node* head,int data)
{
    struct Node* newNode=GetNewNode(data);
    newNode->next=head;
    head=newNode;
  return head;
}
struct Node*  pop(struct Node* head)
{
   struct Node* curr=head;
   if(head==NULL)
   {
   	printf("Stack is Empty...\n");
   	return head;
   }
   head=head->next;
   free(curr);
	return head;
}
void Print(struct Node* head)
{
	printf("stack of List is Below\n--------------------\n");
	while(head!=NULL)
	{
		printf(" %d\n",head->data);
		head=head->next;
	}
	printf("\n");
}
void IsEmpty(struct Node* head)
{
  if(head==NULL) {printf("stack IS Empty");}
  else{printf("stack IS NOT Empty");}
}
void main()
{
   struct Node* List=NULL;
   List=push(List,1);  Print(List);
   List=push(List,2);  Print(List);
   List=push(List,3); Print(List);
   List=push(List,4);  Print(List);
   List=pop(List);   Print(List);
   List=pop(List);  Print(List);
   List=pop(List);Print(List);
   List=pop(List);Print(List);



}
