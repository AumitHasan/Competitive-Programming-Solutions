#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

ll k,p;
int ar[100];

void call()
{
    ll sum = 0,c=0;
    ll ck,in=0,x,n,i=0;
    while(1){

        in=0;
        x = ++i;
        //cout<<x<<endl;
        n=i;

        while(n>0){
            ar[++in] = n%10;
            n/=10;
        }
        if(in%2==0){
            int lo=1,hi=in,f=0,tmp = in/2;

            for(int j=1;j<=tmp;j++){
                if(ar[lo]!=ar[hi]){
                    f=1;
                    break;
                }
                lo++;
                hi--;
            }
            if(f==0){
                //for(int j=1;j<=in;j++) x = (x*10) + ar[j];
                //cout<<x<<endl;
                sum = (sum + x) % p;
                c++;
                if(c==k) break;
            }
        }



    }
    cout<<sum<<endl;
}
int main()
{
    cin>>k>>p;

    call();
}
