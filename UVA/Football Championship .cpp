#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 205
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define umap unordered_map

int bid,flag[100];
umap<string,int>name;

struct info{
    int pt,dif,goal;
    string str;
    bool operator<(const info& nw) const
    {
        if(pt == nw.pt){
            if(dif == nw.dif){
                if(goal == nw.goal) return str < nw.str;
                return goal > nw.goal;
            }
            return dif > nw.dif;
        }
        return pt > nw.pt;
    }
};
info ar[100],tmp[100];

void pre(int in,int x,int y)
{
    for(int i=0;i<5;i++){
        tmp[i].pt = ar[i].pt;
        tmp[i].dif = ar[i].dif;
        tmp[i].goal = ar[i].goal;
        tmp[i].str = ar[i].str;
    }
    tmp[bid].pt += 3;
    tmp[bid].goal += x;
    tmp[bid].dif += x;
    tmp[bid].dif -= y;
    //
    tmp[in].goal += y;
    tmp[in].dif += y;
    tmp[in].dif -= x;
}
int main()
{
    int a,b,in=-1;
    string one,two,ch;
    for(int i=0;i<5;i++){
        cin>>one>>two>>ch;
        if(name[one]==0){
            name[one] = ++in;
            ar[in].str = one;
        }
        if(name[two]==0){
            name[two] = ++in;
            ar[in].str = two;
        }
        if(one=="BERLAND"){
            bid = name[one];
        }
        if(two=="BERLAND"){
            bid = name[two];
        }
        //
        if(one=="BERLAND") flag[name[two]] = 1;
        else if(two=="BERLAND") flag[name[one]] = 1;

        int num=0;
        for(int j=0;j<ch.length();j++){
            if(ch[j]==':'){
                a = num;
                num = 0;
                j++;
                for(;j<ch.length();j++){
                    num = (num*10) + ch[j]-'0';
                }
                b = num;
                break;
            }
            num = (num*10) + ch[j]-'0';
        }
        //cout<<a<<" "<<b<<endl;
        if(a>b) ar[name[one]].pt += 3;
        if(a==b){ ar[name[one]].pt++; ar[name[two]].pt++;}
        if(a<b) ar[name[two]].pt += 3;
        //
        ar[name[one]].goal += a;
        ar[name[one]].dif += a;
        ar[name[one]].dif -= b;
        //
        ar[name[two]].goal += b;
        ar[name[two]].dif += b;
        ar[name[two]].dif -= a;
        //
    }
    //
    int d = 1e5,fx,fy;
    for(int x = 1;x<=20;x++){
        for(int y=0;y<x;y++){
            for(int i=0;i<=in;i++){
                if(flag[i] || i==bid) continue;

                pre(i,x,y);
                sort(tmp,tmp+in+1);
                //
                if(tmp[0].str == "BERLAND" || tmp[1].str == "BERLAND"){
                    if(d > x-y){
                        fx = x; fy = y;
                        d = x - y;
                    }
                }
            }
        }
    }

    if(d==1e5) cout<<"IMPOSSIBLE"<<endl;
    else cout<<fx<<":"<<fy<<endl;

}
