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

#define     mx                      100007
#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....

////

int n,k,ar[2*mx];
map<int,map<int,int> > mp;

int main()
{
    int pos;
    scii(n,k);
    for(int i=0;i<n;i++){
        sci(ar[i]);
        if(ar[i]==k) pos = i;
    }

    int x,y,b=0,s=0;
    ll ans=1;

    for(int i=pos+1;i<n;i++){
        if(ar[i]>k) b++;
        else s++;

        if(b==s || b-1==s) ans++;
        //else if(s==1 && b==0) ans++;
        else if(b==1 && s==0) ans++;

        x = abs(s-max(s,b));
        y = abs(b-max(s,b));

        mp[x][y]++;
    }

    s=b=0;
    for(int i=pos-1;i>=0;i--){
        if(ar[i]>k) b++;
        else s++;

        x = abs(s-max(s,b));
        y = abs(b-max(s,b));

        if(b==s){
            ans++;
            ans += mp[0][0];
            ans += mp[1][0];
        }
        else if(b-1==s){
            ans++;
            ans += mp[0][0];
            ans += mp[0][1];
        }

        else{
            //ans += mp[y][x];

            if(x){
                ans += mp[y][x];
                ans += mp[y][x-1];
            }
            else{
                ans += mp[y][x];
                ans += mp[y+1][x];
            }
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;



}
