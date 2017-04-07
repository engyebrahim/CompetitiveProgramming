/*
- it simply in k turns calculate on each turn number of sequences of length i ending in pos.more detailed 
- save in b array the next turn ; number of sequnce in curent length and end value in it smaller than arr[i]
- make every time new bit save the result of curent length and culculate the next in b
*/
#include<bits/stdc++.h>
using namespace std;
int bit[100003],MOD=5000000;
void add(int i,int x)
{
     for(;i<=100001;i+=i&-i)
       bit[i]=(bit[i]%MOD+x%MOD)%MOD;
}
int solve (int i)
{
     long long ret=0;
     for(;i>0;i-=i&-i)
      ret=(ret%MOD+bit[i]%MOD)%MOD;
     return ret;
}
int main() {
     int k,n; int arr[10002],b[10002];
     scanf("%d%d",&n,&k);
     for(int i=0;i<n;i++)
        scanf("%d",&arr[i]),arr[i]++,b[i]=1;
    
     for(int i=1;i<=k;i++)
     {
          memset(bit,0,sizeof bit);
          for(int j=0;j<n;j++)
          {
               add(arr[j],b[j]);
               b[j]=solve(arr[j]-1); 
          }
     }
     printf("%d\n",solve(100001));
}
