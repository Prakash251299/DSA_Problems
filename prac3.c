/* Encoding for compressing a file using an extra file (bin.txt) which stores file data in binary form */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct Address{
	int count;
	char data;
	struct Address *next,*left,*right;
}*ad=NULL,*d,*q,*r;

int charStore(int arr[]){
	int count = 0;
	for(int i = 0; i<=256; i++){
		if(arr[i]!=0){
			count++;
			if(i==256){
				d->next = (struct Address*)malloc(sizeof(struct Address));
				d = d->next;
				d->data = -1;
				d->count = 1;
				d->next = NULL;
			}else{
				if(ad==NULL){
					ad = (struct Address*)malloc(sizeof(struct Address));
					ad->data = i;
					ad->count = arr[i];
					ad->next = NULL;
					d = ad;
				}
				else{
					d->next = (struct Address*)malloc(sizeof(struct Address));
					d = d->next;
					d->data = i;
					d->count = arr[i];
					d->next = NULL;
				}
			}
		}
	}
	return count;
}

void midFinder(struct Address *head, struct Address **q, struct Address **r){
	struct Address *fast = head;
	struct Address *slow = head;
	while(1){
		if(fast->next==NULL || fast->next->next==NULL){
			break;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	*q = head; 
	*r = slow->next;
	slow->next = NULL;
}

struct Address *sortedMerge(struct Address *q, struct Address *r){
	struct Address *result = NULL; // It is a container for the merged list
	if(q==NULL){
		return r;
	}else{
		if(r==NULL){
			return q;
		}
	}
	if(q->count>r->count){
		result = r;
		result->next = sortedMerge(q,r->next);
	}else{
		result = q;
		result->next = sortedMerge(q->next,r);
	}
	
	return result;
}

void mergeSort(struct Address **q){  // Here **q holds address of pointer (initially address of start)
	struct Address *head = *q; // *q is pointer ( initially start)
	struct Address *front;
	struct Address *back;
	if(head==NULL || head->next==NULL){
		return;
	}
	midFinder(head,&front,&back);
	mergeSort(&front);
	mergeSort(&back);
	*q = sortedMerge(front,back);
}

int insertionSort(struct Address *q){ // just for sorting first element [ Time complexity: O(n) ]
	if(q==NULL || q->next==NULL){
		return 0;
	}
	while(1){
		if(ad->count > q->next->count){
			if(q->next->next==NULL){
				q->next->next = ad;
				ad = ad->next;
				q->next->next->next = NULL; // For more than 2 elements it is must
				return 0;
			}
			else{
				q = q->next;continue;
			}
		}
		else{
			r = q->next;
			q->next = ad;
			ad = ad->next;
			q->next->next = r;
			return 0;  // One element sorted so return
		}
	}
}

int addArrange(){
	int sum = 0;
	q = ad;
	r = NULL;
	sum = q->count + q->next->count;
	r = (struct Address*)malloc(sizeof(struct Address));
	r->count = sum;
	r->left = q;
	r->right = q->next;
	r->next = q->next->next;
	ad = r;
//	printf("\nsum: %d ",sum);
	return 0;
}

int inorderTraverse(int n,struct Address *q, char str[][n], char concat, char bitCont[]){
	strncat(bitCont,&concat,1);
	if(q==NULL){
		bitCont[strlen(bitCont)-1] = '\0';
		return 0;
	}
	if(q->left==NULL){
		printf("%c: %s\n",q->data,bitCont);
		if(q->data==-1){
			strcpy(str[256],bitCont);
		}else{
			strcpy(str[q->data],bitCont);
		}
	}
	inorderTraverse(n,q->left,str,'0',bitCont);
	inorderTraverse(n,q->right,str,'1',bitCont);
	bitCont[strlen(bitCont)-1] = '\0';
	return 0;
}

void display(){
	d = ad;
	int i = 0;
	while(1){
		if(d==NULL){
			return;
		}
		printf("%d. %c: %d\n",i,d->data,d->count);
		d = d->next;
		i++;
	}
	printf("\n");
	return;
}
int j = 0;
int store(struct Address*q,char arr[]){
	if(q==NULL){
		return 0;
	}
	store(q->left,arr);
	if(q->left==NULL){
		printf("%c\n",q->data);
		arr[j] = q->data;
		j++;
	}
//	printf("%c\n",q->data);
	store(q->right,arr);
	return 0;
}

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
	printf("%s",binary);
	return binary;
}

//int compressedStore(char storeInorderedChars[],char str[][8]){
//	printf("\nsize of str[!]: %d",strlen(str['5']));
//	return 0;
//}

int compress(int distinctChars,char str[][8],char storeInorderChars[]){
	int i=0,k=0,a=0,j=0;
//	char s[8];
	FILE *f;
	char *s;
	f = fopen("compressedMessageStore.txt","wb");
//	int c;
	while(1){
		if(i==distinctChars){
			break;
		}
		j = k;
		s = convertToBinary(strlen(str[storeInorderChars[i]])-1);
		a = (a^s[5])<<1;
		a = (a^s[6])<<1;
		a = (a^s[7])<<1;
//		printf("VVVVVVVV:%s",s);
		for(k=0;k<strlen(str[storeInorderChars[i]]);k++){
			a = a^str[storeInorderChars[i]][k];
			j++;
			if(j==8){
				fputc(a,f);
				a = 0;
				j = 0;
			}
			else a = a<<1;
		}
		i++;
		for(k=0;k<8;k++){
			a = (a^str[storeInorderChars[i]][k]);
			j++;
			if(j==8){
				fputc(a,f);
				a = 0;
				j = 0;
			}
			else a = a<<1;
		}
	}
	return 0;
}

int main(){
	int characters[256], distinctChars = 0, i = 0;
	char storeInorderedChars[255];
	for(i = 0; i<=256; i++){
		characters[i] = 0;
	}
	FILE *f,*g,*bin;
	f = fopen("my.txt","rb");
	int c;
	characters[-1] = 1;
	characters[256] = 1; // For information of end ( i.e. EOF )
	while(1){
		c = fgetc(f);
		if(c==EOF){
			break;
		}
		characters[c]++;
	}
	/* For printing all the distinc characters */
//	for(int i = 0; i<256; i++){
//		printf("%d. %c: %d\n",i,i,characters[i]);
//	}

	distinctChars = charStore(characters); // Send characters to store in a linked list
	mergeSort(&ad); // ad stores the characters as linked list
	char str[257][distinctChars-1];
	str[0][0] = '\0';
	char bitCont[distinctChars-1];
	bitCont[0] = '\0';
	if(distinctChars==1){  // For one repeating character this is enough, link it with message [ not necessary 
						// if ender(-1) is there for all the files ]
		char str[3] = "1";
		printf("%c: %s\n",ad->data,str);
	}else{
		while(1){
			addArrange();
			if(ad->next == NULL){
				break;
			}
			insertionSort(ad);
		}
//		char str[257][distinctChars-1];
//		str[0][0] = '\0';
//		char bitCont[distinctChars-1];
//		bitCont[0] = '\0';
		 // This should not be initialized in '.c' but initialize it with '{}' in '.cpp' otherwise 
		// ambiguous result comes
		/* Size of str[] must be just 1 less than distinct characters (its max size may be 256 since only 256 characters are ther in ascii)
		as number of each distinct characters may be greater than previous number of characters for some case (e.g. for " abccddddeeeeeeeee")
										16
									   / \
	 								  8   8e
									 / \
									4   4d
								   / \
								  2  2c
								 / \
								1a 1b
			For this 'a' and 'b' requires 4 character bits of 'str' which is just 1 less than the number of distinct characters */
		inorderTraverse(distinctChars-1,ad,str,'\0',bitCont); // initially str contains only '\0'
		
//		printf("asdf:%s\n",str['!']);
//		printf("Change\n");
		fclose(f);
//		i=0;
//		f = fopen("my.txt","rb");
//		printf("asdf:%s\n",str['!']);
//		while(i<distinctChars){
//			c = fgetc(f);
//			printf("%c: %s\n",bitCont[i],str[c]);
//			i++;
//			if(i==10){
//				printf("%c: %s\n",bitCont[i],str[256]);
//			}
//		}
//		return 0;
		f = fopen("my.txt","rb");
		bin = fopen("bin.txt","wb"); // This is just for containing the binary data of the file, it will be deleted at last
		printf("Repeat\n");
		while(1){
			c = fgetc(f);
			if(c==EOF){
				fputs(str[256],bin);
//				printf("%c\n",c);
				break;
			}
//			printf("%c\n",c);
			fputs(str[c],bin);
		}
//		printf("BEFORE\n");
//		for(i=0;i<distinctChars;i++){
//			printf("%c\n",storeInorderedChars[i]);
//		}
//		printf("\n");
		store(ad,storeInorderedChars);
//		printf("AFTER\n");
//		for(i=0;i<distinctChars;i++){
//			if(storeInorderedChars[i]==-1){
//				printf("%c: %s\n",storeInorderedChars[i],str[256]);
//			}else{
//				printf("%c: %s\n",storeInorderedChars[i],str[storeInorderedChars[i]]);
//			}
//		}
//		printf("End\n");
//		return 0;
//		printf("asdf:%s\n",str['!']);
		fclose(bin);
//		printf("asdf:%s\n",str['!']);
		bin = fopen("bin.txt","rb");
		g = fopen("compressed1.txt","wb");
		int i =0,a=0;
		while(1){
			c = fgetc(bin);
			if(c==EOF){
				a = (a<<(8-i))^0;
				fputc(a,g);
//				printf("%d: %c ",a,a);
				break;
			}
			a = (a<<1)^(c-'0');
			i++;
			if(i==8){
//				printf("%d: %c ",a,a);
				fputc(a,g);
				a = 0;
				i=0;
			}
		}
//		printf("asdf:%s\n",str['!']);
	}
	
//	printf("asdf:%s\n",str['!']);
	printf("###Distinct characters: %d\n",distinctChars);
	fclose(bin);
//	remove("bin.txt"); // bin.txt will be deleted if this is uncommented
	printf("Compressed file is compressed1.txt\n");
	fclose(f);
	fclose(g);
//	f = fopen("my.txt","r");
	printf("AFTER\n");
	for(i=0;i<distinctChars;i++){
		if(storeInorderedChars[i]==-1){
			printf("%c: %s\n",storeInorderedChars[i],str[256]);
		}else{
			printf("%c: %s\n",storeInorderedChars[i],str[storeInorderedChars[i]]);
		}
	}
	fclose(f);
	
	
	
	f = fopen("compressedMessageStore.txt","wb");
	fputs(convertToBinary(distinctChars),f);
	fputs("\r\n",f);
	i=0;
	int a=0,k=0;
	char *s;
	while(i<distinctChars){
		if(storeInorderedChars[i]==-1){
			fputs("-1",f);
			fputc(':',f);
			for(j=0;j<strlen(str[256]);j++){
				fputc(str[256][j],f);
			}
//			fputs(str[256],f);
			fputs("\r\n",f);
		}
		else{
//			fputc(storeInorderedChars[i],f);
			s = convertToBinary(storeInorderedChars[i]);
			for(j=0;j<9;j++){
//				a = a^str[storeInorderedChars[i]][j];k++;
//				s = convertToBinary(storeInorderedChars[i]);
				if(k==8){
					fputc(a,f);
					a = 0;
					k = 0;
//					j--;
				}else{
					a = a<<1;
					a = a^(s[j]-'0');
//					j++;
					k++;
//					a = a<<1;
				}
//				fputc(str[storeInorderedChars[i]][j],f);
			}
			for(j=0;j<3;j++){
				a = a<<1;
				a = a^(str[storeInorderedChars[i]][j]-'0');k++;
				if(k==8){
					fputc(a,f);
					a=0;
					k=0;
				}
			}
//			fputc(':',f);
			for(j=0;j<strlen(str[storeInorderedChars[i]]);j++){
				a = a<<1;
				a = a^(str[storeInorderedChars[i]][j]-'0');k++;
				if(k==8){
					fputc(a,f);
					a=0;
					k=0;
				}
				
//				fputc(str[storeInorderedChars[i]][j],f);
			}
//			fputs(str[storeInorderedChars[i]],f);
//			fputs("\r\n",f);
		}
		i++;
	}
	if(k!=8){
		a = a<<k;
		fputc(a,f);
	}
	fclose(f);
	
//	f = fopen("compressedMessageStore.txt","wb");
//	i=0;
//	while(i<distinctChars){
//		if(storeInorderedChars[i]==-1){
//			fputs("-1",f);
//			fputc(':',f);
//			fputs(str[256],f);
//			fputs("\r\n",f);
//		}
//		else{
//			fputc(storeInorderedChars[i],f);
//			fputc(':',f);
//			fputs(str[storeInorderedChars[i]],f);
//			fputs("\r\n",f);
//		}
//		i++;
//	}


	
//	printf("\nsize of str[!]: %d",strlen(str['5']));
//	compress(distinctChars,str,storeInorderedChars);
	
//	int k = 0, a = 0;
//	i=0;j=0;
//	char s[8];
//	f = fopen("compressedMessageStore.txt","wb");
////	int c;
//	while(1){
//		if(i==distinctChars){
//			break;
//		}
//		j = k;
//		s[0] = convertToBinary(strlen(str[storeInorderedChars[i]])-1,s);
//		a = (a^s[5])<<(7-j);
//		a = (a^s[6])<<(7-j);
//		a = (a^s[7])<<(7-j);
//		for(k=0;k<strlen(str[storeInorderedChars[i]]);k++){
//			a = a^str[storeInorderedChars[i]][k]<<(7-j);
//			j++;
//			if(j==8){
//				fputc(a,f);
//				a = 0;
//				j = 0;
//			}
//		}
//		i++;
//		for(k=0;k<8;k++){
//			a = (a^str[storeInorderedChars[i]][k])<<(7-j);
//			j++;
//			if(j==8){
//				a = 0;
//				j = 0;
//			}
//		}
//	}
	
	
	
	
	
//	compress(distinctChars,str,storeInorderedChars);
//	i=0;
//	while(i<distinctChars){
//		c = fgetc(f);
//		
//		i++;
//	}
	return 0;
}