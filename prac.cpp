#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Address{
	int count;
	char data;
	struct Address *next,*left,*right;
}*ad=NULL,*d,*q,*r;

int charStore(int arr[]){
	int count = 0;
	for(int i = 0; i<256; i++){
		if(arr[i]!=0){
			count++;
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

void inorderTraverse(struct Address *q, char str[], char concat){
	strncat(str,&concat,1);
	if(q==NULL){
		str[strlen(str)-1] = '\0';
		return;
	}
	if(q->left==NULL){
		printf("%c: %s\n",q->data,str);
	}
	inorderTraverse(q->left,str,'0');
//	printf("%d\n",q->count);
	inorderTraverse(q->right,str,'1');
	str[strlen(str)-1] = '\0';
	return;
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

int main(){
	int characters[256], distinctChars = 0;
	for(int i = 0; i<256; i++){
		characters[i] = 0;
	}
	FILE *f;
	f = fopen("my.txt","rb");
	int c;
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
	while(1){
		addArrange();
		if(ad->next == NULL){
			break;
		}
		insertionSort(ad);
	}
	char str[distinctChars-1] = {};// This should not be initialized in '.c' but initialize it with '{}' in '.cpp' otherwise 
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
	inorderTraverse(ad,str,'\0'); // initially str contains only '\0'
	return 0;
}