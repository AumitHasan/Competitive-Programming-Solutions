#include<bits/stdc++.h>
using namespace std;
int main(){

    int test,i,j,k,l,n,q,a;

    vector <pair <int , int> > v;

    cin>>test;
    for(k=1;k<=test;k++)
    {


        v.clear();
        v.push_back(make_pair(0,0));
        scanf("\n%d %d",&n,&q);

        for(l=1;l<=n;l++)
        {
            scanf("%d",&a);
            v.push_back(make_pair(a,l));
        }
        sort(v.begin(),v.end());

        printf("Case %d:\n",k);

        while(q--)
        {
            scanf("%d %d",&i,&j);
            for(l=1;l<=n;l++)
            {
                if(v[l].second>=i && v[l].second<=j){
                    printf("%d\n",v[l].first);
                    break;
                }
            }
        }

    }

return 0;
}
