#include <bits/stdc++.h>
using namespace std;

int main() {
     int t,x,k; long long mn,y;
     cin>>t;
     while(t--)
     {
          mn=1e+18;
          cin>>x;
          for(int i=1;i<=x;i++)
          {
               for(int j=1;j<=x;j++)
               {
                    if(i*j>x||x%(i*j)!=0) continue;
                    k=x/(i*j);
                    y=i*j*2+k*j*2+k*i*2;
                    //cout<<i<<" "<<j<<" "<<k<<" "<<y<<endl;
                    mn=min(y,mn);
               }
          }
          cout<<mn<<endl;
     }
}
