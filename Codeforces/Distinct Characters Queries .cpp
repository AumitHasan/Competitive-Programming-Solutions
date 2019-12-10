#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

//int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; // 4 Direction
//int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1};  // 8 Direction
//int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; // Knight Direction
//int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; // Hexagonal Direction

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)          scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     MAX3(a,b,c)             max(a,max(b,c))
#define     MAX4(a,b,c,d)           max(max(a,b),max(c,d))
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      100007

////

int tree[27][mx*3];
string str;

void update(int node, int i, int j, int idx, int val,int chr)
{
    if(idx>j || idx<i) return;
    if(idx==j && idx==i){
        //cout<<node<<" x "<<chr<<" "<<idx<<endl;
        tree[chr][node] += val;
        return;
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    update(left,i,mid,idx,val,chr);
    update(right,mid+1,j,idx,val,chr);

    tree[chr][node] = tree[chr][left] + tree[chr][right];
}
int query(int node, int i,int j,int l,int r,int chr)
{
    if(i>r || j<l) return 0;
    if(i>=l && j<=r) return tree[chr][node];

    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    int x = query(left,i,mid,l,r,chr);
    int y = query(right,mid+1,j,l,r,chr);

    return x + y;
}
int main()
{
    IO;

    cin>>str;
    for(int i=0;i<str.size();i++){
        int tmp = str[i]-'a'+1;
        //cout<<tmp<<" "<<i+1<<endl;
        update(1,1,str.size(),i+1,1,tmp);
    }
//    cout<<query(1,1,str.size(),1,str.size(),2)<<endl;
//    cout<<"XX: "<<tree[2][3]<<endl;
//    for(int i=1;i<=10;i++) cout<<tree[2][i]<<" ";

    int q,type,l,r,pos,c,ans;
    char ch;
    cin>>q;
    while(q--){
        cin>>type;
        if(type==1){
            cin>>pos>>ch;
            update(1,1,str.size(),pos,-1,str[pos-1]-'a'+1);
            str[pos-1] = ch;
            update(1,1,str.size(),pos,1,ch-'a'+1);

//            ans = 0;
//            l = 1,r = str.size();
//            for(int i=1;i<=3;i++){
//                c = query(1,1,str.size(),l,r,i);
//                cout<<i<<" X "<<c<<endl;
//                if(c) ans++;
//            }
//            cout<<ans<<endl;
//            cout<<"XX: "<<tree[2][3]<<endl;
        }
        else{
            ans = 0;
            cin>>l>>r;
            for(int i=1;i<=26;i++){
                c = query(1,1,str.size(),l,r,i);
                //cout<<i<<" q "<<c<<endl;
                if(c) ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
