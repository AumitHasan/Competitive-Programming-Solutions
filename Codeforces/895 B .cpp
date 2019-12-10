#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define base 10000007
#define ll long long int
#define umap unordered_map
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

llu ans = 0;
int a,b,n,x,k,ar[mx],val,ck[mx];
vector<int>vec;
umap<int,int>mp;

int main()
{
    scanf("%d %d %d",&n, &x, &k);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        if(mp[val]==0){
            mp[val]++;
            vec.push_back(val);
        }
        else mp[val]++;
    }
    sort(vec.begin(),vec.end());
    //
    int len = vec.size();


    if(n==1){
        if(k==0 && vec[0]%x != 0 ) ans++;
        if(k==1 && vec[0]%x==0) ans++;
        cout<<ans<<endl;
        return 0;
    }
    //
    int cnt,ix=len-2,iy=len-1;
    while(1){
        a = vec[ix]/x;
        if(vec[ix]%x==0) a--;
        b = vec[iy]/x;

        cnt = b-a;

        if(b==k && iy>0){ // ///
            int e = vec[0]/x;
            if(vec[0]%x==0) ans += mp[vec[iy]] * mp[vec[0]];
            else{
                if(vec[iy]<x){
                    int cc=0;
                    for(int l=0;l<=iy;l++) cc += mp[vec[l]];
                    ans += cc*cc;
                }
            }
        }

        bool flag = false;

        //cout<<"ab: "<<a<<" "<<b<<endl;

        if(cnt == k){
            ck[ix] = ck[iy] = 1;
            ans += mp[vec[ix]] * mp[vec[iy]];
            //cout<<ix<<" x "<<iy<<endl;
            ix--;
            flag = true;
            //iy--;
        }
        else if(cnt>k){
            iy--;
        }
        else if(cnt<k){
            if(ix==0) break;
            ix--;
        }
        if(ix<0 || ix>iy) break;
        if(ix==iy){
            ix--;
        }
    }
    //cout<<ix<<" res "<<iy<<endl;
    //
    if(k==0){
        for(int i=0;i<len;i++){
            if(ck[i]==0 && vec[i]%x != 0){
                ck[i] = 1;
                ans += mp[vec[i]];
            }
        }
    }
    if(k==1){
        for(int i=0;i<len;i++){
            if(ck[i]==0 && vec[i]%x==0){
                ck[i]=1;
                //cout<<"F"<<endl;
                ans += mp[vec[i]] * mp[vec[i]];
            }
        }
    }
    //
    if(ix>=0 && ix<iy){
            //cout<<"fucmk"<<endl;
        for(int i=iy;i>=ix;i--){
            a = vec[ix]/x;
            if(vec[ix]%x==0) a--;
            b = vec[iy]/x;

            if(cnt == k){
                ans += mp[vec[ix]] * mp[vec[i]];
                //cout<<ix<<" "<<i<<endl;
            }
        }
    }
    //


    cout<<ans<<endl;
}
