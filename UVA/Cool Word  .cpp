#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
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

int alp[30];
set<int>st;
string str;

int main()
{
    int T,N=0,n;

    while(~scanf("%d",&n)){

        int c=0,sz;

        while(n--){
            cin>>str;
            mem(alp,0);
            st.clear();
            sz=0;

            for(int i=0;i<str.length();i++){
                alp[str[i]-'a']++;
            }
            for(int i=0;i<26;i++){
                if(alp[i]>0){
                    st.insert(alp[i]);
                    sz++;
                }
            }
            if(sz>1 && st.size()==sz) c++;
        }

        printf("Case %d: %d\n",++N,c);
    }
    return 0;
}
