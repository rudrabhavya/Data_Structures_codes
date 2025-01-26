#include<stdio.h>
#include<ctype.h>
char s[100];
int top=-1;
void push(char z){
	top=top+1;
		s[top]=z;
}
char pop(){
	if(top == -1)
        return -1;
    else
        return s[top--];
}
int priority(char p){
	switch(p){
		case '(':return 0;
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '^':return 3;
		default:return 0;
	}
}
void main(){
	char ex[100],*e,c;
	printf("Enter the expression: ");
	scanf("%s",&ex);
	e=ex;
	printf("Postfix expression :");
	while(*e!='\0'){
		if (isalnum(*e)){
			printf("%c",*e);
		}
		else if (*e=='('){
			push(*e);
		}
		else if (*e==')'){
			while((c = pop()) != '(')
                printf("%c", c);
		}
		else{
			 while(priority(s[top])>=priority(*e))
                printf("%c",pop());
            push(*e);
		}
		e=e+1;
	}
	while (top!=-1){
		printf("%c",pop());
	}
	
}
