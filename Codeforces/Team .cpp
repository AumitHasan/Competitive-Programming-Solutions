#include<bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))

int cnt[1000009];

int main()
{
    int zero,one;
    cin>>zero>>one;

    if(zero==1){
        if(one<=4){
            int a = one / 2;
            int b = one / 2; b += one % 2;
            for(int i=1;i<=a;i++) cout<<1;
            cout<<0;
            for(int i=1;i<=b;i++) cout<<1;
            cout<<endl;
        }
        else cout<<-1<<endl;
        return 0;
    }

    int n = zero;

    int mn = (zero-1);
    mn = (mn<0) ? 0 : mn;
    int mx = (zero+1) * 2;

    if(one>=mn && one<=mx){
        int tmp = one;
        bool flag = false;
        //
        for(int i=1;i<=2;i++){
            if(!tmp) break;
            for(int j=1;j<n;j++){
                if(!tmp) break;
                cnt[j]++; tmp--;
                if(cnt[j]>2) flag = true;
            }
        }
        if(!flag && !tmp){
            cout<<0;
            for(int i=1;i<n;i++){
                for(int j=1;j<=cnt[i];j++) cout<<1;
                cout<<0;
            }
            cout<<endl;
            return 0;
        }
        //
        //cout<<"ass"<<endl;
        mem(cnt,0);
        tmp = one;
        flag = false;
        for(int i=1;i<=2;i++){
            if(!tmp) break;
            for(int j=1;j<=n;j++){
                if(!tmp) break;
                cnt[j]++; tmp--;
                if(cnt[j]>2) flag = true;
            }
        }
        if(!flag && !tmp){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=cnt[i];j++) cout<<1;
                cout<<0;
            }
            cout<<endl;
            return 0;
        }
        //
        mem(cnt,0);
        tmp = one;
        flag = false;
        //cout<<"F"<<endl;
        for(int i=1;i<=2;i++){
            if(!tmp) break;
            for(int j=1;j<=n+1;j++){
                if(!tmp) break;
                cnt[j]++; tmp--;
                if(cnt[j]>2) flag = true;
            }
        }
        if(!flag && !tmp){
            for(int i=1;i<=n+1;i++){
                for(int j=1;j<=cnt[i];j++) cout<<1;
                if(i<=n) cout<<0;
            }
            //cout<<endl;
            return 0;
        }
    }
    else cout<<-1<<endl;

    return 0;
}
