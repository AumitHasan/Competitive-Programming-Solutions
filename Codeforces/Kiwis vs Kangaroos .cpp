#include<bits/stdc++.h>
using namespace std;

int A[500],B[500];
string a,b,str;

int main()
{
    a = "KANGAROO";
    b = "KIWIBIRD";
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]>='a') str[i] = str[i]-32;
        A[str[i]]++;
        B[str[i]]++;
    }
    int x=0,y=0;
    for(int i=0;i<a.length();i++){
        x += A[a[i]];
    }
    for(int i=0;i<b.length();i++){
        y += B[b[i]];
    }
    if(x>y) cout<<"Kangaroos"<<endl;
    else if(x<y) cout<<"Kiwis"<<endl;
    else cout<<"Feud continues"<<endl;

    return 0;
}
