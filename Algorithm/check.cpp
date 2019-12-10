#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int

int ar[] = {0,2,4,6,8};
ll ans,used[5],res[10];

void call(int pos)
{
    if(pos>=2){
        for(int i=0;i<pos;i++) cout<<res[i];
        cout<<endl;
        ans++;
        return;
    }
    for(int i=0;i<5;i++){
        res[pos] = ar[i];
        call(pos+1);
    }
}
int main()
{
    call(0);
    cout<<ans;
}
