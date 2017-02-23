#include <bits/stdc++.h>
using namespace std;

int main ()
{
     freopen ("input.txt","r",stdin);
     freopen ("output.txt","w",stdout);
     int n,m,a[100002],b[100002];
     vector<int >v,ans;
     cin>>n;
     for(int i=1;i<=n;i++) cin>>a[i];
     cin>>m;
     for(int i=1;i<=m;i++) cin>>b[i];
     int x=n,y=m,cur,c;
     while(x+y)
     {
          if(x&&a[x]==0||y&&b[y]==0) cur=0;
          else cur=1;
          c=0;
          while(x!=0&&a[x]==cur)
          {
               v.push_back(x);
               x--, c++;
          }
          while(y!=0&&b[y]==cur)
          {
               v.push_back(y+n);
               y--, c++;
          }
          ans.push_back(c);
     }
     reverse(ans.begin(),ans.end());
     reverse(v.begin(),v.end());
     for(int i=0;i<n+m;i++) 
          cout<<v[i]<<" ";
     cout<<endl;
     c=(!a[n]||!b[m])?ans.size()-1:ans.size();
     cout<<c<<endl;
     for(int i=0;i<c;i++) 
     {
          if(i) ans[i]+=ans[i-1];
          cout<<ans[i]<<" ";
     }
     cout<<endl;
}
