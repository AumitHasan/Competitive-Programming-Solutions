#include<iostream>
using namespace std;

int main() {

	long long n,x,i,y,z,c,total=0,f;
	x=y=c=z=0;
	cin>>n;
	long long a[n],b[n];

	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		if(c==0 || b[i]<c)
			c=b[i];
		x+=a[i];

	}
    f=b[0];
	for(i=0;i<n;i++)
	{
		if(b[i]==c)
		{
			total+=(x*c);
			break;
		}
	    else{
            if(b[i]<f)
                f=b[i];

            if(b[i]>b[i-1] && i>0)
                total+=(a[i]*f);

            else
                total+=(a[i]*f);

	    }

	    x-=a[i];
	}

	cout<<total<<endl;

return 0;
}
