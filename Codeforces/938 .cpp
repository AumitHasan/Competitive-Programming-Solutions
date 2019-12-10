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

#define mx 110000

umap<ll,int>mp;
ll a,b,bb,mm,ttl,tmp,x;

int main()
{
    IO;
    //
    for(int i=1;i<=mx;i++) mp[i*i] = i;
    //
    int t;
    cin>>t;
    while(t--){
        cin>>x;
        //x == 0
        if(mp[x+1]){
            cout<<mp[x+1]<<" "<<mp[x+1]<<endl;
            continue;
        }
        bool flag = false;

        for(int i=1 ;i<=mx ;i++){
            ttl = i*i;
            if(ttl>x){
                tmp = ttl - x;
                if(tmp<x && tmp>1 && mp[tmp]){
                    bb = i / mp[tmp];
                    //if(i % mp[tmp] != 0) b++;
                    ttl = i / (mp[tmp]+1);
                    if(bb>ttl){
                        cout<<i<<" "<<bb<<endl;
                        flag = true;
                        break;
                    }

                }
            }
        }
        if(flag) continue;
        cout<<-1<<endl;
    }
}
