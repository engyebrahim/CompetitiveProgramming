/*
- it simply in k turns calculate on each turn number of sequences of length i ending in pos.more detailed 
- save in b array the next turn ; number of sequnce in curent length and end value in it smaller than arr[i]
- make every time new bit save the result of curent length and culculate the next in b
- to avoid repetition if any value repeted then its value in b will be its sumation - sumation[last ]
*/
#include<bits/stdc++.h>
using namespace std;
int M=5000000;
int n,k,arr[10002],b[10002],last[10002],bit[10004];
void st(int idx,int x)
{
     if(x<0) x+=M;  // when ?
     for(;idx<10004;idx+=idx&-idx) bit[idx]=((long long)x%M+bit[idx]%M)%M;
}
int solve(int idx)
{
     int ret=0;
     for(;idx>0;idx-=idx&-idx)  ret=((long long)ret%M+bit[idx]%M)%M;
     return ret;
}
int main() {
     scanf("%d%d",&n,&k);
     map<int,int> m;
     memset (last,-1,sizeof last) ;
     for(int i=0;i<n;i++)
     {
          scanf("%d",&arr[i]);
          m[arr[i]]=-1;
     }
     map<int,int>::iterator it=m.begin();
     int c=1;
     for(;it!=m.end();it++)  m[it->first]=c++;
     for(int i=0;i<n;i++) 
     {
          arr[i]=m[arr[i]];
          if(last[arr[i]]==-1) last[arr[i]]=1,b[i]=1;
          else b[i]=0;
     }
     for(int i=0;i<k;i++)
     {
          memset(bit,0,sizeof bit);
          memset (last,0,sizeof last) ;
          for(int j=0;j<n;j++)
          {
               st(arr[j],b[j]);
               b[j]=((long long)solve(arr[j]-1)%M-last[arr[j]]%M)%M;
               last[arr[j]]=((long long)b[j]%M+last[arr[j]]%M)%M;
          }
     }
     cout<<solve(10002)<<endl;
} 
