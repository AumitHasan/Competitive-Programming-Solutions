#include<bits/stdc++.h>
using namespace std;

#define MAX 10007
#define mem(a,b) memset(a,b,sizeof(a))

int n,ar[MAX],ans[MAX],L[MAX],R[MAX];

void Left()
{
    mem(ans,0);
    int len = 0;
    for(int i=0;i<n;i++){
        int pos = lower_bound(ans,ans+len,ar[i]) - ans;
        ans[pos] = ar[i];
        if(pos==len) len++;
        L[i] = pos;
    }
}
void Right()
{
    mem(ans,0);
    int len = 0;
    for(int i=n-1;i>=0;i--){
        int pos = lower_bound(ans,ans+len,ar[i]) - ans;
        ans[pos] = ar[i];
        if(pos==len) len++;
        R[i] = pos;
    }
}
int main()
{
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);

        Left();
        Right();

        int tmp,ans = 0;
        for(int i=0;i<n;i++){
            tmp = min(L[i],R[i]) + 1;
            tmp = tmp*2 - 1;
            ans = max(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}
