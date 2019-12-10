#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

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
#define pii acos(-1.0)

#define mx 1007


int main()
{
    int n,f=0,z=0,tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp==5) f++;
        else z++;
    }
    //cout<<f<<" "<<z<<endl;
    int num = 0,five=0;
    for(int i=1;i<=f;i++){
        num = (num*10) + 5;
        num %= 90;
        if(num==0 || (z && (num*10)%90==0)){
            five = max(i,five);
        }
    }
    if(!five && !z) cout<<-1<<endl;
    else if(!five) cout<<0<<endl;
    else{
        for(int i=1;i<=five;i++) cout<<5;
        for(int i=1;i<=z;i++) cout<<0;
        cout<<endl;
    }
}
