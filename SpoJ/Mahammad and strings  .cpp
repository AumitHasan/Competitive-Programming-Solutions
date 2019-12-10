#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 200007
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

llu H,has[mx],str[mx];
int res[200007];
string ch;

struct info{
    llu qstr;
    int pos;
    bool operator<(const info& sr) const
    {
        return qstr < sr.qstr;
    }
}query[200007];


void pre_has()
{
    has[0] = 1;
    for(int i=1;i<mx;i++) has[i] = has[i-1] * base;
}
int main()
{
    //IO;

    int n,q,last=0;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        cin>>ch;
        H = 0;
        for(int j=0;j<ch.length();j++) H = (H*base) + ch[j];
        str[i] = H;
    }
    sort(str,str+n);

    for(int i=0;i<q;i++){
        cin>>ch;
        H = 0;
        for(int j=0;j<ch.length();j++) H = (H*base) + ch[j];

        query[i].qstr = H;
        query[i].pos = i;
    }
    sort(query,query+q);
    //
    for(int i=0;i<q;i++){

        llu val = query[i].qstr;

        if(last>=n){
            res[query[i].pos] = last;
            last = n;
        }
        else{
            if(val>=str[n-1]){
                res[query[i].pos] = n;
                last = n;
            }
            else if(val<str[0]){
                res[query[i].pos] = 0;
            }
            else{
                llu ans=0,lo=last,hi=n-1;
                //cout<<lo<<" "<<hi<<endl;
                while(lo<=hi){
                    int mid = (lo+hi) / 2;

                    if(str[mid]<=val){
                        ans = mid;
                        lo = mid+1;
                    }
                    else hi = mid-1;
                }
                //cout<<"ans: "<<ans<<endl<<endl;;
                last = ans;
                res[query[i].pos] = last+1;
            }

        }
    }
    for(int i=0;i<q;i++) cout<<res[i]<<endl;
    for(int i=0;i<4;i++) cout<<str[i]<<" "<<query[i].qstr<<endl;

    return 0;
}
