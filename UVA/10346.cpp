#include <bits/stdc++.h>
using namespace std;

int main() {
     long long  n,k, sum;
     while(cin>>n>>k)
     {
          sum=n;
          while(n/k)
          {
               sum+=n/k;
               n=n/k+n%k;
          }
          cout<<sum<<endl;
     }
}
