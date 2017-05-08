#include<bits/stdc++.h>
using namespace std;
 
int main(){
     int t;
     cin>>t;
     int n,m;
     vector<vector<int> > v;
     int x,y,arr[6];
     for(int tc=1;tc<=t;tc++)
     {
          scanf("%d%d",&n,&m);
          v.clear();
          v.resize(n+1);
          while(m--)
          {
               scanf("%d%d",&x,&y);
               v[x].push_back(y);
               v[y].push_back(x);
          }
          memset(arr,0,sizeof arr);
          for(int i=1;i<=n;i++)
          {
               if(v[i].size()==1) arr[1]++;
               else if(v[i].size()==2) arr[2]++;
               else if(v[i].size()==3) arr[3]++;
               else if(v[i].size()==4) arr[4]++;
               else arr[5]++;
          }
          printf("Case %d: ",tc);
          if(arr[1]==2&&!(arr[3]+arr[4]+arr[5])) cout<<"I\n";
          else if(arr[1]==3&&arr[3]==1&&!(arr[4]+arr[5])) cout<<"Y\n";
          else if(arr[1]==4&&arr[4]==1&&!(arr[3]+arr[5])) cout<<"X\n";
          else cout<<"NotValid\n";
     }
}
