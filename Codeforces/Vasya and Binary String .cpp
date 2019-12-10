#include<stdio.h>
#include<bits/stdc++.h>

#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef     long long int           ll;
typedef     unsigned long long int  llu;
typedef     pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)          scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     max3(a,b,c)             max(a,max(b,c))
#define     max4(a,b,c,d)           max(max(a,b),max(c,d))
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


#define     mx                      103

////


int n,ar[mx];
ll dp[mx][mx][mx][3];
string str;


int SET(int pos,int type)
{
    if(str[pos]-'0' == type) return 1;
    return 0;
}
ll call(int pos,int zero,int one,int last)
{
    if(pos >= n){
        return ar[zero] + ar[one];
    }
    if(dp[pos][zero][one][last] != -1) return dp[pos][zero][one][last];

    ll res = 0;

    res = max(res, ar[1] + call(pos+1,zero,one,last));

    if(last == 2){
        res = max(res , ar[1] + call(pos+1,zero,one,2));
        res = max(res, call(pos+1,zero + SET(pos,0), one + SET(pos,1),str[pos]-'0'));
    }
    else{
        if(str[pos]-'0' == 1){//cur = 1
            res = max(res, ar[zero] + ar[one] + call(pos+1,0,1,1));
            if(!one){
                res = max(res, ar[1] + call(pos+1,zero,one,last));
                res = max(res, call(pos+1,zero,one+1,1));
            }
            else{
                if(last==1){
                    res = max(res, call(pos+1,zero,one+1,1));
                    res = max(res, ar[one+1] + call(pos+1,zero,0,(zero ? 0 : 2)));
                }
                else{
                     res = max(res, ar[zero] + call(pos+1,0,one+1,1));
                     res = max(res, ar[one] + call(pos+1,0,1,1));
                     res = max(res, ar[zero] + ar[one+1] + call(pos+1,0,0,2));
                     res = max(res, ar[1] + call(pos+1,zero,one,last));
                }
            }
        }
        else{//cur = 0
            res = max(res, ar[zero] + ar[one] + call(pos+1,1,0,0));
            if(!zero){
                res = max(res, ar[1] + call(pos+1,zero,one,last));
                res = max(res, call(pos+1,zero+1,one,0));
            }
            else{
                if(last==0){
                    res = max(res, call(pos+1,zero+1,one,0));
                    res = max(res, ar[zero+1] + call(pos+1,0,one,(one ? 1 : 2)));
                }
                else{
                     res = max(res, ar[one] + call(pos+1,zero+1,0,0));
                     res = max(res, ar[zero] + call(pos+1,1,0,0));
                     res = max(res, ar[one] + ar[zero+1] + call(pos+1,0,0,2));
                     res = max(res, ar[1] + call(pos+1,zero,one,last));
                }
            }
        }
    }

    return dp[pos][zero][one][last] = res;
}
int main()
{
    sci(n);
    cin>>str;
    for(int i=1;i<=n;i++) sci(ar[i]);

    mem(dp,-1);
    cout<<call(0,0,0,2)<<endl;
}
