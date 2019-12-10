#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
#define ll unsigned long long int
int p[mx];
vector<pair<int,int> >v,vc;

ll sum(int y,int x,int in)
{
    ll proft=0;
    for(int k=in;k<x;k++){
        //cout<<"in:"<<in<<endl;
        cout<<"k: "<<k<<endl;
        if(p[k]>=p[k-1]){
            proft += y-p[k];
            //cout<<i<<" "<<k<<" "<<vc[i].first<<" "<<p[k]<<" "<<y-p[k]<<endl;
            }
        }
        return proft;
}
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--){
        v.clear();
        vc.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&p[i]);

        unsigned long long int proft=0;
        for(int i=0;i<n-1;i++){
            if(p[i+1]>=p[i]){
                int j=i;
                while(p[j+1]>=p[j] and j<n-1) j++;

                int m=p[j];
                v.push_back(make_pair(p[j],j));
                i = j;
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        cout<<endl;
        for(int i=0;i<v.size();i++){
            int a=v[i].first;
            int aa=v[i].second;
            int b=i;
            for(int j=i;j<v.size();j++){
                if(v[j].first>=a){
                    a=v[j].first;
                    aa = v[j].second;
                    b=j;
                    //cout<<"check: "<<a<<" "<<aa<<" "<<b<<endl;
                }
            }
            vc.push_back(make_pair(a,aa));
            i=b;
        }
        cout<<endl;
        for(int i=0;i<vc.size();i++){
            cout<<vc[i].first<<" "<<vc[i].second<<endl;
        }
        cout<<endl;
        int in=1,c=0;
        if(p[0]<=p[1]){
            proft = vc[0].first-p[0];
        }
        int sz = vc.size();
        cout<<"sz: "<<vc[1].first<<endl;
        for(int i=0;i<sz;i++){
            int x = vc[i].second;
            int y = vc[i].first;

            proft += sum(y,x,in);
            in=x+1;
            getchar();
        }
        printf("%lld\n",proft);
    }
    return 0;
}
