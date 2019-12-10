#include<bits/stdc++.h>
using namespace std;
#define pr pair<int,int>

vector<pair<int,int> >v;
vector<int>vv;
int ar[30000];

int main()
{
    int n,p,a,b,mv=0;
    cin>>n>>p;

    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a>b) swap(a,b);
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());

    bool flag=false;

    for(int i=1;i<v.size();i++){
        if(v[i].first>v[i-1].second) flag=true;
    }

    if(flag) cout<<-1<<endl;
    else{

        int x = v[0].first;
        int y = v[v.size()-1].second;

        for(int i=x;i<=y;i++){

            flag = false;
            for(int j=0;j<v.size();j++){

                    if(i>=v[j].first and i<=v[j].second){ }
                    else{ flag=true; break;}

            }
            if(flag==false) ar[i] = 1;
        }

        for(int i=0;i<=1005;i++){
            if(ar[i]==1){
                //cout<<abs(i-p)<<" ";
                vv.push_back(abs(i-p));
            }
        }
        //cout<<endl;
        if(vv.size()==0){
            cout<<-1<<endl;
        }
        else{
            sort(vv.begin(),vv.end());
            cout<<vv[0]<<endl;
        }
    }
}
