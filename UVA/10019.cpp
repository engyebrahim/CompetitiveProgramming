#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int m;
    bitset<20> s;
    int arr[]={0,1,1,2,1,2,2,3,1,2},c;
    while(t--)
    {
         cin>>m;
         s=m;
         c=0;
         cout<<s.count()<<" ";
         while(m)
         {
              c+=arr[m%10];
              m/=10;
         }
         cout<<c<<endl;
    }
}
