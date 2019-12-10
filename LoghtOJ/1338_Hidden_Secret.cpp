#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,N=0;
    char cc[10];
    scanf("%d",&T);
    gets(cc);
    while(++N<=T)
    {
        char s[200],str[200];
        int a[27]={0},b[27]={0};
        int ln=0,len=0;
        gets(s);
        gets(str);
        for(int i=0;i<strlen(s);i++){
            if(s[i]>=65 and s[i]<=90) s[i]+=32;
            if(s[i] != ' '){
                ln++;
                a[s[i]-97]++;
            }
        }
        for(int i=0;i<strlen(str);i++){
            if(str[i]>=65 and str[i]<=90) str[i]+=32;
            if(str[i] != ' '){
                len++;
                b[str[i]-97]++;
            }
        }
        //cout<<ln<<" "<<len<<endl;
        printf("Case %d: ",N);
        if(ln!=len) printf("No\n");
        else{
            int c=0;
            for(int i=0;i<27;i++){
                if(a[i]!=b[i]) c=1;
            }
            if(c==0) printf("Yes\n");
            else printf("No\n");
        }
    }

return 0;
}
