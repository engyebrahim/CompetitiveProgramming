#include<bits/stdc++.h>
using namespace std;

//Do not copy and paste the output statement. The ASCII code for the apostrophe is different.

string name[]={"tom","jerry","goofy","mickey","jimmy","dog","cat","mouse"},
ver[]={"hate" , "love" , "know" , "like" , "hates" , "loves" , "knows" , "likes"},
ch[]={"a","the"},k;
vector<string> v;
int names(int i)
{
     if(i+1!=v.size()&&binary_search(ch,ch+2,v[i])&&binary_search(name,name+8,v[i+1]))
          i+=2;
     else if(binary_search(name,name+8,v[i]))
          i++;
     else return -1;
     while(i<v.size()&&v[i]=="and")
     {
          i++;
          if(i+1!=v.size()&&binary_search(ch,ch+2,v[i])&&binary_search(name,name+8,v[i+1]))
          i+=2;
          else if(i<v.size()&&binary_search(name,name+8,v[i]))
          i++;
          else return -1;
     }
     return i;
}
int main()
{
     string s;
     bool f; int idx;
     sort(name,name+8);
     sort(ver,ver+8);
     while(getline(cin,s))
     {
          if(s=="\0") {cout<<"NO I WON'T\n"; continue;}
          k="";
          for(int i=0;i<s.size();i++)
               if(s[i]==' ') v.push_back(k),k="";
               else k+=s[i];
          v.push_back(k);
          
          for(int i=0;i<v.size();i++)
          {
               f=0;
               
               idx=names(i);
               if(idx==-1||idx==v.size()) break;
               i=idx;
               
               if(binary_search(ver,ver+8,v[i])) i++;
               else break;
               if(i==v.size()) break;
               
               idx=names(i);
               if(idx==-1) break;
               i=idx;
               
               if(i+1==v.size()) break;  //one word or comma will fail
               if(i!=v.size()&&v[i]!=",") break; 
               
               f=1;
          }
          if(f) cout<<"YES I WILL\n";
          else cout<<"NO I WON'T\n";
          v.clear();
     }
}
