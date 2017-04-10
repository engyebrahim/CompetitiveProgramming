/*
for every two point count the number of points on one straightness with them 
then maximize the answer 
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[701];
bool fun(int a,int b,int c)
{
     return (p[b].first-p[c].first)*(p[a].second-p[b].second)==(p[b].second-p[c].second)*(p[a].first-p[b].first);
}
int main() {
     int t;
     scanf("%d",&t);
     int n,c,mx;
     stringstream ss;
     string s;
     getline(cin,s);
     getline(cin,s);
     while(t--)
     {
          n=0,mx=2;
          while(getline(cin,s)) {
               if(s=="") break;
               ss.clear();
               ss<<s;
               ss>>p[n].first;
               ss>>p[n].second;
               //cout<<p[n].first<<p[n].second<<endl;
               n++; 
          }
          //cout<<n<<endl;
          for(int i=0;i<n;i++)
               for(int j=i+1;j<n;j++)
               {
                    c=2;
                    for(int k=0;k<n;k++)
                    {
                         if(k==j||k==i) continue;
                         if(fun(i,j,k)) c++;
                    }
                    mx=max(mx,c);
               }
          cout<<mx<<endl; if(t) cout<<endl;
     }
} 2
