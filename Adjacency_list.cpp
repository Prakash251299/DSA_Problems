/* Spanning tree from a selected node using adjacency list */
/* -----Error for loop on a node----- */
#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next,*down;
}*q,*r,*start=NULL;

int p = 0, priority[100];

int traverse( node *q,int n,int visited[]){
	int i = 0;
	if(q->down==NULL || visited[q->down->data]){
		if(visited[q->data]==0){
			priority[p] = q->data;
			p++;
			visited[q->data] = 1;
		}
		printf("Visited: ");
		for(i=0;i<n;i++){
			if(visited[i] == 1){
				printf("%d ",i);
			}
		}
		printf("\nOrder of visiting: ");
		for(i=0;i<p;i++){
//			if(visited[i] == 1){
			printf("%d ",priority[i]);
//			}
		}
		printf("\n");
		return 0;
	}
	if(visited[q->data]==0){
		priority[p] = q->data;
		p++;
		visited[q->data] = 1;
	}
	r = start;
	while(1){
		if(r->data==q->down->data){
			traverse(r,n,visited);
			if(q->down->down!=NULL){
				q = q->down;
				visited[q->data] = 0;
//				priority[p] = 
				p--;
				r = start;
				continue;
			}
			else{
				visited[q->down->data] = 0;
				p--;
			}
			break;
		}
		else{
			r = r->next;
		}
	}
	return 0;
}

int ins(int n){
	int i = 0, j = 0, connect = 0;
	q = start;
	for(i=0;i<n;i++){
		r=q;
		for(j=0;j<n;j++){
			printf("%d connected with %d(0.No 1.Yes)\n",i,j);
			scanf("%d",&connect);
			if(connect==1){
				r->down = (struct node*)malloc(sizeof(struct node));
				r = r->down;
				r->data = j;
				r->down = NULL;
				r->next = NULL;
				p = 0; // For indicating priority array at 0th position
			}
		}
		q = q->next;
	}
	return 0;
}

int main(){
	int choice = 0, i = 0, j = 0, n = 0, selected = 0;
	while(1){
		printf("1.Insert\n2.Print all connections\n3.Traverse\n4.Exit\n");
		scanf("%d",&choice);
		if(choice==1){
			start = NULL;
			printf("Enter number of nodes\n");
			scanf("%d",&n);
//			p=0;
		}
		int visited[n];
		for(i=0;i<n;i++){
			visited[i] = 0;
		}
		p = 0;
		switch(choice){
			case 1: 
				for(i=0;i<n;i++){
					if(start==NULL){
						start = (struct node*)malloc(sizeof(struct node));
						start->data = 0;
						start->next = NULL;
						start->down = NULL;
						q=start;
					}
					else{
						q->next = (struct node*)malloc(sizeof(struct node));
						q = q->next;
						q->data = i;
						q->next = NULL;
						q->down = NULL;
					}
				}
				i=0;
				ins(n);
				break;
			case 2:q = start;
				for(i=0;i<n;i++){
					r=q;
					for(j=0;j<n;j++){
						if(r->down==NULL){
							break;
						}
						printf("%d - %d\n",q->data,r->down->data);
						r = r->down;
					}
					q = q->next;
				}
				break;
			case 3:
				printf("Select a node for traversal\n");
				scanf("%d",&selected);
				q = start;
				for(i=0;i<n;i++){
					if(selected==q->data){
						traverse(q,n,visited);
						break;
					}
					else{
						q = q->next;
					}
				}
				break;
			case 4:return 0;
			default:printf("Invalid choice\n");
		}
	}
	return 0;
}