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


#define     mx                      200007

////

string res,str,ch = "RGB";
int tmp,n,ar[mx],flag[4],dp[mx][5];


int S(int a,int b)
{
    mem(flag,0);
    flag[a] = flag[b] =  1;
    for(int i=1;i<=3;i++){
        if(flag[i]==0) return i;
    }
}
int call(int pos,int last)
{
    if(pos>=n) return 0;
    if(last != -1 && dp[pos][last] != -1) return dp[pos][last];

    int ans = 1e9,x,y,z,zz;
    x = y = 1e9;

    if(last==-1){

    }
    if(last == ar[pos]){
        if(last==1){
            x = min(x, 1 + call(pos+1,2));
            y = min(y, 1 + call(pos+1,3));
        }
        else if(last==2){
            x = min(x, 1 + call(pos+1,1));
            y = min(y, 1 + call(pos+1,3));
        }
        else if(last==3){
            x = min(x, 1 + call(pos+1,1));
            y = min(y, 1 + call(pos+1,2));
        }
    }
    else{
        x = min(x, call(pos+1,ar[pos]));
        tmp = S(last,ar[pos]);
        y = min(y, 1 + call(pos+1,tmp));
    }
    //cout<<ans<<endl;
    return dp[pos][last] = min(x,y);
}
string cnv(int a)
{
    if(a==1) return "1";
    if(a==2) return "2";
    if(a==3) return "3";
}
void print(int pos,int last)
{
    if(pos>=n){
        for(int i=0;i<res.size();i++){
            if(res[i]=='1') cout<<"R";
            if(res[i]=='2') cout<<"G";
            if(res[i]=='3') cout<<"B";
        }
        cout<<endl;
        return;
    }

    if(last == ar[pos]){
        if(last==1){
            if(dp[pos+1][2] <= dp[pos+1][3]){
                res += "2";
                print(pos+1,2);
            }
            else if(dp[pos+1][2] > dp[pos+1][3]){
                res += "3";
                print(pos+1,3);
            }
//            x = min(x, 1 + call(pos+1,2));
//            y = min(y, 1 + call(pos+1,3));
        }
        else if(last==2){
            if(dp[pos+1][1] <= dp[pos+1][3]){
                res += "1";
                print(pos+1,1);
            }
            else if(dp[pos+1][1] > dp[pos+1][3]){
                res += "3";
                print(pos+1,3);
            }
//            x = min(x, 1 + call(pos+1,1));
//            y = min(y, 1 + call(pos+1,3));
        }
        else if(last==3){
            if(dp[pos+1][1] <= dp[pos+1][2]){
                res += "1";
                print(pos+1,1);
            }
            else if(dp[pos+1][1] > dp[pos+1][2]){
                res += "2";
                print(pos+1,2);
            }
//            x = min(x, 1 + call(pos+1,1));
//            y = min(y, 1 + call(pos+1,2));
        }
    }
    else{
        tmp = S(last,ar[pos]);

        if(dp[pos+1][ar[pos]] <= dp[pos+1][tmp]){
            res += cnv(ar[pos]);
            print(pos+1,ar[pos]);
        }
        else if(dp[pos+1][ar[pos]] > dp[pos+1][tmp]){
            res += cnv(tmp);
            print(pos+1,tmp);
        }

//        x = min(x, call(pos+1,ar[pos]));
//
//        y = min(y, 1 + call(pos+1,tmp));
    }
    //cout<<ans<<endl;

}
int main()
{
    cin>>n;
    cin>>str;

    for(int i=0;i<n;i++){
        if(str[i]=='R') ar[i] = 1;
        if(str[i]=='G') ar[i] = 2;
        if(str[i]=='B') ar[i] = 3;
    }

    mem(dp,-1);
    int ans = call(0,-1);
    cout<<ans<<endl;
    res = "";
    print(0,4);
    //cout<<res<<endl;
}
