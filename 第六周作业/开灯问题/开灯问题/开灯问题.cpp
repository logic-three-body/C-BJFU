#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<stdio.h>
int main()
{
 int n,k,count,i,j;
 scanf("%d%d",&n,&k);
 for(i=1;i<=n;i++)
 {
  count=0;
  for(j=1;j<=k;j++)
  {
   if(i%j==0)count=count+1;
  }
  if(count%2==1)printf("%d ",i);
 }
 return 0;
}