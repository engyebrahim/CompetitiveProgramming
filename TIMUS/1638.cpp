#include<bits/stdc++.h>
using namespace std;

int main(){
     int a,b,s,e;
     cin>>a>>b>>s>>e;
     if(s==e)
     cout<<a<<endl;
     else if(s<e) cout<<b*2+(e-s-1)*2*b+(e-s-1)*a<<endl;
     else cout<<b*2+a*2+(s-e-1)*2*b+(s-e-1)*a<<endl;
}
