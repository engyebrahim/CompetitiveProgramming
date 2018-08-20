#include <bits/stdc++.h>

using namespace std;
int t,arr[1000004];
int main()
{
    string s;
    while(cin>>s)
    {
        bool f=1;
        if(!isalpha(s[0])||isupper(s[0])) f=0;
        for(int i=0;i<s.size()&&f;i++)
            if(!isalpha(s[i])) f=0;
        if(f)
        {
            for(int i=0;i<s.size();i++)
                if(isupper(s[i])) cout<<"_"<<(char)tolower(s[i]);
                else cout<<s[i];
            cout<<endl;
            continue;
        }
        f=1;
        if(!isalpha(s[0])||!isalpha(s[s.size()-1])) f=0;
        for(int i=0;i<s.size()&&f;i++)
            if(isupper(s[i])) f=0;
            else if(i&&s[i]=='_'&&s[i-1]=='_') f=0;
        if(f)
        {
            for(int i=0;i<s.size();i++)
                if(!isalpha(s[i])) {cout<<(char)toupper(s[i+1]); i++;}
                else cout<<s[i];
            cout<<endl;
            continue;
        }
        cout<<"Error!"<<endl;

    }
}
