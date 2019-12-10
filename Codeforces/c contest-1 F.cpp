#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 70
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

ll n,q,val,m,level,curlvl,pos;
ll pw[mx],ar[mx];
string str;


void dfs(ll i,ll j,ll lvl)
{
    ll mid = (i+j) / 2;
    if(mid==val){
        //cout<<val<<" x "<<lvl<<endl;
        curlvl = lvl;
        return;
    }
    if(val<mid){
        pos = 1;
        dfs(i,mid-1,lvl+1);
    }
    else{
        pos = 2;
        dfs(mid+1,j,lvl+1);
    }
}
void pre()
{
    pw[1] = 1;
    for(int i=2;i<=64;i++) pw[i] = pw[i-1] * 2;

    for(int i=1;i<=64;i++){
        if(n < pw[i]){
            level = i-1;
            ar[level] = 0;
            ar[level-1] = 1;

            for(int j=level-2;j>0;j--){
                ar[j] = ar[j+1] * 2;
            }
            break;
        }
    }
    //cout<<level<<endl;
}
int main()
{
    IO;

    cin>>n>>q;

    while(q--){

        cin>>val;
        pre();

        cin>>str;

        dfs(1,n,1);
        //cout<<pos<<" "<<level<<endl;
        int len = str.length();

        for(int i=0;i<len;i++){
            if(str[i]=='L' && curlvl<level){
                val -= ar[curlvl];
                curlvl++;
            }
            else if(str[i]=='R' && curlvl<level){
                val += ar[curlvl];
                curlvl++;
            }
            else if(str[i]=='U' && curlvl>1){
                dfs(1,n,1);
                if(pos==1){
                    val += ar[curlvl-1];
                    curlvl--;
                }
                else if(pos==2){
                    val -= ar[curlvl-1];
                    curlvl--;
                }
                    //dfs(1,n,1);
            }
            //cout<<"i: "<<i<<" "<<val<<" "<<curlvl<<endl;
        }
        cout<<val<<endl;
    }
    return 0;
}
