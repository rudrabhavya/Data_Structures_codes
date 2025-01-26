//Quick sort
#include<stdio.h>
void printarray(int a[],int n){
	int i;
	printf("Sorted array\n");
	for (i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
void quicksort(int a[],int first,int last){
	int p,i,j,temp;
	i=first;
	j=last;
	p=first;
	if (i<j){
		//p=first;
	   while (i<j){
			while(a[i]<=a[p] && i<last)
			i++;
			while(a[j]>a[p])
			j--;
			if (i<j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	temp=a[j];
	a[j]=a[p];
	a[p]=temp;
	quicksort(a,first,j-1);
	quicksort(a,j+1,last);
}
//	printarray(a,n);
    
}
void main(){
	int a[100],n,i;
	printf("Enter the number of elements");
	scanf("%d",&n);
	printf("Enter the elements of the array");
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printarray(a,n);
}
