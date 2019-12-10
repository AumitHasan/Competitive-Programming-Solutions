#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
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
#define SQR(a) ((a*a))


int main()
{
    int c=0;
    char ch;
    double a,b,x,y,res;
    res=a=b=x=y=0.0;

    while(1){
        cin>>ch;
        if(ch=='('){
            //scanf("%lf,%lf",&a,&b);
            cin>>a>>ch>>b;
            cin>>ch;
            cin>>ch;
            break;
        }
    }
    //cout<<a<<" "<<b<<endl;
    while(cin>>ch){
        if(ch=='.'){
            res += sqrt((a-x)*(a-x) + (b-y)*(b-y));
            //cout<<"REs: "<<res<<endl;
            printf("The salesman has traveled a total of %.3f kilometers.\n",res);
            a = x;
            b = y;
        }
        if(ch=='('){
            //scanf("%lf,%lf",&x,&y);
            cin>>x>>ch>>y;
            //cout<<"xy: "<<x<<" "<<y<<endl;
            //cout<<"ab: "<<a<<" "<<b<<endl;
        }
    }
}
