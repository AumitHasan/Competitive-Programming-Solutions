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

int route[20007],sum[20007];
struct info{
    int i,j,val,dif;
    bool operator<(const info& a) const
    {
        if(val==a.val) return dif>a.dif;
        return val>a.val;
    }
}ar[20007];

int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T){
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d",&route[i]);
            sum[i] += sum[i-1]+route[i];
        }

        int maxEnd=0,maxVal=0,s=1,in=-1,e=1;
        for(int i=1;i<n;i++){
            maxEnd += route[i];
            if(maxEnd<0){
                maxEnd = 0;
                s = i+1;
            }
            else if(maxEnd>=maxVal){
                maxVal = maxEnd;
                e = i;
                ar[++in].i = s;
                ar[in].j = e;
                ar[in].val = maxVal;
                ar[in].dif = abs(s-e);
                //cout<<s<<" "<<e<<" "<<maxVal<<endl;
            }
        }
        if(in==-1)
            printf("Route %d has no nice parts\n",N);
        else{
            sort(ar,ar+in+1);
            printf("The nicest part of route %d is between stops %d and %d\n",N,ar[0].i,ar[0].j+1);
        }

    }
    return 0;
}
