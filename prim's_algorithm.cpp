#include<stdio.h>
#include<malloc.h>
struct node{
	int data,weight;
	struct node *next,*down;
}*q,*r,*start=NULL;

ins(int n){
	int connection = 0, i = 0, j = 0;
	start = (struct node*)malloc(sizeof(struct node));
	start->data = i;
	start->next = NULL;
	start->down = NULL;
	q = start;
	for(i=0;i<n;i++){
		r=q;
		for(j=0;j<n;j++){
			connection=0;
			printf("%d connected with %d (0.No 1.Yes)\n",i,j);
			scanf("%d",&connection);
			if(connection == 1){
				r->down = (struct node*)malloc(sizeof(struct node));
				r = r->down;
				r->data = j;
				printf("Weight for %d - %d\n",i,j);
				scanf("%d",&r->weight);
				r->down = NULL;
				r->next = NULL;
			}
		}
		if(i+1<n){
			q->next = (struct node*)malloc(sizeof(struct node));
			q = q->next;
			q->data = i+1;
			q->next = NULL;
			q->down = NULL;
		}
	}
	return 0;
}

int main(){
	int n=0;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	ins(n);
	return 0;
}