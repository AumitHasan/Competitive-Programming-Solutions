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

int ar[] = {101, 103, 107, 109, 11, 113, 127, 13, 131, 137, 139, 149, 151, 157, 163,
167, 17, 173, 179, 181, 19, 191, 193, 197, 199, 2, 211, 223, 227, 229, 23, 233,
239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 29, 293, 3, 31, 37, 41, 43, 47,
5, 53, 59, 61, 67, 7, 71, 73, 79, 83, 89, 97};

int n,t;
int dp[63][1007][16],path[63][1007][16];


int call(int pos,int need,int prime)
{
    if(pos>61){
        if(need==0 && prime==0) return 1;
        return 0;
    }
    if(need==0 && prime==0) return 1;
    if(need==0 || prime==0) return 0;
    if(dp[pos][need][prime] != -1) return dp[pos][need][prime];

    int lim,cnt,res=0;
    if(ar[pos]==2) lim = 1;
    else lim = 2;

    for(int i=lim;i>=0;i--){
        int tmp = ar[pos] * i;
        if(need-tmp >=0 && prime-i >= 0){
            res |= call(pos+1,need-tmp,prime-i);
            cnt = i;
            if(res) break;
        }
    }
    path[pos][need][prime] = cnt;
    return dp[pos][need][prime] = res;
}
int main()
{
    int test=0;
    mem(dp,-1);
    while(scanf("%d %d",&n,&t)){
        if(!n && !t) break;

        int ans = call(0,n,t);
        printf("CASE %d:\n",++test);

        if(!ans){
            printf("No Solution.\n");
        }
        else{
            bool flag = false;
            for(int i=0;i<62;i++){
                int tmp = path[i][n][t];
                if(tmp){
                    for(int j=1;j<=tmp;j++){
                        if(flag) printf("+");
                        printf("%d",ar[i]);
                        flag = true;
                    }
                    n -= tmp*ar[i];
                    t -= tmp;
                }
                if(!n) break;
            }
            printf("\n");
        }
    }
    return 0;
}
