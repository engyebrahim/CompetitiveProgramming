#include<bits/stdc++.h>
using namespace std;
int n;
char p[1000003],s[1000004];
int f[10000003];
 
int main()
{
     while(~scanf("%d%s%s",&n,p,s)){
     f[0]=0;
     for(int i=1,k=0;i<n;i++)
     {
          while(k>0&&p[k]!=p[i])
               k=f[k-1];
               
          if(p[k]==p[i]) f[i]=++k;
          else f[i]=0;
     }
     int len=strlen(s);
     bool l=0;
     for(int i=0,k=0;i<len;i++)
     {
          while(k>0&&p[k]!=s[i])
               k=f[k-1];
               
          if(p[k]==s[i]) ++k;
          if(k==n)
          {
               l=1;
               printf("%d\n",i-n+1);
                k=f[k-1];
          }
     }
     if(!l) cout<<endl;
}
} 
