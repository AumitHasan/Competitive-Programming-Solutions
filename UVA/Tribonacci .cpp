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
#define     MAX3(a,b,c)              max(a,max(b,c))
#define     MAX4(a,b,c,d)            max(max(a,b),max(c,d))
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     1000000009
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      100007

////


class matrix{
public:
    ll mat[5][5];
    int r,c;
    matrix(int _r,int _c){
        r = _r;
        c = _c;
        memset(mat,0,sizeof(mat));
    }
    void identity(){
        for(int i=0;i<r;i++) mat[i][i] = 1;
    }
    matrix operator *(matrix t){
        matrix ans(r,t.c);
        for(int i=0;i<r;i++){
            for(int j=0;j<t.c;j++){
                for(int k=0;k<c;k++){
                    ans.mat[i][j] += (mat[i][k] * t.mat[k][j]) % mod;
                    ans.mat[i][j] %= mod;
                }
            }
        }
        return ans;
    }
    matrix operator ^(ll p){
        matrix ans(r,c);
        ans.identity();
        matrix a = *this;
        while(p){
            if(p&1) ans = (ans * a);
            a = (a * a);
            p = p >> 1;
        }
        return ans;
    }
};


int main()
{
    // for fibonacci series

    ll n;
    while(scanf("%lld",&n) && n){
        if(n<3){
            printf("%lld\n",n-1);
            continue;
        }

        matrix M(3,3);
        M.mat[0][0] = M.mat[0][1] = M.mat[0][2] = M.mat[1][0] = M.mat[2][1] = 1;

        matrix A(3,1);
        A.mat[0][0] = 2;
        A.mat[1][0] = 1;


        M = M^(n-3);
        A = M*A;

        printf("%lld\n",A.mat[0][0] % mod);
    }

    return 0;
}
