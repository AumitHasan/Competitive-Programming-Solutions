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
#define mx 107

int ck[mx][mx],ar[mx][mx],n,m,row[mx],col[mx];
vector<int>a,b;

bool rw()
{
    int c;
    for(int i=1;i<=n;i++){

        c=100000;
        for(int j=1;j<=m;j++) c = min(c,ar[i][j]);

        for(int j=1;j<=m;j++) ar[i][j] -= c;
        for(int k=0;k<c;k++) a.push_back(i);
    }
}
bool cl()
{
    int c;
    for(int i=1;i<=m;i++){
        c = 100000;
        for(int j=1;j<=n;j++) c = min(c,ar[j][i]);
        for(int j=1;j<=n;j++) ar[j][i] -= c;

        for(int k=0;k<c;k++) b.push_back(i);

    }
}
int main()
{
    mem(ar,0);
    mem(ck,0);

    cin>>n>>m;
    bool flag = false;
    if(n<=m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&ck[i][j]);
                ar[i][j]=ck[i][j];
            }
        }
    }
    else{
        flag=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&ck[j][i]);
                ar[j][i]=ck[j][i];
            }
        }
        swap(n,m);
    }

    rw();
    cl();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //cout<<ar[i][j]<<" ";
            if(ar[i][j]!=0){
                cout<<-1<<endl;
                return 0;
            }
        }
    }

    cout<<a.size()+b.size()<<endl;
    if(flag){
        for(int i=0;i<a.size();i++)printf("col %d\n",a[i]);
        for(int i=0;i<b.size();i++) printf("row %d\n",b[i]);
    }
    else{
        for(int i=0;i<a.size();i++)printf("row %d\n",a[i]);
        for(int i=0;i<b.size();i++) printf("col %d\n",b[i]);
    }

    return 0;
}
