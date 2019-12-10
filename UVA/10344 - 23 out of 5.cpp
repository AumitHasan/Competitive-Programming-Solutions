#include<bits/stdc++.h>
using namespace std;

int a[]={1,2,3,4,5},used[6],res[6],found,c,n;

int backtrack(int idx)
{
    if(idx==n){
        if(c==1) return 1;
        else return 0;
    }
    for(int i=0;i<n;i++){

        if(!used[a[i]]){

            used[a[i]] = 1;
            res[idx] = a[i];

            backtrack(idx);
            used[a[i]] = 0;

        }
    }
    res[idx] = a[idx]+backtrack(idx+1);

    cout<<res[idx]<<" ";
    return res[idx];
}
int main()
{
    //res[1] = 1;
    n=5;
    int r = backtrack(0);
    cout<<endl<<found;
}
