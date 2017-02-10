#include <iostream>
#include <set>
#include <cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int n,m,c,a,b,r[200001],p[200001],t[200002];
int parent(int idx)
{
     if(p[idx]==idx)  return idx;
     return p[idx]=parent(p[idx]);
}
void update(int x,int val)
{
     for(int i=x;i<200001;i+=i&-i)
       t[i]+=val;
}
int solve(int x)
{
     int sum=0;
     for(int i=x;i>0;i-=i&-i)
       sum+=t[i];
     return sum;
}
int main()
{
     scanf("%d%d",&n,&m);
     for(int i=1;i<=n;i++)
         p[i]=i,r[i]=1;
     memset(t,0,sizeof t);
     update(1,n);
     int s,e,mid,tmp=n;
     while(m--)
     {
          scanf("%d",&c);
          if(c==0)
          {
               scanf("%d%d",&a,&b);
               if(parent(a)==parent(b)) continue;
               update(r[parent(a)],-1);
               update(r[parent(b)],-1);
               update(r[p[a]]+r[p[b]],1);
               r[p[b]]+=r[p[a]];
               p[p[a]]=p[b];
               tmp--;
          }
          else
          {
               scanf("%d",&a);
               s=1,e=n,a=tmp-a+1;
               while(s<e)
               {
                    mid=(s+e)/2;
                    if(solve(mid)>=a) e=mid;
                    else s=mid+1;
               }
               cout<<s<<endl;
          }
     }
}
