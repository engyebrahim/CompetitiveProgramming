/*
  normal dp to return min path but use deque to save the smallest lex path
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[10][100];
pair<long long ,deque<int> >dp[10][100];
pair<long long ,deque<int> >fun(int i,int j)
{
     pair<long long ,deque<int> > tmp,ans;
     ans.first=0;
     if(j==m) return ans;
     if(dp[i][j].first!=-1) return dp[i][j];
     ans=fun(i,j+1);
     tmp=(i==0)?fun(n-1,j+1):fun(i-1,j+1);
     if(ans.first>tmp.first||(ans.first==tmp.first&&ans.second>tmp.second)) ans=tmp;
     tmp=(i==n-1)?fun(0,j+1):fun(i+1,j+1);
     if(ans.first>tmp.first||(ans.first==tmp.first&&ans.second>tmp.second)) ans=tmp;
     ans.first+=arr[i][j];
     ans.second.push_front(i+1);
     return dp[i][j]=ans;
}
int main(){
     while(cin>>n>>m)
     {
          for(int i=0;i<n;i++)
               for(int j=0;j<m;j++)
               {
                    scanf("%d",&arr[i][j]);
                    dp[i][j].first=-1;
                    dp[i][j].second.clear();
               }
          pair<long long ,deque<int> > ans,tmp;
          ans =fun(0,0);
          for(int i=1;i<n;i++)
          {
               tmp=fun(i,0);
               if(tmp.first<ans.first) ans=tmp;
          }
          for(int i=0;i<ans.second.size();i++)
          {
               cout<<ans.second[i];
               if(i+1!=ans.second.size()) cout<<" ";
          }
          cout<<endl<<ans.first<<endl;
     }
}
