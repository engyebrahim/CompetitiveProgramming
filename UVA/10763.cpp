#include<bits/stdc++.h>
using namespace std;
int main(){
     int n;
     map<pair<int,int>,int> m;
     map<pair<int,int>,int>::iterator it;
     bool f;
     while(cin>>n&&n)
     {
          for(int x,y,i=0;i<n;i++)
          {
               cin>>x>>y;
               m[make_pair(x,y)]++;
               m[make_pair(y,x)]++;
          }
          it=m.begin();
          f=1;
          while(it!=m.end())
          {
               if(it->second%2!=0) {f=0; break;}
               it++;
          }
          if(f) cout<<"YES"<<endl;
          else cout<<"NO\n";
          m.clear();
     }
     
}
