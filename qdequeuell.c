#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
}*front=NULL,*rear=NULL,*temp,*newnode;
void enqueuefront(){
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->next=NULL;
	printf("Enter the data:");
	scanf("%d",&newnode->data);
	if (rear==NULL){
		front=newnode;
		front->prev=NULL;
		rear=newnode;
	}
	else{
		newnode->next=front;
		newnode->prev=NULL;
		front->prev=newnode;
		front=newnode;
	}
}
void enqueuerear(){
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->next=NULL;
	printf("Enter the data:");
	scanf("%d",&newnode->data);
	if (rear==NULL){
		front=newnode;
		front->prev=NULL;
		rear=newnode;
	}
	else{
		rear->next=newnode;
		newnode->prev=rear;
		rear=newnode;
	}
}
void dequeuefront(){
	if(front==NULL){
		printf("Queue is empty");
	}
	else{
		printf("Deleted element is %d\n",front->data);
		temp=front;
		front=front->next;
		front->prev=NULL;
		temp->next=NULL;
		free(temp);
	}
}
void dequeuerear(){
	if(front==NULL){
		printf("Queue is empty");
	}
	else{
		printf("Deleted element is %d\n",rear->data);
		temp=front;
		while(temp->next!=rear){
			temp=temp->next;
		}
		temp->next=NULL;
		rear->prev=NULL;
		rear=temp;
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
		printf("MENU\n1.Insert at front\n2.Insert at rear\n3.Delete at front\n4.Delete at rear\n5.Display\n6.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&z);
		switch(z){
			case 1:enqueuefront();
			break;
			case 2:enqueuerear();
			break;
			case 3:dequeuefront();
			break;
			case 4:dequeuerear();
			break;
			case 5:display();
			break;
			case 6:exit(0);
		}
		printf("Do you want to continue (1-yes,0-no):");
		scanf("%d",&c);
	}
	return 0;
}
