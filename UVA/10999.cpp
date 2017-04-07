//trie tree
/*
1- Put all words of dictionary in trie and mark every end word 
2- try to get maximum score by given characters using back traching
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector< int> > tr;
vector<int > v (26,-1);
int p;
vector<pair<char,int> > ch(10);
vector<bool> f(10,1);
bool flag[1000000];
int fun(int cur)
{
     int ans=-1e+9;
     if(flag[cur]==1) ans=0;
     for(int i=0;i<p;i++)
     {
          if(!f[i]) continue;
          f[i]=0;
          if(tr[cur][ch[i].first-'a']!=-1) ans= max(ans,ch[i].second+fun(tr[cur][ch[i].first-'a']));
          f[i]=1;
     }
     return ans;
}
int main() {
     int n,cur,m;
     char c[100];
     scanf("%d",&n);
     tr.push_back(v);
     while(n--)
     {
          scanf("%s",&c); 
          cur=0;
          for(int i=0;i<strlen(c);i++)
          {
               if(tr[cur][c[i]-'a']==-1)
               {
                    tr[cur][c[i]-'a']=tr.size();
                    cur=tr.size();
                    tr.push_back(v);
               }
               else
                    cur=tr[cur][c[i]-'a'];
               if(strlen(c)==i+1) flag[cur]=1;
          }
     }
     scanf("%d",&m);
     while(m--)
     {
          char chh;
          scanf("%d",&p),scanf("%c",&chh);
          for(int i=0;i<p;i++)
               scanf("%c",&ch[i].first),scanf("%d",&ch[i].second),scanf("%c",&chh);
          printf("%d\n",fun(0));
     }
}
