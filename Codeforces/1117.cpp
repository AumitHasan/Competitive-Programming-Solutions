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


struct info{
    int l,r,u,d;
}ar[2*mx];


int a,b,x,y,n;
string str;


int main()
{
    cin>>a>>b;
    cin>>x>>y;
    cin>>n;
    cin>>str;   str = str + str;

    for(int i=0;i<2*n;i++){
        if(str[i]=='L') ar[i].l++;
        if(str[i]=='R') ar[i].r++;
        if(str[i]=='D') ar[i].d++;
        if(str[i]=='U') ar[i].u++;

        if(i>0){
            ar[i].l += ar[i-1].l;
            ar[i].r += ar[i-1].r;
            ar[i].d += ar[i-1].d;
            ar[i].u += ar[i-1].u;
        }
    }

    if(x>=a && y>=b){ // ur
        int up = x - a;
        int right = y - b;

        int ur = ar[n-1].u + ar[n-1].r;
        if(ur>up){
            int c = 0;
            for(int i=0;i<n;i++){
                if(str[i]=='U' || str[i]=='R') c++;
                if(c==up) break;
            }
            mv = c;
            pos = (c + 1) % n;
        }
        else{
            int tmp = up / ur;
            mv = tmp * ur;
            tmp = up % ur;
            int c = 0;
            for(int i=0;i<n;i++){
                if(str[i]=='U' || str[i]=='R') c++;
                if(c==tmp) break;
            }
            mv += c;
            pos = (c+1) % n;
        }

    }
}
