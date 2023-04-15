#include<stdio.h>
#include<math.h>
#include<string.h>
char *charToBinary(char a, char bin[]){
	strcpy(bin,"00000000");
	int dec = a;
	for(int i = 7; i>=0;i--){
		if(pow(2,i)<=dec){
			bin[7-i] = '1';
			dec = dec - pow(2,i);
			i = 7;
		}
		if(dec == 0){
			break;
		}
	}
//	printf("%s\n",bin);
	return bin;
}

int main(){
	FILE *mainFile, *destinationFile;
	char a = 'A', *b, bin[9]; // bin length should be 9 as we require 8 bits for data and one bit for '\0' 
	mainFile = fopen("file1.txt","rb");
	destinationFile = fopen("i.txt","wb");
	while(1){
		char ch = fgetc(mainFile);
		if(ch==EOF){
			break;
		}
		b = charToBinary(ch,bin);
		fputs(b,destinationFile);
//		fputc(' ',destinationFile); // For reading purpose spaces can be inserted
//		printf("%s ",b);
//		puts(b); // prints the value and ends with '\n'
	}
	fclose(mainFile);
	fclose(destinationFile);
	return 0;
}