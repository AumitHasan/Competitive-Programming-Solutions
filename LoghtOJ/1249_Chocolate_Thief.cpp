#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int , string>i , pair<int , string>j){

    return i.first<j.first;
}

int main(){

    int test,n,t=0,a,b,c,i;
    string s;

    vector <pair<int, string> > v;

    scanf("%d",&test);
    while(test--){

        v.clear(); //clear all data form a vector

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>s;
            scanf("%d %d %d",&a,&b,&c);

            v.push_back(make_pair((a*b*c),s)); //make_pair in vector
        }

        sort(v.begin(),v.end(),compare);

        printf("Case %d: ",++t);
        if(v[0].first<v[n-1].first)
            printf("%s took chocolate from %s\n",v[n-1].second.c_str(),v[0].second.c_str()); //c_str for print string
        else
            printf("no thief\n");

    }

return 0;
}
