#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int num[100],used[100],n,c,tmp;
long long int ans,one;
int ar[] = {0,1,2,8,9,10,11};

void call(int pos)
{
    if(pos>n){
        ans++;
        c = 0;
        for(int i=1;i<=6;i++){
            if(i==num[i]) c++;
        }
        if(c==3){
            tmp++;
            int x = 0;
            for(int i=1;i<=3;i++){
                if(i==num[i]) x++;
            }
            if(x==3) one++;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i] = 1;
            num[pos] = i;
            call(pos+1);
            used[i] = 0;
        }
    }
}
void gen(int pos)
{
    if(pos>6){
        int tmp=0;
        for(int i=1;i<=6;i++){
            cout<<num[i]<<" ";
            if(i==num[i]) tmp++;
        }
        if(tmp) c++;
        cout<<endl;
        ans++;
        return;
    }
    for(int i=1;i<=6;i++){
        if(!used[ar[i]]){
            used[ar[i]] = 1;
            num[pos] = ar[i];
            gen(pos+1);
            used[ar[i]] = 0;
        }
    }
}
int main()
{
    gen(1);
    cout<<ans<<" "<<c<<endl;
    return 0;
    n = 10;
    call(1);
    cout<<ans<<" "<<tmp<<" "<<one<<endl;
}
