#include <bits/stdc++.h>
using namespace std;
vector<int>p;
int main()
{
    bool f;
    for(int i=2;i<=50000;i++)
    {
        f=1;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0) f=0;
        }
        if(f) p.push_back(i);
    }
    int n;
    while(scanf("%d",&n)&&n)
    {
        f=0;
        printf("%d = ",n);
        if(n<0) printf("-1"),f=1,n*=-1;
        for(int i=0;i<p.size();i++)
        {
            while(n%p[i]==0)
            {
                if(!f) printf("%d",p[i]),f=1;
                else printf(" x %d",p[i]);
                n/=p[i];
            }
        }
        if(n!=1) if(!f) printf("%d",n);
                 else printf(" x %d",n);
        printf("\n");
    }
}
