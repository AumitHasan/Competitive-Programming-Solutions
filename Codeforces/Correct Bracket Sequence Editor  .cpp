#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 500007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int n,m,cur,pre[mx],nxt[mx],ar[mx],flag[mx],ck;
char str[mx],ch[mx];

int main()
{
    cin>>n>>m>>cur;
    cin>>str>>ch;

    nxt[0] = 1;
    for(int i=1;i<=n;i++){
        pre[i] = i-1;
        nxt[i] = i+1;
    }

    for(int i=1;i<=n;i++){
        if(str[i-1]=='(') ar[i] = 1;
        else ar[i] = -1;
    }

    for(int i=0;i<m;i++){
        if(ch[i]=='L'){
            if(pre[cur]>=1) cur = pre[cur];
            //cout<<"L: "<<cur<<endl;
        }
        else if(ch[i]=='R'){
            if(nxt[cur]<=n) cur = nxt[cur];
            //cout<<"R: "<<cur<<endl;
        }
        else{
            //cout<<"D: "<<cur<<endl;
            int p=0,ix=cur;
            if(ar[cur] == 1){
                while(1){
                    p += ar[ix];
                    if(p==false){

                        nxt[pre[cur]] = nxt[ix];
                        pre[nxt[ix]] = pre[cur];
                        break;
                    }
                    ix = nxt[ix];
                }
                if(nxt[ix]>n) cur = pre[cur];
                else cur = nxt[ix];
            }
            else if(ar[cur] == -1){
                while(1){
                    p += ar[ix];
                    if(p==false){
                        //cout<<ix<<" "<<nxt[cur]<<endl;
                        pre[nxt[cur]] = pre[ix];
                        nxt[pre[ix]] = nxt[cur];
                        break;
                    }
                    ix = pre[ix];
                }
                if(nxt[cur]>n) cur = pre[ix];
                else cur = nxt[cur];
            }
        }
    }

    cur = 0;
    while(nxt[cur]<=n){
        cur = nxt[cur];
        //if(flag[cur]) continue;
        if(ar[cur]>0) printf("(");
        else printf(")");
    }
    cout<<endl;
}
