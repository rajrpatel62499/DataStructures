#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* GetNewNode(int data)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
struct Node* InsertAtBeg(struct Node* head,int data)
{
	struct Node* newNode=GetNewNode(data);
	newNode->next=head;
	head=newNode;
	return head;
}
struct Node* InsertAtLast(struct Node* head,int data)
{
	struct Node* newNode=GetNewNode(data);
    struct Node* last=head;
    if(head==NULL)
    {
    	head=newNode;
    	return head;
    }
    while(last->next!=NULL)
    {
    	last=last->next;
    }
    newNode->prev=last;
    last->next=newNode;
   return head;
}
struct Node* InsertAtNth(struct Node* head,int data,int N)
{
	struct Node* newNode=GetNewNode(data);
	struct Node *prev=head,*curr;
	int i=0;
	if(N==1)
		{return InsertAtBeg(head,data);}
	for (i = 0; i < N-2; ++i)
	{
		prev=prev->next;
	}

    curr=prev->next;
    newNode->prev=prev;
    newNode->next=curr;
    prev->next=newNode;
    return head;
}
struct Node* deleteAtBeg(struct Node* head)
{
  struct Node* FirstNode=head;
  if(head==NULL){printf("List is empty");}
  head=head->next;
  head->prev=NULL;
  free(FirstNode);
  return head;
}
struct Node* deleteAtLast(struct Node* head)
{
    struct Node* LastNode=head,*prev;
  if(head==NULL){printf("List is empty");}

  while(LastNode->next==NULL)
  {
     LastNode=LastNode->next;
  }
  prev=LastNode->prev;
  prev->next==NULL;
  free(LastNode);
}
struct Node* deleteAtNth(struct Node* head,int N)
{
  struct Node *prev=head,*curr,*next;
  int i=0;

  if(N==1){return deleteAtBeg(head);}
  for(i=0;i<N-2;i++)
  {
    prev=prev->next;
  }
  curr=prev->next;
  next=curr->next;
  if(next==NULL)
  {
     prev->next=next;
     free(curr);
     return head;
  }
  prev->next=next;
  next->prev=prev;
  free(curr);
  return head;
}
int  Length(struct Node* head)
{
   int length=0,i=0;
   while(head!=NULL)
   {
       length++;
       head=head->next;
   }
   printf("\nLength is : %d\n",length);
   return length;
}
void Print(struct Node* head)
{
  printf("List is: ");
  while(head!=NULL)
  {
  printf(" %d",head->data);
  head=head->next;
  }
  printf("\n");
}


void main()
{
    struct Node* DoubleList=NULL;
    DoubleList=InsertAtBeg(DoubleList,5); Print(DoubleList);
    DoubleList=InsertAtLast(DoubleList,4); Print(DoubleList);
    DoubleList=InsertAtNth(DoubleList,3,3); Print(DoubleList);
    DoubleList=InsertAtNth(DoubleList,2,4); Print(DoubleList);
    DoubleList=InsertAtNth(DoubleList,1,5); Print(DoubleList);
    DoubleList=deleteAtNth(DoubleList,1); Print(DoubleList);
    DoubleList=deleteAtNth(DoubleList,4); Print(DoubleList);

	getch();
}
