/* Using hexadecimal address of a variable to change its value */
#include <stdio.h>
int main() {
	int var = 74; // initial value of the variable
	printf("Adress of var = %x, var=%d\n", &var, var); // inital value and address is printed
	/* Assigning hexadecimal address of the variable */
	int *ptr = (int*)0x64fed8; // After 0x just write value of &var
//	int *ptr = &var; // This is same thing but assigning the address as a variable
	printf(" ptr points to %x\n", ptr);
	printf("Enter a number\n");
	scanf("%d",ptr);
	printf("New value of var=%d\n", var); // This is changed as the address value of var is changed
	return 0;
}