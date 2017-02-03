#include <bits/stdc++.h>
using namespace std;

int main()
{
     int t;
     scanf("%d",&t);
     int n,arr[102][102],vis[102][102],tc=0,s=0;
     bool f;
     while(t--)
     {
          tc++;
          memset(vis,0,sizeof vis);
          memset(arr,0,sizeof arr);
          scanf("%d",&n);
          for(int i=0;i<n-1;i++)
               for(int j=0;j<=i;j++)
                {
                     scanf("%d",&arr[i+1][j]);
                     arr[j][i+1]=arr[i+1][j];
                }
          cout<<"Case #"<<tc<<":"<<endl;
          f=1;
          for(int k=0;k<n;k++)
           for(int i=0;i<n;i++)
             for(int j=0;j<n;j++)
             if(i==j||j==k||k==i) continue;
             else if(arr[i][k]+arr[k][j]==arr[i][j])
                    vis[i][j]=1;
               else if(arr[i][k]+arr[k][j]<arr[i][j]) f=0;
               
         if(!f)
           cout<<"Need better measurements."<<endl;
         else
          {
               s=0;
               for(int i=0;i<n;i++)
                 for(int j=0;j<i;j++)
                 if(i!=j&&vis[i][j]==0)
                   s++;
               cout<<s<<endl;
               for(int i=0;i<n;i++)
                 for(int j=i+1;j<n;j++)
                  if(!vis[i][j])
                    cout<<i+1<<" "<<j+1<<" "<<arr[i][j]<<endl;
          } 
      cout<<endl;
     }
     
}
