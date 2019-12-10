#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 1003
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



set<string>st;

int main()
{
    string str,ch;
    cin>>str;
    int len = str.length();
    for(int i=0;i<len;i++){
        int s = i+1;
        for(int j=s+1;j<=len;j++){
            ch = str[i];
            int ss = j;
            ch += str[j-1];
            while(ss<=len){
                int tmp = ss;
                ss += s;
                s = tmp;
                if(ss<=len) ch += str[ss-1];
            }
            cout<<ch<<endl;
            st.insert(ch);
        }
    }
    cout<<st.size()<<endl;
}
/*
int n,q,r1,c,r2,c1,c2,dp[mx][mx];
short ar[mx][mx];
string ch;

int call_cnt(int i,int j)
{
    if(i>=r1 && i<=r2 && j>=c1 && j<=c2) return -1e9;
    if(i>=n || j>=n) return -1e9;
    if(i==n-1 && j==n-1) return ar[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int P = 0;

    P = max(ar[i][j] + call_cnt(i,j+1), ar[i][j] + call_cnt(i+1,j));

    return dp[i][j] = P;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ch;
        for(int j=0;j<n;j++){
            ar[i][j] = (ch[j]=='.') ? 0 : 1;
        }
    }
    //
    cin>>q;
    while(q--){
        //scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        cin>>r1>>c1>>r2>>c2;
        mem(dp,-1);
        int coin = call_cnt(0,0);
        cout<<coin<<endl;
        if(coin<=0){
            cout<<0<<" "<<0<<endl;
        }
        else{

        }
    }
}
*/
