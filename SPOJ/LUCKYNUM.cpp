#include<bits/stdc++.h>
using namespace std;

int main(){
     int t,x;
     cin>>t;
     string s,k;
     bool f;
     while(t--)
     {
          cin>>x;
          s="";
          f=1;
          for(int i=1;i<=200&&f;i++)
          {
               s+='6';
               k=s;
               if(mod(s,x)) {cout<<s<<endl; f=0; break;}
               for(int j=0;j<i;j++)
               {
                    k[j]='8';
                    if(mod(k,x)) {cout<<k<<endl; f=0; break;}
               }
          }
          if(f) cout<<-1<<endl;
     }
}
