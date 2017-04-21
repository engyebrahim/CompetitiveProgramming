//editorial :http://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm319
#include<bits/stdc++.h>
using namespace std;
struct node 
{
int sl,sr,l,r,n;
};
vector<node> v;
vector <int> t;
int idx=0;
int fun(int n)
{
int d=idx++;
v[d].l=-1,v[d].r=-1; v[d].n=n;
v[d].sl=0,v[d].sr=0;
int c;
if(binary_search(t.begin(),t.end(),n*2)) 
{
c=fun(n*2);
v[d].sr=1+v[c].sl+v[c].sr;
v[d].r=c;
}
if(binary_search(t.begin(),t.end(),n*2+1))
{
c=fun(n*2+1);
v[d].sl=1+v[c].sl+v[c].sr;
v[d].l=c;
}
return d;
}
long long f[27];
long long solve(int idx)
{
if(idx==-1) return 1;
int n=v[idx].sl+v[idx].sr,k=v[idx].sl;
return  (f[n]/(f[k]*f[n-k]))*solve(v[idx].l)*solve(v[idx].r);
}
class ConstructBST
{
public:long long numInputs(vector <int> tree)
{
f[0]=1;
for(int i=1;i<=26;i++) f[i]=f[i-1]*i;
t=tree;
sort(t.begin(),t.end());
v.resize(tree.size());
fun(1);
return solve(0) ;
}
};
