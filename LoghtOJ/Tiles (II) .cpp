#include<bits/stdc++.h>
using namespace std;

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
#define INF 0x3f3f3f3f

llu ck(int mask,int pos);
llu pk(int mask,int pos);
llu fk(int mask,int pos);

int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};

int mark[101][900],m,n;
llu dp[100][8][(1<<8)][2];

llu call(int row,int col,int mask,int pos)
{
    int p = 0,p0=0,p1=0,p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,p8=0;
    if(row==m) return 1;

    if(col>=n) p += call(row+1,0,mask,(mask & 1<<0));

    if(dp[row][col][mask][pos] != -1) return dp[row][col][mask][pos];

    if(mark[row][col]==0) p0 += call(row,col+1,mask,fk(mask,col));//(mask & 1<<col+1)); // check obs

    if(col<n-1 && ( (mask & 1<<col) && pos==0 && !(mask & 1<<col+1) ) ){// ||
                  //(!(mask & 1<<col) && !(mask & 1<<col+1)) ) ){
        p1 += call(row,col+2,mask,0);
        if(row<m-1) p += call(row,col+2,(mask | 1<<col+1),0);
        p2 += call(row,col+2,mask,0);
    }

    if(pos==0 && col<n-1 && !(mask & 1<<col) && !(mask & 1<<col+1)){ //2
        if(mark[row][col] && mark[row][col+1]){
            p3 += call(row,col+2,mask,0);
        }
    }
    if(pos==0 && row<m-1 && !(mask & 1<<col) && mark[row][col] && mark[row+1][col]){ //1
            p4 += call(row,col+1,(mask | 1<<col),0);
    }
    if(pos==0 && row<m-1 && col<n-1){
        if(!(mask & 1<<col) && !(mask & 1<<col-1)){ //5
            if(col>0 && mark[row][col] && mark[row+1][col] && mark[row+1][col-1]){
                p5 += call(row,col+1,ck(mask,col),0);
            }
        }

        if(!(mask & 1<<col) && !(mask & 1<<col+1)){ //4
            if(mark[row][col] && mark[row][col+1] && mark[row+1][col]){
                p6 += call(row,col+2,(mask | 1<<col),0);
            }
        }
        if(!(mask & 1<<col) && !(mask & 1<<col+1)){ //6
            if(mark[row][col] && mark[row][col+1] && mark[row+1][col+1]){
                p7 += call(row,col+2,(mask | 1<<col+1),0);
            }
        }
        if(!(mask & 1<<col)){ //3
            if(mark[row][col] && mark[row+1][col] && mark[row+1][col+1]){
                p8 += call(row,col+1,pk(mask,col),0);
            }
        }
    }
    return dp[row][col][mask][pos] = p+p0+p1+p2+p3+p4+p5+p6+p7+p8;
}
llu fk(int mask,int pos)
{
    if( (mask & 1<<pos+1) ) return 1;
    else return 0;
}
llu ck(int mask,int pos)
{
    mask |= 1<<pos;
    mask |= 1<<pos-1;
    return mask;
}
llu pk(int mask,int pos)
{
    mask |= 1<<pos;
    mask |= 1<<pos+1;
    return mask;
}
int main()
{

    m = 3;
    n = 2;
    memset(mark,1,sizeof(mark));
    memset(dp,-1,sizeof(dp));
    cout<<(1<<8);
    llu res = call(0,0,0,0);
    cout<<res<<endl;

}

