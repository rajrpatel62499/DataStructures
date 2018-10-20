#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"C:\Users\Administrator\Desktop\C Pro\5.Tree\Queue operations.c"
#define size 101
struct Node
{
    int data;
   struct Node* left;
   struct Node* right;
};

struct Node* getNewNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void preOrder(struct Node* root)
{

    if(root)
    {
      printf("%d ",root->data);
      preOrder(root->left);
      preOrder(root->right);
    }
}
void inOrder(struct Node* root)
{
    if(root)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
void postOrder(struct Node* root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
void levelOrder(struct Node* root)
{
    struct Node* curr;
if(root)
{
    struct Queue* Q=createQueue(size);
    enQueue(Q,(int)root);
    while(!isEmpty(Q))
    {
       curr=(struct Node*)deQueue(Q);
       printf("%d ",curr->data);

       if(curr->left)
        enQueue(Q,(int)curr->left);
       if(curr->right)
        enQueue(Q,(int)curr->right);
    }
    deleteQueue(Q);
}
}
struct Node* Find(struct Node* root,int data)
{
  struct Node* curr=root;
  if(curr->data==data)
  {
      printf("Data found!!");
      return curr;
  }else if(data<curr->data)
  {
      return (Find(curr->left,data));
  }else if(data>curr->data)
  {
      return (Find(curr->right,data));
  }else
  {
      printf("Data Not Found");
      return NULL;
  }
}
struct Node*  insert(struct Node* root,int data)
{
 struct Node* newNode=getNewNode(data);
 struct Node* curr;
 if(root==NULL)
 {
   root=newNode;
   return root;
 }else
 {
     curr=root;
     if(data<curr->data)
        curr->left=insert(curr->left,data);
     else if(data>curr->data)
        curr->right=insert(curr->right,data);
    return curr;
 }


}
int main()
{
struct Node* root=NULL;
  root=insert(root,5);
  root=insert(root,4);
  root=insert(root,3);
  root=insert(root,2);
  root=insert(root,1);

  inOrder(root);
 return 0;
}
