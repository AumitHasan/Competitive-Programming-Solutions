#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 200007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

char str[mx],ch[mx],tmp,tstr[mx];
llu ha[mx],hb,x[mx],y,H[mx],a[mx],b[mx],ta[mx];

void pre_has()
{
    H[0] = 1;
    for(int i=1;i<mx;i++) H[i] = H[i-1] * base;
}
int main()
{
    IO;
    pre_has();
    llu n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        //scanf("%lld-%c", &a[i],&str[i]);
        cin>>ta[i]>>tmp>>tstr[i];
    }
    int in=0;
    str[0] = tstr[0];
    a[0] = ta[0];
    for(int i=1;i<n;i++){
        if(str[in]==tstr[i]){
            a[in] += ta[i];
        }
        else{
            a[++in] = ta[i];
            str[in] = tstr[i];
        }
    }
    n = in+1;
    //--
    ha[0] = str[0];
    for(int i=1;i<n;i++) ha[i] = (ha[i-1] * base) + str[i];
    x[0] = a[0];
    for(int i=1;i<n;i++) x[i] = (x[i-1] * base) + a[i];
    //
    for(int i=0;i<m;i++){
        //scanf("%lld-%c", &b[i],&ch[i]);
        cin>>ta[i]>>tmp>>tstr[i];
    }
    in = 0;
    ch[0] = tstr[0];
    b[0] = ta[0];
    for(int i=1;i<m;i++){
        if(ch[in]==tstr[i]){
            b[in] += ta[i];
        }
        else{
            b[++in] = ta[i];
            ch[in] = tstr[i];
        }
    }
    m = in+1;
    //--
    hb = ch[0];
    for(int i=1;i<m;i++) hb = (hb * base) + ch[i];
    for(int i=1;i<m-1;i++) y = (y * base) + b[i];

    //
    if(n<m){
        cout<<0<<endl;
        return 0;
    }
    //
    llu ans=0,ck,e,f;
    if(m==1){
        for(int i=0;i<n;i++){
            if(ch[0]==str[i] && a[i]>=b[0]){
                ans += a[i] - b[0] + 1;
            }
        }
    }
    else{
        for(int i=0;i<=n-m;i++){
            ck = i>0 ? ha[i+m-1] - (ha[i-1] * H[m]) : ha[i+m-1];
//            if(i==0){
//                cout<<ck<<" "<<hb<<endl;
//                cout<<a[i]<<" "<<a[i+m-1]<<endl;
//                cout<<b[0]<<" "<<b[m-1]<<endl;
//            }
            if(ck==hb && a[i]>=b[0] && a[i+m-1]>=b[m-1]){
                //cout<<"F"<<endl;
                int ix = i+1,iy = i+m-2;
//                cout<<ix<<" "<<iy<<endl;
//                cout<<x[iy] - (x[ix-1]*base)<<endl;
//                cout<<y[iy] - (y[ix-1]*base)<<endl;
                if(ix<=iy){
                    e = ix>0 ? x[iy] - (x[ix-1] * H[iy-ix+1]) : x[iy];
                    if(e==y) ans++;
                }
                else ans++;
            }
            //cout<<"a: "<<i<<" "<<ans<<endl;
        }
    }
    cout<<ans<<endl;

    return 0;
}
