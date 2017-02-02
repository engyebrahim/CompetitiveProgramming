#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n,arr[100001];
     cin>>n;
     for(int i=0;i<n;i++)
     cin>>arr[i];
     vector<char> v;
     int s=0;
     for(int i=n-1;i>=0;i--)
        if(s<0)  s+=arr[i], v.push_back('+');
        else s-=arr[i], v.push_back('-');
     reverse(v.begin(),v.end());
     if(s<0)
         for(int i=0;i<n;i++) if(v[i]=='-') v[i]='+'; else v[i]='-';
     for(int i=0;i<n;i++) cout<<v[i];
     cout<<endl;
        
}
