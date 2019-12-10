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
int s,m,n,ar[101],in,lim;

ll dp[101][(1<<8)+1][(1<<8)+1],a,b;
vector<int>v[102];


ll call(int i,int mask1,int mask2)
{
    if(mask1==lim && mask2==lim) return 0;
    if(i>=n) return 10000000;
    if(dp[i][mask1][mask2] != -1) return dp[i][mask1][mask2];

    a = mask1,b=mask2;
    for(int j=0;j<v[i].size();j++){
        int add = v[i][j];
        if(!(a & (1<<add))) a = a | (1<<add);
        else if(!(b & (1<<add))) b = b | (1<<add);
    }
    ll p1=10000000;
    p1 = min(p1,ar[i]+call(i+1,a,b));
    p1 = min(p1,call(i+1,mask1,mask2));
    return dp[i][mask1][mask2] = p1;

    //return dp[i][mask1][mask2] = min(call(i+1,a,b)+ar[i],call(i+1,mask1,mask2));
}
int main()
{

    while(1){
        int cost=0,cst=0;
        mem(dp,-1);
        for(int i=0;i<102;i++)v[i].clear();
        cin>>s>>m>>n;
        if(s==0) break;
        lim = (1<<s)-1;


        in=-1;
        string str;
        int mask1=0,mask2=0;

        for(int i=0;i<m;i++){
            cin>>cst;
            cost+=cst;
            cin.ignore();
            getline(cin,str);

            int add = 0;

            for(int j=0;j<str.length();j++){

                if(str[j]==' '){
                    add--;
                    if((mask1 & (1<<add))==0){
                        mask1 = mask1 | (1<<add);
                    }
                    else mask2 = mask2 | (1<<add);
                    add=0;
                }
                else add = (add*10)+(str[j]-'0');
            }
            if(add>0){
                add--;
                if((mask1 & (1<<add))==0){
                    mask1 = mask1 | (1<<add);
                }
                else mask2 = mask2 | (1<<add);
            }
        }

        for(int i=0;i<n;i++){
            cin>>ar[++in];
            cin.ignore();
            getline(cin,str);
            int add = 0;

            for(int j=0;j<str.length();j++){
                if(str[j]==' '){
                    v[in].push_back(add-1);
                    add=0;
                }
                else add = (add*10)+(str[j]-'0');
            }
            if(add>0) v[in].push_back(add-1);
        }
        cost += call(0,mask1,mask2);
        cout<<cost<<endl;
    }
    return 0;
}
