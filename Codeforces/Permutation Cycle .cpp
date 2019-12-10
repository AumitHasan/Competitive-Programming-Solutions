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
#define pii acos(-1.0)

#define mx 1000007

int a,b,n,ans[mx];

int main()
{
    cin>>n>>a>>b;
    if(a>b) swap(a,b);
    //
    if(a==1 || b==1){
        for(int i=1;i<=n;i++){
            cout<<i;
            if(i<n) cout<<" ";
            else cout<<endl;
        }
        return 0;
    }
    else if(n%a == 0){
        for(int i=1;i<=n/a;i++){
            int lo = ((i-1) * a) + 1;
            int hi = i * a;
            for(int j=lo;j<hi;j++) ans[j] = j + 1;
            ans[hi] = lo;
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i];
            if(i<n) cout<<" ";
            else cout<<endl;
        }
        return 0;
    }
    else if(n%b == 0){
        for(int i=1;i<=n/b;i++){
            int lo = ((i-1) * b) + 1;
            int hi = i * b;
            for(int j=lo;j<hi;j++) ans[j] = j + 1;
            ans[hi] = lo;
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i];
            if(i<n) cout<<" ";
            else cout<<endl;
        }
        return 0;
    }
    else{
        //cout<<"d"<<endl;
        int x,y;
        for(int i=1;i<=(n/a);i++){
            x = (i*a);
            y = n - x;
            if(x && y && y%b==0){
                //cout<<i<<" "<<y/b<<endl;
                //
                for(int j=1;j<=i;j++){
                    int lo = ((j-1) * a) + 1;
                    int hi = j * a;
                    //cout<<lo<<" "<<hi<<endl;
                    for(int k=lo;k<hi;k++) ans[k] = k + 1;
                    ans[hi] = lo;
                }
                //
                for(int j=1;j<=(y/b);j++){
                    int lo = (i*a) + ((j-1) * b) + 1;
                    int hi = (i*a) + (j * b);
                    //cout<<lo<<" "<<hi<<endl;
                    for(int k=lo;k<hi;k++) ans[k] = k + 1;
                    ans[hi] = lo;
                }
                // prnt
                for(int ii=1;ii<=n;ii++){
                    cout<<ans[ii];
                    if(ii<n) cout<<" ";
                    else cout<<endl;
                }
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}

