#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
}*head,*tail,*newnode,*temp;
struct node *head=NULL;
struct node *tail=NULL;

void traverse(){
	int c1=0;
	if(head==NULL) {
		printf("List is empty\n");
        return;
        }
    else{
	temp=head;
	printf("the data is:");
	while(temp!=tail)
	{
	    printf("%d  ",temp->data);
		temp=temp->next;
		c1++;
	    
	}
	printf("%d  ",temp->data);
	printf("count %d",c1+1);
    }
   
    
}
void deletion(){
	int z,p,i;
	struct node *temp1;
	if (head==NULL){
			printf("The list is empty\n");
		}
	printf("Delete element at 1.beginning 2.ending 3 specific position:");
	scanf("%d",&z);
	if (z==1){
		temp=head;
		head=head->next;
		head->prev=tail;
		temp->next=NULL;
		return;
	}
	if(z==2){
		temp=head;
		while(temp->next!=tail){
			temp=temp->next;
		}
		temp->next=head;
		tail->prev=NULL;
		tail=temp;
		return;
	}
	if (z==3){
		printf("Enter position");
		scanf("%d",&p);
		temp=head;
		for (i=0;i<p-1;i++){
			temp=temp->next;
		}
		temp->next->next->prev=temp;
		temp->next=temp->next->next;
		temp->next->next=NULL;
	}
}
void search(){
	int l=0,key;
	struct node *temp1;
	temp1=head;
	printf("Enter element to be searched:");
	scanf("%d",&key);
	if (head==NULL){
			printf("The list is empty\n");
		}
	while ((temp1->data!=key) &&(temp1->next!=head)){
		temp1=temp1->next;
		l++;
    }
    if ((temp1->next==head)&&(temp->data!=key)){
    	printf("Element is not found\n");
	}
	else{
		printf("Element is found at location %d\n",l);
	}
}
void insertion(){
	int z,p,i,c=0;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->next=NULL;
	if (head==NULL){
		printf("Enter the data");
	scanf("%d",&newnode->data);
		head=newnode;
		head->prev=newnode;
		tail=newnode;
		tail->next=newnode;
		return;
	}
    else{printf("Insert element at 1.beginning 2.ending 3 specific position:");
	scanf("%d",&z);    
	printf("Enter the data:");
	}
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if (z==1){
		newnode->next=head;
		newnode->prev=tail;
		head->prev=newnode;
		tail->next=newnode;
		head=newnode;
		return;
	}
	if(z==2){
		tail->next=newnode;
		newnode->prev=tail;
		newnode->next=head;
		head->prev=newnode;
		tail=newnode;
		return;
	}
	if (z==3){
		printf("Enter position");
		scanf("%d",&p);
		temp=head;
		for (i=0;i<p-1;i++){
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
		newnode->prev=temp;
		newnode->next->prev=newnode;
		return;
	}
}
void main(){
	int x=1,a;
	while(x==1){
		printf("MENU LIST\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Search\n");
		printf("4.Traverse\n");
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
	printf("Do you want to continue the process(YES-1/NO-0):");
		scanf("%d",&x);	
	}
}
