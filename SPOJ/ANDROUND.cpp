#include <bits/stdc++.h>
using namespace std;
int tree[1000000],arr[20000];
void updat(int r,int s,int e)
{
     if(s==e) 
     {
          tree[r]=arr[s];
          return;
     }
     updat(r*2,s,(s+e)/2);
     updat(r*2+1,(s+e)/2+1,e);
     
     tree[r]=tree[r*2]&tree[r*2+1];
}
 
int solve(int r,int s,int e,int x,int y)
{
     if(x>e||y<s) return (2<<32)-1;
     if(s>=x&&e<=y)
        return tree[r];
     return solve(r*2,s,(s+e)/2,x,y)&solve(r*2+1,(s+e)/2+1,e,x,y);
       
}
int main()
{
     int k,n,t,s;
     
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d%d",&n,&k);
          for(int i=0;i<n;i++) scanf("%d",&arr[i]);
          if(k>=n/2)
            {
                 s=arr[0];
                 for(int i=1;i<n;i++)
                   s&=arr[i];
                 for(int i=0;i<n;i++)
                   cout<<s<<" ";
                   cout<<endl;
            }
            else
            {
                 int a,b;
                 //cout<<1;
                 updat(1,0,n-1);
                 for(int i=0;i<n;i++)
                 {
                      a=i+k;
                      b=i-k;
                      if(a>n-1)
                      s=solve(1,0,n-1,i,n-1)&solve(1,0,n-1,0,a%n);
                      else 
                      s=solve(1,0,n-1,i,a);
                      
                      if(b<0)
                      s&=solve(1,0,n-1,0,i)&solve(1,0,n-1,n+b,n-1);
                      else
                      s&=solve(1,0,n-1,b,i);
                      cout<<s<<" ";
                 }
                 cout<<endl;
          
            }  
     }
     
} 
