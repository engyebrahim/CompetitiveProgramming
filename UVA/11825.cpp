#include <bits/stdc++.h>
#include<string.h>
using namespace std;
int n,p[20],arr[1<<17],dp[1<<17];
int fun(int mask){
    if(mask == 0) return 0;
    if(dp[mask] != -1) return dp[mask];
    int ret = 0;
    for(int i = mask ;i;i =(i - 1)&mask){
        if(arr[i]){
            ret = max(ret,fun(mask&(~i))+1);
        }
    }
    return dp[mask]=ret;
}
int main()
{
     int n,tc=0;
     while(cin>>n&&n)
     {
          tc++;
          for(int m,x,i=0;i<n;i++)
          {
               p[i]=1<<i;;
               scanf("%d",&m);
               while(m--){
                    scanf("%d",&x);
                    p[i]|=(1<<x);
               }
          }
          for(int x,i=0;i<(1<<n);i++)
              {
                   x=arr[i]=0;
                   for(int j=0;j<n;j++)
                    if(i&(1<<j)) x|=p[j];
                    if(x==((1<<n)-1)) arr[i]=1;
              }
          memset(dp,-1,sizeof dp);
          cout<<"Case "<<tc<<": ";
          cout<<fun((1<<n)-1)<<endl;
     }
}
