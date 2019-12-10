#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

////

//

#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define mx 100007
#define mod 1000000009
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....
//

int f,n,d,ar[mx],dp[mx][31][2],path[mx][31][2],pos[mx];


bool com(int x,int y)
{
    return x>y;
}
int call(int i,int m,int ck)
{
    cout<<i<<" "<<m<<" "<<ck<<endl;

    if(i>0 && ck && !f) pos[i-1] = 1;
    else if(i>0 && !ck && !f) pos[i-1] = 0;

    if(i>=n){
        if(m==0) return 1;
        return 0;

    }
    if(dp[i][m][ck] != -1) return dp[i][m][ck];

    int ans = 0,nisi = 1;

    ans |= call(i+1,((m*10)+ar[i]),1);

    ans |= call(i+1,m,0);

    //path[i][m] = nisi;


    return dp[i][m][ck] = ans;
}
int main()
{
    cin>>n;
    int sum=0,d=0;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        if(ar[i]==0) d = 1;
        sum += ar[i];
    }

    if(!d) cout<<-1<<endl;
    else if(sum==0) cout<<0<<endl;
    else{
        sort(ar,ar+n,com);
        mem(dp,-1);
        int ans = call(0,0,0);
        if(ans){
            for(int i=0;i<n;i++){
                if(pos[i]) cout<<ar[i];
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
}
