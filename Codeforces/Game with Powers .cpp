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

bool flag[mx];
map<int,int>mp;

int main()
{
    ll n,c=0,cc=0,tmp;

    cin>>n;
    for(int i=2;i*i<=n;i++){
        if(!flag[i]){
            cc++;
            //c++;
            bool ck=false;
            tmp = i;
            while(1){
                tmp *= i;
                //cout<<tmp<<endl;
                if(tmp>n) break;
                if(tmp*tmp <= n) flag[tmp] = 1;
                ck = true;
                c++;
            }
            if(ck) c++;
        }
    }
    //cout<<c<<" "<<cc<<endl;
    n -= c;

    if(n&1) cout<<"Vasya"<<endl;
    else cout<<"Petya"<<endl;
}
