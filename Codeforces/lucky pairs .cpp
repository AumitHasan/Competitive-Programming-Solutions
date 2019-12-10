#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)

#define     mx                      1007
#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....

////


bool check(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='n') return 1 ;
    return 0;
}
bool check2(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ) return 1 ;
    return 0;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > a;
    int c = 0,x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    vector<int>ans;
    ans.push_back(max(a[0].first,a[0].second));
    for(int i=1;i<n;++i){
        int x = max(a[i].first,a[i].second);
        int y = min(a[i].first,a[i].second);

        if(ans[i-1]>=x) ans.push_back(x);
        else if(ans[i-1]>=y) ans.push_back(y);
        else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}
