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


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      100007

////




int main()
{
    int n,k;
    scii(n,k);
    int range = 2*k + 1;


    for(int i=1;i<=k+1;i++){
        vector<int>v;
        v.push_back(i);
        int c = i;
        while(c+range<=n){
            c += range;
            v.push_back(c);
        }
        int tmp = v[v.size()-1];
        if(tmp + k >= n){
            cout<<v.size()<<endl;
            for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
            return 0;
        }
    }
}
