#include<stdio.h>
#include<string.h>


int call(int pos,int wt,int n,int sum,int ar[],int dp[21][201])
{
    if(pos==n){
        if(wt==sum) return 1;
        return 0;
    }
    if(dp[pos][wt] != -1) return dp[pos][wt];

    int res = 0;

    res |= call(pos+1,wt+ar[pos],n,sum,ar,dp);
    res |= call(pos+1,wt,n,sum,ar,dp);

    return dp[pos][wt] = res;
}
int extract(char ch[], int ar[])
{
    int i,num = 0, idx = 0;
    for( i=0;i<strlen(ch);i++){
        if(ch[i] == ' '){
            ar[idx++] = num;
            num = 0;
        }
        else num = (num*10) + (ch[i] - '0');
    }
    if(num>0) ar[idx++] = num;
    return idx;
}
int main()
{
    int i, t,ar[25],n,sum,dp[21][201];
    scanf("%d",&t);
    char ch[10000];

    getchar();

    while(t--){
        memset(dp,-1,sizeof(dp));
        gets(ch);

        n = extract(ch,ar);
        sum = 0;
        for(i=0;i<n;i++) sum += ar[i];

        if(sum&1) printf("NO\n");
        else{
            sum /= 2;
            int ans = call(0,0,n,sum,ar,dp);
            if(ans) printf("YES\n");
            else printf("NO\n");
        }

    }
    return 0;
}
