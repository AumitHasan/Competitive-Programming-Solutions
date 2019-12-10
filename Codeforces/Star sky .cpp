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

int ar[101][101][11];
int ck[101][101][11];

int main()
{
    int row,col,a,b,x,y,n,q,mod,d,t,c;

    cin>>n>>q>>mod;

    for(int i=0;i<n;i++){
        scanf("%d %d %d",&col,&row,&x);
        ar[row][col][0] += x;
        //cout<<row<<" "<<col<<" "<<x<<endl;
        for(int j=1;j<=10;j++){
            ar[row][col][j] += (x+j) % (mod+1);
            //cout<<row<<" "<<col<<" "<<j<<" "<<ar[row][col][j]<<endl;
        }
    }

    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            for(int k=0;k<=10;k++){
                ck[i][j][k] = ar[i][j][k] + ck[i][j-1][k];
            }
        }
    }


    while(q--){
        ll times=0,v=0;
        scanf("%d %d %d %d %d",&t,&a,&b,&c,&d);

        int M = t % (mod+1);
        //cout<<M<<endl;


        if(a>c) swap(a,c);
        if(b>d) swap(b,d);

        for(int i=a;i<=c;i++){
            v += ck[i][d][M] - ck[i][b-1][M];
        }
        cout<<v<<endl;
    }
    return 0;
}
