#include <bits/stdc++.h>
using namespace std;
 
vector<set<string> > ans;
set<string> p;
int n,m,cur;
char c[100];
vector<string> s;
vector<int> a(26,-1);
vector<vector<int> >ed,v;
int equ[22001];
int main()
{
     memset(equ,-1,sizeof equ);
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
          scanf("%s",&c);
          s.push_back(c);
     }
     scanf("%d",&m);
     v.push_back(a);
     ed.push_back(a);
     
     for(int i=0;i<m;i++)
          ans.push_back(p);
 
     for(int i=0;i<m;i++)
     {
          scanf("%s",&c);
          cur=0;
          for(int j=0;j<strlen(c);j++)
          {
               if(j+1==strlen(c)&&ed[cur][c[j]-'a']==-1) ed[cur][c[j]-'a']=i;
               else if(j+1==strlen(c)) equ[i]=ed[cur][c[j]-'a'];
               if(v[cur][c[j]-'a']==-1)
               {
                    v[cur][c[j]-'a']=v.size();
                    cur=v.size();
                    v.push_back(a);
                    ed.push_back(a);
               }
               else
                    cur=v[cur][c[j]-'a'];
          }
               
     }
     for(int i=0;i<n;i++)
     {
          cur=0;
          for(int j=0;j<s[i].size();j++)
          {
               if(ed[cur][s[i][j]-'a']!=-1&&j!=s[i].size()-1) ans[ed[cur][s[i][j]-'a']].insert(s[i]);  
               if(v[cur][s[i][j]-'a']==-1) break;
               else 
               {
                    cur=v[cur][s[i][j]-'a'];
               }
          }
     }
     int idx;
     set<string>::iterator it;
     for(int i=0;i<m;i++)
     {
          if(equ[i]!=-1) idx=equ[i];
          else idx=i;
          printf("Case #%d:\n",i+1);
          if(ans[idx].size()==0) {
               cout<<"No match.\n";
               continue;
          }
          it=ans[idx].begin();
          for(;it!=ans[idx].end();it++)
           cout<<*it<<endl;
     }
     
}
