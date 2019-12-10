#include<bits/stdc++.h>
using namespace std;

#define pr pair<int,int>

int ar[1001][1001];
int ck[1001],in;
vector<pr> v;

int main()
{
    int n,m,u,x;

    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&u,&x);
        ar[u][x]=1;
        ck[u]+=1; ck[x]+=1;
    }
    int mid=1002;
    for(int i=1;i<=n;i++){
        if(mid>ck[i]){
            mid=ck[i]; in=i;
        }
    }


    for(int i=1;i<=n;i++){
        if(i==in) continue;
        if(ar[i][in]==0) v.push_back(make_pair(i,in));
    }

    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        printf("%d %d\n",v[i].first,v[i].second);
    }


return 0;
}

