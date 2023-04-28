#include<stdio.h>
#include<stdlib.h>
int main(){
	int n = 0, i = 1, m = 0, l = 0;
	printf("Enter test cases\n");
	scanf("%d",&n);
	while(i <= n){
		printf("Test case %d:-\n",i);
		printf("Enter number of elements in the CrewID\n");
		scanf("%d",&m);
		int A[m], B[m], j = 0, sum = 0;
		while(j<m){
//			printf("Enter CrewID[%d]",j);
//			scanf("%d",&A[j]);
			A[j] = rand()%100;
			j++;
		}
		printf("\nEnter number of elements in the JobID\n");
		scanf("%d",&l);
		j = 0;
		while(j<l){
//			printf("Enter JobID[%d]",j);
//			scanf("%d",&B[j]);
			A[j] = rand()%100;
			j++;
		}
		j = 0;
		while(j<m){
			sum = sum + ( B[j] - A[j] );
			j++;
		}
		printf("Sum: %d\n",sum);
		i++;
	}
	return 0;
}