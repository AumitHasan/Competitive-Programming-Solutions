#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
#define mem(a,b) memset(a,b,sizeof(a))
void xx(int i);

map<string,int>mp;
vector<int>edg[mx];
int p[mx],vis[mx],rt[mx];
string str[mx];
queue<int>q;
int j,c,sp=0,n,src,des,cc=0;
string aa,bb;


void vbfs(int s,int d)
{
    mem(vis,0);
    mem(p,0);
    while(!q.empty()){
        q.pop();
    }

    p[s] = s;
    q.push(s);
    vis[s] = 1;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i=0;i<edg[f].size();i++){
            int in = edg[f][i];
            if(vis[in]==0){
                p[in] = f;
                vis[in]=1;
                q.push(in);
            }
        }
    }


    if(n==1 and src==des){
        if(src>0) cout<<aa<<" "<<bb<<endl;
        else if(src==0) printf("No route\n");
    }
    else if(p[d]==0){
        printf("No route\n");
    }
    else{

        mem(rt,0);
        rt[0]=0;
        j=c=0;
        xx(d);

        for(int i=c;i>1;i--){
            cout<<str[rt[i]]<<" "<<str[rt[i-1]]<<endl;
        }

    }
}
void xx(int i) // for path
{
    c++;
    rt[++j]=i;
    if(p[i]==i) return ;
    xx(p[i]);
}
int main()
{
    while(~scanf("%d",&n))
    {
        mem(edg,0);
        mp.clear();
        //mem(str,'\0');

        int i=0;
        str[0]="s";
        for(int j=0;j<n;j++)
        {
            string a,b;
            cin>>a>>b;
            int x=0,y=0;

            if(mp[a]==0) x=0;
            else x = mp[a];
            if(mp[b]==0) y=0;
            else y = mp[b];

            if(a==b){
                if(x==0 and y==0){ str[++i]=a; mp[a]=i;}
            }
            else if(x==0 and y==0){
                str[++i]=a;
                mp[a]=i;
                int si=i;
                str[++i]=b;
                mp[b]=i;
                int sj=i;
                edg[si].push_back(sj);
                edg[sj].push_back(si);
            }
            else if(x>0 and y>0 and x!=y){
                edg[x].push_back(y);
                edg[y].push_back(x);
            }
            else if(x==0){
                str[++i]=a;
                mp[a]=i;
                edg[i].push_back(y);
                edg[y].push_back(i);
            }
            else if(y==0){
                str[++i]=b;
                mp[b]=i;
                edg[i].push_back(x);
                edg[x].push_back(i);
            }
        }

        cin>>aa>>bb;

        ++cc;
        if(cc>1) cout<<endl;

        src = mp[aa];
        des = mp[bb];
        if(mp[bb]==0){
            printf("No route\n");
            continue;
        }
        vbfs(src,des);
    }

return 0;
}


