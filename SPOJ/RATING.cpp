#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
     int a,b,idx;
};
bool cmp(node a,node b)
{
     if(a.a!=b.a) return a.a<b.a;
     return a.b<b.b;
}
node arr[300000];
int ans[300000]={},tree[100002]={};
void update(int ind)
{
    for(int i=ind;i<100002;i+=(i&-i))
      tree[i]++;
}
int solve(int ind)
{
     int s=0;
     for(int i=ind;i>0;i-=(i&-i))
      s+=tree[i];
     return s;
}
int main()
{
     scanf("%d",&n);
     for(int i=0;i<n;i++)
        {scanf("%d%d",&arr[i].a,&arr[i].b); arr[i].idx=i;}
     sort(arr,arr+n,cmp);
     //cout<<arr[0].a;
     for(int i=0;i<n;i++)
     {
          if(i&&arr[i].a==arr[i-1].a&&arr[i].b==arr[i-1].b)
             ans[arr[i].idx]=ans[arr[i-1].idx];
          else ans[arr[i].idx]=solve(arr[i].b);
          update(arr[i].b);
     }
     for(int i=0;i<n;i++)
       cout<<ans[i]<<endl;
}
