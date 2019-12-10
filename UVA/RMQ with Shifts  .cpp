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

int n,q,ar[mx],tree[mx*3];
string str;

void build(int node,int i,int j)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(i==j){
        tree[node] = ar[i];
        return ;
    }
    build(left,i,mid);
    build(right,mid+1,j);

    tree[node] = min(tree[left],tree[right]);
}
void update(int node,int i,int j,int idx,int value)
{
    if(idx<i || idx>j) return ;
    if(i>=idx && j<=idx){
        tree[node] = value;
        return;
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    update(left,i,mid,idx,value);
    update(right,mid+1,j,idx,value);

    tree[node] = min(tree[left] , tree[right]);
}
int query(int node,int i,int j,int s,int e)
{
    if(i>e || j<s) return 1e9;
    if(i>=s && j<=e){
        return tree[node];
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    int p1 = query(left,i,mid,s,e);
    int p2 = query(right,mid+1,j,s,e);

    return min(p1 , p2);
}
void shift()
{
    int len = str.length()-1;
    int prev,num=0,c=0;

    for(int i=6;i<len;i++){
        if(str[i]==','){
            c++;
            if(c>1){
                swap(ar[prev],ar[num]);
                //cout<<ar[prev]<<" "<<ar[num]<<endl;
                update(1,1,n,prev,ar[prev]);
            }
            prev = num;
            num = 0;
            continue;
        }
        num = (num*10) + str[i]-'0';
    }
    swap(ar[prev],ar[num]);
    //cout<<ar[prev]<<" "<<ar[num]<<" "<<c<<endl;

    update(1,1,n,prev,ar[prev]);
    update(1,1,n,num,ar[num]);

}
int main()
{
    IO;

    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>ar[i];

    build(1,1,n);

    while(q--){
        cin>>str;
        if(str[0]=='q'){ //query
            int s=0,e=0,flag=0;

            for(int i=6;i<str.length()-1;i++){
                if(str[i]==','){
                    flag=true;
                    continue;
                }
                if(flag) e = (e*10) + str[i]-'0';
                else s = (s*10) + str[i]-'0';
            }
            //cout<<s<<" "<<e<<endl;
            cout<<query(1,1,n,s,e)<<endl;
        }
        else{ // shift
            shift();
        }
    }
    return 0;
}
