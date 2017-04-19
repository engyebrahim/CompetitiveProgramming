/*
save in dp strings and compare its size 
if size is equal return the one that comes lexicographically earliest.
*/
#include<bits/stdc++.h>
using namespace std;
string s;
string dp[1001][1001];
string fun(int i,int j)
{
     string ans;
     if(i>j) return "";
     if(i==j) return ans=s[i];
     if(dp[i][j]!="-1") return dp[i][j];
     if(s[i]==s[j]) return dp[i][j]=s[i]+fun(i+1,j-1)+s[j];
     string a=fun(i+1,j),b=fun(i,j-1);
     if(a.size()>b.size()) return dp[i][j]=a;
     if(b.size()>a.size()) return dp[i][j]=b;
     if(a>b) return dp[i][j]=b;
     return dp[i][j]=a;
}
int main(){
     while(cin>>s)
     {
          for(int i=0;i<s.size();i++)
            for(int j=0;j<s.size();j++) dp[i][j]="-1";
          cout<<fun(0,s.size()-1)<<endl;
     }
}
