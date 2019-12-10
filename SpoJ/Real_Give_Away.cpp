#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]>=97) s[i]-=32;
            else s[i]+=32;
        }
        cout<<s<<endl;
    }
}
