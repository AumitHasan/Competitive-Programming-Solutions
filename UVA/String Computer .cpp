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

int len;
string str,ans;
unordered_map<string,unordered_map<int,int> >dp;

int call(string ch,int mv)
{
    if(ch.length()>len+3) return 0;
    if(ch==ans) return 0;

    if(dp[ch][mv]!=0) return dp[ch][mv];

    int P = 0;

    for(int i=0;i<ch.length();i++){
        //P = 1 + call()
    }
}
int main()
{
    str = "abcde";
    string s="a"+1;
    str.insert(1,s);
    cout<<str;
    ans = "bcgfe";
    len = ans.size();
}
