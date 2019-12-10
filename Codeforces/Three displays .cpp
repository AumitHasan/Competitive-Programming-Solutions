#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

#define pf(a) cout<<a<<endl
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define MX 3007
#define MOD 1000000007
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....

////

int n,ar[MX],cost[MX],tmp[MX];


int main()
{
    IO;
    //

    cin>>n;
    for(int i=1;i<=n;i++) cin>>ar[i];
    for(int i=1;i<=n;i++) cin>>cost[i];

    for(int i=1;i<n;i++){
        int tk = 2e9;
        for(int j=i+1;j<=n;j++){
            if(ar[j]>ar[i]) tk = min(tk,cost[j]);
        }
        if(tk<2e9){
            tmp[i] = tk;
            //cout<<i<<" "<<tk<<endl;
        }
    }
    int ans = 2e9;

    for(int i=1;i<n-1;i++){
        int tk = 2e9,f=0;

        for(int j=i+1;j<n;j++){
            if(ar[i]<ar[j] && tmp[j]){
                f = 1;
                tk = min(tk,tmp[j]+cost[j]);
            }
        }
        if(f){
            ans = min(ans,cost[i]+tk);
        }
    }

    if(ans==2e9) cout<<-1<<endl;
    else cout<<ans<<endl;
}
