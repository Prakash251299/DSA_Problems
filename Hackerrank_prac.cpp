#include<stdio.h>
#include<stdlib.h>
int *p;
int sumation(int A[], int B[], int j){
	int sum = 0;
	if(j==*p){
		return 0;
	}
	sum = B[j] - A[j] + sumation(A, B, j + 1);
//	return sum = sum + sum(A, B, j);
//	print()
	return sum;
}

int main(){
    int n = 0, i = 1, m = 0, l = 0;
    // printf("Enter test cases\n");
//    scanf("%d",&n);
//    while(i <= n){
        // printf("Test case %d:-\n",i);
        // printf("Enter number of elements in the CrewID\n");
        scanf("%d",&m);
        p = &m;
        int A[m], B[m], j = 0, sum = 0, *p;
        while(j<m){
            // printf("Enter CrewID[%d]",j);
//            scanf("%d",&A[j]);
			A[j] = rand();
            j++;
        }
        // printf("Enter number of elements in the JobID\n");
        scanf("%d",&l);
        j = 0;
        while(j<l){
            // printf("Enter JobID[%d]",j);
//            scanf("%d",&B[j]);
            B[j] = rand();
            j++;
        }
        j = 0;
//        while(j<m){
//            sum = sum + ( B[j] - A[j] );
//            j++;
//        }
        sum = sumation(A,B,j);
        printf("%d\n",sum);
//        i++;
//    }
    return 0;
}