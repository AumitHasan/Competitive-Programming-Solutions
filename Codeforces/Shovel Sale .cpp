#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int n,ar[100];

void call()
{
    ll zero=1000,num = 999,nine=3,c=1;
    while(1){

        for(int i=1;i<=8;i++){
            num += zero;
            if(n<num){
                cout<<c<<endl;
                return;
            }
            c++;
        }
        //
        num += zero;
        //cout<<n<<" "<<num<<endl;
        if(n<num){
            cout<<c<<endl;
            return ;
        }
        else if(n==num){
            cout<<1<<endl;
            return;
        }
        c=0;
        zero *= 10;
    }
}
int main()
{
    cin>>n;
    if(n>=1000){
        call();
    }
    else{
        for(int i=9;i<=n*2;i+=10){
            int x,tmp=i,cnt=0,c =0;

            while(tmp>0){
                x = tmp % 10;
                tmp/=10;
                if(x!=9) break;
                if(x==9) cnt++;
            }
            cout<<cnt<<" ";

            for(int j=1;j<=n;j++){
                x = i-j;
                if(j>i) break;
                c++;
            }
            ar[cnt] = c;
            cout<<ar[cnt]<<endl;
        }
        int ans = 0;

        for(int i=1;i<=12;i++){
            if(ar[i]>0) ans = ar[i];
        }
        cout<<ans<<endl;
    }
}

