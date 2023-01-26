#include<iostream>
#include<cmath>
#include<array>
using namespace std;
int fibbo(int n)
{
	if(n==0||n==1){
	return n;
	}
    int ans1=fibbo(n-1);
    int ans2=fibbo(n-2);
   // cout<<ans1+ans2<<" ";
    return ans1+ans2;
	//return fibbo(n-1)+fibbo(n-2);
}
float root(float n){
if(n==0||n==1){
	return n;
}
float y,z;
y=n;
z=(y+(n/y))/2;
while(abs(y-z)>=0.000001){
	y=z;
	z=(y+(n/y))/2;
}
return z;
}
int div(int n){
	if(n==1||n==0){
		return n;
	}
	//float rt=root((float)n);
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return i;
		}
	}
return 1;
}
int gcd(int x,int y){
	int min=(x>y)?x:y;
	for(int i=min;i>1;i--){
		if(x%i==0&&y%i==0){
			return i;
		}
	}
	return 1;
}
void prime(int n){
	int i=2;
	while(i<=sqrt(n)){
		if(n%i==0){
			cout<<i<<" ";
			n=n/i;

		}
		else{
			i++;
		}
	}
	cout<<n;
}
void mul(int x,int ar[],int ed){
	int carry=0;
	//int sz=sizeof(ar)/sizeof(ar[0]);
	for(int i=0;i<100;i++){
		int c=ar[i]*x;
        ar[i]=(c+carry)%10;
        carry=(c+carry)/10;

	}
}
void power(int x,int n){
	int ar[100];
	//{0,0,0,0,0,0,0,0,0,0};
	for(int i=1;i<100;i++){
		ar[i]=0;
	}
	ar[0]=x;
    int i=2;
	while(i<=n){
		mul(x,ar,0);
		i++;
	}
	for(int i=99;i>=0;i--){
		cout<<ar[i];
	}
}
int main(){
   int n=315;
	//int res=fibbo(n);
	//cout<<res;
//	int ans=gcd(56,456);
	//div(453);
//	cout<<ans;
   power(2,320);
	return 0;
	}