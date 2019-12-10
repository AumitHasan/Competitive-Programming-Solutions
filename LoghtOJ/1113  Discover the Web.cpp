#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        stack<string>bk,fr;
        printf("Case %d:\n",N);
        string s,str;
        s = "http://www.lightoj.com/";
        bk.push(s);
        while(1){
            cin>>s;
            if(s=="VISIT"){
                cin>>str;
                cout<<str<<endl;
                bk.push(str);
                while(!fr.empty()) fr.pop();
            }
            else if(s=="BACK"){
                if(bk.size()<=1) printf("Ignored\n");
                else{
                    str = bk.top();
                    fr.push(str);
                    bk.pop();
                    str = bk.top();
                    cout<<str<<endl;
                }
            }
            else if(s=="FORWARD"){
                if(fr.size()>0){
                    str = fr.top();
                    cout<<str<<endl;
                    bk.push(str);
                    fr.pop();
                }
                else printf("Ignored\n");
            }
            else if(s=="QUIT") break;
        }
    }
    return 0;
}
