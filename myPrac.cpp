#include<stdio.h>
void print(){
	printf("Enter the name: ");
	char name[10];
	scanf("%s",&name);
	printf("%s",name);
	return;
}
int main(){
	print();
	return 0;
}