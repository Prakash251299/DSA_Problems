#include<stdio.h>
#include<malloc.h>

struct node1{
	int val;
	struct node1 *next;
};
struct node{
	int count;
	struct node1 *l;
	struct node1 *start;
	struct node *next;
}*start=NULL,*q,*r;


int max = 5;


void ins(int val1,int i){
	if(start==NULL){
		start = (struct node*)malloc(sizeof(struct node));
		start->l = (struct node1*)malloc(sizeof(struct node1));
		start->l->val = val1;
		start->next = NULL;
		start->l->next = NULL;
		start->count = 1;
		start->start = start->l;
		q = start;
	}else{
		if(q->count>=max){
			q->next = (struct node*)malloc(sizeof(struct node));
			q = q->next;
			q->next = NULL;
			q->start = (struct node1*)malloc(sizeof(struct node1));
			q->start->next = NULL;
			q->start->val = val1;
			q->l = q->start;
			q->count = 1;
		}else{
			q->l->next = (struct node1*)malloc(sizeof(struct node1));
			q->l = q->l->next;
			q->l->val = val1;
			q->l->next = NULL;
			q->count = i+1;
		}
	}
}

void display(){
	r = start;
	while(r!=NULL){
		r->l = r->start;
		while(r->l!=NULL){
			printf("%d ",r->l->val);
			r->l = r->l->next;
		}
		printf("|");
		r = r->next;
	}r->l->next;
}

int main(){
	for(int i=0;i<10;i++){
		ins(i,i%max);
	}
	display();
	return 0;
}