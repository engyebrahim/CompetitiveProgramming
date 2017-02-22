#include <bits/stdc++.h>
using namespace std;
int c;
long long fun(long long n)
{
     c=(n==1)?0:1;
     long long sum=1;
          for(int i=2;i*i<=n;i++)
            {
                 if(n%i==0) sum+=i,c++;
                 if(n%i==0&&i*i!=n) sum+=n/i,c++; 
            }
     return sum;
}
int main ()
{
     long long n,m,fib[90];
     fib[0]=0,fib[1]=1;
     for(int i=2;i<90;i++)
        fib[i]=fib[i-1]+fib[i-2]; 
     int t;
     cin>>t;
     for(int tc=1;tc<=t;tc++)
     {
          cin>>n>>m;
          n=fun(n)%m;
          fun(n);
          cout<<"Case #"<<tc<<" : ";
          if(binary_search(fib,fib+90,c)) cout<<"YES.\n";
          else cout<<"NO.\n";
     }
}
