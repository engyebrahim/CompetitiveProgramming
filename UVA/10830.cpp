#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long phi[50001];
    phi[1]=0;
    for(int i=2; i<50001; i++) phi[i]=i;
    for(int i=2; i<50001; i++)
    {
        if(i==phi[i]){
            for(int j=i*2; j<50001; j+=i)
            {
                phi[j]-=phi[j]/i;
            }
            phi[i]--;
        }
        phi[i]=phi[i]*2+phi[i-1];
    }
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        printf("%d\n",phi[n]+1);
    }
}
