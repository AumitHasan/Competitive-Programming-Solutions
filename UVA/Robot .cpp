#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
#define ll long long int
#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 1007
#define int_map map<int,int>
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)

int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int pos[4][2]=
{
    {3,1}, {0,2}, {1,3}, {2,0}
};


int M,q,ar[1007][1007],mv,dir,P,a,b;

int main()
{
    string str;
    while(~scanf("%d%d",&M,&q)){
        a=b=0;
        bool flag = true;

        P=0;
        while(q--){
            cin>>str;
            if(str=="MOVE"){
                scanf("%d",&mv);
                a += dx[P]*mv;
                b += dy[P]*mv;
                //cout<<a<<" "<<b<<" "<<P<<" "<<mv<<endl;
                if(a<0 || a>M || b<0 || b>M) flag = false;
            }
            else{
                scanf("%d",&dir);
                //cout<<P<<" "<<dir<<endl;
                //if(dir==1) dir=0;
                //else dir=1;
                P = pos[P][dir];
                //cout<<P<<endl;
            }
        }
        if(flag){
            swap(a,b);
            cout<<a<<" "<<b<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}
