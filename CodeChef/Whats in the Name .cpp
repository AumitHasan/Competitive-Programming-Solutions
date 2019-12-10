#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d ",&T);
    while(T--){
        string s,a,b,c;
        getline(cin,s);
        int len = s.length();
        int spc=0;
        for(int i=0;i<len;i++){
            if(s[i]==' ') spc++;

            else if(spc==0) a += s[i];
            else if(spc==1) b += s[i];
            else c += s[i];
        }

        if(spc==0){
            for(int i=0;i<a.length();i++){
                if(i==0) a[0] = toupper(a[0]);
                else a[i] = tolower(a[i]);
            }
            cout<<a<<endl;
        }
        else if(spc==1){
            char x = toupper(a[0]);
            cout<<x<<". ";
            for(int i=0;i<b.length();i++){
                if(i==0) b[0] = toupper(b[0]);
                else b[i] = tolower(b[i]);
            }
            cout<<b<<endl;
        }
        else{
            char x = toupper(a[0]);
            char y = toupper(b[0]);
            cout<<x<<". "<<y<<". ";
            for(int i=0;i<c.length();i++){
                if(i==0) c[0] = toupper(c[0]);
                else c[i] = tolower(c[i]);
            }
            cout<<c<<endl;
        }
    }
    return 0;
}
