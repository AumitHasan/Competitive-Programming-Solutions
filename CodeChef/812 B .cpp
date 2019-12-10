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

int ar[17][101],dp[16][101],n,m,x=10e9;
struct info{
    int total,left,right;
}digit[17];

int call(int i,int j)
{
    cout<<i<<" "<<j<<endl;
    if(i==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int P = 100000000;

        if(j==m){
            P = min(P,m+2+call(i-1,0));
            P = min(P,digit[i].right*2+1+call(i-1,j));
        }
        if(j==0){
            P = min(P,m+2+call(i-1,m));
            P = min(P,digit[i].left*2+1+call(i-1,j));
        }
        //x = min(x,P);

    return dp[i][j] = P;
}
int main()
{
    cin>>n>>m;
    string str;
    for(int i=1;i<=n;i++){
        int c=0,x=-1,y=-1;
        cin>>str;
        for(int j=0;j<=m+1;j++){
            ar[i][j] = str[j]-'0';
            if(ar[i][j]==1) c++;
        }
        digit[i].total = c;
        if(c>0){
            digit[i].left = 0;
            for(int j=1;j<=m;j++){
                if(ar[i][j]==1){
                    digit[i].left = j;
                    break;
                }
            }
            int c = 0;
            digit[i].right = 0;
            for(int j=m;j>0;j--){
                c++;
                if(ar[i][j]==1){
                    digit[i].right = c;
                    break;
                }
            }
        }
        cout<<digit[i].total<<" "<<digit[i].left<<" "<<digit[i].right<<endl;
    }
    //cout<<"dffdlsj"<<endl;
    mem(dp,-1);
    int res = call(n,0);
    cout<<res<<endl;
}
