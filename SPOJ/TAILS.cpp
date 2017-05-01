/*
make dp+bits
for every index try change it or not 
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2000000][21];
int fun(bitset<20>b,int i)
{
     bitset<20> tmp;
     int a=b.to_ulong();
     if(a==0) return 0;
     if(i==20) return 1e+9;
     if(dp[a][i]!=-1) return dp[a][i];
     dp[a][i]=fun(b,i+1);
     tmp=b;
     if(!i) tmp[i]=!b[i],tmp[i+1]=!b[i+1];
     else if(i==19) tmp[i]=!b[i],tmp[i-1]=!b[i-1];
     else tmp[i]=!b[i],tmp[i+1]=!b[i+1],tmp[i-1]=!b[i-1];
     dp[a][i]=min(dp[a][i],1+fun(tmp,i+1));
     return dp[a][i];
}
int main(){
     memset(dp,-1,sizeof dp);
     bitset<20>b;
     int arr[20];
     for(int i=0;i<20;i++) scanf("%d",&arr[i]),b[19-i]=arr[i];
     cout<<fun(b,0)<<endl;
}
