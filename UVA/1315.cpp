#include<bits/stdc++.h>
using namespace std;

int main()
{
     int t,n;
     cin>>t;
     long long arr[1000007];
     arr[3]=0;
     for(int j=1,i=4;i<=1000000;i+=2,j++)
          arr[i]=arr[i-1]+j,arr[i+1]=arr[i]+j;
     for(int i=4;i<=1000000;i++) arr[i]+=arr[i-1];
     while(t--)
     {
          cin>>n;
          cout<<arr[n]<<endl;
     }
}
