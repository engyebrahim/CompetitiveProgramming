//dfs
#include <bits/stdc++.h>
using namespace std;
int n,m; char arr[101][101];
bool vis[101][101];
int xp[]={-1,1,-1,1,1,-1,0,0},yp[]={1,-1,-1,1,0,0,1,-1};
void dfs(int x,int y)
{
    vis[x][y]=1;
    int a,b;
    for(int i=0;i<8;i++)
    {
        a=x+xp[i];
        b=y+yp[i];
        if(a>=0&&a<n&&b>=0&&b<m&&!vis[a][b]&&arr[a][b]=='@')
            dfs(a,b);
    }
}
int main()
{
    int c;
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        for(int i=0;i<n;i++)
                scanf("%s",arr[i]);
        memset(vis,0,sizeof vis);
        c=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j]&&arr[i][j]=='@')
                {
                    dfs(i,j);
                    c++;
                }
        printf("%d\n",c);
    }

}
