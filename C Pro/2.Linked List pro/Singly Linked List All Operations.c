#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Node
{
int data;
struct Node* next;
};

int CountListMember(struct Node*);
void Print(struct Node* head);
struct Node* ReverseList(struct Node* head);
struct Node* InsertAtBeg(struct Node* head,int data);
struct Node* InsertAtLast(struct Node* head,int data);
struct Node* InsertAtNth(struct Node* head,int data,int n);
struct Node* deleteAtBeg(struct Node* head);
void deleteAtLast(struct Node* head);
struct Node* deleteAtNth(struct Node* head,int n);

void main()
{
 int i,size,num,pos=1,choice;

 struct Node* MarksList=NULL;

 do{

    printf("Linked list operations \n=================================\n");
    printf("1.Creating List\n");
    printf("2.Inserting Element At Beginning\n");
    printf("3.Insert Element At End\n");
    printf("4.Insert Element At Nth Position\n");
    printf("5.Delete Element At Beginning\n");
    printf("6.Delete Element At Last\n");
    printf("7.Delete Element At Nth position\n");
    printf("8.Length of the list\n");
    printf("9.REVERSE A LIST\n");
    printf("10.Print List\n");
    printf("11.EXIT\n");

    printf("Make Choise : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:{
                printf("Enter the Size of List");
                scanf("%d",&size);
                for(i=0;i<size;i++)
                {
                  printf("Enter Number:");
                  scanf("%d",&num);
                  MarksList=InsertAtLast(MarksList,num);
                  Print(MarksList);
                }
                printf("List is Successfully Created!!\n");
              }break;

      case 2:{
               printf("Enter Number:");
               scanf("%d",&num);
               MarksList=InsertAtBeg(MarksList,num);
              }break;
      case 3:{
               printf("Enter Number:");
               scanf("%d",&num);
             MarksList=InsertAtLast(MarksList,num);
              }break;
      case 4:{
               printf("Enter Number:");
               scanf("%d",&num);
               printf("At which Poistion?  ->");
               scanf("%d",&pos);
                MarksList=InsertAtNth(MarksList,num,pos);
             }break;
      case 5:{
             MarksList=deleteAtBeg(MarksList);
             }break;
      case 6:{
               deleteAtLast(MarksList);
              }break;
      case 7:{
               printf("Delete At which poistion? ->");
               scanf("%d",&pos);
               MarksList=deleteAtNth(MarksList,pos);
              }break;
      case 8:{
                printf("Length of List is:%d\n",CountListMember(MarksList));
             }break;
      case 9:{ MarksList=ReverseList(MarksList);}break;
      case 10:{Print(MarksList);}break;
      case 11:{exit(0);}break;
    }

 }while(1);

 getch();
}
int CountListMember(struct Node* head)
{
  int count=0;
  while(head!=NULL)
  {
    count++;
    head=head->next;
  }
  return count;
}
void Print(struct Node* head)
{
struct Node* last=head;
 printf("List is:");
 while(last!=NULL)
 {
     printf(" %d",last->data);
     last=last->next;
 }
 printf("\n");
}
struct Node* ReverseList(struct Node* head)
{
	struct Node *current,*prev,*next;
	int i;
	prev=NULL;//Initially for store ./the first node next part previous Must be set to NULL
    current=head;//It's point to the first node which is current node
    while(current!=NULL)
	{
         next=current->next;//It will contain the next node Address
         current->next=prev;//It will stroe the previous node address into the current node next position(it will reverse the list)
         prev=current;//change the prev point to the current position
         current=next;	//change the current poistion to the next
	}
	return prev;//At last Node Address will be store in prev
}
struct Node* InsertAtBeg(struct Node* head,int data)
{
 struct Node* new_Node=(struct Node*)malloc(sizeof(struct Node));

 new_Node->data=data;
 if(head==NULL){
        head=new_Node;
     new_Node->next=NULL;
 }
 else{
    new_Node->next=head;
    head=new_Node;
 }
}

struct Node* InsertAtLast(struct Node* head,int data)
{
  struct Node* last;
  struct Node* new_Node=(struct Node*)malloc(sizeof(struct Node));

  new_Node->data=data;
  new_Node->next=NULL;
 if(head==NULL)
 {
   head=new_Node;
   return head;
 }else{
   last=head;

   while(last->next!=NULL)
    last=last->next;

   last->next=new_Node;
   return head;
 }
}


struct Node* InsertAtNth(struct Node* head,int data,int n)
{
	struct Node *prev,*current;
    int i=0;
	struct Node* new_Node=(struct Node*)malloc(sizeof(struct Node));
     new_Node->data=data;
     new_Node->next=NULL;

	if(n==1)
	{
       new_Node->next=head;
       head=new_Node;
	   return head;
	}else if(n<=CountListMember(head))
	{
      prev=head;
	for(i=0;i<n-2;i++)
	{
      prev=prev->next;
	}
     current=prev->next;
     new_Node->next=current;
     prev->next=new_Node;

     return head;
	}else{
	 printf("Postition is Invalid ....Try Again");
	}
}
struct Node* deleteAtBeg(struct Node* head)
{
  struct Node* next;
   if(head==NULL)
   {
    printf("List is Empty");
    return head;
   }
   next=head->next;
   free(head);
   head=next;
   return head;
}
void deleteAtLast(struct Node* head)
{
  struct Node* last=head,*prev=head;
  int length;
  int i=0;
  length=CountListMember(head);

  if(head==NULL){printf("List is empty\n"); return;  }
   for(i=0;i<length-2;i++)
    prev=prev->next;

   while(last->next!=NULL)
     last=last->next;

   prev->next=NULL;

   free(last);

}
struct Node* deleteAtNth(struct Node* head,int n)
{
	int i=0;
	struct Node *prev,*current,*next;
	prev=head;//Point the First Element in the list

	if(n==1)
	{
		next=head->next;
         free(head);
         head=next;
         return head;
	}else if(n<=CountListMember(head))
	{
	for(i=0;i<n-2;i++)
		prev=prev->next;//Point to N-1 element

	current=prev->next;//point Nth element
	next=current->next;//Point N+1 element

	prev->next=next;//N-1 element directly link with the n+1 element so Nth element will be deleted
	free(current);//Free the memory of Nth element
	return head;
	}else{

	printf("Position is Invalid ...Try Again");
	return head;

	}

}
