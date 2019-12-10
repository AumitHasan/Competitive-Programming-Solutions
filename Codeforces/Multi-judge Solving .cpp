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

int dx[] = {1,1,1,0};
int dy[] = {-1,0,1,1};

ll ar[1009];

int main()
{
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>ar[i];
    sort(ar,ar+n);

    if(k*2>=ar[n-1]){
        cout<<0<<endl;
        return 0;
    }


    int c=0;
    if(ar[0] > k*2){
        ll val = k;
        while(val<ar[0]){
            val *= 2;
            if(val<ar[0]) c++;
            if(val>=ar[0]){
                val/=2;
                break;
            }
        }
        k = max(val,ar[0]);
    }
    //ar[0] = max(ar[0],k);
    //k = max(ar[0],k);

    for(int i=1;i<n;i++){
        if(ar[i] <= k*2) continue;

        ar[i-1] = max(ar[i-1],k);

        if(ar[i-1]*2 < ar[i]){
            //if(ar[i-1]<k){
                ll val = max(ar[i-1],k);

                while(val<ar[i]){

                    val *= 2;
                    if(val<ar[i]) c++;
                    //cout<<val<<endl;
                    if(val>=ar[i]){
                        val /= 2;
                        break;
                    }
                }
                k = max(k,val);
                //k = max(k,ar[i]);
            //}
            //else{

            //}
        }
        k = max(ar[i],k);
    }
    cout<<c<<endl;
}

