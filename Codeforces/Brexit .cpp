#include<bits/stdc++.h>
using namespace std;

#define MAX 200007
#define pr pair<int,int>

set<pr>st;
set<pr>::iterator it;
int c,p,me,l,org[MAX],leave[MAX];
vector<int>v[MAX];
struct st{
    int a,b;
}ar[MAX];

int main()
{
    scanf("%d %d %d %d", &c, &p, &me, &l);

    for(int i=0;i<p;i++){
        scanf("%d %d",&ar[i].a, &ar[i].b);
        org[ar[i].a]++;
        org[ar[i].b]++;

        st.insert(pr(ar[i].a,ar[i].b));
        v[ar[i].a].push_back(ar[i].b);
        v[ar[i].b].push_back(ar[i].a);
    }
    //cout<<org[3]<<endl;
    for(int i=0;i<MAX;i++){
        if(org[i]>0){
            //cout<<org[i]<<endl;
            leave[i] = org[i]/2;
            if(org[i]%2 !=0) leave[i]++;
        }
    }
    //cout<<endl<<"me: "<<me<<" "<<org[me]<<endl;
    queue<int>Q;
    Q.push(l);
    leave[l] = 0;
    while(!Q.empty()){
        int x = Q.front();
        //org[u] -= v[u].size();
        Q.pop();
        if(!leave[x]){
            for(int i=0;i<v[x].size();i++){
                int y = v[x][i];
                if(x>y){
                    it = st.find(pr(y,x));
                    if(it != st.end()){
                        leave[y]--;
                        st.erase(it);
                        if(leave[y]<=0) Q.push(y);
                    }
                }
                else{ //x<y
                    it = st.find(pr(x,y));
                    if(it != st.end()){
                        leave[y]--;
                        st.erase(it);
                        if(leave[y]<=0) Q.push(y);
                    }
                }
            }
        }
    }
    //cout<<leave[me]<<endl;
    if(leave[me]>0) cout<<"stay"<<endl;
    else cout<<"leave"<<endl;
}
