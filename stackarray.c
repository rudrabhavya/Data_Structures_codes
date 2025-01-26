#include<stdio.h>
#include<stdlib.h>
int top=-1,a[10],s=4;
int isfull(){
	return(top==s-1);
}
int isempty(){
	return(top==-1);
}
void push(){
	int z;
	if (isfull()){
		printf("Full");
	}
	else{
		printf("Enter element:");
		scanf("%d",&z);
		top=top+1;
		a[top]=z;
    }
}
void pop(){
	if (isempty()){
		printf("Empty");
	}
	else{
		printf("%d-element poped",a[top]);
		top=top-1;
	}
}
void display(){
	int i;
	for (i=0;i<=top;i++){
		printf("%d ",a[i]);
	}
}
void main(){
	int n,c=1;
	while(c==1){
		printf("MENU\n1.push()\n2.pop()\n3.isempty()\n4.isfull()\n5.top\n6.display()\n7.exit\n");
		printf("Enter your choice: ");
		scanf("%d",&n);
		switch(n){
			case 1:push();
			break;
			case 2:pop();
			break;
			case 6:display();break;
			case 3:if (isempty()){
				printf("Stack is empty");}
				else{
					printf("Stack is not empty");
				}
				break;
			case 4:if (isfull()){
				printf("Stack is full");}
				else{
					printf("Stack is not full");
				}
				break;
			case 5:printf("Top: %d",a[top]);
			break;
			case 7:exit(0);
        }
        printf("Do you want to continue:");
        	scanf("%d",&c);
	}
}
