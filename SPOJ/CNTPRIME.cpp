#include<bits/stdc++.h>
using namespace std;
int tree[100000],arr[100000];
bool isprime[1000002];
void refresh(int node,int s,int e)
{
     if(arr[node]){
          if(!isprime[arr[node]])
            tree[node]=e-s+1;
          else 
            tree[node]=0;
          arr[node*2]=arr[node*2+1]=arr[node];
          arr[node]=0;
     }
}
void update(int node,int s,int e,int x,int y,int val)
{
     if(x>e||s>y)
     {
          refresh(node,s,e);
          return;
     }
     if(s>=x&&e<=y)
     {
          arr[node]=val;
          refresh(node,s,e);  
          return;
     }
     refresh(node,s,e);
     update(node*2,s,(s+e)/2,x,y,val);
     update(node*2+1,(s+e)/2+1,e,x,y,val);
     
     tree[node]=tree[node*2]+tree[node*2+1];
}
int solve(int node,int s,int e,int x,int y)
{
     if(x>e||s>y) return 0;
     refresh(node,s,e);
     if(s>=x&&e<=y)
          return tree[node];
     return solve(node*2,s,(s+e)/2,x,y)+solve(node*2+1,(s+e)/2+1,e,x,y);
}
int main() {
     int t;
     scanf("%d",&t);
     int n,q;
     int x,y,val;
     for(int i=2;i*i<=1000000;i++)
     {
          if(!isprime[i])
          for(int j=i*i;j<=1000000;j+=i)
             isprime[j]=1;
     }
     
     for(int tc=1;tc<=t;tc++)
     {
          memset(arr,0,sizeof arr);
          scanf("%d%d",&n,&q);
          for(int i=0;i<n;i++)
          {
               scanf("%d",&x);
               update(1,0,n-1,i,i,x);
          }
          printf("Case %d:\n",tc);
          while(q--)
          {
               scanf("%d",&x);
               if(x)
               {
                    scanf("%d%d",&x,&y);
                    printf("%d\n",solve(1,0,n-1,x-1,y-1));
               }
               else
               {
                    scanf("%d%d%d",&x,&y,&val);
                    update(1,0,n-1,x-1,y-1,val);
               }
          }
     }
}
