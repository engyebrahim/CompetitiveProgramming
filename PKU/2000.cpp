#include<iostream>
using namespace std;

int main()
{
    long long m,n,k,ans;
    while(cin>>n&&n)
    {
         m=n;
         k=1,ans=0;
         while(n)
         {
              if(n>=k) n-=k;
              else {ans+=k*n; break;}
              ans+=k*k;
              k++;
         }
         cout<<m<<" "<<ans<<endl;
    }
}
