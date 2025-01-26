#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL,*temp,*new1;
void push(){
    int a;
    new1=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&new1->data);
if (top==NULL){
   new1->next=NULL;
   top=new1;
}
else{
   new1->next=top;
   top=new1;
}
}
void pop(){
if (top==NULL){
   printf("Empty");
}
else{
   temp=top;
   printf("%d popped",temp->data);
   top=top->next;
   temp->next=NULL;
   free(temp);
}
}
void display(){
temp=top;
while (temp!=NULL){
   printf("%d ",temp->data);
   temp=temp->next;
}
}
void main(){
int n,c=1;
while(c==1){
printf("MENU\n1.push()\n2.pop()\n3.top\n4.display()\n5.exit\n");
printf("Enter your choice: ");
scanf("%d",&n);
switch(n){
case 1:push();
break;
case 2:pop();
break;
case 3:printf("Top: %d",top->data);
break;
case 4:display();break;
case 5:exit(0);
        }
        printf("\nDo you want to continue:");
        scanf("%d",&c);
}
}
