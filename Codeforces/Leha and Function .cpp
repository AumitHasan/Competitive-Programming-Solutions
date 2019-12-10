#include<bits/stdc++.h>
using namespace std;

#define pr pair<int,int>
#define mx 200007

int res[mx];
vector<int>ar;
vector<pr>v;

int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        ar.push_back(x);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        v.push_back(pr(x,i));
    }
    sort(ar.rbegin(),ar.rend());
    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){
        res[v[i].second] = ar[i];
    }
    for(int i=0;i<n;i++){
        if(i==n-1) printf("%d\n",res[i]);
        else printf("%d ",res[i]);
    }

    return 0;
}
