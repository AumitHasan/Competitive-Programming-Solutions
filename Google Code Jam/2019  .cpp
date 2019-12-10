#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

//int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; // 4 Direction
//int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1};  // 8 Direction
//int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; // Knight Direction
//int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; // Hexagonal Direction

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)          scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     MAX3(a,b,c)             max(a,max(b,c))
#define     MAX4(a,b,c,d)           max(max(a,b),max(c,d))
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
int a[mx],b[mx],dif;

int call(int i,int j)
{
    int x=0,y=0;
    while(i<=j){
        x = max(x,a[i]);
        y = max(y,b[i]);
        i++;
    }
    if(abs(x-y)<=dif) return 1;
    return 0;
}
int main()
{
    int T,N=0,ans,n;
    cin>>T;
    while(++N<=T){
        cin>>n>>dif;
        ans = 0;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans += call(i,j);
            }
        }
        printf("Case #%d: %d\n",N,ans);
    }
    return 0;
}
