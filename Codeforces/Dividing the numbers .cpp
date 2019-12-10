#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
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

ll dif;
vector<int>v;

void call(int rem)
{
    if(rem==1){
        v.push_back(1);
        dif += 1;
    }
    else if(rem==2){
        dif += 1;
        v.push_back(1);
    }
    else if(rem==3){
        v.push_back(3);
    }
}
int main()
{
    int n;
    cin>>n;

    if(n>=4){
        //call(n%4);
        int nw = n,num=0;
        n %= 4;
        if(n==1){
            dif += num+1;
            v.push_back(num+1);
            num = 1;
        }
        else if(n==2){
            dif++;
            v.push_back(num+1);
            num = 2;
        }
        else if(n==3){
            //dif += ( (num+1) + (num+2) - (num+3) );
            v.push_back(num+1);
            v.push_back(num+2);
            num = 3;
        }

        int x = nw/4;

        for(int i=1;i<=x;i++){
            num++;
            v.push_back(num);
            num += 3;
            v.push_back(num);
        }


    }
    else{
        call(n);
    }

    cout<<dif<<endl<<v.size()<<" ";
    for(int i=0;i<v.size();i++){
        cout<<v[i];
        if(i<v.size()-1) cout<<" ";
        else cout<<endl;
    }
}
