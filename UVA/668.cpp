#include<bits/stdc++.h>
using namespace std;

int main(){
     int t,n;
     cin>>t;
     bool arr[1001];
     int sum,e,f=0;
     while(t--)
     {
          if(f) cout<<endl;
          f=1;
          sum=0;
          cin>>n;
          memset(arr,0,sizeof arr);
          for(int i=2;i<=n;i++)
          {
               e=i;
               arr[i]=1;
               sum+=i;
               if(sum-n==1)
               {
                    arr[i]=arr[2]=0;
                    e=i+1;
                    break;
               }
               else if(sum-n>1)
               {
                    arr[sum-n]=0;
                    break;
               }
               else if(sum==n) break;
          }
          for(int i=2;i<e;i++) if(arr[i]) cout<<i<<" ";
          cout<<e<<endl;
          
     }
}
