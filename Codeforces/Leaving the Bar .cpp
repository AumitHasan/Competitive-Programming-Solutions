#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define pf(a)                   cout<<a<<endl
#define sci(a)                  scanf("%d",&a)
#define scii(a, b)              scanf("%d %d",&a, &b)
#define sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define scl(a)                  scanf("%lld", &a)
#define scll(a, b)              scanf("%lld %lld", &a, &b)
#define sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define umap                    unordered_map
#define mem(a,b)                memset(a,b,sizeof(a))
#define IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)

#define mx                      100007
#define mod                     1000000007
#define base                    10000007
#define eps                     1e-9
#define INF                     1llu<<61
#define inf                     1<<29
#define PI                      acos(-1.0) //3.14159.....

////


struct info{
    int x, y;
    info(){};
    info(int _x, int _y){
        x = _x;
        y = _y;
    }
}ar[mx];

int sign[mx];

bool ok(ll x, ll y)
{
    //cout<<(x*x + y*y)<<endl;
    return (x*x + y*y <= 2250000000000);
}
int main()
{
    int n,a,b;
    ll sumx = 0, sumy = 0;

    sci(n);

    for(int i=0;i<n;i++){
        scll(a,b);
        ar[i] = info(a,b);
        sign[i] = rand()%2 ? 1 : -1;
        sumx += a * sign[i];
        sumy += b * sign[i];

    }
    //cout<<sumx<<" "<<sumy<<endl;
    while(!ok(sumx, sumy)){
        int idx = rand() % n;
        sign[idx] *= -1;

        sumx += 2 * sign[idx] * ar[idx].x;
        sumy += 2 * sign[idx] * ar[idx].y;
    }

    for(int i=0;i<n;i++) printf("%d ",sign[i]);

    return 0;
}
