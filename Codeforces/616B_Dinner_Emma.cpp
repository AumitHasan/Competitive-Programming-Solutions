#include<bits/stdc++.h>
using namespace std;

int main(){

    long n,m,u,min,cost,i;

    cin>>n>>m;
    vector <long> v;

    while(n--){

        min=0;

        for(i=0;i<m;i++)
        {
            cost=0;
            scanf("%ld",&cost);

            if(cost<min || i==0)
                min=cost;
        }

        v.push_back(min);
    }

    cout<< *max_element(v.begin(),v.end())<<endl;


return 0;
}
