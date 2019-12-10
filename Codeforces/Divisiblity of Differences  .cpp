#include<bits/stdc++.h>
using namespace std;

#define mx 100007

vector<int>v;
int ar[mx],dif[mx],ck[mx];

int main()
{
    int n,m,k,x;
    cin>>n>>k>>m;

    for(int i=0;i<n;i++) scanf("%d",&ar[i]);
    sort(ar,ar+n);

    for(int i=1;i<n;i++){
        x = abs(ar[0]-ar[i]) % m;
        dif[i] = x;
        //cout<<x<<endl;
        ck[x]++;
    }
    ck[0]++;
    //cout<<ck[0]<<endl;
    for(int i=0;i<m;i++){
            //cout<<ck[i]<<endl;
        if(ck[i]>=k){
            cout<<"Yes"<<endl;
            int c = 0;
            for(int j=0;j<n;j++){
                if(dif[j]==i){
                    c++;
                    printf("%d",ar[j]);
                    if(c==k){
                        cout<<endl;
                        return 0;
                    }
                    printf(" ");
                }
            }
        }
    }
    cout<<"No"<<endl;
}
