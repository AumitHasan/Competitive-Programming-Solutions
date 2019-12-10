#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
#define mx 300
int add(int i,int idx);

char ch[260];
string str;
int len,ln2,dp[mx][mx],sum[mx],dig[mx];

int call(int i,int idx)
{
    if(i>len){
        //cout<<i<<" x "<<idx<<endl;
        return -inf;
    }
    if(idx == ln2){
        //cout<<i<<" "<<idx<<endl;
        return 0;
    }
    if(dp[i][idx] != -1) return dp[i][idx];

    return dp[i][idx] = max(call(i+dig[idx],idx+1)+add(i,idx),call(i+1,idx));
}
int add(int i,int idx)
{
    int x = dig[idx];
    //cout<<"val: "<<sum[i+idx-1]-sum[i-1]<<endl;
    if(i==0) return sum[i+x-1];
    else  return sum[i+x-1]-sum[i-1];
}
int main()
{

    while(~scanf("%s",ch)){
        cin.ignore();
        getline(cin,str);
        if(str.length()==0){
            printf("0\n");
            continue;
        }
        mem(dp,-1);
        mem(dig,0);
        mem(sum,0);

        //scanf("%s",str);
        len = strlen(ch);
        //ln2 = strlen(str);
        ln2 = str.length();

        sum[0] = ch[0]-48;
        //cout<<sum[0]<<" ";
        for(int i=1;i<len;i++){
            sum[i] = sum[i-1]+(ch[i]-48);
            //cout<<sum[i]<<" ";
        }
        //cout<<endl;
        for(int i=0;i<ln2;i++) dig[i] = str[i]-96;
        int res = call(0,0);
        printf("%d\n",res);
    }
}
