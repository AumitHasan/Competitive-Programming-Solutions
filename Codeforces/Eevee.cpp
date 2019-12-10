#include<bits/stdc++.h>
using namespace std;


string v[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon",
            "glaceon", "sylveon"};

int n,c=0;
string str;
char s,ss;

int main()
{
    scanf("%d",&n);
    cin>>str;

    for(int i=0;i<8;i++)
    {
        int len = v[i].length();
        c=0;
        if(len==n)
        {
            string com = v[i];

            for(int j=0;j<len;j++){

               if(str[j]=='.'){}
               else if(com[j] == str[j])
               {

               }else c=1;
            }
            if(c==0){
                cout<<com<<endl;
               return 0;
            }
        }
    }

return 0;
}
