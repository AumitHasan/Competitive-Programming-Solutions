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

int N,r,c,x,y,ar[103][103],sum[103],cros[103],ans;

void kadne()
{
    ans = 0;

    for(int i=1;i<=N;i++){
        mem(sum,0);
        for(int j=i;j<=N;j++){
            for(int k=1;k<=N;k++){
                if(ar[k][j]) sum[k]=0;
                else sum[k]++; cros[k]=j;
            }

            for(int k=1;k<=N;k++){
                int m = sum[k],c=0,X=0;
                for(int l=k;l<=N;l++){
                    if(m==sum[l]){
                        c++;
                        k=l;
                    }
                    else break;
                }
                if(m>0){
                    //cout<<c<<endl;
                    ans = max(ans,m*c);
                }
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        mem(ar,0);
        int b;
        scanf("%d%d",&N,&b);
        while(b--){

            scanf("%d%d%d%d",&r,&c,&x,&y);
            for(int i=min(r,x);i<=max(r,x);i++){
                for(int j=min(c,y);j<=max(c,y);j++) ar[i][j]=1;
            }
            //
        }
//        for(int i=1;i<=N;i++){
//            for(int j=1;j<=N;j++) cout<<ar[i][j]<<" ";
//            cout<<endl;
//      }
        kadne();
        printf("%d\n",ans);
    }
    return 0;
}
