#include <bits/stdc++.h>
using namespace std;
struct node
{
     int left,right,sum,best;
     node merge(node a,node b)
     {
          left=max(a.left,b.left+a.sum);
          right=max(b.right,b.sum+a.right);
          sum=a.sum+b.sum;
          best=max(a.best,max(b.best,a.right+b.left));   // a-> + <-b
     }
};
node tree[40002]; int arr[10001];
void update(int n,int s,int e)
{
     if(s==e)
         {tree[n].left=arr[s],tree[n].right=arr[s],tree[n].sum=arr[s],tree[n].best=arr[s]; return;}
     update(n*2,s,(s+e)/2);
     update(n*2+1,(s+e)/2+1,e);
     tree[n].merge(tree[n*2],tree[n*2+1]);
}
node solve(int n,int s,int e,int a,int b)
{
     if(b<a)    // if y==b at this call -> solve(1,0,n-1,y+1,b).left);
      return  tree[0];
     node ret;
     int m=(s+e)/2;
     //devied the condutions to avoid wrong ranges 
     if(s>=a&&e<=b)
       return  ret= tree[n];
       
     if(m>=b)   //if  [m+1,e] out of rang [a,b], means no sol at  return solve(n*2+1,m+1,e,a,b);
     return solve(n*2,s,m,a,b);
     
     if(a>m)  //if  [s,m] out rang [a,b], means no sol at  return solve(n*2,s,m,a,b);
     return solve(n*2+1,m+1,e,a,b);
     //if two braches have sol
     node x=solve(n*2,s,m,a,b);
     node y=solve(n*2+1,m+1,e,a,b);
     ret.merge(x,y);
     
     return ret;
}
int ans(int x,int y,int a,int b,int n)
{
     if(y<a)
      return solve(1,0,n-1,x,y).right+solve(1,0,n-1,y+1,a-1).sum+solve(1,0,n-1,a,b).left; 
      
      return max(max(solve(1,0,n-1,a,y).best,solve(1,0,n-1,x,a-1).right+solve(1,0,n-1,a,b).left),
      solve(1,0,n-1,x,y).right+solve(1,0,n-1,y+1,b).left);
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&n);
         for(int i=0;i<n;i++)
              scanf("%d",&arr[i]);
         update(1,0,n-1);
         scanf("%d",&m);
         for(int c,d,a,b,i=0;i<m;i++)
         {
              scanf("%d%d%d%d",&a,&b,&c,&d);
              printf("%d\n",ans(a-1,b-1,c-1,d-1,n));
         }
    }
}
