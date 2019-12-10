#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mod 1000000007
#define base 10
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define mx 2000000

string str;
int len,three;
ll has[mx],H[mx];

void pre_has()
{
    H[0] = 1;
    for(int i=1;i<mx;i++) H[i] = (H[i-1] * base)%mod;
}
bool check(int one,int two)
{
    //cout<<one<<" "<<two<<" "<<three<<endl;
    if(one>=0 && one<two && two<three && str[one+1] == '0' && one+1==two && str[two+1] != '0'){
        ll a = has[one]%mod;
        a%=mod;
        a+=mod;
        a%=mod;
        ll b = (has[two] - (has[one]*H[two-one])%mod)%mod;
        b%=mod;
        b+=mod;
        b%=mod;
        ll c = (has[three] - (has[two]*H[three-two])%mod)%mod;
        c%=mod;
        c+=mod;
        c%=mod;
        //cout<<a<<" "<<b<<" "<<c<<endl<<endl;
        if((a%mod+b%mod)%mod == c%mod){
            return true;
        }
    }
    if(one>=0 && one<two && two<three && str[one+1] != '0' && str[two+1] != '0'){
        ll a = has[one]%mod;
        a%=mod;
        a+=mod;
        a%=mod;
        ll b = (has[two] - (has[one]*H[two-one])%mod)%mod;
        b%=mod;
        b+=mod;
        b%=mod;
        ll c = (has[three] - (has[two]*H[three-two])%mod)%mod;
        c%=mod;
        c+=mod;
        c%=mod;
        //cout<<a<<" "<<b<<" "<<c<<endl<<endl;
        if((a%mod+b%mod)%mod == c%mod){
            return true;
        }
    }
    return false;
}
void ans(int one,int two)
{
    for(int i=0;i<len;i++){
        cout<<str[i];
        if(i==one) cout<<"+";
        else if(i==two) cout<<"=";
    }
    cout<<endl;
}
int main()
{
    pre_has();

    cin>>str;
    if(str=="000"){
        cout<<"0+0=0"<<endl;
        return 0;
    }
    len = str.length();
    three = len - 1;
    bool flag = false;
    if(str[0]=='0') flag = true;
    //
    has[0] = str[0]-'0';
    for(int i=1;i<len;i++) has[i] = ((has[i-1] * base) + str[i]-'0') % mod;
    //cout<<has[70]<<endl;
    //return 0;

    for(int i=0;i<=(len/2)+1;i++){
        int ix = i+1;
        if(len - 2*ix <= ix){
            ix = len - ix;
        }
        else{
            ix = (len+ix)/2;
        }
        //
        if(check(i,ix-2)){
            ans(i,ix-2);
            return 0;
        }
        else if(check(i,ix-1)){
            ans(i,ix-1);
            return 0;
        }
        else if(check(i,ix)){
            ans(i,ix);
            return 0;
        }
        //
        if(flag) break;
    }
}

