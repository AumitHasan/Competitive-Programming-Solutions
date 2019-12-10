#include<bits/stdc++.h>
using namespace std;

map<string,string>mymap;

int main()
{
        string ch;
        char str[100],s[100];

        while(1)
        {
            getline(cin,ch);

            if(ch.length()==0) break;

            int len = ch.length();
            //cout<<len<<endl;
            string s,str;
            bool flag=false;
            for(int i=0;i<len;i++)
            {
                if(ch[i]==' ') flag=true;
                else if(flag==false) s+=ch[i];
                else if(flag==true) str+=ch[i];
            }
            //cout<<s<<endl<<str<<endl;
        }

        while(1){
            string b;
            getline(cin,b);
            if(b.length()==0) break;

            string k = mymap[b];

            if(k.size()==0) cout<<"eh"<<endl;
            else cout<<mymap[b]<<endl;
        }

return 0;
}
/*
    int i,j;
            for(i=0;i<len;i++)
            {

                if(ch[i]==' '){
                    s[i]='\0';
                    break;
                }
                s[i]=ch[i];
            }
            int c=-1;
            i++;
            for(j=i;j<len;j++) str[++c]=ch[j];
            str[++c]='\0';

            if(mymap.find(str)==mymap.end()){
                string a;
                a = string(str);
                mymap[a]=s;
            }

*/
