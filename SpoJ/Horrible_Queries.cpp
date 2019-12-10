#include<bits/stdc++.h>
using namespace std;

#define mx 100007
#define ll unsigned long long int

struct info{
    ll sum,prop;
}tree[3*mx];


void update(ll node,ll i,ll j,ll a,ll b,ll val)
{
    if(a>j || b<i) return ;
    if(i>=a&&j<=b){
        tree[node].sum += (j-i+1)*val;
        tree[node].prop += val;
        return ;
    }
    ll mid = (i+j)/2;
    ll left = node*2;
    ll right = left+1;

    update(left,i,mid,a,b,val);
    update(right,mid+1,j,a,b,val);

    tree[node].sum = tree[left].sum + tree[right].sum + (j-i+1)*tree[node].prop;
}
ll query(ll node,ll i,ll j,ll a,ll b,ll carry)
{
    if(a>j || b<i) return 0;
    if(i>=a&&j<=b){
        return tree[node].sum + carry*(j-i+1);
    }

    ll mid = (i+j)/2;
    ll left = node*2;
    ll right = left+1;

    ll p1 = query(left,i,mid,a,b, carry+tree[node].prop);
    ll p2 = query(right,mid+1,j,a,b, carry+tree[node].prop);

    return p1+p2;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(tree,0,sizeof(tree));
        //cout<<tree[5].sum<<" "<<tree[5].prop<<endl;
        ll n,c,num;
        cin>>n>>c;
        //initial(1,1,n);

        while(c--)
        {
            cin>>num;
            ll i,j,v;
            if(num==0){
                cin>>i>>j>>v;
                update(1,1,n,i,j,v);
            }
            else if(num==1){
                cin>>i>>j;
                cout<<query(1,1,n,i,j,0)<<endl;
            }
        }
    }

return 0;
}
