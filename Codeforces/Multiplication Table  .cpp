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

int k;
vector<int>v[100];

int cnv(int num)
{
    vector<int>x;
    while(num>0){
        x.push_back(num%k);
        num /= k;
    }
    num = 0;
    for(int i=x.size()-1;i>=0;i--) num = (num*10) + x[i];

    return num;
}
void pre()
{
    for(int i=1;i<10;i++){
        int val = 0;
        for(int j=1;j<10;j++){
            val += i;
            v[i].push_back(val);
        }
    }
}
int main()
{
    pre();
    //
    scanf("%d",&k);

    for(int i=1;i<k;i++){
        for(int j=0;j<k-1;j++){
            if(j>0) printf(" %2d",cnv(v[i][j]));
            else printf("%d",v[i][j]);
        }
        printf("\n");
    }
}
