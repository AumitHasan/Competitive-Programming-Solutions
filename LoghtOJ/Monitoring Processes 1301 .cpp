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

int n;
struct info{
    int s,t;
    bool operator<(const info& a) const
    {
        if(s==a.s) return t<a.t;
        return s<a.s;
    }
}ar[50003];

int possible(int pro)
{
    int k=0,e=ar[0].t;
    for(int i=1;i<n;i++){
        if(ar[i].s<=e) k++;
        else e = ar[i].t;
    }
    if(k<=pro) return 1;
    return 0;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d%d",&ar[i].s,&ar[i].t);
        sort(ar,ar+n);
        for(int i=0;i<n;i++){
            cout<<"   "<<ar[i].s<<" "<<ar[i].t<<endl;
        }
        int ix=-1,in=n-1,e=-1,k=0;
        while(1){
            int c=0;
            e=-1,ix=-1;
            cout<<in<<endl;
            for(int i=0;i<=in;i++){
                if(e<=ar[i].s){
                    ar[++ix].s=ar[i].s;
                    ar[ix].t=ar[i].t;
                }
                else{
                    c++;
                    e=ar[i].t;
                }
            }
            if(in==ix && in==0) break;
            in=ix;
            k++;

        }


        int res = k;
        printf("Case %d: %d\n",N,res);
    }
    return 0;
}
