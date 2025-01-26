#include<stdio.h>
int main(){
	int n,a[100],temp,i,j;
	printf("Enter the number of elements of the array");
	scanf("%d",&n);
	printf("Enter elements of the array");
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (i=1;i<n;i++){
		temp=a[i];
		for (j=i;j>0 &&a[j-1]>temp;j--){
			a[j]=a[j-1];
		}
		a[j]=temp;
	}
	for (i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
