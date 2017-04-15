#include <bits/stdc++.h>
using namespace std;

int main() {
     int arr[4][4],c[4];
     string s,ans;
     int mn,sum;
     while(cin>>arr[0][1]>>arr[0][3]>>arr[0][2]
              >>arr[1][1]>>arr[1][3]>>arr[1][2]
              >>arr[2][1]>>arr[2][3]>>arr[2][2])
          {
               for(int i=1;i<=3;i++)
               {
                    c[i]=0;
                    for(int j=0;j<3;j++) c[i]+=arr[j][i];
               }
               mn=1e+9; s="123";
               do
               {
                    sum=0;
                    for(int i=0;i<3;i++)
                    {
                         sum+=c[s[i]-'0']-arr[i][s[i]-'0'];
                    }
                    if(sum<mn)mn=sum,ans=s;
               }while(next_permutation(s.begin(),s.end()));
               for(int i=0;i<3;i++)
               if(ans[i]=='1') ans[i]='B';
               else if(ans[i]=='2') ans[i]='C';
               else ans[i]='G';
               cout<<ans<<" "<<mn<<endl;
          }
}
