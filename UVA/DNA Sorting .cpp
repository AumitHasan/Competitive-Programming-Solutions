#include<bits/stdc++.h>
using namespace std;

struct st{
    string s;
    int cnt;
    bool operator<(const st & a) const
    {
        return cnt<a.cnt;
    }
}ar[102];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T,N=0;
    cin>>T;
    string str;
    while(T--){
        int in=-1;
        int n,m,c;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            cin>>str;
            c=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(str[j]<str[i]) c++;
                }
            }
            ar[++in].s = str;
            ar[in].cnt = c;
        }
        sort(ar,ar+in+1);
        for(int i=0;i<m;i++) cout<<ar[i].s<<endl;
        if(T) printf("\n");
    }
    return 0;
}
