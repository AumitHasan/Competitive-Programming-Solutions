#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define llu unsigned ll
#define pi pair<llu,llu>

int ar[200];
bool flag[200];
llu nar[200],pro[200],val,sign,cnt[200];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    while(~scanf("%d",&ar[1])){
        for(int i=2;;i++){
            scanf("%d",&ar[i]);
            n = i;
            if(ar[i]==-999999) break;
        }

        memset(flag,0,sizeof(flag));
        for(int i=1;i<n;i++){
            if(ar[i]<0){
                flag[i] = 1;
                ar[i] = abs(ar[i]);
            }
            nar[i] = ar[i];
            cnt[i] = flag[i] + cnt[i-1];
        }
        //
        llu ans = 1e18, rs = 1;
        for(int i=1;i<n;i++){
            val = 1;
            for(int j=i;j<n;j++){
                val *= nar[j];
                sign = cnt[j] - cnt[i-1];
                if(sign%2==0) sign = 0;
                else sign = 1;
                //cout<<"ij: "<<i<<" "<<j<<" "<<val<<" "<<sign<<endl;
                if(sign==1 && rs==1){
                    ans = min(ans,val);
                }
                else if(sign==0 && rs==1){
                    rs = 0;
                    ans = val;
                }
                else if(sign==0 && rs==0) ans = max(ans,val);
            }
        }
        if(rs==1) printf("-");
        printf("%llu\n",ans);
    }
}
