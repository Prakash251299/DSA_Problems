#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *f,*g;
	int c;
	f = fopen("abcd.txt","rb");
	g = fopen("my.txt","wb");
	if(g==NULL)
    {
        puts("Unable to copy!");
        fclose(f);
        exit(2);
    }
	while(1){
		c = fgetc(f);
		if(c==EOF) break;
//		printf("%d ",c);
		fputc(c,g);
	}
	fclose(f);
	fclose(g);
//	char a = fgetc(f);
//	printf("%c",a);
	return 0;
}