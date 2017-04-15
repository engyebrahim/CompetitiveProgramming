#include <bits/stdc++.h>
using namespace std;

int main() {
     int t;
     cin>>t;
     int n;
     char m [20][20], c[20][20] ,ans[20][20];
     bool f;
     while(t--)
     {
          cin>>n;
          f=0;
          for(int i=0;i<n;i++) cin>>m[i]; 
          for(int i=0;i<n;i++) cin>>c[i];
          for(int i=0;i<n;i++)
          {
               for(int j=0;j<n;j++)
               {
                    if(c[i][j]=='.') ans[i][j]='.';
                    else if(m[i][j]=='*') f=1;
                    else 
                    {
                         ans[i][j]='0';
                         if(i!=0&&m[i-1][j]=='*')  ans[i][j]++;
                         if(i!=n-1&&m[i+1][j]=='*')  ans[i][j]++;
                         if(j!=0&&m[i][j-1]=='*')  ans[i][j]++;
                         if(j!=n-1&&m[i][j+1]=='*')  ans[i][j]++;
                         if(i!=0&&j!=0&&m[i-1][j-1]=='*') ans[i][j]++;
                         if(i!=n-1&&j!=n-1&&m[i+1][j+1]=='*') ans[i][j]++;
                         if(i!=n-1&&j!=0&&m[i+1][j-1]=='*') ans[i][j]++;
                         if(i!=0&&j!=n-1&&m[i-1][j+1]=='*') ans[i][j]++;
                         //cout<<i<<" " <<j<<" "<<ans[i][j]<<endl;
                    }
                    
               }
               
          }
          if(f)
          for(int i=0;i<n;i++)
               for(int j=0;j<n;j++) if(m[i][j]=='*') ans[i][j]='*';
          for(int i=0;i<n;i++){ for(int j=0;j<n;j++) cout<<ans[i][j]; cout<<endl;}
          if(t) cout<<endl;
     }
}
