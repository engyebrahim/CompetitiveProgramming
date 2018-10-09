#include <bits/stdc++.h>
using namespace std;
long long x,y;
long long extende_equlid(long long a,long long b)
{
    //ax+by=gcd(a,b)
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int g=extende_equlid(b,a%b)
          ,tmp=x;
    x=y,y=tmp-x*(a/b);
    return g;
}
int main()
{
    int a,b,g;
    while(scanf("%d%d",&a,&b)==2)
    {
        g=extende_equlid(a,b);
        cout<<x<<" "<<y<<" "<<g<<endl;
    }
}



