#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
int dN8x[]={-2,-1,1,2,2,1,-1,-2};//knight in chess
int dN8y[]={1,2,2,1,-1,-2,-2,-1};
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
//#define map map
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)

map<llu,map<int,map<int,map<int,int> > > >dp;
int mv,chess[9][9],pos[65],f=0,mk[66];
llu lim,val;

llu sett(llu mask,int p)
{
    return mask ^= 1<<p;
}
llu call(llu mask,int i,int j,int m)
{
    //cout<<mask<<" "<<i<<" "<<j<<" "<<m<<endl;
    //getchar();
    if(f==1) return 0;
    if(m>mv) return 0;
    if(mask==0){
        f=1;
        return 1;
    }
    if(dp[mask][i][j][m] != 0) return dp[mask][i][j][m];

    int P = 0;

    for(int k=0;k<8;k++){
        int x = dN8x[k] + i;
        int y = dN8y[k] + j;
        int z = x*7 + y;
        if(x>=0 && x<8 && y>=0 && y<8){
            //pos[z] = 1;
            if(pos[z]==0 && mk[z]<=1000){
                mk[z]++;
                P += call(sett(mask,z),x,y,m+1);
            }
        }
    }
    return dp[mask][i][j][m] = P;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;
    char ch;
    scanf("%d",&T);
    while(T--){
        f=0;
        dp.clear();
        mem(pos,0);
        int in=-1,si,sj;
        lim = 0;
        scanf("%d",&mv);
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>ch;
                in++;
                if(ch=='K' || ch=='p') pos[in] = 1;
                else if(ch=='P') lim |= 1<<in;
                else if(ch=='k'){
                    si = i;
                    sj = j;
                }
            }
        }

        //cout<<lim<<endl;
        llu res = call(lim,si,sj,0);
        cout<<f<<endl;
    }

}
