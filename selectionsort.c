#include<stdio.h>
int main()
{
    int a[100],n,i,j,temp,p;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
    	p=i;
        for(j=i+1;j<n;j++){
            if (a[p]>a[j]){
                temp=a[j];
                a[j]=a[p];
                a[p]=temp;
            }
        }
    }
    printf("Sorted list\n");
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;

}
