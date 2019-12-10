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

int n,ar[21],dp[21][203];

int call(int i,int val)
{
    if(i==n){
        if(val==0) return 1;
        return 0;
    }
    if(dp[i][val]!=-1) return dp[i][val];

    return dp[i][val] = max(call(i+1,val+ar[i]),call(i+1,val-ar[i]));
}
int main()
{
    int in,test,num;
    scanf("%d ",&test);
    string str;
    while(test--){
        mem(dp,-1);
        getline(cin,str);
        in = -1;
        num = 0;
        int len = str.length();

        for(int i=0;i<len;i++){
            if(str[i]==' '){
                ar[++in] = num;
                num = 0;
            }
            else if(i==len-1 && str[i]!=' '){
                num = (num*10) + (str[i]-'0');
                ar[++in] = num;
            }
            else{
                num = (num*10) + (str[i]-'0');
            }
        }
        n = in+1;

        int res = call(0,0);
        if(res) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
