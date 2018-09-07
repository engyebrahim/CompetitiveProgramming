#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int p[1000001]={};

int main()
{
    for(int i=2;i<1000001;i++)
        if(p[i]==0)
            for(int j=i;j<1000001;j+=i)
                p[j]=i;
    int x;
    set<int> s;
    for(int i=1;i<=1000000;i++)
    {
        x=i;
        while(x!=1)
        {
            s.insert(p[x]);
            x/=p[x];
        }
        arr[i]=s.size();
        s.clear();
    }
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        printf("%d : %d\n",n,arr[n]);
    }
}
