#include<stdio.h>
#include<math.h>
#include<string.h>
char *q;
char *convertToBinary(int a){ // This works only upto 8 bit numbers
	int i = 0;
	static char binary[9]; // static is necessary for returning the array ( binary[] )
//	char *p;
//	p = &binary[0];
	binary[8] = '\0';
	for(i=0;i<8;i++){
		binary[i] = '0';
	}
//	printf("%s\n",binary);
	for(;a>0;){
		for(i=0;;i++){
			if(pow(2,i)>a){
				i--;
				binary[8-i-1] = '1';
				break;
			}
		}
		a = a - pow(2,i);
	}
//	printf("%s",binary);
	return binary;
}

int main(){
	char *a;
	a = convertToBinary(14);
	printf("%s",a);
	return 0;
}