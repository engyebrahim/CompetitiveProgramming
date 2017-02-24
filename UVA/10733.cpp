#include <bits/stdc++.h>
using namespace std;
long long pow(long long x,int y)
{
     if(y==0) return 1;
     return x*pow(x,y-1);
}
int main ()
{
     long long x;
     while(cin>>x&&x)
          cout<<(pow(x,6)+3*pow(x,4)+12*pow(x,3)+8*pow(x,2))/24<<endl;
}
