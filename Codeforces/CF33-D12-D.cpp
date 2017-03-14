//http://codeforces.com/blog/entry/733
#include<bits/stdc++.h>
using namespace std;
bitset<1001> s[1001],tmp;
int main() {
   int n,m,k;
   scanf("%d%d%d",&n,&m,&k);
   pair<int ,int> p[1001];
   for(int i=0;i<n;i++)
        scanf("%d%d",&p[i].first,&p[i].second);
   long long r,x,y;
   for(int j=0;j<m;j++)
   {
        scanf("%lld%lld%lld",&r,&x,&y);
        for(int i=0;i<n;i++)
           if((long double)(x-p[i].first)*(x-p[i].first)+(y-p[i].second)*(y-p[i].second)<r*r)
             s[i][j]=1;
   }
   while(k--)
   {
        scanf("%d%d",&x,&y);
        x--,y--;
        tmp=s[x]&s[y];
        cout<<s[x].count()+s[y].count()-2*tmp.count()<<endl;
   }
}
