/*
for each character i get new index from 1 to i
by this fomula idx[i]=I/(!n/!i)+1
then update I =(idx[i]-1)*(!n/!i)

when calculat !n if its value become more than I stop and make idx[i]=1 
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
     int t;
     cin>>t;
     long long idx,n,d;
     bool f;
     int arr[27];
     string s,ans;
     while(t--)
     {
          cin>>s>>idx;
          n=s.size();
          idx--;
          ans="";
          arr[1]=1;
          for(int i=2;i<=n;i++)
          {
               d=1;
               f=0;
               for(int j=i+1;j<=n;j++) 
               {
                    d*=j;
                    if(d>idx) {f=1; break;}
               }
               //cout<<d<<endl;
               if(f) arr[i]=1;
               else
               {
                    arr[i]=idx/d+1;
                    idx-=(arr[i]-1)*d;
               }
          }
          
          for(int i=1;i<=n;i++) {
               //cout<<arr[i]<<" "<<i<<endl;
               if (i==1) ans.push_back(s[i-1]);
               else ans.insert(arr[i]-1,1,s[i-1]);
          }
          cout<<ans<<endl;
     }
     
}
