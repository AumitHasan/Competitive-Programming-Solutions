#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int cnt[10],ar[3][6];

int main()
{
    set<int>st,ck;

    int n,x,y,z;

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            scanf("%d",&ar[i][j]);
            ck.insert(ar[i][j]);
        }
        while(ck.size() != 0){
            x = *ck.begin();
            ck.erase(x);
            cnt[x]++;
        }
    }
    //
    if(cnt[1]>=1 && cnt[0]>=2) st.insert(100);
    //
    if(n==1){
        for(int i=0;i<6;i++) st.insert(ar[0][i]);
    }
    else if(n==2){
        for(int i=0;i<6;i++){
            x = ar[0][i];
            for(int j=0;j<6;j++){
                st.insert(x);
                st.insert(ar[1][j]);
                st.insert((x*10)+ar[1][j]);
                st.insert((ar[1][j]*10)+x);
            }
        }
    }
    else{
        //01
        for(int i=0;i<6;i++){
            x = ar[0][i];
            for(int j=0;j<6;j++){
                st.insert(x);
                st.insert(ar[1][j]);
                st.insert((x*10)+ar[1][j]);
                st.insert((ar[1][j]*10)+x);
            }
        }
        // 12
        for(int i=0;i<6;i++){
            x = ar[1][i];
            for(int j=0;j<6;j++){
                st.insert(x);
                st.insert(ar[2][j]);
                st.insert((x*10)+ar[2][j]);
                st.insert((ar[2][j]*10)+x);
            }
        }
        // 02
        for(int i=0;i<6;i++){
            x = ar[0][i];
            for(int j=0;j<6;j++){
                st.insert(x);
                st.insert(ar[2][j]);
                st.insert((x*10)+ar[2][j]);
                st.insert((ar[2][j]*10)+x);
            }
        }
        //
    }

    set<int>:: iterator it;
    for(int i=1;;i++){
        it = st.find(i);
        if(it==st.end()){
            cout<<i-1<<endl;
            return 0;
        }
    }
}
