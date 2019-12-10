#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

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

#define mx 100007

double f[100];

void pre()
{
    f[0] = 5.5957541127;
    f[1] = 1.7320508076;
    for(int i=2;i<=10;i++){
        f[i] = (f[i-1] * f[i-1] - 5) / (2 * f[i-1] + 4);
        //cout<<f[i]<<endl;
    }
}
int main()
{
    pre();
    string str;
    while(cin>>str){
        if(str=="0") printf("%.10f\n",f[0]);
        else if(str=="1") printf("%.10f\n",f[1]);
        else if(str=="2") printf("%.10f\n",f[2]);
        else{
            int n = str[str.length()-1] - '0';
            if(n&1) printf("%.10f\n",f[3]);
            else printf("%.10f\n",f[4]);
        }
    }
}
