#include<bits/stdc++.h>
using namespace std;

struct st{
    int a,b,c;
    bool operator<(const st& x) const
    {
        if(a==x.a) return b<x.b;
        return a<x.a;
    }
}ar[200];

int main()
{
    int n,x,y,z,res[200],test=0;

    while(scanf("%d",&n) && n){
        test++;
        memset(res,0,sizeof(res));
        int in = -1;
        for(int i=0;i<n;i++){
            scanf("%d %d %d", &x, &y, &z);
            ar[++in].a = x; ar[in].b = y; ar[in].c = z;
            ar[++in].a = x; ar[in].b = z; ar[in].c = y;
            ar[++in].a = y; ar[in].b = x; ar[in].c = z;
            ar[++in].a = y; ar[in].b = z; ar[in].c = x;
            ar[++in].a = z; ar[in].b = x; ar[in].c = y;
            ar[++in].a = z; ar[in].b = y; ar[in].c = x;
        }
        sort(ar,ar+in+1);

        for(int i=in;i>=0;i--){
            res[i] = ar[i].c;
            //res[i] = 1;
            for(int j=i+1;j<=in;j++){
                if(ar[i].a<ar[j].a && ar[i].b<ar[j].b){
                        //cout<<i<<" "<<j<<" "<<res[i]+res[j]<<endl;
                    res[i] = max(res[i],ar[i].c+res[j]);
                    //if(res[i]+ar[j])
                    //res[i] = max(res[i],res[j]+1);
                }
            }
         }
         int ans = 0;
         for(int i=0;i<=in;i++) ans = max(ans,res[i]);

         printf("Case %d: maximum height = %d\n",test,ans);
    }
    return 0;
}
