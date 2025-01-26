#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}*new,*front=NULL,*rear=NULL,*temp;
void enqueue(){
	int data,c=1;
		new=(struct node*)malloc(sizeof(struct node));
		printf("enter data\n");
		scanf("%d",&data);
		new->data=data;
		new->next=front;
		if(rear==NULL){
			rear=new;
			front=new;
		}
		else{
			rear->next=new;
			new->next=front;
			rear=new;
		}
		
	}
void display(){
	temp=front;
	if(front==NULL){
		printf("queue is empty\n");
	}
	else{
		printf("the linked list elments are:\t");
		while(temp->next!=front){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("%d\t",temp->data);
	}
}
void dequeue(){
	if(front==NULL){
		printf("queue is empty\n");
	}
	else{
		printf("the deleted element is %d",front->data);
		temp=front;
		front=front->next;
		rear->next=front;
		temp->next=NULL;
		free(temp);
	}
}
int main(){
	int c=1,a;
	while(c){
	printf("MENU\n1.Insert\n2.delete\n3.display\n");
	printf("enter the choice\n");
	scanf("%d",&a);
		switch(a){
			case 1:enqueue();
			break;
			case 2:dequeue();
			break;
			case 3:display();
			break;
			default:exit(0);
		}
		printf("do you want to continue 1-yes/0-n0\n");
		scanf("%d",&c);
	}			
}

