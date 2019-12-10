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

int main()
{
    int ar[103];
    int T,N=0,n;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
        bool mark[103]={0};

        int res = 0;
        for(int i=1;i<=n;i++){
            if(mark[i]==0 && i!=ar[i]){
                int s = ar[i],c=0;
                mark[i]=1;
                while(s!=i){
                    c++;
                    mark[s]=1;
                    s = ar[s];
                }
                res += c;
            }
        }
        printf("Case %d: %d\n",N,res);
    }
    return 0;
}
