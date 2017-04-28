/*
for every char find first and last possible index
then all char in thies ranges can be in subsequence
*/
#include<bits/stdc++.h>
using namespace std;
int arr[26][200002],r[200002],l[200002];
int main(){
     string s,t;
     cin>>s>>t;
     memset(l,-1,sizeof l);
     memset(r,-1,sizeof r);
     for(int i=0,j=0;i<s.size();i++)
     {
          if(s[i]==t[j]) l[j]=i,j++;
     }
     for(int i=s.size()-1,j=t.size()-1;i>=0;i--)
     {
          if(s[i]==t[j]) r[j]=i,j--;
     }
     for(int j=0;j<t.size();j++)
     {
          if(l[j]!=-1&&r[j]!=-1&&r[j]>=l[j]) arr[t[j]-'a'][l[j]]+=1,arr[t[j]-'a'][r[j]+1]+=-1;
     }
     for(int i=0;i<26;i++)
     for(int j=1;j<s.size();j++)
     arr[i][j]+=arr[i][j-1];
     
     for(int i=0;i<s.size();i++)
     if(!arr[s[i]-'a'][i]) {cout<<"No\n"; return 0;}
     
     cout<<"Yes\n";
}
