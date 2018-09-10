#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> p;
    long long n=1;
    bool f;
    for(long long i=2;i*i<=(n<<31);i++)
    {
        f=1;
        for(long long j=2;j*j<=i;j++)
            if(i%j==0) f=0;
        if(f) p.push_back(i);
    }
    map<long long,long long> m;
    map<long long,long long>::iterator it;
    long long phi,t;
    while(scanf("%lld",&n)==1)
    {
        if(n==0) {printf("0\n"); continue;}
        t=phi=n;
        for(int i=0;i<p.size();i++)
        {
            if(t%p[i]==0) phi-=phi/p[i];
            while(t%p[i]==0)
            {
                m[p[i]]++;
                t/=p[i];
            }
        }
        if(t!=1) m[t]++,phi-=phi/t;
        t=1;
        for(it=m.begin();it!=m.end();it++)
            t*=it->second+1;
        printf("%lld\n",(n-phi)-(t-1));
        m.clear();
    }
}
