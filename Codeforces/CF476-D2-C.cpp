#include<bits/stdc++.h>
using namespace std;
// (b(b-1)/2) (b (a(a+1))/2 +a)
long long fun(long long a)
{
     long long x=a,y=a+1;
     if(x%2==0) x/=2;
     else y/=2;
     x%=1000000007;
     y%=1000000007;
     return (x*y)%1000000007;
}
int main()
{
     long long a,b,x,y;
     cin>>a>>b;
     x=fun(a);
     y=fun(b-1);
     //cout<<x<<" "<<y<<endl;
     x=(b*x)%1000000007;
     x=(x+a)%1000000007;
     cout<<(x*y)%1000000007<<endl;
}
