#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head,*tail,*newnode,*temp;
struct node *head=NULL;
struct node *tail=NULL;
void traverse(){
	int c1=0;
	temp=head;
	printf("the data is:");
	while(temp!=NULL)
	{
	    printf("%d  ",temp->data);
		temp=temp->next;
		c1++;
	    
	}
	printf("count %d",c1);
}
void deletion(){
	int z,p,i;
	if (head==NULL){
		printf("Empty");
		return;
	}
	printf("Delete element at 1.beginning 2.ending 3 specific position:");
	scanf("%d",&z);
	if (z==1){
		temp=head;
		head=head->next;
		temp->next=NULL;
	}
	else if(z==2){
		temp=head;
		while(temp->next!=tail){
			temp=temp->next;
		}
		temp->next=NULL;
		tail=temp;
	}
	else{
		printf("Enter position");
		scanf("%d",&p);
		temp=head;
		for (i=0;i<p-1;i++){
			temp=temp->next;
		}
		temp->next=temp->next->next;
		temp->next->next=NULL;
	}
}
void search(){
	int l=0,key;
	temp=head;printf("Enter element:");
	scanf("%d",&key);
	while ((temp->data!=key) &&(temp->next!=NULL)){
		temp=temp->next;
    }
    if ((temp->next==NULL)&&(temp->data!=key)){
    	printf("Element is not found");
	}
	else{
		printf("Element is found at location %d",l);
	}
}
int insertion(){
	int z,p,i,c=0;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if (head==NULL){
		head=newnode;
		tail=newnode;
		return;
	}
	printf("\nEnter 1.beginning 2.ending 3specific position");
	scanf("%d",&z);
	if (z==1){
		newnode->next=head;
		head=newnode;
	}
	else if (z==2){
		tail->next=newnode;
		tail=newnode;
	}
	else{
		printf("Enter position");
		scanf("%d",&p);
		temp=head;
		for (i=0;i<p-1;i++){
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}


void main(){
	int x=1,a;
	struct node *head;
	head=NULL;
	while(x==1){
		printf("1.Insert\n");
		printf("2.delete\n");
		printf("3.Search\n");
		printf("4.Display\n");
		printf("5.Exit\n");
		printf("Enter choice:");
		scanf("%d",&a);
		switch(a){
			case 1:insertion();
			break;
			case 2:deletion();
			break;
			case 3:search();
			break;
			case 4:traverse();
			break;
			case 5:exit(0);
		}
	printf("Do you want to continue the process yes-1,no-0");
		scanf("%d",&x);	
	}
}
