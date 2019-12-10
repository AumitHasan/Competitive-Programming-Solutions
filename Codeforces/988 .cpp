#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,string> pr;

#define pf(a) cout<<a<<endl
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define MX 100007
#define MOD 1000000007
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....

////

int len,ans;
string str,ch,tmp;


void f75()
{
    int c = 0;
    for(int i=0;i<str.size();i++) if(str[i]=='7') c=1;
    for(int i=0;i<str.size();i++) if(str[i]=='5') c=2;

    if(c!=2) return;
    tmp = str;
    c=0;
    for(int i=len-1;i>=0;i--){
        if(tmp[i]=='5'){
            for(int j=i;j<len-1;j++){
                c++;
                swap(tmp[j],tmp[j+1]);
            }
            break;
        }
    }
    for(int i=len-2;i>=0;i--){
        if(tmp[i]=='7'){
            for(int j=i;j<len-2;j++){
                c++;
                swap(tmp[j],tmp[j+1]);
            }
            break;
        }
    }
    ans = min(c,ans);
    cout<<tmp<<endl;
}
void f50()
{
    int c = 0;
    for(int i=0;i<str.size();i++) if(str[i]=='0') c=1;
    for(int i=0;i<str.size();i++) if(str[i]=='5') c=2;

    if(c!=2) return;
    tmp = str;
    c=0;
    for(int i=len-1;i>=0;i--){
        if(tmp[i]=='0'){
            for(int j=i;j<len-1;j++){
                c++;
                swap(tmp[j],tmp[j+1]);
            }
            break;
        }
    }
    for(int i=len-2;i>=0;i--){
        if(tmp[i]=='5'){
            for(int j=i;j<len-2;j++){
                c++;
                swap(tmp[j],tmp[j+1]);
            }
            break;
        }
    }
    ans = min(c,ans);
    cout<<tmp<<endl;
}
void f25()
{
    int c = 0;
    for(int i=0;i<str.size();i++) if(str[i]=='2') c=1;
    for(int i=0;i<str.size();i++) if(str[i]=='5') c=2;

    if(c!=2) return;
    tmp = str;
    c=0;
    for(int i=len-1;i>=0;i--){
        if(tmp[i]=='5'){
            for(int j=i;j<len-1;j++){
                c++;
                swap(tmp[j],tmp[j+1]);
            }
            break;
        }
    }
    for(int i=len-2;i>=0;i--){
        if(tmp[i]=='2'){
            for(int j=i;j<len-2;j++){
                c++;
                swap(tmp[j],tmp[j+1]);
            }
            break;
        }
    }
    ans = min(c,ans);
    cout<<tmp<<endl;
}
void f00()
{
    int c = 0;
    for(int i=0;i<str.size();i++) if(str[i]=='0') c=1;
    for(int i=0;i<str.size();i++) if(str[i]=='0') c=2;

    if(c!=2) return;
    tmp = str;
    c=0;
    for(int i=len-1;i>=0;i--){
        if(tmp[i]=='0'){
            for(int j=i;j<len-1;j++){
                c++;
                swap(tmp[j],tmp[j+1]);
            }
            break;
        }
    }
    for(int i=len-2;i>=0;i--){
        if(tmp[i]=='0'){
            for(int j=i;j<len-2;j++){
                c++;
                swap(tmp[j],tmp[j+1]);
            }
            break;
        }
    }
    cout<<c<<endl;
    ans = min(c,ans);
    cout<<tmp<<endl;
}
int main()
{
    cin>>str;
    ans = 1e5;
    len = str.size();
    f75();
    f50();
    f25();
    f00();
    if(ans<1e5) cout<<ans<<endl;
    else cout<<-1<<endl;
}
