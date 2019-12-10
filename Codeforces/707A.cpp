#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,c=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch!='W' and ch!='B' and ch!='G'){
                c=1;
            }
        }
    }
    if(c==0) cout<<"#Black&White"<<endl;
    else cout<<"#Color"<<endl;
}
