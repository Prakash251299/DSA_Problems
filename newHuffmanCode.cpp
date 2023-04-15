#include<stdio.h>
#include<malloc.h>
struct node{
	int count;
	char data;
	struct node *next,*left,*right;
}*start = NULL,*q;

int getElements(){
	int charCounter[256];
	int i = 0;
	FILE *f;
	for(i = 0;i<256;i++){
		charCounter[i] = 0;
	}
	char fileName[] = "file1.txt";
	f = fopen(fileName,"r");
	while(1){
		char ch = fgetc(f);
		if(ch == EOF) break;
		charCounter[ch]++;
//		printf("%c",ch);
	}
	i=0;
	while(i<256){
		if(charCounter[i] != 0){
			if(start==NULL){
				start = (struct node*)malloc(sizeof(struct node));
				start->data = i;
				start->count = charCounter[i];
				start->next = NULL;
				start->left = NULL;
				start->right = NULL;
				q = start;
			}
			else{
				q->next = (struct node*)malloc(sizeof(struct node));
				q = q->next;
				q->data = i;
				q->count = charCounter[i];
				q->next = NULL;
				q->left = NULL;
				q->right = NULL;
			}
		}
		i++;
	}
//	q = start;
//	while(1){
//		if(q==NULL){
//			break;
//		}
//		printf("%c: %d\n",q->data,q->count);
//		q = q->next;
//	}
	return 0;
}

int main(){
	getElements();
	q = start;
	while(1){
		if(q==NULL){
			break;
		}
		printf("%c: %d\n",q->data,q->count);
		q = q->next;
	}
	return 0;
}