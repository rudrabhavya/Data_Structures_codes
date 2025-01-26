#include<stdio.h>
#include<stdlib.h>
int s,q[5],front=-1,rear=-1,data;
void enqueue(){
	if (rear==s-1){
		printf("Overflow\n");
	}
	else{
		printf("Enter the data:");
		scanf("%d",&data);
		if(front==-1){
			front++;
		}
		rear++;
		q[rear]=data;
	}
}
void dequeue(){
	if (rear==-1 ||front>rear){
		printf("Queue is empty\n");
	}
	else{
		printf("The deleted data is %d\n",q[front]);
		front=front+1;
	}
}
void display(){
	int i;
		if (rear==-1 ||front>rear){
		printf("Queue is empty");
	}
	for(i=front;i<=rear;i++){
		printf("%d  ",q[i]);
	}
	printf("\n");
}
int main(){
	int c=1,z;
	printf("Enter size of queue:");
	scanf("%d",&s);
	while(c==1){
		printf("MENU\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&z);
		switch(z){
			case 1:enqueue();
			break;
			case 2:dequeue();
			break;
			case 3:display();
			break;
			case 4:exit(0);
		}
		printf("Do you want to continue (1-yes,0-no):");
		scanf("%d",&c);
	}
	return 0;
}
