#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n,c=0,cnt=0;
    cin>>n;
    cin>>s;

    for(int i=0;i<n;i++){
        if(s[i]=='>') break;
        c++;
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='<') break;
        cnt++;
    }
    if(c+cnt>0) cout<<c+cnt<<endl;
    else cout<<0<<endl;

    return 0;
}
