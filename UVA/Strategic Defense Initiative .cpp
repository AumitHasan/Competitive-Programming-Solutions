#include<bits/stdc++.h>
using namespace std;

#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

string str;
vector<int>v;
int tail[1000000],parent[1000000],id[1000000];

int call(int last){
    if(parent[last]!=-1)call(parent[last]);
    printf("%d\n",v[last]);
}
void LIS()
{
    int len = 0,last=0;
    tail[0]=1e9;
    for(int i=0;i<v.size();i++){
        int pos = lower_bound(tail,tail+len,v[i])-tail;
        //cout<<"p: "<<pos<<endl;
        tail[pos] = v[i];
        id[pos] = i;
        parent[i] = pos>0 ? id[pos-1] : -1;

        if(pos==len){
            len++;
            last=i;
        }
        else if(pos+1==len)last=i;
    }
    cout<<"Max hits: "<<len<<endl;
    call(last);
    for(int i=0;i<=v.size();i++) parent[i]=tail[i]=id[i]=0;
}
int cnv()
{
    int val=0;
    for(int i=0;i<str.length();i++){
        val = (val*10) + str[i]-'0';
    }
    return val;
}
int main()
{


    int T,N=0,n;
    scanf("%d",&T);
    getchar();
    while(getline(cin,str)){
        if(str.length()==0){
            //cout<<"f";
            N++;
            if(N==1) continue;
            if(N>2) v.erase(v.begin());
            LIS();
            cout<<endl;
            v.clear();
        }
        n = cnv();
        v.push_back(n);
    }
    //cout<<"v: "<<v.size()<<endl;
    v.erase(v.begin());
    LIS();

}
