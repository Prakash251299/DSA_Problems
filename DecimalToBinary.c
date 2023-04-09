

/*  ##### Make it for all values, at the time it is working only upto 255  */



#include<stdio.h>
#include<math.h>
int convertToBinary(int a){
	int i = 0, b = 0;
	b = (log2(a)+1);
	char binary[b];
	binary[8] = '\0';
	for(i=0;i<8;i++){
		binary[i] = '0';
	}
	printf("%s\n",binary);
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
	printf("%s",binary);
	return 0;
}

int main(){
	int a = 14;
	printf("Enter a number to convertit into binary: ");
	scanf("%d",&a);
	convertToBinary(a);
	return 0;
}