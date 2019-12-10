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
#define     pb                      push_back


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define mx 400007


////

vector<int>res;


int main()
{
    bool flag = false;
    int zero,one,two,three;
    cin>>zero>>one>>two>>three;

    if(!zero && one && two && three){

    }
    else if(!zero && !one && two && three){

        if(abs(three-two) <= 1 ){
            if(three > two) res.pb(3);
            for(int i=0;i<min(one,two);i++){ res.pb(2); res.pb(3);}
            if(two > three) res.pb(2);
        }
        else flag = true;
    }
    else if(!zero && one && two && !three){

        if(abs(one-two) <= 1 ){
            if(one < two) res.pb(2);
            for(int i=0;i<min(one,two);i++){ res.pb(1); res.pb(2);}
            if(one> two) res.pb(1);

        }
        else flag = true;
    }
    else{

    }

}
