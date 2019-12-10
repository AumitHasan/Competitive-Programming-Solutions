#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define mx 100007
#define mod 1000000009
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....
////
double angle(double cone){ return (PI * cone) / 180.0;}
//

int ar[mx];

int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T){
        int sum=0,n,L;
        cin>>n>>L;
        for(int i=0;i<L;i++){
            cin>>ar[i];
            sum += ar[i];
        }
        int rem = n - sum;
        int ans = 0;
        ar[0] += rem;
        //ans += round ((ar[0]*100) / (n*1.0) );
        for(int i=0;i<L;i++){
            int tmp = round((ar[i]*100)/(n*1.0));
            cout<<tmp<<endl;
            ans  += tmp;
        }
        cout<<ans<<endl;
    }
}
