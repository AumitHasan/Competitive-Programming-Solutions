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

int sum,ar[7],dp[60007],cnt[60007];

void call()
{
    mem(dp,0);
    bool P = false;
    dp[0]=1;

    for(int i=1;i<=6;i++){
        mem(cnt,0);
        for(int j=0;j<=sum;j++){
            if(cnt[j]==ar[i]) break;
            if(dp[j] && !dp[j+i] && cnt[j]<ar[i]){
                dp[j+i] = 1;
                cnt[j+i] = cnt[j]+1;
            }
        }
    }
}
int main()
{
    int test=0;
    while(1){

        sum = 0;
        test++;

        for(int i=1;i<=6;i++){
            cin>>ar[i];
            //cout<<ar[i]*i<<endl;
            sum += ar[i] * i;
        }
        //cout<<sum/2<<endl;
        if(sum==0) return 0;

        printf("Collection #%d:\n",test);

        if(sum%2==1){
            printf("Can't be divided.\n\n");
            continue;
        }

        sum /= 2;

        call();

        if(dp[sum]) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");

    }
    return 0;
}
