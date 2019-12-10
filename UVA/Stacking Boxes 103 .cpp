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

int n,k,parent[32],length[32];
vector<int>path;

struct st{
    int id;
    int d[12];
}ar[32];

bool cmp (int x, int y)
{
    for ( int i = 0; i < n; i++ ){
        if (ar[x].d [i] <= ar[y].d [i])
            return false;
    }
    return true;
}
void call(int ix)
{
    if(ix == parent[ix]) return;
    call(parent[ix]);
    path.push_back(ar[parent[ix]].id);
}
int LIS()
{
    for(int i=0;i<k;i++){
        length[i] = 1;
        parent[i] = i;
    }
    for(int i=1;i<k;i++){
        for(int j=0;j<i;j++){
            if(cmp(i,j) && length[i] < length[j] + 1 ){
                length[i] = length[j] + 1;
                parent[i] = j;
            }
        }
    }
    int len=0,ix;
    for(int i=0;i<k;i++){
        if(len<length[i]){
            ix = i;
            len = length[i];
        }
    }
    call(ix);
    path.push_back(ar[ix].id);

    //cout<<len<<" "<<ix<<endl;
    return len;
}
int main()
{
    while(~scanf("%d %d",&k ,&n)){
        path.clear();
        for(int i=0;i<k;i++){
            ar[i].id = i+1;
            for(int j=0;j<n;j++) scanf("%d",&ar[i].d[j]);
            sort(ar[i].d,ar[i].d+n);
        }

        for ( int i = 0; i < k; i++ ){
            for ( int j = i + 1; j < k; j++ ){
                if ( cmp (i, j) )
                    swap (ar[i], ar[j]);
            }
        }

        cout<<LIS()<<endl;
        for(int i=0;i<path.size();i++){
            printf("%d",path[i]);
            if(i<path.size()-1) printf(" ");
        }
        cout<<endl;
    }
}
