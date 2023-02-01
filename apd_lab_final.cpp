#include<iostream>
#include<math.h>
#include<string>
#include<time.h>
using namespace std;
int factorial_using_recursion(int n);

//q28,q29,q30 sorting questions


//question 27

void mergesort(int ar[],int start,int mid,int end){
	int i=start;
	int j=mid+1;
	int temp[end-start+1];
	int ind=0;
	while(i<=mid&&j<=end){
      if(ar[i]<ar[j]){
         temp[ind++]=ar[i++];
      }
      else{
      	temp[ind++]=ar[j++];
      }
	}
	while(i<=mid){
		temp[ind++]=ar[i++];
	}
	while(j<=end){
		temp[ind++]=ar[j++];
	}
	int l=0;
	for(i=start;l<ind;l++){
		ar[i++]=temp[l];
	}
}

void merge(int ar[],int start,int end){
	if(start>=end){
      return;
	}
	int mid=start+(end-start)/2;
     merge(ar,start,mid);
     merge(ar,mid+1,end);
     mergesort(ar,start,mid,end);
}

void q27(){
	int ar[]={1,8,3,9,4,7,0,2};
	int n=sizeof(ar)/sizeof(ar[1]);
	merge(ar,0,n-1);
	cout<<"array after merge sort is \n";
	for(int i=0;i<n;i++){
		cout<<ar[i];
	}
}

//question 26

//question 25

void q25(){
	int ar[]={1,2,3,4,5,6,7,8};
    int size=sizeof(ar)/sizeof(ar[0]);
	int even[size/2];
	int osize=size/2;
	if(size%2!=0){
		osize++;
	}
	int odd[osize];
	int j=0,k=0;
	for(int i=0;i<size;i++){
		if((i+1)%2==0){
			even[j++]=ar[i];
		}
		else{odd[k++]=ar[i];}
	}
	for(int i=0;i<k;i++){
		ar[i]=odd[i];
	}
	int l=0;
	for(int i=k;i<size;i++){
		ar[i]=even[l++];
	}
	for(int i=0;i<size;i++){
		cout<<ar[i]<<" ";
	}
}

//question 24

void q24(){
	int ar[]={1,2,6,8,3,6,9,4,7,24,46,54,7,6,6,5,3,5,4,45,4,5,4,5,34,23,43,4,3,4,4,56,45,6,5,45,6,6,5,75,6,4,54,53,4};
int cnt[100]={0};
	for(int i=0;i<100;i++){
		cnt[i]=0;
	}
	for(int i=0;i<sizeof(ar)/sizeof(ar[0]);i++){
		cnt[ar[i]]++;
	}
	cout<<"numbers with frequencies ";
	for(int i=0;i<100;i++){
		if(cnt[i]!=0){
			cout<<i<<" "<<cnt[i]<<endl;
		}
	}
}

//question 23

void q23(){
	int ar[]={1,2,2,3,7,7,9,10,12,12};
	int temp[10];
	temp[0]=ar[0];
	int j=1;
	for(int i=1;i<10;i++){
		if(ar[i]!=ar[i-1]){
			temp[j++]=ar[i];
		}
	}
	cout<<"array after removing duplicate ";
	for(int i=0;i<j;i++){
		cout<<temp[i]<<" ";
	}
}


//question 22 - easy


//question 21

void q21(){
	int r1,c1,r2,c2;
	cout<<"enter the dimension of matrix 1 ";
	cin>>r1>>c1;
	cout<<"enter the dimension of matrix 2 ";
	cin>>r2>>c2;
	if(c1!=r2){
		cout<<"multiplication can not be performed ";
		return;
	}
	int ar1[r1][c1],ar2[r2][c2];
	cout<<"enter the values in matrix 1";
	for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			cin>>ar1[i][j];
		}
	}
	cout<<"enter the value in matrix 2 ";
	for(int i=0;i<r2;i++){
		for(int j=0;j<c2;j++){
			cin>>ar2[i][j];
		}
	}
   int mul[r1][c2];
   for(int i=0;i<r1;i++){
       for(int j=0;j<c2;j++){
           mul[i][j]=0;
       }
   }
   for(int i=0;i<r1;i++){
   	for(int j=0;j<c2;j++){
   		for(int k=0;k<c1;k++){
   			mul[i][j]+=(ar1[i][k]*ar2[k][j]);
   		}
   	}
   }
