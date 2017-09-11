#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,nm,idx;
    int p[11],arr[2000];
    p[0]=1;
    for(int i=1;i<11;i++) p[i]=p[i-1]*2;
    while(cin>>n>>k)
    {
        for(int i=0;i<p[n];i++) cin>>arr[i];
        nm=arr[k];
        sort(arr,arr+p[n]);
        idx=lower_bound(arr,arr+p[n],nm)-arr;
        if(arr[idx]==arr[p[n]-1]) cout<<n<<" "<<n<<endl;
        else cout<<0<<" "<<(int)log2(idx+1)<<endl;
    }
}
