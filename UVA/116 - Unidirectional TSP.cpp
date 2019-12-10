#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<ll,ll>


ll vis[15][105],path[15][105];
ll cell[15][105],dis[15][105];
struct{
    ll r,c;
}parent[15][105];

ll src_i,src_j,des_i,des_j,row,col,in;
ll dx[]={-1,0,1};
ll dy[]={1,1,1,};
ll fx[]={0,0,1};
ll fy[]={1,1,1};
ll lx[]={-1,0,0};
ll ly[]={1,1,1};

void bfs_2d(ll si,ll sj)
{
    queue<pr>q;
    fx[0]=row-1;
    lx[2] = -(row-1);

    mem(vis,0);
    mem(parent,0);
    mem(dis,0);
    dis[si][sj]=cell[si][sj];

    vis[si][sj]=1;
    q.push(pr(si,sj));
    while(!q.empty())
    {
        pr t = q.front();
        q.pop();
        ll a=t.first;
        ll b=t.second;
        for(int i=0;i<3;i++){
            ll x,y;
            if(a==0){
                x = a+fx[i];
                y = b+fy[i];
            }
            else if(a==row-1){
                x = a+lx[i];
                y = b+ly[i];
            }
            else{
                x = a+dx[i];
                y = b+dy[i];
            }

            if(y<col and vis[x][y]==0){
                dis[x][y] = dis[a][b]+cell[x][y];
                q.push(pr(x,y));
                parent[x][y].r=a;
                parent[x][y].c=b;
                vis[x][y]=1;
            }
            else if(y<col and vis[x][y]==1 and dis[x][y]>dis[a][b]+cell[x][y]){
                dis[x][y] = dis[a][b]+cell[x][y];
                q.push(pr(x,y));
                parent[x][y].r=a;
                parent[x][y].c=b;
            }
        }
    }


    ll x=INFINITY,y,a,xx=col;
    for(int i=0;i<row;i++){
        if(x>dis[i][col-1]){
            x = dis[i][col-1];
            a=i;
        }
    }
    //cout<<"max: "<<x<<endl;
    path[++in][col]=x;
    x=a;
    y=col-1;
    int z=in;
    for(int i=col-1;i>=0;i--){
        path[in][i] = x+1;
        x = parent[x][y].r;
        y = parent[x][y].c;
       // cout<<path[in][i]<<" ";
       // cout<<x<<" ";
    }
    //cout<<endl;


    //cout<<cell[des_i][des_j]<<endl;
    //return 0;
}
int main()
{
    while(~scanf("%lld %lld",&row,&col))
    {
        mem(path,0);
        in=-1;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++) scanf("%lld",&cell[i][j]);
        }
        if(row==1){
            ll m=0;
            for(int i=0;i<col;i++){
                cout<<i+1<<" ";
                m+=cell[0][i];
            }
            cout<<endl<<m<<endl;

        }
        else{
            for(int i=0;i<row;i++) bfs_2d(i,0);

            ll mx=INFINITY;
            for(int i=0;i<row;i++){
                if(mx>path[i][col]){
                    mx=path[i][col];
                }
            }
            cout<<endl;
            for(int i=0;i<row;i++){
                for(int j=0;j<=col;j++) cout<<path[i][j]<<" ";
                cout<<endl;
            }
            cout<<endl;
            string str[103];
            int sn=-1;
            for(int i=0;i<row;i++){

                if(path[i][col]==mx){
                    ++sn;
                    for(int j=0;j<col;j++){
                        string s;
                        ostringstream convert;
                        convert<<path[i][j];
                        s = convert.str();
                        str[sn]+=s;
                    }
                }

            }
            sn++;
            sort(str,str+sn);

            for(int i=0;i<col;i++) cout<<str[0][i]<<" ";
            cout<<endl<<mx<<endl;
        }
    }

return 0;
}
/*


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a=10;
    string str[101];

    int path[2][4]={{1,4,8,1},{1,2,9,1}};

    int row=2,col=4,mx=1;
    /*ostringstream convert;
    convert<<a;
    str[0]+= convert.str();
    cout<<str[0]+"99";
    int sn=-1;
    for(int i=0;i<row;i++){
        if(path[i][col-1]==mx){
            ++sn;
            for(int j=0;j<col-1;j++){
                ostringstream convert;
                convert<<path[i][j];
                str[sn] += convert.str();
            }
        }
    }
    sn++;
    sort(str,str+sn);
    cout<<str[0]<<endl<<str[1];
return 0;
}
*/
