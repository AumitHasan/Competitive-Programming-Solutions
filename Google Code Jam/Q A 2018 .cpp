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

int D;
string str;

void sp()
{
    for(int i=str.length()-2;i>=0;i--){
        if(str[i]=='C' && str[i+1]=='S'){
            swap(str[i],str[i+1]);
            break;
        }
    }
}
int clc()
{
    int damage = 0,pw=1;
    for(int i=0;i<str.length();i++){
        if(str[i]=='C') pw *= 2;
        else{
            damage += pw;
        }
    }
    //cout<<damage<<endl;
    return damage;
}
int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T){
        cin>>D>>str;
        if(clc()<=D){
            printf("Case #%d: 0\n",N);
            continue;
        }
        //
        bool flag = false;

        for(int i=1;i<=905;i++){
            sp();
            if(clc()<=D){
                printf("Case #%d: %d\n",N,i);
                flag = true;
                break;
            }
        }
        if(!flag) printf("Case #%d: IMPOSSIBLE\n",N);
    }
    return 0;
}
