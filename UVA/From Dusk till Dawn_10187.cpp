#include<bits/stdc++.h>
using namespace std;
#define mx 107
#define pr pair<int,int>
#define clr(a) memset(a,0,sizeof(a))

string s,str;
struct xx{

    int to,x,y;

};
map<string,int>mp;
vector<xx>path[mx];

int cal(int p,int ar,int lft)
{
    int val=0;
    if(p<=ar) return 0;
    else return 1;
}
void dijkastra(int src,int des)
{
    queue<pr>Q;
    xx st;
    st.to = src;
    st.x = st.y = 0;
    Q.push(pr(src,1000));

    while(!Q.empty()){
        xx prev = Q.front();
        Q.pop();

        for(int i=0;path[prev.to].size();i++){
            xx now = path[prev.to][i];
            int val = cal(prev.y,now.x,now.y);
            if(city[now.to] > city[prev.to]+val){
                city[now.to] = city[prev.to]+val
            }
        }
    }

}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){

        mp.clear();
        //clr(path);

        int route,a,b,in=0;
        scanf("%d",&route);

        for(int i=0;i<route;i++){
            cin>>s>>str;
            scanf("%d %d",&a ,&b);

            if(mp[s] == 0) mp[s] = ++in;
            if(mp[str] == 0) mp[str] = ++in;

            xx st;
            if((a>=18 and a+b<=30)){
                st.to = mp[str];
                st.x = a;
                st.y = a+b;
                path[mp[s]].push_back(st);
            }
            if(a<=6 and a+b<=6){
                st.to = mp[str];
                st.x = a+24;
                st.y = a+b+24;
                path[mp[s]].push_back(st);
            }

        }

        string src,des;
        cin>>src>>des;

        if(mp[src]==0 or mp[des]==0){
            printf("There is no route Vladimir can take.\n");
            continue;
        }

        dijkastra(mp[src],mp[des]);

    }
    return 0;
}
