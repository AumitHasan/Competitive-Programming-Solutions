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

llu x,w,m,k,n,ar[20];
llu num,ans,cost;

int main()
{
    ar[1] = 1;
    for(int i=2;i<=19;i++){
        ar[i] = ar[i-1] * 10;
        //cout<<ar[i]<<endl;
    }

    cin>>w>>m>>k;
    int ix;
    for(int i=2;i<=18;i++){
        if(m<ar[i]){
            x = ar[i] - m;
            num = w / ((i-1)*k);
            cost = (i-1)*k;
            if(num > x){
                ans += x;
                //cout<<num<<endl;
                w = (num-x)*cost + (w%cost);
            }
            else{
                ans += num;
                cout<<ans<<endl;
                return 0;
            }
            //cout<<ans<<" "<<w<<endl;
            //
            for(int j=i;j<18;j++){
                x = ar[j+1] -  ar[j];
                cost = j * k;
                num = w / cost;

                if(num>x){
                    ans += x;
                    w = ((num-x) * cost) + (w%cost);
                }
                else{
                    ans += num;
                    cout<<ans<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<ans<<endl;
}
