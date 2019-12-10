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

int idx,in,parent[100001],id[100001];


struct info{
    int w,IQ,idx;
}S[100001];
struct st{
    int a,IQ,b;
}tail[100001];
bool comp(const info& p, const info& q)
{
    if(p.IQ!=q.IQ) return p.IQ>q.IQ;
        return p.w<q.w;
}

int call(int last){
    if(parent[last]!=-1)call(parent[last]);
    printf("%d\n",S[last].idx+1);
}
int bin(int lo,int hi,int key)
{
    while(hi>lo){
        int mid = (lo+hi)/2;
        if(tail[mid].a>=key) hi = mid;
        else lo = mid+1;
    }
    return hi;
}
void LIS()
{
    int len=0;
    tail[0].a = S[0].w;
    tail[0].IQ = S[0].IQ;
    tail[0].b = S[0].idx;
    parent[0] = -1;
    id[0] = 0;
    for(int i=1;i<=in;i++){
        //int pos = lower_bound(tail,tail+len,S[i])-tail;
        if(tail[0].a>S[i].w){
            tail[0].a = S[i].w;
            tail[0].b = S[i].idx;
            tail[0].IQ = S[i].IQ;
            parent[i] = -1;
            id[0] = i;
        }
        else if(tail[len].a<S[i].w && tail[len].IQ>S[i].IQ){
            tail[++len].a = S[i].w;
            tail[len].IQ = S[i].IQ;
            tail[len].b = S[i].idx;
            parent[i] = id[len-1];
            id[len] = i;

        }
        else if(tail[len].a==S[i].w || tail[len].IQ==S[i].IQ) continue;
        else{
            int ix = bin(0,len,S[i].w);
            if(tail[ix].a==S[i].w || tail[ix].IQ==S[i].IQ) continue;
            tail[ix].a = S[i].w;
            tail[ix].IQ = S[i].IQ;
            tail[ix].b = S[i].idx;
            parent[i] = id[ix-1];
            id[ix] = i;

        }
    }
    /*cout<<endl;
    for(int i=0;i<=in;i++) cout<<id[i]<<" ";
    cout<<endl;
    for(int i=0;i<=in;i++) cout<<parent[i]<<" ";*/
    cout<<len+1<<endl;
    call(id[len]);
}
int main()
{
    READ("in.txt");
    WRITE("out.txt");
    in=0;

    while(~scanf("%d%d",&S[in].w,&S[in].IQ)){
        //scanf("%d%d",&S[in].w,&S[in].IQ);
        S[in].idx = in;
        in++;
    }
    in--;
    sort(S,S+in+1,comp);
    /*cout<<endl;
    for(int i=0;i<=in;i++) cout<<S[i].w<<" "<<S[i].IQ<<" "<<S[i].idx<<endl;
    cout<<endl;*/
    LIS();

    return 0;
}
