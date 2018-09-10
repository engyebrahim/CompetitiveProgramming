#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> p;
    bool f;
    for(long long i=2;i*i<=2147483647;i++)
    {
        f=1;
        for(long long j=2;j*j<=i;j++)
           if(i%j==0) f=0;
        if(f) p.push_back(i);
    }
    int n,m,s,e,last,mn,mx,a,b,x,y,dif;
    bool arr[1000001];
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==1) n++;
        memset(arr,0,sizeof arr);
        e=m-n;
        for(int i=0;i<p.size();i++)
        {
            s=n/p[i]*p[i];
            if(s<n) s+=p[i];
            for(int j=s-n;j<=e;j+=p[i])
                if(j+n!=p[i]) arr[j]=1;
        }
        last=-1,mx=-1,mn=2147483647;
        for(int i=0;i<=e;i++)
        {
            if(!arr[i])
            {
                if(last!=-1)
                {
                    dif=i-last;
                    if(mx<dif) mx=dif,a=last+n,b=i+n;
                    if(mn>dif) mn=dif,x=last+n,y=i+n;
                }
                last=i;
            }
        }
        if(mx!=-1) printf("%d,%d are closest, %d,%d are most distant.\n",x,y,a,b);
        else printf("There are no adjacent primes.\n");
    }
}
