#include <bits/stdc++.h>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
int row,col,N,c,dp[1<<17][20];

int ck(int mask,int ab,int x,int y)
{
    mask ^= (1<<ab);
    mask ^= (1<<x);
    mask |= (1<<y);
    return mask;
}
int call(int mask,int cnt)
{
    //if(__builtin_popcount(mask)==1){
    if(cnt==1) return 1;

    if(dp[mask][cnt] != -1) return dp[mask][cnt];

    int p = 0;
    for(int i=0;i<row*col;i++){

        if((mask & (1<<i))){
            int a = i/(col);
            int b = i%(col);

            for(int j=0;j<8;j++){
                int x = d8x[j]+a;
                int y = d8y[j]+b;
                int z = (x*col)+y;

                if(z>=0 and (mask & (1<<z))){
                    int xx = x + d8x[j];
                    int yy = y + d8y[j];
                    int zz = (xx*col)+yy;
                    if(xx>=0 && xx<row && yy>=0 && yy<col && !(mask & (1<<zz))){
                       p += call(ck(mask,i,z,zz),cnt-1);
                    }
                }
            }
        }
    }
    return dp[mask][cnt] = p;
}
int main()
{
    int T,n=0;
    cin>>T;
    while(++n<=T){
        mem(dp,-1);
        int a,b,mask=0;
        c=0;
        //cin>>row>>col>>N;
        scanf("%d %d %d",&row ,&col ,&N);
        //cout<<N<<endl;
        for(int i=0;i<N;i++){
            //cin>>a>>b;
            scanf("%d %d",&a ,&b);
            a--;
            b--;
            int ps = (a*(col))+b;
            //cout<<ps<<endl;
            mask |= 1<<(ps);
            //cout<<mask<<endl;
        }
        //cout<<mask<<endl;
        //cout<<"fjdksj";
        if(row*col>=N) c = call(mask,N);

        printf("Case %d: %d\n",n,c);
    }
}
