#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL,*temp,*newnode;
void enqueue(){
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->next=NULL;
	printf("Enter the data:");
	scanf("%d",&newnode->data);
	if (rear==NULL){
		front=newnode;
		rear=newnode;
	}
	else{
		rear->next=newnode;
		rear=newnode;
	}
}
void dequeue(){
	if(front==NULL){
		printf("Queue is empty\n");
	}
	else{
		printf("Deleted element is %d\n",front->data);
		temp=front;
		front=front->next;
		temp->next=NULL;
		free(temp);
	}
}
void display(){
	if(front==NULL){
		printf("Queue is empty");
	}
	temp=front;
	while(temp!=NULL){
		printf("%d  ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	int c=1,z;
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
			default:printf("Invalid number");
		}
		printf("Do you want to continue (1-yes,0-no):");
		scanf("%d",&c);
	}
	return 0;
}
