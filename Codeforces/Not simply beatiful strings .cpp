#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

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
#define pii acos(-1.0)

#define mx 100007

int alp[30];

int main()
{
    int f = 0;
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++) alp[str[i]-'a']++;
    int c = 0;
    for(int i=0;i<26;i++){
        if(alp[i]){
            c++;
            if(alp[i]>1) f++;
        }
    }
    //
    if(c==1) cout<<"NO"<<endl;
    else if(c==2){
        if(f>=2 || !f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else{
        if(c%2==0) cout<<"YES"<<endl;
        else{
            if(f) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}
