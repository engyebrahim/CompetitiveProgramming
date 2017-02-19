#include<bits/stdc++.h>
using namespace std;
int p[9];
string ans; int n;
bool fun(int sum,int idx)
{
     if(idx==-1&&sum==n) return 1;
     else if(idx==-1) return 0;
     bool f=0;
     if(fun(sum+p[idx],idx-1)) ans+='+',f=1;
     else if(fun(sum-p[idx],idx-1)) ans+='-',f=1;
     else if(fun(sum,idx-1)) ans+='0',f=1;
     return f;
}
int main()
{
     int t;
     scanf("%d",&t);
     p[0]=1;
     for(int i=1;i<9;i++) p[i]=p[i-1]*3;
     while(t--)
     {
          cin>>n;
          ans="";
          for(int i=0;i<=7;i++)
          {
               if(fun(p[i],i-1)) break;
          }
          ans+='+';
          reverse(ans.begin(),ans.end());
          cout<<ans<<endl;
     }
}
