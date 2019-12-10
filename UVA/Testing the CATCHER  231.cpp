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

int idx,ar[1000000],tail[1000000];
vector<int>v;

int bin(int lo,int hi,int key)
{
    while(hi>lo){
        int mid = (lo+hi)/2;
        if(tail[mid]>=key) hi = mid;
        else lo = mid+1;
    }
    return hi;
}
int LIS()
{
    int len=0;
    tail[0] = ar[0];
    for(int i=1;i<idx+1;i++){
        //int pos = lower_bound(tail,tail+len,ar[i])-tail;
        if(ar[i]<tail[0]) tail[0] = ar[i];
        else if(ar[i]>tail[len]) tail[++len] = ar[i];
        else{
            tail[bin(0,len,ar[i])] = ar[i];
        }
    }

    return len;
}
int main()
{

    int num,T=0;
    while(scanf("%d",&num) && num!=-1){
        if(T>0) printf("\n");
        T++;
        v.push_back(num);
        while(scanf("%d",&num) && num!=-1){
            v.push_back(num);
        }
        //cout<<v.size();
        idx = -1;
        for(int i=v.size()-1;i>=0;i--) ar[++idx] = v[i];

        int res = LIS();
        printf("Test #%d:\n",T);
        printf("  maximum possible interceptions: %d\n",res+1);

        v.clear();
    }
    return 0;
}
