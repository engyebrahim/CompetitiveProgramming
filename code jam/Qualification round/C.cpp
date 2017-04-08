//          small input 1&2 

#include <iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,k;
vector<int> v;
void fun(int num)
{
     //cout<<num<<endl;
     if(num==0) return ;
     v.push_back(num);
     if(num==1) return;
     fun(num/2);
     fun(num-num/2-1);
}
bool cmp(int a,int b)
{
     return a>b;
}
int main()
{
    freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    scanf("%d",&t);
    
    for(int tc=1;tc<=t;tc++)
    {
            scanf("%d%d",&n,&k);
            k--;
            fun(n);
            sort(v.begin(),v.end(),cmp);
            printf("Case #%d: %d %d\n",tc,v[k]/2,v[k]-v[k]/2-1);
            v.clear();
    }
    return 0;
}


