#include<bits/stdc++.h>
using namespace std;
#define mx 257

int used[mx],path[mx],n,c,found,check[2][mx];
vector<int>v[mx];
set<int>st;
char s[6];

void backtrack(int last,int in)
{
    if(found) return;

    if(in==n+1){

        for(int j=1;j<=n;j++){
            st.insert(path[j]);
        }
        if(check[1][path[n]] and st.size()==n){
            for(int j=1;j<=n;j++) printf("%d ",path[j]);
            printf("1\n");
            found = 1;
        }
        st.clear();
        return;
    }

    for(int i=0;i<v[last].size();i++){

        if(!used[v[last][i]]){
            used[v[last][i]] = 1;
            path[in] = v[last][i];

            backtrack(v[last][i],in+1);

            used[v[last][i]] = 0;
        }
    }
}
int main()
{
    int u,vv;
    while(~scanf("%d",&n)){

        found=0;
        memset(v,0,sizeof(v));
        while(1){

            scanf("%s",s);
            if(s[0]=='%') break;
            scanf("%d",&vv);

            u=0;
            for(int i=0;i<strlen(s);i++){
                u = (u*10)+(s[i]-48);
            }
            v[u].push_back(vv);
            v[vv].push_back(u);
            if(u==1) check[u][vv] = 1;
            else if(vv=1)check[vv][u] = 1;
        }

        path[1] = 1;
        backtrack(1,2);
        if(!found) printf("N\n");
        memset(v,0,sizeof(v));
    }
    return 0;
}
