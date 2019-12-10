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



int main()
{
    string str;
    cin>>str;
    int ans=0,len = str.length();
    for(int i=0;i<str.length();i++){
        if(str[i]=='Q'){
            int c=0;
            for(int j=i+1;j<len;j++){
                if(str[j]=='A') c++;
                if(str[j]=='Q'){
                    ans += c;
                }
            }
        }
    }
    cout<<ans<<endl;
}
