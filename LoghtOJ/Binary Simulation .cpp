#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define MAX 100007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

char str[MAX],ch;
int tree[MAX*3],ans;

void update(int node,int i,int j,int qs,int qe)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(i>j) return;

    if(tree[node] != 0){
        if(i != j){
            //cout<<node<<" "<<left<<" "<<right<<" "<<tree[node]<<" ij: "<<i<<" "<<j<<endl;
            tree[left] += tree[node];
            tree[right] += tree[node];
        }
        if(i != j) tree[node] = 0;
    }

    if(qs>j || qe<i) return;

    if(i>=qs && j<=qe){
        tree[node]++;

        if(i != j){
            tree[left] += tree[node];
            tree[right] += tree[node];
        }
        if(i != j) tree[node] = 0;
        return;
    }

    update(left,i,mid,qs,qe);
    update(right,mid+1,j,qs,qe);
}
void query(int node,int i,int j,int idx)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(tree[node] != 0){
        if(i != j){
            tree[left] += tree[node];
            tree[right] += tree[node];
        }
        if(i != j) tree[node] = 0;
    }

    if(idx>j || idx<i) return;

    if(idx==i && i==j){
        tree[node] = tree[node] % 2;
        ans = tree[node];
        return ;
    }

    query(left,i,mid,idx);
    query(right,mid+1,j,idx);
}
int main()
{
    int T,N=0,n,q,s,e;
    scanf("%d",&T);
    getchar();
    while(++N<=T){
        mem(tree,0);
        scanf("%s",str);
        n = strlen(str);

        printf("Case %d:\n",N);

        scanf("%d",&q);
        while(q--){
            getchar();
            scanf("%c",&ch);
            if(ch=='I'){ // update
                scanf("%d %d", &s, &e);
                update(1,1,n,s,e);
            }
            else{
                scanf("%d", &s);
                ans=0;
                query(1,1,n,s);
                //cout<<"node : ";
                //cout<<tree[8]<<" "<<tree[9]<<endl;
                //cout<<"ANS: "<<ans<<endl;
                if(ans){
                    if(str[s-1]=='1') ans = 0;
                    else ans = 1;
                }
                else{
                    ans = str[s-1]-'0';
                }
                printf("%d\n",ans);
            }
        }
    }
}
