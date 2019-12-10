#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

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
#define pii acos(-1.0)

#define mx 100007

stack<char>st;

void solve()
{
    string str,sign;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]>='a' && str[i]<='z') cout<<str[i];
        else if(str[i]==')'){
            sign="";
            while(1){
                if(st.top()=='('){
                    st.pop(); break;
                }
                sign += st.top(); st.pop();
            }
            reverse(sign.begin(),sign.end());
            cout<<sign;
        }
        else st.push(str[i]);
    }
    cout<<endl;
}
int main()
{
    IO;

    int T;
    cin>>T;
    while(T--){
        while(!st.empty()) st.pop();
        solve();
    }
    return 0;
}

