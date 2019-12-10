
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

umap<string,int>mp;
umap<int,string>name;
umap<int,umap<string,int> > suff;
vector<string>v[10000];

int main()
{
    int n,in=0,entry,serial;
    string str,number;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str>>entry;

        if(!mp[str]){
            mp[str] = ++in;
            name[in] = str;
        }
        serial = mp[str];

        while(entry--){
            cin>>number;
            v[serial].push_back(number);
            for(int i=number.length();i>0;i--){
                string ch="";
                for(int j=i;j<number.length();j++){
                    ch += number[j];
                }
                //cout<<ch<<endl;
                if(ch.length()>0) suff[serial][ch] = 1;
            }
        }
    }
    //cout<<"FDLF "<<suff[1]["12"]<<endl;
    cout<<in<<endl;
    for(int i=1;i<=in;i++){
        set<string>st;
        for(int j=0;j<v[i].size();j++){
            if(!suff[i][v[i][j]]) st.insert(v[i][j]);
        }
        cout<<name[i]<<" "<<st.size();
        set<string>::iterator it;
        for(it=st.begin();it!=st.end();++it){
            cout<<" "<<*it;
        }
        cout<<endl;
    }

    return 0;
}
