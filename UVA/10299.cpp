
#include <bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> p,v;
    bool f;
    for(int i=2; i*i<=1000000000; i++)
    {
        f=1;
        for(int j=2; j*j<=i; j++)
            if(i%j==0) f=0;
        if(f) p.push_back(i);
    }
    int n,m,ans,c;
    set<int> s;
    set<int>::iterator it;
    while(scanf("%d",&n)==1&&n)
    {
        m=n;
        for(int j=0; j<p.size()&&m!=1; j++)
        {
            while(m%p[j]==0)
            {
                s.insert(p[j]);
                m/=p[j];
            }
        }
        if(m!=1) s.insert(m);
        ans=0;
        for(it=s.begin();it!=s.end();it++)
            v.push_back(*it);
        for(int i=1;i<(1<<v.size());i++)
        {
            m=1,c=0;
            for(int j=0;j<v.size();j++)
            {
                if(i&(1<<j))
                {
                    c++;
                    m*=v[j];
                }
            }
            if(c%2==0) ans-=n/m;
            else ans+=n/m;
        }
        if(n==1) printf("0\n");
        else{
        ans=n-ans;
        printf("%d\n",ans);}
        s.clear();
        v.clear();
    }

}
