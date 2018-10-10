#include <bits/stdc++.h>
using namespace std;
int p[101];
void setParent(int i,int j)
{
    p[i]=j;
}
int getParent(int i)
{
    if(i==p[i]) return i;
    return p[i]=getParent(p[i]);
}
int main()
{
    int n,c[101],mx;
    double ring[101][3],d,l;
    while(scanf("%d",&n)&&n!=-1)
    {
        mx=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf%lf",&ring[i][0],&ring[i][1],&ring[i][2]);
            p[i]=i;
            c[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                d=sqrt((ring[i][0]-ring[j][0])*(ring[i][0]-ring[j][0])+(ring[i][1]-ring[j][1])*(ring[i][1]-ring[j][1]));
                l=ring[i][2]+ring[j][2];
                if(d<l&&d+min(ring[i][2],ring[j][2])>max(ring[i][2],ring[j][2])&&(getParent(j)!=getParent(i)))
                    setParent(p[i],p[j]);
            }
        }
        for(int i=0;i<n;i++) mx=max(mx,++c[getParent(i)]);
        if(mx==1) printf("The largest component contains %d ring.\n",mx);
        else printf("The largest component contains %d rings.\n",mx);
    }
}
