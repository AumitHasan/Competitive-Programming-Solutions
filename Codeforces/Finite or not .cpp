#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

#define pf(a) cout<<a<<endl
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define mx 100007
#define mod 1000000009
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....

////

ll p,q,b;
double ar[25];

int main()
{

    int t,sz;
    scanf("%d",&t);
    ll a,b;
    while(t--){
        scanf("%lld %lld %lld",&p,&q,&b);

        if(p%q==0){
            printf("Finite\n");
            continue;
        }

        double num = (p*1.0)/q ;
        ll x = num;
        //cout<<num<<" "<<x<<endl;
        num = num - x;

        b = num * 1e12;
        cout<<num<<" X "<<b<<endl;

        if(num==.0){
            printf("Finite\n");
            continue;
        }

        bool flag = false;
        int in = 1;

        while(++in<=20){
            num = num * b * 1.0;
            x = num;
            num = num - x;
            a = num * 1e12;

            cout<<num<<" "<<a<<" "<<b<<endl;
            //printf("%.10f %.10f\n",num,tmp);
            if(a==b){
                cout<<"F"<<endl;
                flag = true;
                break;
            }

        }


        if(!flag) printf("Finite\n");
        else printf("Infinite\n");
    }

    return 0;
}
