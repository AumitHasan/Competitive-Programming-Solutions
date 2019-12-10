#include<bits/stdc++.h>
using namespace std;

#define mx 100007

string a,s;

int main()
{
    cin>>a>>s;

    int len1 = a.length();
    int len2 = s.length();

    sort(s.begin(),s.end());

    int j=len2-1;
    for(int i=0;i<len1&&j>=0;i++)
    {
        if(s[j]>a[i]) a[i]=s[j--];
    }

    cout<<a<<endl;

return 0;
}
