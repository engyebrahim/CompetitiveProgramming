//          small input 1 

#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,arr[1000005],k,mn,mx,idx;
pair<int,int> p[1000005];
int main()
{
    freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
            scanf("%d%d",&n,&k);
            arr[0]=0,arr[n+1]=0;
            for(int i=1;i<=n;i++) arr[i]=1,p[i].first=i-1,p[i].second=n-i;
            for(int i=0;i<k;i++)
            {
                      mn=-1,mx=-1;
                      for(int j=1;j<=n;j++) 
                        if(arr[j]&&min(p[j].first,p[j].second)>mn) mn=min(p[j].first,p[j].second);
                      for(int j=1;j<=n;j++)
                        if(arr[j]&&min(p[j].first,p[j].second)==mn&&max(p[j].first,p[j].second)>mx) mx=max(p[j].first,p[j].second),idx=j;
                        
                      arr[idx]=0;
                      for(int j=idx+1;j<=n;j++)
                        if(arr[j]==0) break;
                        else p[j].first=j-idx-1;
                      for(int j=idx-1;j>0;j--)
                        if(arr[j]==0) break;
                        else p[j].second=idx-j-1;
            }
            printf("Case #%d: %d %d\n",tc,mx,mn);
    }
    return 0;
}
