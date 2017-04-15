#include <bits/stdc++.h>
using namespace std;

int main() {
     int t,n,p,arr[4000],x,s,ans;
     cin>>t;
     while(t--)
     {
          memset(arr,0,sizeof arr);
          cin>>n>>p;
          while(p--)
          {
               cin>>x; s=x;
               while(s<=n) arr[s]=1,s+=x;
          }
          ans=0;
          for(int i=1;i<=n;i++) if(arr[i]&&i%7!=0&&i%7!=6) ans++;
          cout<<ans<<endl;
     }
}
