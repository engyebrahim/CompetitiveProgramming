#include <bits/stdc++.h>
using namespace std;
int n,f[12],ans;
bool m[12][12];
bool ok(int node){
    for(int i=0;i<node;i++)
        if(m[node][i] && f[node]==f[i]) return false;
    return true;
}
void fun(int node,int c)
{
    if(c>=ans) return;
    if(node==n) {ans=c; return ;}
    for(int i=1;i<ans;i++)
    {
        f[node]=i;
        if(!ok(node)) continue;
        fun(node+1,max(c,i));
    }
}
int main()
{
    pair<double,double>p[12];
    int tc=1;
    while(cin>>n&&n)
    {
        memset(m,0,sizeof m);
        for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if((p[i].first-p[j].first)*(p[i].first-p[j].first)+(p[i].second-p[j].second)*(p[i].second-p[j].second)<=400)
                    m[i][j]=1;
        ans=n;
        fun(0,1);
        printf("The towers in case %d can be covered in %d frequencies.\n",tc++,ans);

    }
}
