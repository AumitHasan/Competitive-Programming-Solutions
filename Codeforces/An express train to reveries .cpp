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

bool mark[1007],ck[1007];
int cntA[1007],cntB[1007];

int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];



    for(int i=0;i<n;i++){
        cntA[a[i]]++;
        cntB[b[i]]++;
        if(a[i]==b[i]) mark[i]=1;
        if(a[i]==b[i]) ck[i]=1;

    }
    for(int i=0;i<n;i++){
        if(a[i]!=b[i] && cntA[a[i]]>1 && !mark[i]){
            //cout<<i<<" "<<cntA[a[i]]<<" "<<a[i]<<endl;
            cntA[a[i]]--;
            cntA[b[i]]++;
            mark[b[i]]=1;
            swap(a[i],b[i]);

        }
    }
    bool flag = false;
    for(int i=1;i<n;i++){
        if(cntA[i]!=1) flag = true;
    }
    if(flag==false){
        for(int i=0;i<n;i++){
            cout<<a[i];
            if(i<n-1) cout<<" ";
        }
        cout<<endl;
        return 0;
    }

    bool f = false;
    for(int i=0;i<n;i++){
        if(b[i]!=a[i] && cntB[a[i]]>1 && ck[i]==0){
            cntA[b[i]]--;
            cntA[a[i]]++;
            mark[a[i]]=1;
            swap(a[i],b[i]);

        }
    }
    for(int i=0;i<n;i++){
        if(cntB[i]!=1) f = true;
    }

    if(f==false){
        //cout<<"x"<<endl;
        for(int i=0;i<n;i++){
            cout<<b[i];
            if(i<n-1) cout<<" ";
        }
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cout<<i;
        if(i<n) cout<<" ";
    }
    cout<<endl;
}
