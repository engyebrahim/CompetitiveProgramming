#include<bits/stdc++.h>
using namespace std;
int main(){
     int t;
     cin>>t;
     int n,m;
     int arr[10][100];
     bool f;
     int sum;
     while(t--)
     {
          cin>>n>>m;
          for(int i=0;i<n;i++)
          {
               for(int j=0;j<m;j++)
               {
                    cin>>arr[i][j];
               }
          }
          sum=0; f=1;
          for(int i=0;i<m;i++)
          {
               arr[n][i]=0;
               for(int j=0;j<n;j++) arr[n][i]+=arr[j][i];
               if(arr[n][i]==2) sum++;
               else if(arr[n][i]!=0) f=0;
          }
          if(f)
          {
               for(int j=1;j<m;j++)
               {
                    if(arr[n][j])
                    {
                         for(int i=0;i<j;i++)
                         {
                              f=1;
                              for(int k=0;k<n;k++)
                              {
                                   if(arr[k][j]!=arr[k][i]) f=0;
                              }
                              if(f) sum--;
                         }
                    }
               }
               if(sum==m)
               cout<<"Yes"<<endl;
               else cout<<"No"<<endl;
               
          }
          else cout<<"No"<<endl;
     }
}
