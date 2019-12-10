#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;


#define pr pair<int,string>
#define mem(a,b) memset(a,b,sizeof(a))

int beauty[5],ar[1000];
string str[5];
vector<pr>v;
set<int>st;

int main()
{
    int n;

    cin>>n;
    cin>>str[1]>>str[2]>>str[3];

    mem(beauty,0);

    for(int i=1;i<=3;i++){

        if(str[i].size()==1){
            beauty[i] = 1;
            continue;
        }
        else{
            mem(ar,0);
            for(int j=0;j<str[i].size();j++) ar[str[i][j]]++;
            int m = 0;
            for(int j=0;j<160;j++) m = max(m,ar[j]);
            if(m+n<=str[i].size()){
                beauty[i] = m+n;
            }
            else{
                if(m!=str[i].size()){
                    beauty[i] = str[i].size();
                }
                else{
                    int tmp = n ;
                    int len = str[i].size();

                    if(tmp==1) beauty[i] = len-1;
                    else if(tmp>1) beauty[i] = len;
                }
//                cout<<"t: "<<tmp<<" "<<m<<endl;
//                if(tmp%2==0){cout<<tmp<<" X" <<endl; beauty[i] = str[i].size();}
//                else{cout<<"I: "<<i<<" "<<str[i].size()-1<<endl; beauty[i] = str[i].size() - 1;}
            }
        }
        //cout<<beauty[i]<<endl;
    }

    int ans = 0;
    for(int i=1;i<=3;i++) ans = max(ans,beauty[i]);
    //for(int i=1;i<=3;i++) cout<<beauty[i]<<endl;
    int c = 0;

    for(int i=1;i<=3;i++){
        if(beauty[i]==ans) c++;
    }
    if(c>1){
        cout<<"Draw"<<endl;
        return 0;
    }
    v.push_back(pr(beauty[1],"Kuro"));
    v.push_back(pr(beauty[2],"Shiro"));
    v.push_back(pr(beauty[3],"Katie"));
    sort(v.rbegin(),v.rend());
    cout<<v[0].second<<endl;


}
