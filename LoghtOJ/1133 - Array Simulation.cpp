#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,N=0,n,t,x,y;
    char ch;
    vector<int>v;
    scanf("%d",&T);
    while(++N<=T){
        v.clear();
        printf("Case %d:\n",N);
        scanf("%d%d",&n,&t);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            v.push_back(x);
        }
        for(int i=1;i<=t;i++){
            cin>>ch;
            if(ch=='S'){
                scanf("%d",&x);
                for(int j=0;j<n;j++) v[j]+=x;
            }
            else if(ch=='M'){
                scanf("%d",&x);
                for(int j=0;j<n;j++) v[j]*=x;
            }
            else if(ch=='D'){
                scanf("%d",&x);
                for(int j=0;j<n;j++) v[j]/=x;
            }
            else if(ch=='R') reverse(v.begin(),v.end());
            else if(ch=='P'){
                scanf("%d%d",&x,&y);
                int tmp = v[x];
                v[x] = v[y];
                v[y] = tmp;
            }
        }
        for(int i=0;i<n;i++){
            printf("%d",v[i]);
            if(i<n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
