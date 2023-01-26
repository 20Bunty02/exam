#include<iostream>
using namespace std;
void fibbo(){
	int a=0,b=1;
	int c;
	int n=10;
	//c=a+b;
	for(int i=1;i<10;i++){
    c=b+a;
    cout<<c<<" ";
    a=b;
    b=c;
	}
}
void mul(int ar1[][2],int ar2[][2],int r1,int c,int c2){
	int ar[r1][c2];
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			ar[i][j]=0;
		}
	}
	for(int i=0;i<r1;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<c;k++){
				ar[i][j]+=ar1[i][k]*ar2[k][j];
			}
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int ar1[2][2]={{1,1},{2,2}};
	int ar2[2][2]={{1,1},{2,2}};
	mul(ar1,ar2,2,2,2);
	//return 0;
}