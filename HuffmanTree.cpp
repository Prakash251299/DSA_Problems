#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
}*start = NULL,*q,*r;

int ins(int n){
	int i = 0;
	start = (struct node*)malloc(sizeof(struct node));
	start->data = 5;
	start->next = NULL;
	q = start;
	for(i=0;i<n-1;i++){
		q->next = (struct node*)malloc(sizeof(struct node));
		q->next->data = i+2;
		q = q->next;
		q->next = NULL;
	}
	return 0;
}

int display(){
	q = start;
	while(q!=NULL){
		printf("%d ",q->data);
		q = q->next;
	}
	return 0;
}

int insertionSort(node *q){ // just for sorting first element [ Time complexity: O(n) ]
	if(q==NULL || q->next==NULL){
		return 0;
	}
	while(1){
		if(start->data > q->next->data){
			if(q->next->next==NULL){
				q->next->next = start;
				start = start->next;
				q->next->next->next = NULL; // For more than 2 elements it is must
				return 0;
			}
			else{
				q = q->next;continue;
			}
		}
		else{
			r = q->next;
			q->next = start;
			start = start->next;
			q->next->next = r;
			return 0;
		}
	}
}

int main(){
	int n = 0;
	printf("Enter length: ");
	scanf("%d",&n);
	ins(n);
	display();
	insertionSort(start);
	printf("\n");
	display();
}