cout<<"the result is \n";
for(int i=0;i<r1;i++){
	for(int j=0;j<c2;j++){
		cout<<mul[i][j]<<" ";
	}
	cout<<endl;
}

}

//question 20
void linear_search(int ar[],int n,int el){
	for(int i=0;i<n;i++){
		if(ar[i]==el){
			cout<<"\nelement found at index "<<i;
		}
	}
	cout<<"\nelemen not found "; 
}

void binary_search(int ar[],int n,int el){
	int start=0,end=n-1;
	int mid;
	while(start<=end){
     mid=start+(end-start)/2;
     if(ar[mid]==el){
     	cout<<"\nelemnt found at index "<<mid;
     	return;
     }
     if(ar[mid]<el){
     	start=mid+1;
     }
     else{
     	end=mid-1;
     }
	}
	cout<<"\nelement not found ";
}

void q20(){
	int n,el;
	cout<<"enter the size of array ";
	cin>>n;
	int ar[n];
	cout<<"enter the values in array ";
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
    cout<<"enter elements to be searched ";
    cin>>el;
    cout<<"searching using linear search ";
    clock_t start,end;
    start=clock();
    linear_search(ar,n,el);
    end=clock();
    cout<<"\ntotal time taken by linear search is ";
    cout<<(float)(end-start)/CLOCKS_PER_SEC;
    cout<<"\nsearching using inary search ";
    start=clock();
    binary_search(ar,n,el);
    end=clock();
    cout<<"\ntotal time taken by binary search ";
    cout<<(float)(end-start)/CLOCKS_PER_SEC;


}

//question 19 - easy 

//question 18
void mul(int ar[],int x){
	int sum;
	int carry=0; 
	for(int i=0;i<100;i++){
    sum=ar[i]*x;
    ar[i]=(carry+sum)%10;
    carry=(carry+sum)/10;
	}
}

void q18(){
	int x,n;
	cout<<"enter the value of x ";
	cin>>x;
	cout<<"enter the value of n ";
	cin>>n;
	int ar[100];
	for(int i=0;i<100;i++){
		ar[i]=0;
	}
	ar[0]=x;
	int i=2;
	while(i<=n){
	mul(ar,x);
	i++;
}
	cout<<"the answer is ";
	for(int i=99;i>=0;i--){
		cout<<ar[i];
	}  
}


//question 17

void q17(){
	int x0,x1,a,b,m,n;
	cout<<"enter the value of x0 ";
	cin>>x0;
	cout<<"enter the value of a and b ";
	cin>>a>>b;
	cout<<"enter the value of m ";
	cin>>m;
	cout<<"enter the value of n ";
	cin>>n;
	for(int i=1;i<=n;i++){
    x1=(a*x0+b)%m;
    cout<<x1<<" ";
    x0=x1;
	}
}

