#include<bits/stdc++.h>
using namespace std;
#include<string>
map<string,int>m;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string ch;
        cin>>ch;

        int check = m[ch];

        if(check==0){
            m[ch]=1;
            cout<<"OK"<<endl;
        }
        else{
            int i = m[ch];

            string s;
            stringstream out;
            out << i;
            s = out.str();

            m[ch]++;
            ch+=s;
            cout<<ch<<endl;
            m[ch]=1;
        }
    }

return 0;
}
