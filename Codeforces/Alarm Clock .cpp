#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
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

vector<int>v;
int ar[2*mx];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<n;i++) scanf("%d",&ar[i]);
    sort(ar,ar+n);

    if(n==1 && k==1){
        cout<<1<<endl;
        return 0;
    }

    int c=1,last = ar[n-1] - m;
    //cout<<last<<endl;
    if(c<k) v.push_back(ar[n-1]);

    for(int i=n-2;i>=0;i--){
        if(ar[i]>last){
            c++;
            if(c<k) v.push_back(ar[i]);
        }
        else{
            c=1;
            last = ar[i] - m;
            if(c<k) v.push_back(ar[i]);
        }
    }
    int x = n - v.size();
    v.clear();

    c=1,last = ar[0] + m;
    //cout<<last<<endl;
    if(c<k) v.push_back(ar[0]);

    for(int i=1;i<n;i++){
        if(ar[i]<last){
            c++;
            if(c<k) v.push_back(ar[i]);
        }
        else{
            c=1;
            last = ar[i] + m;
            if(c<k) v.push_back(ar[i]);
        }
    }
    int y = n - v.size();

    //cout<<x<<" "<<y<<endl;
    cout<<min(x,y)<<endl;


}
