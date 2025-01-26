#include<stdio.h>
#include<ctype.h>
char s[100],a,b;
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
int op(char e,int a,int b){
	switch(e){
		case '+':return b+a;
		case '-':return b-a;
		case '*':return a*b;
		case '/':return b/a;
		case '^':return b^a;
	}
}
int main(){
	char ex[100],*e,z;
	printf("Enter postfix expression:");
	scanf("%s",&ex);
	int i=0;
	while(ex[i]!='\0'){
		if (isdigit(ex[i])){
			push(ex[i]-'0');
		}
		else{
			a=pop();
			b=pop();
			z=op(ex[i],a,b);
			push(z);
		}
		i++;
	}
	printf("%d",pop());
	
}
