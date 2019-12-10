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

int n,k,ar[1005];

int possible(int mid)
{
    int cur=0,camp=0;
    for(int i=0;i<=n;i++){
        if(mid<ar[i]) return 0;
        cur += ar[i];
        if(cur>mid){
            camp++;
            cur = ar[i];
        }
    }
    if(camp<=k) return 1;
    return 0;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d%d",&n,&k);
        for(int i=0;i<=n;i++) scanf("%d",&ar[i]);
        int lo=0,hi=10e9+7,res;
        while(lo<=hi){
        //    cout<<
            int mid = (lo+hi)/2;

            if(possible(mid)){
                res = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        printf("Case %d: %d\n",N,res);

        int cur = 0,c=0;
        bool mark[1005]={0};

        for(int i=0;i<=n;i++){
            cur += ar[i];
            if(cur>res){
                c++;
                mark[i-1] = 1;
                //cout<<"m: "<<i-1<<endl;
                cur = ar[i];
            }
        }
        if(c<k){
            c = k-c;
            for(int i=n-1;c>0 && i>=0;i--){
                if(mark[i]==0){
                    c--;
                    mark[i]=1;
                }
            }
        }
        cur = 0;
        for(int i=0;i<=n;i++){
            cur += ar[i];
            if(mark[i]){
                printf("%d\n",cur);
                cur = 0;
            }
        }
        if(cur>0) printf("%d\n",cur);
    }
    return 0;
}
