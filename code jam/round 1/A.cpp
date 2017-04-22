#include <iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main()
{
    freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    int t;
    cin>>t;
    double d,n,mx,k,s; 
    for(int tc=1;tc<=t;tc++)
    {
            cin>>d>>s;
            mx=0;
            while(n--)
            {
                      cin>>k>>s;
                      mx=max(mx,(d-k)/s);
            }
            cout<<"Case #"<<tc<<": ";
            printf("%.6lf",d/mx);
            
     }
    return 0;
}
