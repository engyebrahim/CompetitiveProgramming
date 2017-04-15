#include <bits/stdc++.h>
using namespace std;

int main() {
     int n,arr[1002],last;
     stack<int> s;
     bool f;
     while(cin>>n&&n)
     {
          while(cin>>arr[0]&&arr[0])
          {
               for(int i=1;i<n;i++) scanf("%d",&arr[i]);
               last=0;
               f=1;
               for(int i=0;i<n;i++)
               {
                    if(arr[i]>last) 
                    {
                         for(int j=last+1;j<arr[i];j++)
                           s.push(j);
                         last=arr[i];
                    }
                    else
                    {
                         if(s.empty()||s.top()!=arr[i]){ f=0; break;}
                         s.pop();
                    }
               }
               if(!f) cout<<"No"<<endl;
               else cout<<"Yes"<<endl;
          }
          cout<<endl;
     }
}
