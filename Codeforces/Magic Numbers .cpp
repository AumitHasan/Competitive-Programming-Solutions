#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)



int main()
{
    string str;
    cin>>str;

    bool flag = false;

    for(int i=0;i<str.length();i++){
        if(str[i]=='1' || str[i]=='4'){

        }
        else flag = true;
    }
    if(flag || str[0]=='4'){
        cout<<"NO"<<endl;
        return 0;
    }

    for(int i=1;i<str.length();i++){
        if(str[i]=='4'){
            if(i>1){
                if(str[i-1]=='4'){
                    if(str[i-2]!='1') flag = true;
                }
            }
            else{
                if(str[i-1]!='1') flag = true;
            }
        }
    }
    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
