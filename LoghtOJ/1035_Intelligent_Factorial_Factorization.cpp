#include<bits/stdc++.h>
using namespace std;

vector<int>v[15];
map<int,int>mp;
int p[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,97};
int pre(int x)
{
    mp.clear();
    for(int i=2;i<=x;i++)
    {
        int n=0;
        n=i;

        for(int j=0;j<sizeof(p)&&p[j]*p[j]<=n;j++){

            if(n%p[j]==0){
                while(n%p[j]==0){
                    n/=p[j];
                    mp[p[j]]++;
                }
            }
        }
        if(n>=2) mp[n]++;
    }
}
int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T)
    {
        int n;
        cin>>n;
        pre(n);

        printf("Case %d: %d = ",N,n);
        int c=0;
        for (map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it){

            if(it->first==100) break;

            if(c==0) printf("%d (%d)",it->first,it->second);
            else printf(" * %d (%d)",it->first,it->second);
            c++;
        }
        cout<<endl;
    }

return 0;
}
