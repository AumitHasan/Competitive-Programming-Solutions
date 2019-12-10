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
#define stan "Stan wins."
#define olie "Ollie wins."

#define mx 100007


int main()
{
    ll n;
    while(~scanf("%lld",&n)){
        if(n<=9) cout<<stan<<endl;
        else if(n<=18) cout<<olie<<endl;
        else{
            bool flag = true;
            ll pos = 18;
            while(1){
                flag = 1 - flag;
                if(flag){
                    pos *= 2;
                    if(pos>=n){
                        cout<<olie<<endl;
                        break;
                    }
                }
                else{
                    pos *= 9;
                    if(pos>=n){
                        cout<<stan<<endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