//question 16
bool isprime(int n){
	if(n==1){
		return true;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
return true;
}

void q16(){
	int n;
	cout<<"enter a number ";
	cin>>n;
	int i=2;
	while(n>0&&i<=sqrt(n)){
		if(isprime(i)){
			if(n%i==0){
				cout<<i<<" ";
				n=n/i;
				continue;
			}
		}
	   i++;
	}

}

//question 15 - easy

//question 14

void q14(){
	int n;
	cout<<"how many numbers you want to enter ";
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	int max=ar[0];
	for(int i=1;i<n;i++){
		if(ar[i]>max){
			max=ar[i];
		}
	}
	cout<<"maximum of given numbers is "<<max;
}

//question 13

void q13(){
	int marks[5],total=0;float percent;
	cout<<"enter marks (>33)";
	for(int i=0;i<5;i++){
		cin>>marks[i];
		total+=marks[i];
	}
  percent=(float)total/5;
  cout<<"total marks "<<total;
  cout<<"\npercentage "<<percent;

}

//question 12

void q12(){
	char ar[]="helloiam";
	 char ch[]="eoa";
	 int size=sizeof(ar)/sizeof(ar[0]);
	// cout<<size;
	 int j=0;
	 for(int i=0;i<size;i++){
       
       if(ar[i]==ch[j]){
         j++;
       }
	 }
	
	 if(j>=sizeof(ch)/sizeof(ch[0])){
       	cout<<"\nsubstring is present in the string ";
      
       }
       else{
       	cout<<"\nsubstring is not present ";
       }
}

//question 11

void q11(){
	int n;
	cout<<"enter the length of text ";
	cin>>n;
	char ar[n];
	int cnt[26]={0};
	cout<<"enter characters ";
	for(int i=0;i<n;i++){
		cin>>ar[i];
		cnt[ar[i]-'a']++;
	}
	cout<<"duplicate letter and their frequencies "<<endl;
	for(int i=0;i<26;i++){
     if(cnt[i]!=0){
     	cout<<(char)(i+'a')<<"   "<<cnt[i]<<endl;
     }
	}
}

//question 10 = easy

//question 9

void q9(){
int n;
cout<<"enter the size of array ";
cin>>n;
char ar[n];
char rev[n];
cout<<"enter characters ";
for(int i=0;i<n;i++){
	cin>>ar[i];
} 
for(int i=0,j=n-1;i<n&&j>=0;i++,j--){
	rev[i]=ar[j];
}
int ch=0;
cout<<"reversed array is ";
for(int i=0;i<n;i++){
	if(ar[i]!=rev[i]){
		ch=-1;
	}
	cout<<rev[i];
}
if(ch==-1){
	cout<<"\nstring is not palindrom ";
}
else{
	cout<<"\nstring is palindrom ";
}
}

//question 8

void q8(){
	int n,rev=0;
	cout<<"enter the number ";
	cin>>n;
	int copy=n;
	while(n>0){
      rev=rev*10+n%10;
      n/=10;
	}
	cout<<"the reversed number is "<<rev<<endl;
	if(copy==rev){
		cout<<"number is palindrom ";
	}
	else{
		cout<<"number is not palindrom ";
	}

}

//question 7

void q7(){
	int n,m;
	cout<<"enter two numbers ";
    cin>>n>>m;
    int temp,max,min;
    if(n>=m){
    	max=n;
    	min=m;
    }
    else{max=m;min=n;}
    while(max%min!=0){
     temp=max%min;
     max=min;
     min=temp;
    }
    cout<<"the answer is "<<min;
}

//question 6

void q6(){
	float n;
	cout<<"enter number ";
	cin>>n;
	float y,z;
	y=n;
	z=(y+n/y)/2;
	while(abs(y-z)>0.000001){
		y=z;
		z=(y+n/y)/2;
	}
	cout<<"the answer is "<<z;
}

//qustion 5

void q5(){
	float x,n;
	cout<<"enter the value of x ";
	cin>>x;
	cout<<"enter the value of n ";
	cin>>n;
	x=x*(3.14/180);
	int sign=-1;
	int ans=0;
	for(int i=1;i<=n;i+=2){
     ans=ans+(sign*-1)*(pow(x,i)/factorial_using_recursion(i));
	}
	cout<<"the answer is "<<ans;
}
//question 4

void q4(){
	int n;
cout<<"enter the value ";
cin>>n;
int fact=factorial_using_recursion(n);
float ans=1/(float)fact;
cout<<"the answer is "<<ans;
}

//qustion 3

void fibbo_using_iteration(int n){
	int n3,n1=0,n2=1;
	for(int i=1;i<n;i++){
		n3=n1+n2;
		n1=n2;
		n2=n3;
	}
	cout<<"the answer is "<<n3<<endl;
}
int fibbo_using_recursion(int n){
	if(n==0||n==1){
		return n;
	}
	return fibbo_using_recursion(n-1)+fibbo_using_recursion(n-2);
}
void q3(){
	int n;
	cout<<"enter the number ";
	cin>>n;
	fibbo_using_iteration(n);
	int ans=fibbo_using_recursion(n);
	cout<<"the answer is "<<ans;
}

//question 2

void factorial_using_iteration(int n){
	int ans=1;
	while(n>0){
		ans=ans*n;
		n--;
	}
	cout<<"factorial of the number is "<<ans;
}
int factorial_using_recursion(int n){
	if(n==0||n==1){
		return 1;
	}
	return n*factorial_using_recursion(n-1);
}
void q2(){
int n;
cout<<"enter the number ";
cin>>n;
factorial_using_iteration(n);
int ans=factorial_using_recursion(n);
cout<<"\nfactorial of the number is "<<ans;
}

//question 1

void q1()
{ int n;
	cout<<"enter how many digts you want to enter ";
	cin>>n;
	int ar[n];
	int sum=0;
	cout<<"enter the digits ";
	for(int i=0;i<n;i++){
	cin>>ar[i];
	sum=sum*10+ar[i];
	}
	cout<<"the number is "<<sum;
	
}
int main(){
	
	q27();
}
