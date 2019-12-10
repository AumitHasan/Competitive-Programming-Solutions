#include<stdio.h>
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
#define scii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
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




int main()
{
    int h1,a1,c,h2,a2;
    vector<string>v;

    cin>>h1>>a1>>c;
    cin>>h2>>a2;

    while(h2>0){
        if(h1 <= a2 && h2>a1){
            v.push_back("HEAL");
            h1 += c;
            h1 -= a2;
        }
        else{
            v.push_back("STRIKE");
            h2 -= a1;
            h1 -= a2;
        }
    }

    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<endl;

    return 0;
}
