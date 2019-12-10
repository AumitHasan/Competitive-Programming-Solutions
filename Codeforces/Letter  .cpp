#include<bits/stdc++.h>
using namespace std;

string s[60];

int main()
{
    int x,y,n,m,strt=-1,endd=-1;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(s[j][i]=='*'){ strt=i; break;}
        }
    }
    //cout<<strt<<endl;
    for(int i=m-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(s[j][i]=='*'){ endd=i; break;}
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='*'){x=i;break;}
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(s[i][j]=='*'){y=i;break;}
        }
    }
    //cout<<x<<" "<<y<<endl;
    for(int i=y;i<=x;i++){
        for(int j=endd;j<=strt;j++) cout<<s[i][j];
        cout<<endl;
    }
}
