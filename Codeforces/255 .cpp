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

#define mx 100007

int main()
{
    int i,g,m,p[100],sum=0,count=1;
    scanf("%d%d",&g,&m);
    for(i=0;i<g;i++)
    {
        scanf("%d",&p[i]);

        if(sum+p[i]<=m)
        {
            sum+=p[i];

        }
        else
        {
            //cout<<sum<<endl;
            count++;
            sum=p[i];
            //if(i==g-1) count++;
        }


    }
    printf("%d",count);
}
