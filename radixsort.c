#include<stdio.h>
int getmax(int a[],int n){
	int max,i;
	max=a[0];
	for (i=1;i<n;i++){
		if (max<a[i]){
			max=a[i];
		}
	}
	return max;
}
void countingsort(int a[],int n,int place){
	int c[10],temp[n],i;
	for (i=1;i<10;i++){
		c[i]=0;
	}
	for (i=0;i<n;i++){
		c[(a[i]/place)%10]=c[(a[i]/place)%10]+1;
	}
	printf(c);
	for (i=1;i<n;i++){
		c[i]=c[i-1]+c[i];
	}
	printf(c);
	for (i=n-1;i>=0;i--){
		temp[c[(a[i]/place)%10]]=a[i];
		c[(a[i]/place)%10]=c[(a[i]/place)%10]-1;
		printf(c);	
	}
	for (i=0;i<n;i++){
		temp[i]=a[i];
	}
	for (i=0;i<n;i++){
		printf(temp[i]," ");
	}
}
void radixsort(int a[],int n){
	int p,max,i;
	max=getmax(a,n);
	printf(max);
	for (p=1;max/p>0;p=p*10){
		countingsort(a,n,p);
	}
	for (i=0;i<n;i++){
 	printf("%d ",a[i]);
 }
}
void main(){
	int n,a[100],i;
	printf("Enter the size of the array");
	scanf("%d",&n);
	printf("Enter elements of the array");
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	radixsort(a,n);
}
