
#include <bits/stdc++.h>
using namespace std;
vector<int>p;
int main()
{
    bool f;
    for(int i=2; i<=46342; i++)
    {
        f=1;
        for(int j=2; j*j<=i; j++)
        {
            if(i%j==0) f=0;
        }
        if(f) p.push_back(i);
    }
    int n,m,x,c;
    map<int,int> mp;
    map<int,int>::iterator it;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(m==0)
        {
          printf("%d does not divide %d!\n",m,n);
          continue;
        }

        x=m;
        for(int i=0; i<p.size()&&x!=1; i++)
        {
            while(x%p[i]==0)
            {
                mp[p[i]]++;
                x/=p[i];
            }
        }
        if(x!=1) mp[x]++;
        f=1;
        for(it=mp.begin();it!=mp.end();it++)
        {
            x=n,c=0;
            while(x)
            {
                x/=it->first;
                c+=x;
            }
            if(c<it->second) f=0;
        }
        if(f)printf("%d divides %d!\n",m,n);
        else printf("%d does not divide %d!\n",m,n);
        mp.clear();
    }
}
