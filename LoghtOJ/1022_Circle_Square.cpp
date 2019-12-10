#include <iostream>
#include<cmath>
#include<stdio.h>

using namespace std;
int main() {

	int t,i;
	double r,res,rr,pi;
	pi = 2*acos(0);
	cin>>t;
	for(i=1;i<=t;i++){

        res=rr=r=0;

		cin>>r;
		rr=(r*2)*(r*2);

		res = rr - (pi*r*r);

        printf("Case %d: %.2lf\n",i,res);

	}

	return 0;
}
