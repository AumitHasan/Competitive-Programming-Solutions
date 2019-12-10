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
#define pr pair<int,string>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 100007

int mv,ans;
string str,uni,ch,org="123456789";


void shift(int type,int flag)
{
    if(type==1){
        if(flag){swap(uni[0],uni[1]); swap(uni[1],uni[4]); swap(uni[3],uni[4]);}
        else{ swap(uni[0],uni[3]); swap(uni[1],uni[3]); swap(uni[3],uni[4]);}
    }
    else if(type==2){
        if(flag){swap(uni[1],uni[2]); swap(uni[2],uni[5]); swap(uni[4],uni[5]);}
        else{ swap(uni[1],uni[4]); swap(uni[2],uni[4]); swap(uni[4],uni[5]);}
    }
    else if(type==3){
        if(flag){swap(uni[3],uni[6]); swap(uni[3],uni[7]); swap(uni[3],uni[4]);}
        else{ swap(uni[3],uni[4]); swap(uni[3],uni[6]); swap(uni[6],uni[7]);}
    }
    else if(type==4){
        if(flag){swap(uni[4],uni[5]); swap(uni[5],uni[8]); swap(uni[7],uni[8]);}
        else{ swap(uni[4],uni[5]); swap(uni[4],uni[8]); swap(uni[4],uni[7]);}
    }
}
void bfs()
{
    set<pr>Q;
    Q.insert(pr(0,str));
    //
    int sf;
    while(!Q.empty()){
        pr nw = *Q.begin(); Q.erase(nw);
        if(nw.second == org){
            ans = min(ans,nw.first);
            return;
        }
        sf = nw.first;
        if(sf>mv) return;

        for(int i=1;i<=4;i++){
            //cout<<uni<<" ";
            uni = nw.second; shift(i,0);
            //cout<<uni<<" "<<sf+1<<endl;
            Q.insert(pr(sf+1,uni));

            //cout<<uni<<" ";
            uni = nw.second; shift(i,1);
            //cout<<uni<<" "<<sf+1<<endl;
            Q.insert(pr(sf+1,uni));
        }
    }
}
int main()
{
    int test=0;
    while(cin>>str){
        if(str=="0000000000") break;
        mv = str[0] - '0';
        str = str.substr(1,9);
        //
        cout<<++test<<". ";
        //
        if(str==org){
            cout<<0<<endl;
            continue;
        }
        //
        ans = 1e5;
        bfs();
        if(ans==1e5 || ans>mv) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}
