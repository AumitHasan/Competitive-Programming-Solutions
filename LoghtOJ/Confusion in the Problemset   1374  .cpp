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

int ar[100003];
bool ans[10003];

int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T){
        int n,pos;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        pos = n-1;
        bool flag = false;
        mem(ans,false);
        for(int i=0;i<n;i++){
            if(ar[i]>pos){
                flag=true;
                break;
            }
            if(ans[ar[i]]==0) ans[ar[i]]=1;
            else if(ans[pos-ar[i]]==0) ans[pos-ar[i]]=1;
            else{
                flag = true;
                break;
            }
        }
        if(flag) printf("Case %d: no\n",N);
        else printf("Case %d: yes\n",N);
    }
    return 0;
}
