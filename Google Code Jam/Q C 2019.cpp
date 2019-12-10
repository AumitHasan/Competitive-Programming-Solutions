#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

//int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; // 4 Direction
//int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1};  // 8 Direction
//int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; // Knight Direction
//int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; // Hexagonal Direction

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)          scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     MAX3(a,b,c)             max(a,max(b,c))
#define     MAX4(a,b,c,d)           max(max(a,b),max(c,d))
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      200007

////

int n,val,l,ar[203],res[203],tmp[203];


int main()
{
    IO;

    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int T,N=0;
    sci(T);
    while(++N<=T){
        mem(ar,0);
        mem(res,0);
        mem(tmp,0);
         scii(n,l);
         for(int i=1;i<=l;i++) sci(ar[i]);

         if(ar[1] >= ar[2]) val = __gcd(ar[2],ar[1]);
         else val = __gcd(ar[1],ar[2]);

         res[1] = ar[1] / val;
         res[2] = val;
         res[3] = ar[2] / val;
         for(int i=3;i<=l;i++){
            res[i+1] = ar[i] / res[i];
         }
         set<int>st;
        for(int i=1;i<=l+1;i++){
                st.insert(res[i]);
        }

        int idx = 0;
        while(st.size()){
            tmp[idx++] = *st.begin();
            st.erase(st.begin());

        }
        cout<<"Case #"<<N<<": ";
         for(int i=1;i<=l+1;i++){
            for(int j=0;j<26;j++){
                if(res[i]==tmp[j]){
                    cout<<str[j];
                    break;
                }
            }
         }
         cout<<endl;
    }
    return 0;

}
