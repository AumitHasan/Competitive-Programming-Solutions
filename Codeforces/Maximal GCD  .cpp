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

vector<ll>v,ans;

int main()
{
    ll sum=0,n,k;
    cin>>n>>k;
    for(int i=1;;i++){
        if(sum+i<=n){
            v.push_back(i);
            sum += i;
        }
        else{
            ll tmp = n-sum;
            v[v.size()-1] += tmp;
            break;
        }
    }
    //for(int i=0;i<v.size();i++) cout<<v[i]<<endl;

    if(v.size()>=k){
        sum = 0;
        for(int i=0;i<v.size();i++){
            if(i<k-1){
                ans.push_back(v[i]);
            }
            else sum += v[i];
        }
        if(sum>0) ans.push_back(sum);
        //
        for(int i=0;i<ans.size();i++){
            printf("%lld",ans[i]);
            if(i<ans.size()-1) printf(" ");
            else printf("\n");
        }
    }
    else{
        cout<<-1<<endl;
    }

    return 0;
}
