#include<bits/stdc++.h>
using namespace std;

#define MAX 2007
#define mem(a,b) memset(a,b,sizeof(a))

int n,ar[MAX],Left[MAX],Right[MAX],len,last,s,f;

void LIS_one()
{
    len = last = 0;
    for(int i=n-1;i>=0;i--){
        int pos = lower_bound(Left,Left+len,ar[i])-Left;
        //cout<<pos<<" ";
        Left[pos] = ar[i];
        if(pos==len) len++;
    }
//    cout<<endl<<len<<endl;
//    cout<<Left[len-1]<<endl;
}
int LIS_two(int val)
{
    int ln = 0;
    mem(Right,0);
    for(int i=0;i<n;i++){
        if(ar[i]<=val) continue;
        int pos = lower_bound(Right,Right+ln,ar[i])-Right;
        Right[pos] = ar[i];
        if(pos==ln) ln++;
    }
    return ln;
}
int main()
{


    int T;
    scanf("%d",&T);
    while(T--){
        mem(Left,0);
        mem(Right,0);
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        LIS_one();
        //
        f = Left[len-1];
//        for(int i=0;i<len;i++) cout<<Left[i]<<" ";
//        cout<<endl;
        int ans = 0;
        for(int i=len-1;i>=0;i--){
            int ln = LIS_two(Left[i]);
            //cout<<i+1<<" "<<ln<<endl;
            ans = max(ans, i+1+ln);
        }

        printf("%d\n",ans);
    }
    return 0;
}
