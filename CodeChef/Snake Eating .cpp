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
#define M 100003

int ar[M],res[M];
struct info{
    int len,pos;
    bool operator<(const info& a) const
    {
        return len<a.len;
    }
}Q[M];
int main()
{
    int n,T,query;
    cin>>T;
    while(T--){

        cin>>n>>query;
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        sort(ar,ar+n);

        for(int i=0;i<query;i++){
            scanf("%d",&Q[i].len);
            Q[i].pos = i;
        }
        sort(Q,Q+query);
        //for(int i=0;i<query;i++) cout<<Q[i].len<<" "<<Q[i].pos<<endl;
        int in=0;
        for(int i=0;i<query;i++){

            int strt = lower_bound(ar,ar+n,Q[i].len)-ar;
            //cout<<"strt: "<<strt<<endl;
            //for(int ii=0;ii<n;ii++) cout<<ar[ii]<<endl;
            //cout<<"end"<<endl;
            if(strt>=n) break;
            int c = n-strt;
            strt--;

            for(int j=strt;j>in;j--){
                int a = Q[i].len-ar[j];
                if(in+a<=j && a){
                    //cout<<Q[i].len<<" in: "<<in<<" a: "<<a<<" j: "<<j<<endl;
                    c++;
                    ar[j] = Q[i].len;
                    in += a;
                }
                else break;
            }
            res[Q[i].pos] = c;
            //cout<<Q[i].len<<" "<<Q[i].pos<<" res: "<<c<<endl;
        }
        for(int i=0;i<query;i++){
            printf("%d\n",res[i]);
            res[i]=0;
        }
    }
    return 0;
}
