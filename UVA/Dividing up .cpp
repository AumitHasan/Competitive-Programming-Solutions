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

int ar[7],sum,dp[7][20010];

int call(int i,int val)
{
    //cout<<i<<" "<<val<<endl;
    if(val==0) return 1;
    if(i==7 || val<0) return 0;
    //if(val>sum) return 0;
    if(dp[i][val]!=-1) return dp[i][val];

    int P=0;
    for(int j=1;j<=ar[i];j++){
        P |= call(i+1,val-j*i);
    }
    return dp[i][val] |= P;
}
int main()
{
    int test=0;
    while(1){

        sum = ck = 0;
        test++;

        for(int i=1;i<6;i++){
            scanf("%d",&ar[i]);
            sum += ar[i] * i;
        }
        if(sum==0) break;
        //

        printf("Collection #%d:\n",test);
        if(sum%2==1){
            printf("Can't be divided.\n");
            continue;
        }
        //
        sum /= 2;

        mem(dp,-1);

        int res = call(1,sum);

        if(res) printf("Can be divided.\n");
        else printf("Can't be divided.\n");
        printf("\n");
    }
    return 0;
}
