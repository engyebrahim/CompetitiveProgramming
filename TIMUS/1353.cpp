#include<bits/stdc++.h>
using namespace std;
int m,dp[10][100];
int fun(int idx,int s)
{
     if((idx==9&&s==m)||(idx==9&&m==1&&s==0)) return 1;
     if(idx==9) return 0;
     if(dp[idx][s]!=-1) return dp[idx][s];
     dp[idx][s]=0;
     for(int i=0;i<10;i++)
     dp[idx][s]+=fun(idx+1,s+i);
     return dp[idx][s];
}
int main(){
     cin>>m;
     memset(dp,-1,sizeof dp);
     cout<<fun(0,0)<<endl;;
}
