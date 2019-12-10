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

#define mx 100007

ll n,k,ans,s,ss,inc,num,ar[5][1007];

void solve()
{
    for(int i=4;i<=1000;i++){//1
        ar[1][i] = 1;
    }
    //
    s = 3;
    ar[2][4] = 6;
    for(int i=5;i<=1000;i++){//2
        s++;
        ar[2][i] += ar[2][i-1] + s;
    }
    //
    s = 4; inc = 6;
    ar[3][4] = 8;
    for(int i=5;i<=1000;i++){//3
        s+=2;
        //if(i<10) cout<<s<<" "<<inc;
        inc += s;
        ar[3][i] += ar[3][i-1] + inc;
        //if(i<10) cout<<ar[3][i]<<" ";
    }
    //
    ar[4][4] = 9; ar[4][5] = 45; ar[4][6] = 135;
    s = 27; ss = 54; inc = 90;
    for(int i=7;i<=1000;i++){
        s += 9;
        ss += s;
        inc += ss;
        ar[4][i] += ar[4][i-1] + inc;
        //if(i<10) cout<<ar[4][i]<<" ";
    }

}
int main()
{
    solve();
    cin>>n>>k;
    int c=0;
    for(int i=1;i<=k;i++) ans += ar[i][n];
    cout<<ans<<endl;

    return 0;
}

