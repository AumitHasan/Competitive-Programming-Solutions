#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

llu yello,pink,white,tmp,ans = 0,a,b,c,sum;
int n,x[mx],y[mx];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=n;i++) scanf("%d",&y[i]);

    for(int i=1;i<=n;i+=3) sum += x[i];
    a = sum;
    //
    sum=0;
    for(int i=2;i<=n;i+=3) sum += x[i];
    b = sum;
    //
    sum=0;
    for(int i=3;i<=n;i+=3) sum += x[i];
    c = sum;
    //
    for(int i=1;i<=n;i++){
        if(i%3==0){
            pink += y[i] * a;
            white += y[i] * b;
            yello += y[i] * c;
        }
        else if(i%3==1){
            white += y[i] * a;
            yello += y[i] * b;
            pink += y[i] * c;
        }
        else{
            yello += y[i] * a;
            pink += y[i] * b;
            white += y[i] * c;
        }
    }
    cout<<yello<<" "<<pink<<" "<<white<<endl;
}
