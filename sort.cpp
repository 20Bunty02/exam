#include<iostream>
using namespace std;
void srt(int ar[],int st,int mid,int end);
void bubble(int ar[],int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(ar[j]>ar[j+1]){
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
	cout<<"\nsorted array using bubble sort ";
	for(int i=0;i<n;i++){
		cout<<ar[i];
	}
}
void selection(int ar[],int n){
	int index;
	for(int i=0;i<n-1;i++){
		int el=ar[i],index=i;
		for(int j=i;j<n-1;j++){
			if(ar[j+1]<=el){
              el=ar[j+1];
              index=j+1;
			}
		}
		
		ar[index]=ar[i];
        ar[i]=el;
        }
	
	cout<<"\nsorted array using selection sort ";
	for(int i=0;i<n;i++){
		cout<<ar[i];
	}
}
void insertion(int ar[],int n){
	for(int i=0;i<n-1;i++){
		int el=ar[i+1],ind=i+1;
		for(int j=i;j>=0;j--){
			if(ar[j]>el){
				ar[j+1]=ar[j];
				ind=j;
			}
		}
		ar[ind]=el;
	}
	cout<<"\nsorted array using insertion sort ";
    for(int i=0;i<n;i++){
    	cout<<ar[i];
    }
}
void merge(int ar[],int st,int end){
	if(st>=end){

		return;
	}
	int mid=st+(end-st)/2;
	merge(ar,st,mid);
	merge(ar,mid+1,end);
	srt(ar,st,mid,end);
}
void srt(int ar[],int st,int mid,int end){
	int i=st,j=mid+1,k=0;
	int temp[end-st+1];
	while(i<=mid&&j<=end){
		if(ar[i]<=ar[j]){
			temp[k++]=ar[i++];
		}
		else{temp[k++]=ar[j++];}
	}
	while(i<=mid){
		temp[k++]=ar[i++];
	}
	while(j<=end){
		temp[k++]=ar[j++];
	}
	for(int l=0,m=st;l<k;l++,m++){
		ar[m]=temp[l];
	}
}
void quick(int ar[],int st,int end,int p){
	if(st>=end){
		return;
	}
	int temp,j=st-1;
	for(int i=st;i<=end;i++){
		if(ar[i]<=ar[p]){
			j++;
			temp=ar[i];
			ar[i]=ar[j];
            ar[j]=temp;
		}
	}
	quick(ar,st,j-1,j-1);
	quick(ar,j+1,end,end);
}
int main(){
	int n;
	cout<<"enter the value of n ";
	cin>>n;
	int ar[n];
	cout<<"enter the elements to be stored ";
	for(int i=0;i<n;i++){
     cin>>ar[i];
	}
//	bubble(ar,n);
//	selection(ar,n);
	//insertion(ar,n);
	//merge(ar,0,n-1);
	quick(ar,0,n-1,n-1);
	for(int i=0;i<n;i++){
    	cout<<ar[i];
    }
}