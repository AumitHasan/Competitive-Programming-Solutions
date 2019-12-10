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
    string str,x,y;
    int n;
    cin>>n;
    getchar();
    while(n--){
        getline(cin,str);

        if(str=="lala.") cout<<"Freda's"<<endl;
        else if(str=="miao.") cout<<"Rainbow's"<<endl;
        else if(str.size()<5) cout<<"OMG>.< I don't know!"<<endl;
        else{
            x = str.substr(0,5);
            y = str.substr(str.size()-5,5);
            if(x=="miao." && y=="lala.") cout<<"OMG>.< I don't know!"<<endl;
            else if(x=="miao.") cout<<"Rainbow's"<<endl;
            else if(y=="lala.") cout<<"Freda's"<<endl;
            else cout<<"OMG>.< I don't know!"<<endl;
        }
    }
}
