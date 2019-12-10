#include<bits/stdc++.h>
using namespace std;

int n,ans,k,mdl;
int Left[20],Right[20];

void call(int i,int cnt)
{
    if(cnt==k){
        ans++;
        return;
    }
    if(i==n) return;

    if(k==n) call(i+1,cnt);

    for(int k=0;k<=n;k++){

        if(k==n) call(i+1,cnt);

        if(i==k){
            if(!mdl){

                mdl = 1;
                call(i,cnt+1);
                mdl = 0;
               //cout<<"m: "<<i<<" "<<k<<endl;
            }
        }
        else if(i>k){
            int in = (2 * abs(n-i)) + i + k;
            if(Left[in]==0){

                Left[in] = 1;
                call(i,cnt+1);
                Left[in] = 0;
                //cout<<"i>j: "<<i<<" "<<k<<endl;
            }

        }
        else if(i<k){
            int in = (2*abs(n-k)) + i+k;
            if(!Right[in]){

                Right[in] = 1;
                call(i,cnt+1);
                Right[in] = 0;
                //cout<<"i<j: "<<i<<" "<<k<<endl;
            }
        }
    }
}
int main()
{
    n=8,k=64;
    call(0,0);
    cout<<ans<<endl;
}
