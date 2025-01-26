// Merge sort in C

#include <stdio.h>
void merge(int a[], int l, int m, int h) {
  int n1=m-l+1;
  int n2=h-m;
  int L[n1],M[n2],i,j,k;

  for (i=0;i<n1;i++)
    L[i]=a[l+i];
  for (j=0;j<n2;j++)
    M[j]=a[m+1+j];
  i=0;
  j=0;
  k=l;
  while (i<n1 && j<n2) {
    if (L[i] <= M[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = M[j];
    j++;
    k++;
  }
}
void mergeSort(int a[],int l,int h) {
  if (l<h) {
    int m=l+(h-l)/2,i;
    mergeSort(a,l,m);
    mergeSort(a,m+1,h);
    merge(a,l,m,h);
  }
}
void printArray(int a[], int n) {
	int i;
	for (i=0;i<n;i++)
    	printf("%d ", a[i]);
  printf("\n");
}
int main() {
  int a[100],n,i;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

  mergeSort(a,0,n-1);

  printf("Sorted array: \n");
  printArray(a, n);
}
