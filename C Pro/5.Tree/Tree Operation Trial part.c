#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct BstNode
{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
struct BstNode* getNewNode(int data)
{
 struct BstNode* newNode=(struct BstNode*)malloc(sizeof(struct BstNode));
  newNode->data=data;
  newNode->left=NULL;
  newNode->right=NULL;
  return newNode;
}
struct BstNode* Find(struct BstNode* root,int data)
{

     if(root->data==data)
    {
        printf("Data Found Successfully\n");
        return root;
    }
    if(data<root->data)
    {
         return (Find(root->left,data));
    }
    if(data>root->data)
    {
       return ( Find(root->right,data));
    }
    if(root==NULL)
    {
      printf("Data Not Found!!\n");
       return root;
    }

}
struct BstNode* insert(struct BstNode* root,int data)
{
   struct BstNode* newNode=getNewNode(data);

     if(root==NULL)
     {
         root=newNode;
         return root;
     }else if(data<root->data)
     {
         root->left=insert(root->left,data);
     }else
     {
         root->right=insert(root->right,data);
     }
     return root;
}
void inOrder(struct BstNode* root)
{
    if(root)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }

}
void preOrder(struct BstNode* root)
{
    if(root)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }

}
void postOrder(struct BstNode* root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }

}
void main()
{
struct BstNode* root=NULL;
   root=insert(root,7);
   root=insert(root,3);
   root=insert(root,4);
   root=insert(root,1);
   root=insert(root,2);
   root=insert(root,6);
   root=insert(root,5);
   root=insert(root,13);
   root=insert(root,10);
   root=insert(root,16);
    root=insert(root,8);
     root=insert(root,12);
 root=insert(root,15);
 root=insert(root,14);
 root=insert(root,18);

 inOrder(root); printf("\n");
 preOrder(root);printf("\n");
 postOrder(root);printf("\n");

}
