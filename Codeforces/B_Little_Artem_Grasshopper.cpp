#include<bits/stdc++.h>
using namespace std;

string str;
int d[100007],len;
map<int,int>mp;

int main()
{
    int n;
    cin>>n;

    cin>>str;
    len = str.length();
    for(int i=0;i<n;i++) scanf("%d",&d[i]);

    int i=0;
    while(1)
    {
        mp[i]++;
        if(str[i]=='>'){ i+=d[i]; }
        else if(str[i]=='<')
        {
            int x = d[i];
            i-=d[i];

            if(i>=0&&str[i]=='>'&&d[i]==x){
                cout<<"INFINITE"<<endl;
                break;
            }
        }
        if(mp[i]>1){cout<<"INFINITE"<<endl; break;}

        if(i<0 || i>=len){
            cout<<"FINITE"<<endl;
            break;
        }
    }

return 0;
}
