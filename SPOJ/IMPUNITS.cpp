#include<bits/stdc++.h>
using namespace std;
int main()
{
     long long n,x,y,a,b,g;
     while(cin>>n&&n!=-1)
     {
          x=1,y=1;
          n--;
          while(n--)
          {
               cin>>a>>b;
               x*=a,y*=b;
          }
          g=__gcd(x,y);
          cout<<x/g<<" "<<y/g<<endl;
     }
}
*long long 
