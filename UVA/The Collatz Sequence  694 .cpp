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
    //READ("in.txt");
    //WRITE("out.txt");
    int N=0;
    ll A,lim,B;
    while(1){
        cin>>A>>lim;
        B=A;
        if(A<=-1 && lim<=-1) break;
        int i;
        for(i=1;;i++){
            if(A==1) break;
            if(A%2==0) A/=2;
            else A = A*3 +1;
            if(A>lim) break;
        }

        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",++N,B,lim,i);
    }
    return 0;
}
