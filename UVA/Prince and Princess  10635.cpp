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
#define M 62505

int n,p,q,ar[M],pcs[M];
unordered_map<int,int>mp;
int tail[M];


int LIS()
{
    int len=0;
    for(int i=1;i<=p+1;i++){
        if(mp[ar[i]]!=0){
            int in = mp[ar[i]];
            if(in<tail[0]){
                tail[0] = in;
            }
            else if(in>tail[len]){
                tail[++len] = in;
            }
            else{
                int pos = lower_bound(tail,tail+len+1,in)-tail;
                tail[pos] = in;
            }
        }
    }

    return len;
}
int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T){
        mp.clear();
        scanf("%d %d %d",&n ,&p ,&q);
        for(int i=1;i<=p+1;i++) scanf("%d",&ar[i]);
        for(int i=1;i<=q+1;i++){
            scanf("%d",&pcs[i]);
            mp[pcs[i]] = i;
        }

        int len = LIS();

        printf("Case %d: %d\n",N,len);
    }
    return 0;
}
