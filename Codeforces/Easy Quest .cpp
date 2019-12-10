#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 1007
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int ar[mx],ck[mx];
vector<int>v;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&ar[i]);

    for(int i=0;i<n;i++){
        if(ar[i]<0){
            bool flag = false;
            for(int j=0;j<i;j++){
                if(abs(ar[i])==ar[j] && ck[j]==0){
                    flag = true;
                    ck[j] = 1;
                    break;
                }
            }
            if(flag==false){
                for(int j=0;j<i;j++){
                    if(ar[j]==0 && ck[j]==0){
                        ck[j] = abs(ar[i]);
                        flag = true;
                        break;
                    }
                }
            }
            if(flag==false){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    for(int i=0;i<n;i++){
        if(ar[i]==0 && ck[i]>0) v.push_back(abs(ck[i]));
        else if(ar[i]==0 && ck[i]==0) v.push_back(1);
    }
    for(int i=0;i<v.size();i++){
        printf("%d",v[i]);
        if(i<v.size()-1) printf(" ");
        else printf("\n");
    }
}
