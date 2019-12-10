#include<bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))

int main()
{
    int T,N=0,n;
    scanf("%d",&T);
    while(++N<=T)
    {
        string cell[2];

        scanf("%d",&n);

        cin>>cell[0];
        cin>>cell[1];
        bool flag=false;
        int st;
        for(int i=0;i<n;i++){
            if(cell[0][i]=='#' || cell[1][i]=='#'){
                st=i;
                //cout<<i+1<<endl;
                break;
            }
        }
        int cnt = 0;
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                if(cell[i][j]=='#') cnt++;
            }
        }

        int idx = st,c=0;
        if(cell[0][st]=='#'){
            int pos = 0;
            while(idx<n){

                if(cell[pos][idx]=='#') c++;
                else break;

                if(pos==0 && cell[1][idx]=='#'){
                    c++;
                    pos = 1;
                }
                else if(pos==1 && cell[0][idx]=='#'){
                    c++;
                    pos=0;
                }
                else if(pos==0 && idx+1<n && cell[0][idx+1]=='#'){
                    pos = 0;
                }
                else if(pos==1 && idx+1<n && cell[1][idx+1]=='#'){
                    pos = 1;
                }
                else break;
                idx++;
            }
            //cout<<"C: "<<c<<endl;
        }
        if(c==cnt){
            printf("yes\n");
            continue;
        }
        if(cell[1][st]=='#'){
            c=0;
            idx = st;
            int pos = 1;
            while(idx<n){

                if(cell[pos][idx]=='#') c++;
                else break;

                if(pos==0 && cell[1][idx]=='#'){
                    c++;
                    pos = 1;
                }
                else if(pos==1 && cell[0][idx]=='#'){
                    c++;
                    pos=0;
                }
                else if(pos==0 && idx+1<n && cell[0][idx+1]=='#'){
                    pos = 0;
                }
                else if(pos==1 && idx+1<n && cell[1][idx+1]=='#'){
                    pos = 1;
                }
                else break;
                idx++;
            }
            //cout<<"C: "<<c<<endl;
        }
        if(c==cnt){
            printf("yes\n");
            continue;
        }

        printf("no\n");

    }

return 0;
}
