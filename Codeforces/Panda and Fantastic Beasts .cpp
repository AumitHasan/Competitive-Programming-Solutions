#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 250007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int n;
vector<llu>has[50007];
vector<int>res[30];
llu H[mx],tmp;
string str[50007];
set<int>st;
umap<llu,int>mp;
umap<int,int>ck;

void pre_h()
{
    H[0] = 1;
    for(int i=1;i<mx;i++) H[i] = H[i-1] * base;
}
void src()
{
//    llu x='a';
//    x = x*base + 'b';
//    cout<<"ab: "<<x<<endl;
//    x = 'b';
//    x = x*base + 'a';
//    cout<<"ba: "<<x<<endl;
//    cout<<has[1][1]<<endl;
//    cout<<(has[1][2] - (has[1][0]*H[2]))<<endl;
    ck.clear();
    int is=0,in=-1,mid,lo=1,hi=str[0].length();
    while(lo<=hi){
        mid = (lo+hi) / 2;
        mp.clear();
        //
        cout<<"p:"<<endl;
        for(int i=1;i<n;i++){
            int ln = str[i].length();
            if(ln<mid) continue;
            mp[has[i][mid-1]] = 1;
            cout<<has[i][mid-1]<<endl;
            for(int j=1;j<=ln-mid;j++){
                mp[has[i][j+mid-1] - (has[i][j-1]*H[mid]) ] = 1;
                cout<<has[i][j+mid-1] - (has[i][j-1]*H[mid])<<endl;
            }
        }
        cout<<endl;
        in++;
        ck[mid] = in;
        bool flag = false;
        if(mp[has[0][mid-1]]==0){
            cout<<"h: "<<0<<" "<<has[0][mid-1]<<endl;
            flag = true;
            res[in].push_back(0);
            st.insert(mid);
            cout<<"m: "<<mid<<endl;
        }
        int ln = str[0].length();

        for(int j=1;j<=ln-mid;j++){
            if(mp[has[0][j+mid-1] - (has[0][j-1]*H[mid]) ] == 0){
                cout<<"H: "<<j<<" "<<has[0][j+mid-1] - (has[0][j-1]*H[mid])<<endl;
                flag = true;
                res[in].push_back(j);
                st.insert(mid);
                cout<<"M: "<<mid<<endl;
            }
        }

        if(flag){
            hi = mid - 1;
            is = 1;
        }
        else lo = mid + 1;
    }

    cout<<"F: "<<is<<endl;
    cout<<st.size()<<endl;
}
int main()
{
    IO;
    pre_h();

    int T,N=0,len;
    cin>>T;
    while(++N<=T){
        mem(res,0);
        mem(has,0);
        st.clear();
        //
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>str[i];
            len = str[i].length();
            has[i].push_back(str[i][0]);
            for(int j=1;j<len;j++){
                tmp = (has[i][j-1] * base) + str[i][j];
                has[i].push_back(tmp);
            }
        }
        //
        //cout<< has[1][2] - (has[1][0]*H[2])<<endl<<endl;

        src();
        if(st.size()==0){
            cout<<"Case #"<<N<<": Impossible"<<endl;
        }
        else{
                cout<<endl;
            int in = *st.begin();
            cout<<in<<endl;
            in = ck[in];
            for(int i=0;i<res[in].size();i++){
                cout<<res[in][i]<<endl;
            }
        }
    }
}
