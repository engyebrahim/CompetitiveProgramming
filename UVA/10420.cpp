#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin>>n;
     string s,k;
     getline(cin,s);
     stringstream ss;
     map<string ,int>m;
     while(n--)
     {
          k="";
          getline(cin,s);
          for(int i=0;i<s.size();i++)
          if(s[i]!=' ') k+=s[i];
          else break;
          m[k]++;
     }
     map<string ,int>::iterator it=m.begin();
     while(it!=m.end())
     {
          cout<<it->first<<" "<<it->second<<endl;
          it++;
     }
}
