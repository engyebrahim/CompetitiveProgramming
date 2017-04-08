#include <iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
using namespace std;

int main()
{
    freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    int t,arr[1003],k,sum,c;
    char s[1003];
    bool f;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
         sum=0,f=1,c=0;
         memset(arr,0,sizeof arr); 
         scanf("%s",&s);
         scanf("%d",&k);
         for(int i=0;i<strlen(s);i++)
         {
                 sum+=arr[i];
                 if((s[i]=='-'&&sum%2==1)||(s[i]=='+'&&sum%2==0)) s[i]='+';
                 else if(i+k>strlen(s)) {f=0; break;}
                 else 
                 {
                      arr[i]+=1;
                      arr[i+k]+=-1;
                      sum+=1;
                      s[i]='+';
                      c++;
                 }
         }
         printf("Case #%d: ",tc);
         if(f) printf("%d\n",c);
         else printf("IMPOSSIBLE\n");
    }
    
    return 0;
}
