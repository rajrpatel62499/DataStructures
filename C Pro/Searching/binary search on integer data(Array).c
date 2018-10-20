#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int bin_search(int L[],int N,int item)
{
    int l=0,u=N-1 ,m;

    while(l<=u){
            m = (l+u)/2;
      if(L[m]==item)
         {
             printf("Item successfully find at index %d",m);
             return L[m];
         }else if(item<L[m])
          {u=m-1;}
      else
          {l=m+1;}

    }
    printf("Item Not Found");
    return ;
}
void main()
{
    int A[]={11,22,33,44,55,66,77,88,99,100};
    int item=11;
    int N=10;
    bin_search(A,N,item);
}
