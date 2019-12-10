#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define base 1000007
#define ll unsigned long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<ll,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

ll H[100],n,m,qs,ans;
string str,aski="abcde";
unordered_map<ll,int>mp,tmp;
vector<pr>v,pos;

void pre_base()
{
    H[0] = 1;
    for(int i=1;i<100;i++) H[i] = H[i-1] * base;
}
void ck(int a,int b,int c)
{
    //cout<<"ix: "<<a<<" "<<b<<" "<<c<<endl;
    int cnt=0,ln = v.size();
    ll h = 0;

    if(v[0].second == -1){
        if(a>-1){
            h = aski[a];
        }
        cnt++;
    }
    else h = v[0].first;

    for(int i=1;i<ln;i++){
        if(v[i].second > -1) h = (h * H[v[i].second]) + v[i].first;
        else{
            cnt++;
            if(cnt==1){
                if(a > -1) h = (h * base) + aski[a];
            }
            else if(cnt==2){
                if(b > -1) h = (h * base) + aski[b];
            }
            else if(cnt==3){ // 3
                if(c > -1) h = (h * base) + aski[c];
            }
        }
    }
    //cout<<h<<endl<<endl;;
    if(mp[h] && !tmp[h]){
        tmp[h] = 1;
        ans += mp[h];
        //cout<<h<<endl<<endl;
    }
    return;
}
void call()
{
    tmp.clear();

    ck(-1,-1,-1);
    for(int i=0;i<5;i++){
        ck(i,-1,-1);
        //
        if(qs==1) continue;
        for(int j=0;j<5;j++){
            ck(-1,j,-1);
            ck(i,j,-1);
            //
            if(qs==2) continue;
            for(int k=0;k<5;k++){
                ck(-1,-1,k);
                ck(-1,j,k);
                ck(i,-1,k);
                ck(i,j,k);
            }
        }
    }
}
int main()
{
    IO;

    pre_base();
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>str;
        ll h = str[0],len = str.length();
        for(int j=1;j<len;j++) h = (h*base) + str[j];
        mp[h]++;
        //cout<<h<<endl;
    }
    //cout<<endl;
    while(m--){
        ans = 0;
        v.clear();
        cin>>str;
        ll h=0,len = str.length();
        int in=0,c=0;
        for(int i=0;i<len;i++){
            if(str[i]=='?'){
                c++;
                if(h>0) v.push_back(pr(h,in));
                v.push_back(pr(0,-1));
                h=0;
                in=0;
                continue;
            }
            in++;
            h = (h*base) + str[i];
        }
        if(h>0) v.push_back(pr(h,in));
        //
//        for(int i=0;i<v.size();i++){
//            cout<<v[i].first<<" "<<v[i].second<<endl;
//        }
        qs = c;
        //cout<<qs<<endl;
        call();
        cout<<ans<<endl;
    }
//    if(qs==2) ans = (ans==0) ? 0 : ans-5;
//    if(qs==3) ans = (ans==0) ? 0 : ans-10;
//    if(ans<0) ans = 0;

}
