#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,n;
    string str;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>str;
        bool flag = false;
        int h=0,t=0,c=0;
        for(int i=0;i<n;i++){
            if(str[i]=='H'){
                if(h==1) flag = true;
                else h = 1;
            }
            else if(str[i]=='T'){
                if(h==0) flag = true;
                h = 0;
            }
        }
        if(flag || h==1) cout<<"Invalid"<<endl;
        else cout<<"Valid"<<endl;
    }
    return 0;
}
