#include <bits/stdc++.h>
using namespace std;

int main()
{
     long long l1,l2,g,l,ans, n,m;
     cin>>n>>m;
     string s,k;
     cin>>s>>k;
     l1=s.size(),l2=k.size();
     g=__gcd(l1,l2);
     l=ans=l1*l2/g;
     long long arr[1000001][26]={};
     for(int i=0;i<l1;i++)
     arr[i%g][s[i]-'a']++;
     for(int i=0;i<l2;i++)
     ans-=arr[i%g][k[i]-'a'];
     cout<<ans*(n*l1/l)<<endl;;
}
