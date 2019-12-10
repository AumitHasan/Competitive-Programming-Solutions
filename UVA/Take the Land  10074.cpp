#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
#define ll long long int
#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 1007
#define int_map map<int,int>
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)

int row,col,ar[101][1001],tmp[1001],zero[101];
int kadane(int C)
{
    int sum = 0,maxSum=0;
    for(int i=0;i<row;i++){
        sum += tmp[i];
        if(tmp[i]==0 || zero[i] || ar[i][C]==0) sum = 0;
        if(sum>maxSum) maxSum = sum;
    }
    return maxSum;
}
int main()
{
    int num;
    while(scanf("%d%d",&row,&col) && row && col){
        int maxSum = 0,sum=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                scanf("%d",&num);
                ar[i][j] = 1^num;
            }
        }
        for(int left=0;left<col;left++){
            mem(tmp,0);
            mem(zero,0);
            for(int right=left;right<col;right++){
                for(int i=0;i<row;i++){
                    tmp[i] += ar[i][right];
                    if(ar[i][right]==0) zero[i] = 1;
                }

                sum = kadane(right);
                if(sum>maxSum) maxSum = sum;
            }
        }

        printf("%d\n",maxSum);
    }
    return 0;
}
