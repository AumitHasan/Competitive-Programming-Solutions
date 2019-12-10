#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int main()
{
    int n,ar[1007],flag=0;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
        if(ar[i]==1) flag = 1;
    }
    //
    if(n==1){
        cout<<2<<endl;
        cout<<ar[0]<<" "<<ar[0]<<endl;
        return 0;
    }
    //
    int x = ar[0];
    for(int i=1;i<n;i++) x = __gcd(x,ar[i]);

    if(x != ar[0]){
        cout<<-1<<endl;
        return 0;
    }

    vector<int>v;
    v.push_back(x);
    for(int i=0;i<n;i++){
        v.push_back(x);
        v.push_back(ar[i]);
    }

    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        printf("%d",v[i]);
        if(i==v.size()-1) cout<<endl;
        else printf(" ");
    }
}
