#include<bits/stdc++.h>
using namespace std;

int mark[1005],num[1000];

int main()
{
    int n,sum=0,i=0,pr=1,in=-1;
    scanf("%d",&n);

    while(sum<n){

        i++;
        int x = sum+i;
        if(mark[n-x]==0){
            int a = n-x;
            if(a!=i){
                mark[i]=1;
                num[++in] = i;
                sum+=i;
            }
        }
    }
    cout<<in+1<<endl;
    for(int i=0;i<=in;i++){
        cout<<num[i];
        if(i!=in) cout<<" ";
    }
    cout<<endl;
}
