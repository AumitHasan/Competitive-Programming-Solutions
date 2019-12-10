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

string A[103],B[103],str;
int x,y,dp[103][103];
vector<string>v;

int LCS(int i,int j)
{
    if(i>x || j>y) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int P=0;
    if(A[i]==B[j]){
        //cout<<A[i]<<" "<<B[j]<<endl;
        P = 1+LCS(i+1,j+1);
    }
    else
        P = max(LCS(i,j+1),LCS(i+1,j));

    return dp[i][j] = P;
}
void path(int i,int j)
{
    if(i>x || j>y){
        return ;
    }
    if(A[i]==B[j]){
        v.push_back(A[i]);
        path(i+1,j+1);
    }
    else{
        if(dp[i][j+1]>dp[i+1][j]) path(i,j+1);
        else path(i+1,j);
    }
}
int main()
{
    IO;
    while(cin>>str){
        x = -1,y=-1;
        A[++x] = str;
        while(1){
            cin>>str;
            if(str=="#") break;
            A[++x] = str;
        }
        while(1){
            cin>>str;
            if(str=="#") break;
            B[++y] = str;
        }
        //cout<<x<<" "<<y<<endl;
        mem(dp,-1);
        v.clear();
        int len = LCS(0,0);
        path(0,0);
        //cout<<len<<endl;
        for(int i=0;i<v.size();i++){
            if(i>0) cout<<" ";
            cout<<v[i];
        }
        cout<<endl;
    }
}
