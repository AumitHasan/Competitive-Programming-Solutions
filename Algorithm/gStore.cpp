#include<bits/stdc++.h>
using namespace std;

#define mx 100000

vector<int>edge[mx];
vector<int>cost[mx];

int main()
{
    int N,E;
    cin>>N>>E;

    for(int i=0;i<E;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);

        edge[x].push_back(y);
        edge[y].push_back(x);

        cost[x].push_back(1);
        cost[y].push_back(1);
    }

    cin>>N;
    for(int i=0;i<edge[N].size();i++) cout<<edge[N][i]<<" ";

return 0;
}
