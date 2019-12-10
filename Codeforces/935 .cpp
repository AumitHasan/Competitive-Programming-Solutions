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
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi acos(-1.0)
#define sq(a) a*a
#define mx 100007

double ans,ux,uy,cx,cy,fx,fy,R,r,a,b,x,y,tx,ty;

double getd(double d)
{
    return (d*pi) / 180.00;
}
void solve()
{
    tx = (a+x) / 2.0;
    ty = (b+y) / 2.0;
    double tr = sq(fabs(a-tx)) + sq(fabs(b-ty));
    tr = sqrt(tr);
    double tmp = sq(fabs(fx-tx)) + sq(fabs(fy-ty));
    tmp = sqrt(tmp);
    if(tr >= tmp) return;

    if(tr > ans){
        ans = tr;
        ux = tx; uy = ty;
    }
}
int main()
{
    r = .0001;
    cin>>R>>cx>>cy>>fx>>fy;
    for(double i=0.0;i<=360.0;i+=.1){
        a = R * cos(getd(i)) + cx;
        b = R * sin(getd(i)) + cy;
        for(double j=0.0;j<=360.0;j+=.1){
            x = r * cos(getd(j)) + fx;
            y = r * sin(getd(j)) + fy;
            solve();
        }
        //cout<<vec.size()<<endl;
    }
    printf("%.16f %.16f %.16f\n",ux,uy,ans);
}

