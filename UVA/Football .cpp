#include<bits/stdc++.h>
using namespace std;

int ar[10007];

int main()
{
    int n,point;
    while(~scanf("%d",&n)){
        point = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&ar[i]);
            point += ar[i];
        }

        int p = (n*(n-1))/2;
        if(point!=p){
            cout<<-1<<endl;
            continue;
        }

        sort(ar,ar+n);

        bool flag = true;
        int rem = 0;

        for(int i=n-1;i>=0;i--){
            int val = i-ar[i];
            rem += val;
            if(rem<0){
                flag = false;
                break;
            }
        }
        if(flag) cout<<1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
