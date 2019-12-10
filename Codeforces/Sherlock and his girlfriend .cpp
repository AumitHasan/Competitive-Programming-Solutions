#include<bits/stdc++.h>
using namespace std;
#define mx 100010

int ar[mx];
bool mark[mx];
vector<int>v;

void seive()
{
    for(int i=4;i<mx;i+=2) mark[i] = 1;
    for(int i=3;i*i<mx;i+=2){
        if(mark[i]==0){
            for(int j=i*i;j<mx;j+=2*i) mark[j] = 1;
        }
    }
}
int main()
{
    seive();

    int n,k=0;
    cin>>n;

    for(int i=n+1;i>1;i--){
        if(ar[i]==0 and mark[i]==0){
            int c=0,j = i;
            while(j <= n+1){
                if(ar[j]==0) ar[j] = ++c;
                j += i;
            }
            if(k<c) k = c;
        }
    }

    cout<<k<<endl;
    for(int i=2;i<=n+1;i++){
        if(i==n+1){
            cout<<ar[i]<<endl;
        }
        else cout<<ar[i]<<" ";
    }
}
