//IGNORE DELETE AND SEARCH METHODS
#include<stdio.h>
#define size 10
#include<stdlib.h>
int arr[size],i,a=0;
void insert(int value){ 
int i;
    int key = value % size;
    if(arr[key] == -1){   
        arr[key] = value;
    }
    else{   
        for (i=1;i<10;i++){
        	key=(value+i*i)%size;
        	if (arr[key]==-1){
        	arr[key]=value;
        	return;
        	}
		}
    }
}
void del(int value){
    int key = value % size;
    if(arr[key] == value)
        arr[key] = -1;
    else
        printf("%d not present in the hash table\n",value);
}
void search(int value){
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}
void print(){
    for(i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}
int main(){
	int c=1,z,n,val;
	for(i = 0; i < size; i++)
        arr[i] = -1;
	while(c==1){
		printf("MENU\n1.insert\n2.delete\n3.search\n4.display\n5.exit\nEnter your choice:");
		scanf("%d",&z);
		switch(z){
			case 1:printf("enter the number of elements\n");
			scanf("%d",&n);
			printf("enter the elements\n");
			for(i=0;i<n;i++){
				scanf("%d",&val);
				insert(val);
			}
			break;
			case 2:printf("enter the value to be deleted\n");
			scanf("%d",&val);
			del(val);
			break;
			case 3:printf("enter the value to be searcched\n");
			scanf("%d",&val);
			search(val);
			break;
			case 4:printf("The hash table is\n");
			print();
			break;
			case 5: exit(0);
			break;
		}
		printf("Do you want to continue:");
		scanf("%d",&c);
	}
    return 0;
}
