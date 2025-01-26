#include<stdio.h>
#include<ctype.h>
#include<string.h>
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
	int i,j;
	char temp[100];
	for (i=strlen(ex)-1,j=0;i+1!=0;--i,++j) {
		if (ex[i]=='('){
			temp[j]=')';
		}
		else if (ex[i]==')'){
			temp[j]='(';
		}
		else{
		temp[j]=ex[i];
	}
	}
	temp[j]='\0';
	strcpy(ex,temp);
	e=ex;
	char p[100];i=0;
	while(*e!='\0'){
		if (isalnum(*e)){
			p[i]=*e;
			i++;
		}
		else if (*e=='('){
			push(*e);
		}
		else if (*e==')'){
			while((c = pop()) != '('){
				p[i]=c;i++;
            }
		}
		else{
			 while(priority(s[top])>=priority(*e))
				{ p[i]=pop();i++;}
            push(*e);
		}
		e=e+1;
	}
		while (top!=-1){
		p[i]=pop();i++;
	}
	printf("Infix to prefix :%s",strrev(p));
	}
	
	

