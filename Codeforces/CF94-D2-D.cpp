#include <bits/stdc++.h>
using namespace std;

int main()
{
     double n,m,w;
     cin>>n>>w>>m;
     double res=w*n/m,arr[55],sum;
     int cnt[55]={};
     vector< vector<pair<int,double> > >v(55,vector<pair<int,double> >());
     bool f;
     for(int i=1;i<=n;i++) arr[i]=w;
     for(int j=1,i=0;i<m;i++)
     {
          sum=0,f=1;
          while(res-sum>1e-6)
          {
               if(res-sum>=arr[j]-1e-9)
               v[i].push_back(make_pair(j,arr[j])),sum+=arr[j],arr[j]=0,j++;
               else if(cnt[j]==0) 
               {
                    arr[j]-=res-sum;
                    cnt[j]++;
                    v[i].push_back(make_pair(j,res-sum));
                    sum=res;
                    f=0;
               }
               else if(j!=n&&cnt[j+1]==0)
               {    arr[j+1]-=res-sum;
                    cnt[j+1]++;
                    v[i].push_back(make_pair(j+1,res-sum));
                    sum=res;
                    
               }
               else
               {cout<<"NO"<<endl; return 0;}
          }
     }
     cout<<"YES\n";
     for(int i=0;i<m;i++)
     {for(int j=0;j<v[i].size();j++)
     printf("%d %.6lf ",v[i][j].first,v[i][j].second); cout<<endl;}
}
