#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
}*head,*tail=NULL,*newnode,*temp;
struct node *head=NULL;
void traverse(){
	int c=0;
	struct node *temp3;
	if(head==NULL) {
		printf("List is empty\n");
        return;
        }
    else{
        temp3=head;
        printf("The List elements are:");
        while(temp3!=NULL){
            printf("%d  ",temp3->data );
            temp3=temp3->next ;
            c++;
        }
    }
	printf("\nNo of elements:%d\n",c);
}
void deletion(){
	int z,p,i;
	struct node *temp1,*fp;
	if (head==NULL){
			printf("The list is empty\n");
		}
	printf("Delete element at 1.beginning 2.ending 3 specific position :");
	scanf("%d",&z);
	if (z==1){
		temp=head;
		head=head->next;
		head->prev=NULL;
		temp->next=NULL;
		return;
	}
	if(z==2){
		temp=head;
		while(temp->next!=tail){
			temp=temp->next;
		}
		temp->next=NULL;
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
		return;
	}
}
void search(){
	int l=0,key;
	temp=head;
	printf("Enter element to be searched:");
	scanf("%d",&key);
	if (head==NULL){
			printf("The list is empty\n");
		}
	while ((temp->data!=key) &&(temp->next!=NULL)){
		temp=temp->next;
		l++;
    }
    if ((temp->next==NULL)&&(temp->data!=key)){
    	printf("Element is not found\n");
	}
	else{
		printf("Element is found at location %d\n",l);
	}
}
void insertion(){
	int z,p,i;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(head==NULL){
		printf("Enter the data:");
		head=newnode;
		tail=newnode;
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
		newnode->prev=NULL;
		head->prev=newnode;
		head=newnode;
		return;
	}
	if(z==2){
		tail->next=newnode;
		newnode->prev=tail;
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
