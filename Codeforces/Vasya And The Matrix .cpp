#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      100007

////

int ans[104][104];


int main()
{
    int n,m;
    scii(n,m);
    int r[n],c[m];
    int cur = 0;
    for(int i=0;i<n;i++) sci(r[i]) , cur ^= r[i] , ans[i][m-1] = r[i];
    for(int i=0;i<m;i++) sci(c[i]) , cur ^= c[i], ans[0][i] = c[i];

    if(cur != 0){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;

    cur = r[0];
    for(int i=0;i<m-1;i++) cur ^= c[i];

    ans[0][m-1] = cur;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
