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

int n;
string str[mx];
map<int,int>pt;
map<string,int>mp,ck;
set<string>st,S;

int main()
{
    IO;



    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str[i];
        //st.insert(str[i]);
    }

    string ch,tmp;
    int sz;
    for(int ii=0;ii<n;ii++){
        ch = str[ii];
        S.insert(ch);
        tmp = "";
        for(int i=0;i<ch.size();i++){
            if(tmp.size()==0) tmp += ch[i];
            else{
                sz = tmp.size() - 1;
                if(tmp[sz] == '(' && ch[i] == ')'){
                    tmp.pop_back();
                }
                else tmp += ch[i];
            }
        }
        int l=0,r=0;
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]=='(') l++;
            else r++;
        }
        if(!l && !r){
            st.insert(ch);
            mp[ch] = 0;
            pt[0]++;
        }
        else if(l && !r){
            mp[ch] = l;
            pt[l]++;
        }
        else if(!l && r){
            mp[ch] = -r;
            pt[-r]++;
        }
        else{
            ck[ch] = 1;
        }
        cout<<ch<<" "<<mp[ch]<<endl;
    }

    ll a=0,ans = 0;
    int x,y;
    sz = st.size() - 1;
    while(S.size()){
        ch = *S.begin(); S.erase(S.begin());

        if(ck[ch]==0){
            x = mp[ch];
            if(x==0){
                a += sz;
            }
            else{
                if(x<0){
                    ans += pt[-1*x];
                }
                else if(x>0){
                    ans += pt[-x];
                }
            }
            cout<<ch<<" "<<x<<" "<<ans<<endl;
        }
    }


    if(ans) ans /= 2;
    cout<<a<<" "<<ans<<endl;
    ans += a;
    cout<<ans<<endl;
}
