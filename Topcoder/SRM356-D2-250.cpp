#include<bits/stdc++.h>
using namespace std;
class SMSLanguage
{
     string clr(string s)
     {
          string k="";
          for(int i=0;i<s.size();i++)
          {
               if(s[i]=='.'||s[i]==','||s[i]=='?'||s[i]== '!') continue;
               k+=tolower(s[i]);
          }
          return k;
     }
     public:string translate(string s)
     {
          s=clr(s);
          string k,ans="";
          for(int i=0;i<s.size();)
          {
               k="";
               for(int j=i;j<i+3&&i+2<s.size();j++)
               {
                    k+=s[j];
               }
               if(k=="and") ans+='&',i+=3;
               else if(k=="you") ans+='U',i+=3;
               else if(k=="ate") ans+='8',i+=3;
               else ans+=s[i],i++;
          }
          s=ans;
          ans="";
          for(int i=0;i<s.size();)
          {
               k="";
               for(int j=i;j<i+2&&i+1<s.size();j++)
               {
                    k+=s[j];
               }
               if(k=="at") ans+='@',i+=2;
               else ans+=s[i],i++;
          }
          return ans;
     }
};

