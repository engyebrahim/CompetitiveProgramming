#include<bits/stdc++.h>
using namespace std;

int main()
{
     int t,n;
     cin>>t;
     int arr[100002];
     arr[0]=0;
     for(int j=0,i=1;i<100000;i+=2,j++)
          arr[i]=arr[i-1]+j,arr[i+1]=arr[i]+j;
     while(t--)
     {
          cin>>n;
          cout<<arr[n]<<endl;
     }
}



