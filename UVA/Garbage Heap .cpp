#include<bits/stdc++.h>
using namespace std;



int main() {

	int T;
	cin>>T;
	while (T--) {
        int A,B,C;
        cin>>A>>B>>C;

        long long ar[A][B][C];

        for (int i=0;i<A;++i){
            for (int j=0;j<B;++j){
                for (int k=0;k<C;++k) {
                    //
                    long long g; cin>>g;
                    if (i>0) g+=ar[i-1][j][k];
                    if (j>0) g+=ar[i][j-1][k];
                    if (k>0) g+=ar[i][j][k-1];
                    if (i>0 && j>0) g-=ar[i-1][j-1][k];
                    if (j>0 && k>0) g-=ar[i][j-1][k-1];
                    if (i>0 && k>0) g-=ar[i-1][j][k-1];
                    if (i>0 && j>0 && k>0) g+=ar[i-1][j-1][k-1];
                    ar[i][j][k]=g;
                }
            }
        }

        long long max_val = -1e16;

        for (int i=0;i<A;++i){
            for (int j=0;j<B;++j)
                for (int k=0;k<C;++k)
                    //
                    for (int i1=i;i1<A;++i1){
                        for (int j1=j;j1<B;++j1){
                            for (int k1=k;k1<C;++k1){
                                long long res = ar[i1][j1][k1];
                                if (i>0) res -= ar[i-1][j1][k1];
                                if (j>0) res -= ar[i1][j-1][k1];
                                if (k>0) res -= ar[i1][j1][k-1];
                                if (i>0 && j>0) res += ar[i-1][j-1][k1];
                                if (j>0 && k>0) res += ar[i1][j-1][k-1];
                                if (i>0 && k>0) res += ar[i-1][j1][k-1];
                                if (i>0 && j>0 && k>0) res -= ar[i-1][j-1][k-1];
                                if (res > max_val) max_val = res;
                            }
                        }
                    }
                    //
        }
        cout<<max_val<<endl;
        if (T) cout<<endl;
	}
	return 0;
}
// help : // www.redgreencode.coar/three-diarensional-dynaaric-prograararing-uva-10755/
