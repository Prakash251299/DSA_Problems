#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fs,*ft;
    int ch;

    fs=fopen("C:/Users/Ishu/Desktop/f1.txt","r");
    if(fs==NULL)
    {
        puts("Unable to open source!");
        exit(1);
    }
    ft=fopen("C:/Users/Ishu/Desktop/mn.txt","w");
    if(ft==NULL)
    {
        puts("Unable to copy!");
        fclose(fs);
        exit(2);
    }
	char p=NULL,q=NULL,r=NULL;
	int sum = 0;
    while(1)
    {
        ch=fgetc(fs);
//        if(ch==EOF) break;
//        printf(" char: %c ",ch);
        if(ch == ' '|| (ch==EOF)){
//        	if(ch==EOF){
//        		printf("\nlast: %d %d %d\n",p,q,r);
//			}
//        	printf("p:%d q:%d r:%d\n",p,q,r);
        	if(p!=NULL && q!=NULL && r!=NULL){
        		sum = (int(p)-int('0'))*100+(int(q)-int('0'))*10+(int(r)-int('0')*1);
			}
			else{
				if(p!=NULL && q!=NULL && r==NULL){
					sum = (int(p)-int('0'))*10+(int(q)-int('0'))*1;
//					printf("sum: %d\n",sum);
				}else{
					if(p!=NULL && q==NULL && r==NULL){
						sum = (int(p)-int('0'))*1;
					}
				}
			}
			p = NULL;
			q = NULL;
			r = NULL;
			if(ch==EOF){
				break;
			}
		}else{
	        if(p==NULL){
	        	p = ch;
			}
			else{
				if(q==NULL){
					q = ch;
				}else{
					r = ch;
				}
			}
//			if(ch==EOF) break;
			continue;
		}
//        if(ch==EOF) break;
        fputc(sum,ft);
        sum = 0;
//    	printf("%d ",ch); // It prints all the characters of the jpg file
	}
    fclose(fs);
    fclose(ft);
    return 0;
}