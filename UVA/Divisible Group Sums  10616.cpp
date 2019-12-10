#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
#define ll long long int
#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 1007
#define int_map map<int,int>
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)
#define mx 201

int num[mx],C,used[mx],N,Q,D,M;
unordered_map<int,unordered_map<int,unordered_map<int,int>>>dp;

ll call(int i,int cnt,int sum)
{
    //cout<<i<<" "<<cnt<<" "<<sum<<endl;
    if(cnt>=M || i>=N){
        C++;
        //cout<<"sum: "<<sum<<endl;
        if(sum==0 && cnt==M) return 1;
        return 0;
    }
    if(dp[i][cnt][sum]!=0) return dp[i][cnt][sum];

    ll p1=0,p2=0;
    p1 += call(i+1,cnt+1,(sum+num[i])%D);
    p2 += call(i+1,cnt,sum%D);

    return dp[i][cnt][sum] = p1+p2;
}
int main()
{
    int T=0;
    while(scanf("%d %d",&N ,&Q) && N && Q){
        for(int i=0;i<N;i++) scanf("%d",&num[i]);
        printf("SET %d:\n",++T);
        for(int i=0;i<Q;i++){
            scanf("%d %d",&D ,&M);
            dp.clear();
            ll res = 0;
            for(int i=0;i<=N-M;i++){
                res += call(i+1,1,num[i]%D);
            }
            //cout<<C<<endl;
            printf("QUERY %d: %lld\n",i+1,res);
        }
    }
    return 0;
}
