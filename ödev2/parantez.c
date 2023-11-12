#include <stdio.h>
#include <stdlib.h>

int top=-1;
char stack[100]; 

void push(char x){
	stack[top]=x;
	top++;
	
}
void pop(){ 
	if(top==-1)
		printf("yanlis parantez kullanimi");
	else
		top--;	
}
void peak(){
	if(top==-1)
		printf("dogru parantez kullanimi");
	else
		printf("Yanlis parantez kullanimi");	
}

int main() {
	
	int i;
	char ifade[100];
	
	printf("lütfen matematiksel ifadenizi giriniz: ");
	scanf("%s",&ifade);
	
	for(i=0; ifade[i]!='\0'; i++){
		if(ifade[i]=='(')
			push(ifade[i]);
		else if(ifade[i]==')')
			pop();	
	}
	peak();
	
	
	return 0;
}
