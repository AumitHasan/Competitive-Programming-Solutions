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
#define M 100003

ll val[M],ar[M];
ll s,price=0,item=0,n;

int binSearch(int k)
{


    for(int i=0;i<n;i++){
        val[i] = (i+1)*k + ar[i];
    }
    sort(val,val+n);
    int sum=0;
    for(int i=0;i<k;i++){
        sum += val[i];
    }
    if(sum<=s) return sum;
    return 0;
}
int main()
{

    cin>>n>>s;
    for(int i=0;i<n;i++){
        //scanf("%lld",&ar[i].p);
        cin>>ar[i];
    }
    int lo=0,hi=n;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        //cout<<mid<<endl;
        //cout<<lo<<" "<<hi<<endl;
        ll res = binSearch(mid);
        if(res>0){
            //if(mid>item){
                price = res;
                item = mid;
            //}
            lo = mid+1;
        }
        else hi = mid-1;
    }
    cout<<item<<" "<<price<<endl;
    return 0;
}
