#include<bits/stdc++.h>
using namespace std;
int main(){
     vector<int>v;
     long long m=1,c=1;;
     v.push_back(1);
     while(m<2147483648)
     {
          m+=c;
          c++;
          v.push_back(m);
     }
     int n,x;
     cin>>n;
     while(n--)
     {
          cin>>x;
          if(binary_search(v.begin(),v.end(),x)) cout<<1;
          else cout<<0;
          if(n) cout<<" ";
     }
     
}
