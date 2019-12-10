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

int n,sz,fsz,flag,last;
string str,ch,ans[100],ar[100],nw;
map<int,int>mp;

bool check(int n)
{
    int sum=0;
    while(n>0){
        sum += n%10;
        n/=10;
    }
    if(sum<10) return 1;
    return 0;
}
void call(int pos,int val,int in)
{
    if(flag) return;
    if(pos>=sz){
        if(check(val)){
            fsz = in;
            last = val;
            flag = true;
            //cout<<"v: "<<val<<endl;
            //cout<<fsz<<endl;
            for(int i=0;i<in;i++) ans[i] = ar[i];
            //cout<<endl<<endl;
        }
        //cout<<val<<endl;
        //for(int i=0;i<in;i++) cout<<ar[i]<<" ";
        //cout<<endl<<endl;
        return ;
    }
    for(int i=pos;i<sz;i++){
        nw = "";
        int x = 0;
        for(int j=pos;j<=i;j++){
            nw += ch[j];
            x = (x*10) + ch[j]-'0';
        }
        //cout<<"in: "<<in<<endl;
        ar[in] = nw;
        call(i+1,val+x,in+1);
    }
}
int main()
{


    cin>>n;
    cin>>str;
    for(int i=1;i<=10 && i<=n;i++){
        int val=0,sum=0,in=0;
        while(in<n){
            val=0;
            for(int j=in;j<n && j<in+i;j++) val = (val*10) + str[j]-'0';
            sum += val;
            in += i;
        }
        mp[i] = sum;
    }

    for(int i=1;i<=10;i++){
        if(mp[i]){
            stringstream ss;
            ss << mp[i];
            ch = ss.str();
            sz = ch.length();
            call(0,0,0);
            if(flag){
                //cout<<"I: "<<i<<endl;
                for(int j=0;j<i;j++) cout<<str[j];
                int in = i;
                while(in<n){
                    cout<<"+";
                    ch = "";
                    for(int j=in;j<in+i && j<n;j++) ch += str[j];
                    cout<<ch;
                    in = in+i;
                }
                cout<<endl;
                //
                //cout<<ar[0]<<" x "<<ar[1]<<endl;
                cout<<ans[0];
                for(int i=1;i<fsz;i++) cout<<"+"<<ans[i];
                cout<<endl;
                //
                stringstream ss;
                ss << last;
                ch = ss.str();
                //
                cout<<ch[0];
                for(int i=1;i<ch.length();i++) cout<<"+"<<ch[i];
                cout<<endl;
                return 0;
            }
        }
    }
}
