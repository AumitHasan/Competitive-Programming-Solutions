#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
#define mx 1000001
#define bs 1000011

ll base[mx];
ll has[mx],com;

void pre_base()
{
    base[0]=1;
    for(int i=1;i<mx;i++) base[i] = base[i-1]*bs;
}
bool check(int i,int len)
{
    ll val;
    if(i==0) val = has[i+len-1];
    else val = has[i+len-1]-(has[i-1]*base[len]);

    if(com==val) return true ;
    else return false;
}
int main()
{
    pre_base();
    int n;
    while(~scanf("%d",&n))
    {
        int c=0;
        string str,s;
        cin>>s>>str;

        ll len = str.length();

        if(n>len){
            cout<<endl;
            continue;
        }

        com=0;
        for(int i=0;i<n;i++) com = (com*bs)+s[i];

        has[0]=str[0];
        for(int i=1;i<len;i++) has[i] = (has[i-1]*bs)+str[i];

        for(int i=0;i<=len-n;i++)
        {
            if(check(i,n)==true){
                c=1;
                printf("%d\n",i);
            }
        }

        if(c==0) cout<<endl;
    }

return 0;
}
