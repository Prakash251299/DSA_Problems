/* Error for loop on a node */
#include<stdio.h>
int main(){
	int i=0,j=0,n=0,selected=0,p=0,q=0,a=0,connection = 0,count=0;
	while(1){
		printf("Enter number of nodes\n");
		scanf("%d",&n);
		if(n<=0){
			printf("Invalid number of nodes please try again\n");
		}
		else{
			break;
		}
	}
//	printf("ehfi");
	int A[n][n],Explore[n],visited[n];
//	printf("ehfi");
	while(1){
//		printf("ehfi");
		printf("Select a node from 0 to %d\n",n-1);
		scanf("%d",&selected);
		if(selected<0 or selected>=n){
			printf("Invalid node please try again\n");
		}
		else{
			break;
		}
	}
	Explore[q] = selected;q++;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
//			printf("%d connected with %d (0.No 1.Yes)\n",i,j);
//			scanf("%d",&connection);
//			A[i][j] = connection;
			A[i][j] = 1;
		}
	}
//	printf("ixhd");
	for(i=0;i<n;i++){
		visited[i] = 0;
//		printf("ixhd");
	}
	i = selected;
	for(;i<n;i++){
		for(j=0;j<n;j++){
			if(A[i][j]==1){
				if(visited[j]==0){
					Explore[q] = j;
					q++;
//					count++;
				}
			}
		}
		for(j=a;j<q;j++){
			if(visited[Explore[j]]==0){
				visited[Explore[j]] = 1;
//				count++;
			}
		}
		a++;
//		if(a+1==q){ // Here
////			printf("kd");
//			break;
//		}
//		count++;
		i = Explore[a];
	}
	printf("Visited nodes: ");
	for(i=0;i<n;i++){
		if(visited[i]==1){
			printf("%d ",i);
		}
	}
//	printf("\nCount: %d",count);
	return 0;
}