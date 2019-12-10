#include<bits/stdc++.h>

using namespace std;

int num,in;
int a[123456],tail[123456],id[123456],par[123456];

int call(int last){
    if(par[last]!=-1)call(par[last]);
    printf("%d\n",a[last]);
}
void LIS(){
    int last=0,len=0;
    for(int i=0;i<=in;i++){
        int pos=lower_bound(tail,tail+len,a[i])-tail;
        tail[pos]=a[i];
        id[pos]=i;
        par[i] = pos>0 ? id[pos-1]:-1;
        if(pos==len){
            len++;
            last=i;
        }
        else if(pos+1==len)last=i;
    }
    printf("%d\n-\n",len);
    call(last);
}

int main()
{
    in=-1;
    while(~scanf("%d",&num) )a[++in]=num;
    LIS();

    return 0;
}
