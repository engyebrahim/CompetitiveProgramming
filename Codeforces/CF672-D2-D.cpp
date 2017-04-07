//editorial: http://codeforces.com/blog/entry/44821
#include<bits/stdc++.h>
using namespace std;

int main() {
     long long n,k;
     scanf("%lld%lld",&n,&k);
     long long arr[500004],t;
     for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
     long long s=0,e=2e+9,m,z=0,sum;
     
     while(s<e)
     {
          m=(s+e+1)/2;
          sum=0;
          for(int i=0;i<n;i++) sum+=max(z,m-arr[i]);
          if(sum<=k) s=m;
          else e=m-1;
     }
     t=k;
     for(int i=0;i<n;i++)
       t-=max(s-arr[i],z),arr[i]=max(s,arr[i]);
     for(int i=0;i<n;i++)
       if(arr[i]==s&&t)
         t--,arr[i]++;
     s=0,e=2e+9;
     while(s<e)
     {
          m=(s+e)/2;
          sum=0;
          for(int i=0;i<n;i++) sum+=max(z,arr[i]-m);
          if(sum<=k) e=m;
          else s=m+1;
     }
     t=k;
     for(int i=0;i<n;i++)
       t-=max(arr[i]-s,z),arr[i]=min(s,arr[i]);
     
     for(int i=0;i<n;i++)
       if(arr[i]==s&&t)
         t--,arr[i]--;
         
     sort(arr,arr+n);
     cout<<arr[n-1]-arr[0]<<endl;
}
