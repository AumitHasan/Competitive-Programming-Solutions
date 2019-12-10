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



#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      100007

////

ll mod;

class matrix{
public:
    ll mat[6][6];
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
    int N=0,T,a1,a2,b1,b2,c1,c2,f0,f1,f2,g0,g1,g2,t;
    ll n;
    sci(T);
    while(++N<=T){
        sciii(a1,b1,c1);
        sciii(a2,b2,c2);
        sciii(f0,f1,f2);
        sciii(g0,g1,g2);
        scl(mod);
        sci(t);
        printf("Case %d:\n",N);


        matrix M(6,6);
        M.mat[0][0] = a1; M.mat[0][1] = b1; M.mat[0][5] = c1;
        M.mat[3][2] = c2; M.mat[3][3] = a2; M.mat[3][4] = b2;
        M.mat[1][0] = M.mat[2][1] = M.mat[4][3] = M.mat[5][4] = 1;

        matrix A(6,1);
        A.mat[0][0] = f2; A.mat[1][0] = f1; A.mat[2][0] = f0;
        A.mat[3][0] = g2; A.mat[4][0] = g1; A.mat[5][0] = g0;


        while(t--){
            scl(n);

            if(n<3){
                if(!n) printf("%d %d\n",f0%mod,g0%mod);
                if(n==1) printf("%d %d\n",f1%mod,g1%mod);
                if(n==2) printf("%d %d\n",f2%mod,g2%mod);
                continue;
            }



            matrix tmp = M^(n-2);
            tmp = tmp*A;

            printf("%lld %lld\n",tmp.mat[0][0]%mod,tmp.mat[3][0]%mod);
        }
    }
    return 0;
}
