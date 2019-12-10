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

vector<int>v;

int add(int n)
{
    int sum=0;
    while(n>0){
        sum += n%10;
        n/=10;
    }
    return sum;
}
int main()
{
    int n,val;
    cin>>n;

    int last = (n-10000)<0 ? 0 : (n-10000);

    for(int i=n;i>=last;i--){
        val = add(i) + i;
        if(val==n) v.push_back(i);
    }
    if(v.size()==0) cout<<0<<endl;
    else{
        cout<<v.size()<<endl;
        sort(v.begin(),v.end());
        int len = v.size();
        for(int i=0;i<len;i++){
            printf("%d\n",v[i]);
        }
    }
    return 0;
}
