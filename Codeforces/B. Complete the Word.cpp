#include<bits/stdc++.h>
using namespace std;

int main()
{
    int al[26];
    vector<int>v;
    char ch[500003];
    cin>>ch;
    int ln = strlen(ch);
    //
    if(ln<26) cout<<"-1"<<endl;
    else{
        int c,cnt,x;
        for(int i=0;i+25<ln;i++){

            c=cnt=x=0;
            memset(al,0,sizeof(al));
            v.clear();
                for(int j=i;j<i+26;j++){
                    if(ch[j]=='?'){
                        cnt++;
                        continue;
                    }
                    al[ch[j]-65]++;
                    c++;
                    if(al[ch[j]-65]>1){
                        x=1;
                        break;
                    }
                }
                if(c+cnt==26 and x==0){

                    for(int j=0;j<26;j++)
                        if(al[j]==0) v.push_back(j);

                    for(int j=0;j<i;j++){
                        if(ch[j]=='?') printf("A");
                        else printf("%c",ch[j]);
                    }

                    int k=-1;
                    for(int j=i;j<i+26;j++){
                        if(ch[j]=='?') printf("%c",v[++k]+65);
                        else printf("%c",ch[j]);
                    }

                    for(int j=i+26;j<ln;j++){
                        if(ch[j]=='?') printf("A");
                        else printf("%c",ch[j]);
                    }
                    cout<<endl;
                    return 0;
                }
        }
        cout<<"-1"<<endl;
    }
    return 0;
}
